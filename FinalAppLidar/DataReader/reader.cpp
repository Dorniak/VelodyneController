#include "reader.h"
#include <locale.h>

DataReader::DataReader(List<Punto3D^>^ puntosController_in, cli::array<Object^>^ ParamReader_in, cli::array<bool>^ Flags_in, cli::array<Thread^>^ Threads_in, OpenGl^ Dibujador_in, cli::array<Object^>^ gps_in)
{
	try
	{
		this->Threads = Threads_in;
		this->Flags = Flags_in;
		ArrayDataReader = ParamReader_in;
		ArrayDataReader[INFORME] = "";
		ArrayGps = gps_in;
		this->puntosController = puntosController_in;
		this->Dibujador = Dibujador_in;
		if (!thread_reader) {
			thread_reader = gcnew Thread(gcnew ThreadStart(this, &DataReader::Esperar));
		}
		thread_reader->Start();
		this->Threads[THREAD_READER] = thread_reader;
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
	LaserIpEndPoint = (IPEndPoint^)ArrayDataReader[IP];
	ClientLIDAR = gcnew UdpClient(LaserIpEndPoint);
	Informar("Inicio");
	setlocale(LC_NUMERIC, "es_ES");
	if (Flags[FLAG_LOG]) {
		Informar("Log activo");
		path = (String^)ArrayDataReader[PATH_LOG] + "\\" + DateTime::Now.ToString("dd - MMMM - yyyy - HH - mm - ss");
		Directory::CreateDirectory(path);
		frame = 0;
		loger = gcnew StreamWriter(path + "\\log.log", false, Encoding::UTF8, 4096);
		loger->AutoFlush = false;
	}
	else {
		Informar("Log apagado");
	}
	Informar("Calibracion");
	CALIBRATE_X = Convert::ToDouble(ArrayDataReader[PCALIBRATE_X]);
	CALIBRATE_Y = Convert::ToDouble(ArrayDataReader[PCALIBRATE_Y]);
	CALIBRATE_Z = Convert::ToDouble(ArrayDataReader[PCALIBRATE_Z]);
	CALIBRATE_R = Convert::ToDouble(ArrayDataReader[PCALIBRATE_R]);
	CALIBRATE_P = Convert::ToDouble(ArrayDataReader[PCALIBRATE_P]);
	CALIBRATE_W = Convert::ToDouble(ArrayDataReader[PCALIBRATE_W]);
	max = Convert::ToDouble(ArrayDataReader[MAX_DISTANCE]);
	min = Convert::ToDouble(ArrayDataReader[MIN_DISTANCE]);
	azimuth_index = 0;
	distance_index = 0;
	intensity_index = 0;
	cli::array<Byte>^ ReceiveBytes;
	cli::array<Double>^ azimuths;
	cli::array<Double>^ distances;
	cli::array<Double>^ intensities;
	Punto3D^ p;
	int corte = -1;
	double azi = -1;
	long StartingTime = Stopwatch::GetTimestamp(); 
	long EndingTime;
	Stopwatch^ frecuency_clock = gcnew Stopwatch();
	Stopwatch^ process_clock = gcnew Stopwatch();
	frecuency_clock->Start();
	long ElapsedTime;
	double ElapsedSeconds; 
	ArrayDataReader[FRECUENCY_TIME] = 0;
	ArrayDataReader[PROCESS_TIME] = 0;
	while (!Flags[FLAG_WARNING] && !Flags[FLAG_PAUSA]) {
		try
		{
			Informar("Interior del while");
			ReceiveBytes = ClientLIDAR->Receive(LaserIpEndPoint);
			process_clock->Start();
			Informar("Puntos Recibidos");
			azimuths = InterpolateAzimuth(ReceiveBytes, &corte, &azi);
			distances = ExtractDistances(ReceiveBytes);
			intensities = ExtractIntensities(ReceiveBytes);
			Informar("Inicio de bloque");
			for (int block = 0; block < 12; block++) {
				for (int i = 0; i < NUMBER_OF_CHANNELS; i++) {
					//Corte de vuelta
					if (azimuth_index > 0 && (azimuths[azimuth_index] - azimuths[azimuth_index - 1]) < -2) {
						ArrayDataReader[FRECUENCY_TIME] = frecuency_clock->ElapsedMilliseconds;
						frecuency_clock->Restart();
						copiarPuntos();
						frame++;
					}
					else if (azimuth_index == 0 && (azimuths[azimuth_index + 1] - azimuths[azimuth_index]) < -2) {
						ArrayDataReader[FRECUENCY_TIME] = frecuency_clock->ElapsedMilliseconds;
						frecuency_clock->Restart();
						copiarPuntos();
						frame++;
					}
					if (distances[distance_index] >= min && distances[distance_index] <= max) {
						p = gcnew Punto3D(distances[distance_index], intensities[intensity_index], azimuths[azimuth_index], getAngle(i));
						p->CalculateCoordinates(CALIBRATE_X, CALIBRATE_Y, CALIBRATE_Z, CALIBRATE_P, CALIBRATE_R, CALIBRATE_Y);
						Puntos->Add(p);
						if (Flags[FLAG_LOG]) {
							//Azimuth, X, Y, Z, Distance;
							loger->WriteLine(frame + "," + p->visualize() + ArrayGps[TRAMA]->ToString());
						}
					}
					else {
						p = gcnew Punto3D();
						Puntos->Add(p);
					}
					distance_index++;
					intensity_index++;
					azimuth_index++;
				}
				if (Flags[FLAG_LOG]) {
					loger->Flush();
				}
			}
			azimuth_index = 0, distance_index = 0, intensity_index = 0;
		}
		catch (Exception^ e)
		{
			Flags[FLAG_WARNING] = true;
			System::Windows::Forms::MessageBox::Show(e->ToString());
		}
		ArrayDataReader[PROCESS_TIME] = process_clock->ElapsedMilliseconds;
		process_clock->Restart();
	}
	ClientLIDAR->Close();
	if (Flags[FLAG_LOG])
		loger->Close();
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
	Informar("ESTOY EN ESPERA");
	while (Flags[FLAG_WARNING] || Flags[FLAG_PAUSA]) {
	//	if (Flags[FLAG_WARNING])
	//		Kill();
		Sleep(250);
	}
	Read();
}

void DataReader::Kill()
{
	thread_reader->Abort();
}

cli::array<Double>^ DataReader::InterpolateAzimuth(cli::array<Byte>^ &ReceiveBytes, int *corte, double *azi) {

	if (ReceiveBytes->Length == 0)
		throw gcnew Exception("Recibiendo 0 bytes...");

	if (ReceiveBytes->Length != 1206)
		throw gcnew Exception("Paquete con formato extraño");

	cli::array<double>^ result = gcnew cli::array<double>(384);
	cli::array<double>^ azimuths = gcnew cli::array<double>(12);
	int byteIndex = 2;

	for (int i = 0; i < 12; i++)
	{
		azimuths[i] = (ReceiveBytes[byteIndex] + (ReceiveBytes[byteIndex + 1] << 8));
		azimuths[i] /= 100;
		byteIndex += 100;
	}
	if (*azi > azimuths[0]) {
		*corte = 0;
	}
	for (int k = 0; k < 12; k++) {
		for (int j = 0; j < 32; j++)
		{
			if (j < 16)
			{
				result[j + (32 * k)] = azimuths[k] + (j*0.0165887);
			}
			else {
				result[j + (32 * k)] = azimuths[k] + ((j*0.0165887) + 0.1326959);
			}

			if (result[j + (32 * k)] >= 360) {
				result[j + (32 * k)] -= 360;

				if (*corte == -1)
					*corte = (j + (32 * k));
			}
		}
		if (k < 11) {
			if (result[31 + (32 * k)] < result[(32 * (k + 1))]) {

				if (*corte == -1)
					*corte = 31 + (32 * k);
			}
		}
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

void DataReader::copiarPuntos()
{
	Informar("Copiar puntos");
	puntosController->Clear();
	puntosController->AddRange(Puntos);

	if (Flags[FLAG_OPENGL]) {
		Informar("OpenGl activo");
		if (puntosController->Count > 2000) {
			Dibujador->modificarPuntos(puntosController);
			Dibujador->listo = true;
		}
	}
	//Controller de colision
	if (!Flags[FLAG_TRATAMIENTO] && Flags[FLAG_ANALISYS]) {
		Informar("Warning");
		Flags[FLAG_WARNING] = true;
		//mensaje pantalla
	}
	Flags[FLAG_TRATAMIENTO] = false;
	Puntos->Clear();
}

double DataReader::getAngle(int channel)
{
	switch (channel)
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
}
