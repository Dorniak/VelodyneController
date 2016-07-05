#include "reader.h"
#include <locale.h>

DataReader::DataReader(List<Punto3D^>^ puntosController_in, cli::array<Object^>^ ParamReader_in, cli::array<bool>^ Flags_in, cli::array<Thread^>^ Threads_in, OpenGl^ Dibujador_in, cli::array<Object^>^ gps_in, Logger^ lg)
{
	try
	{
		this->Threads = Threads_in;
		this->Flags = Flags_in;
		ArrayDataReader = ParamReader_in;
		ArrayGps = gps_in;
		log = lg;
		this->puntosController = puntosController_in;
		this->Dibujador = Dibujador_in;
		ArrayDataReader[INFORME] = "";
		thread_reader = gcnew Thread(gcnew ThreadStart(this, &DataReader::Esperar));
		this->Threads[THREAD_READER] = thread_reader;
		Puntos = gcnew List<Punto3D^>(NUMBER_OF_POINTS);
		thread_reader->Start();
	}
	catch (Exception^ e)
	{
		System::Windows::Forms::MessageBox::Show(e->ToString());
	}
}

DataReader::~DataReader()
{
	delete ClientLIDAR;
	delete LaserIpEndPoint;
	thread_reader->Abort();
}

void DataReader::Read()
{
	ClientLIDAR = gcnew UdpClient((IPEndPoint^)ArrayDataReader[IP]);
	ClientLIDAR->Client->ReceiveTimeout = 1000;
	ClientLIDAR->Client->ReceiveBufferSize *= 2;
	calibrate();
	setlocale(LC_NUMERIC, "es_ES");
	cli::array<Byte>^ ReceiveBytes = gcnew cli::array<Byte>(1206);
	cli::array<Double>^ azimuths = gcnew cli::array<Double>(384);
	cli::array<Double>^ distances = gcnew cli::array<Double>(384);;
	cli::array<Double>^ intensities = gcnew cli::array<Double>(384);
	Punto3D^ p;
	recorrido_disparo = (2 * Convert::ToInt32(ArrayDataReader[FRECUENCY]) * 0.000002304 * 180);
	recorrido_recarga = (2 * Convert::ToInt32(ArrayDataReader[FRECUENCY]) * 0.00001843 * 180);
	bool corte = false;
	double last_azimuth_before = -1;
	Stopwatch^ frecuency_clock = gcnew Stopwatch();
	Stopwatch^ process_clock = gcnew Stopwatch();
	ArrayDataReader[FRECUENCY_TIME] = safe_cast<System::Object^>(0);
	ArrayDataReader[PROCESS_TIME] = safe_cast<System::Object^>(0);
	bool first_line = false;
	if (Flags[FLAG_LOG])
		log->init(CALIBRATE_X, CALIBRATE_Y, CALIBRATE_Z, CALIBRATE_R, CALIBRATE_P, CALIBRATE_W, (int)ArrayDataReader[FRECUENCY]);
	frecuency_clock->Start();

	while (!Flags[FLAG_WARNING] && !Flags[FLAG_PAUSA]) {
		try
		{
			ReceiveBytes = ClientLIDAR->Receive(LaserIpEndPoint);
			process_clock->Start();
			azimuths = InterpolateAzimuth(ReceiveBytes, &corte, &last_azimuth_before);
			distances = ExtractDistances(ReceiveBytes);
			intensities = ExtractIntensities(ReceiveBytes);

			for (int i = 0; i < NUMBER_OF_CHANNELS*NUMBER_OF_BLOCKS; i++) {
				if (corte || timeToSplit(i, azimuths)) {
					ArrayDataReader[FRECUENCY_TIME] = frecuency_clock->ElapsedMilliseconds / 1000;
					if (Flags[FLAG_LOG])
						log->addToBuffer(Puntos, (String^)ArrayGps[TRAMA]);
					copiarPuntos();
					frame++;
					first_line = true;
					corte = false;
					frecuency_clock->Restart();
				}
				if ((distances[i] >= min) && (distances[i] <= max)) {
					p = gcnew Punto3D(distances[i], intensities[i], azimuths[i], getAngle(i), frame);
					p->CalculateCoordinates(CALIBRATE_X, CALIBRATE_Y, CALIBRATE_Z, CALIBRATE_P, CALIBRATE_R, CALIBRATE_Y);
					Puntos->Add(p);
				}
				else {
					p = gcnew Punto3D(frame, azimuths[i]);
					Puntos->Add(p);
				}
			}
		}
		catch (SocketException^)
		{
			Flags[FLAG_WARNING] = true;
			log->Stop();
			System::Windows::Forms::MessageBox::Show("No se reciben datos en el puerto " , "Error", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
			ClientLIDAR->Close();
			if (Flags[FLAG_LOG])
				log->close();
			Puntos->Clear();
			delete ReceiveBytes;
			delete azimuths;
			delete distances;
			delete intensities;
			delete p;
			Esperar();
		}
		catch (Exception^ e)
		{
			Flags[FLAG_WARNING] = true;
			System::Windows::Forms::MessageBox::Show(e->ToString(), "Error", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
			ClientLIDAR->Close();
			log->Stop();
			if (Flags[FLAG_LOG])
				log->close();
			Puntos->Clear();
			delete ReceiveBytes;
			delete azimuths;
			delete distances;
			delete intensities;
			delete p;
			Esperar();
		}
		ArrayDataReader[PROCESS_TIME] = process_clock->ElapsedMilliseconds;
		process_clock->Restart();
	}
	log->Stop();
	ClientLIDAR->Close();
	log->close();
	Puntos->Clear();
	delete ReceiveBytes;
	delete azimuths;
	delete distances;
	delete intensities;
	delete p;
	Esperar();
}

void DataReader::Esperar()
{
	log->Stop();
	while (Flags[FLAG_WARNING] || Flags[FLAG_PAUSA]) {
		Sleep(250);
	}
	Read();
}

void DataReader::Kill()
{
	thread_reader->Abort();
}

cli::array<Double>^ DataReader::InterpolateAzimuth(cli::array<Byte>^ &ReceiveBytes, bool *corte, double *azi) {

	if (ReceiveBytes->Length == 0)
		throw gcnew Exception("Recibiendo 0 bytes...");

	if (ReceiveBytes->Length != 1206)
		throw gcnew Exception("Paquete con formato extraño");

	cli::array<double>^ result = gcnew cli::array<double>(384);
	cli::array<double>^ azimuths = gcnew cli::array<double>(12);
	int byteIndex = 2;
	//2*f*t*180 / 1000
	for (int i = 0; i < 12; i++)
	{
		azimuths[i] = (ReceiveBytes[byteIndex] + (ReceiveBytes[byteIndex + 1] << 8));
		azimuths[i] /= 100;
		byteIndex += 100;
	}
	for (int k = 0; k < 12; k++) {
		for (int j = 0; j < 32; j++) {
			if (j < 16)
			{
				result[j + (32 * k)] = azimuths[k] + (j*recorrido_disparo);//0.0165887 PARA 20 HZ
			}
			else
			{
				result[j + (32 * k)] = azimuths[k] + ((j*recorrido_disparo) + recorrido_recarga);//0.1326959 para 20hz
			}

			if (result[j + (32 * k)] >= 360) {
				result[j + (32 * k)] -= 360;
			}
			if (j + k>0) {
				double b = result[j + (32 * k) - 1];
				double a = result[j + (32 * k)];
				if ((b - a > 5.0) && (b - a < 15.0)) {

					int a = 2;
				}
			}
		}
	}
	if (*azi > azimuths[0]) {
		*corte = true;
	}
	*azi = result[383];
	return result;
}

cli::array<Double>^ DataReader::ExtractDistances(cli::array<Byte>^ &ReceiveBytes) {
	if (ReceiveBytes->Length == 0)
		throw gcnew Exception("Recibiendo 0 bytes...");

	if (ReceiveBytes->Length != 1206)
		throw gcnew Exception("Paquete con formato extraño");

	cli::array<Double>^ distances = gcnew cli::array<Double>(384);
	int bytes = 0;
	double dist;

	for (int j = 0; j < 12; j++)
	{
		bytes += 4;
		for (int i = 0; i < 32; i++)
		{
			dist = (ReceiveBytes[bytes] + (ReceiveBytes[bytes + 1] << 8));
			distances[j * 32 + i] = (dist * 2) / 1000;
			bytes += 3;
		}
	}

	return distances;
}

cli::array<Double>^ DataReader::ExtractIntensities(cli::array<Byte>^ &ReceiveBytes) {
	if (ReceiveBytes->Length == 0)
		throw gcnew Exception("Recibiendo 0 bytes...");

	if (ReceiveBytes->Length != 1206)
		throw gcnew Exception("Paquete con formato extraño");

	cli::array<Double>^ intensities = gcnew cli::array<Double>(384);
	int bytes = 0;

	for (int j = 0; j < 12; j++)
	{
		bytes += 6;
		for (int i = 0; i < 32; i += 2)
		{
			intensities[j * 32 + i] = ReceiveBytes[bytes];
			bytes += 3;
		}
	}
	return intensities;
}

void DataReader::Informar(String ^ Entrada)
{
	ArrayDataReader[INFORME] += DateTime::Now.ToString("HH - mm - ss") + "]" + Entrada + "\r\n";

}

void DataReader::calibrate()
{
	CALIBRATE_X = Convert::ToDouble(ArrayDataReader[PCALIBRATE_X]);
	CALIBRATE_Y = Convert::ToDouble(ArrayDataReader[PCALIBRATE_Y]);
	CALIBRATE_Z = Convert::ToDouble(ArrayDataReader[PCALIBRATE_Z]);
	CALIBRATE_R = Convert::ToDouble(ArrayDataReader[PCALIBRATE_R]);
	CALIBRATE_P = Convert::ToDouble(ArrayDataReader[PCALIBRATE_P]);
	CALIBRATE_W = Convert::ToDouble(ArrayDataReader[PCALIBRATE_W]);
	max = Convert::ToDouble(ArrayDataReader[MAX_DISTANCE]);
	min = Convert::ToDouble(ArrayDataReader[MIN_DISTANCE]);
}


void DataReader::copiarPuntos()
{
	Informar("Copiar Puntos");
	for (int i = 0; i < puntosController->Count; i++)
	{
		delete puntosController[i];
	}
	puntosController->Clear();
	puntosController->AddRange(Puntos);

	if (Flags[FLAG_OPENGL]) {
		if (puntosController->Count > 1000) {
			Dibujador->modificarPuntos(puntosController);
			Dibujador->listo = true;
		}
	}
	//Controller de colision
	if (!Flags[FLAG_TRATAMIENTO] && Flags[FLAG_ANALISYS]) {
		//Flags[FLAG_WARNING] = true;
		}
	Flags[FLAG_TRATAMIENTO] = false;
	for (int i = 0; i < Puntos->Count; i++)
	{
		delete Puntos[i];
	}
	Puntos->Clear();
}

double DataReader::getAngle(int channel)
{
	switch (channel % 16)
	{
	case 0: return -15;
	case 1: return 1;
	case 2: return -13;
	case 3: return 3;
	case 4: return -11;
	case 5: return 5;
	case 6: return -9;
	case 7: return 7;
	case 8: return -7;
	case 9: return 9;
	case 10: return -5;
	case 11: return 11;
	case 12: return -3;
	case 13: return 13;
	case 14: return -1;
	case 15: return 15;
	}
	return -99;
}
bool DataReader::timeToSplit(int azimuth_index, cli::array<Double>^ azimuths) {
	if ((azimuth_index > 0) && (azimuths[azimuth_index] < azimuths[azimuth_index - 1]))
		return true;
	else if ((azimuth_index == 0) && (azimuths[azimuth_index + 1] < azimuths[azimuth_index]))
		return true;
	return false;
}


