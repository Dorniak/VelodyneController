#include "reader.h"
#include <time.h>
#define NUMBER_OF_BLOCKS 12
#define NUMBER_OF_CHANNELS 32

/// <summary>
/// Initializes a new instance of the <see cref="DataReader"/> class.
/// LaserIpEndPoint apunta a la dirección ip del laser (O a cualquier IP) escuchando solo al puerto 2368
/// ClientLIDAR es el sockect que se utiliza para la comunicación con el LIDAR.
/// </summary>
/// <param name="LIp">The Lidar IP.</param>
DataReader::DataReader(IPEndPoint^ LIp)//SerialPort^ p
{
	try
	{
		Threads = gcnew cli::array<Thread^>(3);
		LaserIpEndPoint = LIp;
		ClientLIDAR = gcnew UdpClient(LaserIpEndPoint);
		read = true;
	}
	catch (Exception^ e)
	{
		System::Windows::Forms::MessageBox::Show(e->ToString());
	}
}

/// <summary>
/// Finalizes an instance of the <see cref="DataReader"/> class.
/// </summary>
DataReader::~DataReader()
{
	delete ClientLIDAR;
	delete LaserIpEndPoint;
}

/// <summary>
/// Reads the stream data from the LIDAR.
/// <para>Función que lee el stream de bytes del LIDAR y obtiene las propiedades del punto retornadas, así como se calculan aquellas
/// que pueden inducirse de estas primeras. Con esta inforación se construye y almacena el punto Cada paquete consta de 1206 bytes
/// ClientLIDAR elimina la cabecera de 42 bytes </para>
/// </summary>

void DataReader::ReadData(List<Punto3D^>^ puntosController, cli::array<Object^>^ ParamReader, cli::array<bool>^ Flags, cli::array<Thread^>^ Threads, OpenGl^ Dibujador)
{
	try
	{
		this->Threads = Threads;
		this->Flags = Flags;
		ArrayDataReader = ParamReader;
		this->puntosController = puntosController;
		this->Dibujador = Dibujador;
		if (!thread_reader) {
			thread_reader = gcnew Thread(gcnew ThreadStart(this, &DataReader::ReadDataThread));
		}
		thread_reader->Start();
		this->Threads[0] = thread_reader;
	}
	catch (Exception^ e)
	{
		System::Windows::Forms::MessageBox::Show(e->ToString());
	}
}
void DataReader::ReadData(List<Punto3D^>^ puntosController, cli::array<Object^>^ ParamReader, cli::array<bool>^ Flags, cli::array<Thread^>^ Threads)
{
	try
	{
		this->Threads = Threads;
		this->Flags = Flags;
		ArrayDataReader = ParamReader;
		this->puntosController = puntosController;
		if (!thread_reader) {
			thread_reader = gcnew Thread(gcnew ThreadStart(this, &DataReader::ReadDataThread));
		}
		thread_reader->Start();
		this->Threads[0] = thread_reader;
	}
	catch (Exception^ e)
	{
				System::Windows::Forms::MessageBox::Show(e->ToString());
	}
}
void DataReader::ReadDataThread()
{
	if (Flags[FlagLogOn]) {
		path = (String^)ArrayDataReader[Ppath] + "\\" + DateTime::Now.ToString("dd - MMMM - yyyy - HH - mm - ss");
		Directory::CreateDirectory(path);
		frame = 0;
		loger = gcnew StreamWriter(path + "log.log", false, Encoding::ASCII, 4096);
		loger->AutoFlush = false;
		log = true;
	}
	else {
		log = false;
	}
	double CALIBRATE_X, CALIBRATE_Y, CALIBRATE_Z, CALIBRATE_R, CALIBRATE_P, CALIBRATE_W, max, min;
	CALIBRATE_X = (Double)ArrayDataReader[PCALIBRATE_X];
	CALIBRATE_Y = (Double)ArrayDataReader[PCALIBRATE_Y];
	CALIBRATE_Z = (Double)ArrayDataReader[PCALIBRATE_Z];
	CALIBRATE_R = (Double)ArrayDataReader[PCALIBRATE_R];
	CALIBRATE_P = (Double)ArrayDataReader[PCALIBRATE_P];
	CALIBRATE_W = (Double)ArrayDataReader[PCALIBRATE_W];
	max = (Double)ArrayDataReader[Pmax];
	min = (Double)ArrayDataReader[Pmin];
	int azimuth_index = 0, distance_index = 0, intensity_index = 0;
	cli::array<Byte>^ ReceiveBytes;
	cli::array<Double>^ azimuths;
	cli::array<Double>^ distances;
	cli::array<Double>^ intensities;
	Punto3D^ p;
	int corte = -1;
	double azi = -1;


	while (!Flags[FlagWarning] && !Flags[FlagPausa]) {
		try
		{
			ReceiveBytes = ClientLIDAR->Receive(LaserIpEndPoint);

			azimuths = InterpolateAzimuth(ReceiveBytes, &corte, &azi);
			distances = ExtractDistances(ReceiveBytes);
			intensities = ExtractIntensities(ReceiveBytes);

			for (int block = 0; block < 12; block++) {
				for (int i = 0; i < NUMBER_OF_CHANNELS; i++) {
					//Corte de vuelta
					//if ((azimuth_index > 0 && (azimuths[azimuth_index] < azimuths[azimuth_index - 1]))) {
					if (azimuth_index > 0 && (azimuths[azimuth_index] - azimuths[azimuth_index - 1]) < -1) {
							copiarPuntos();
							frame++;
					}
					else if (azimuth_index == 0 && (azimuths[azimuth_index + 1] - azimuths[azimuth_index]) < -1) {
							copiarPuntos();
							frame++;
						}
					
					if (distances[distance_index] >= min && distances[distance_index] <= max) {
						p = gcnew Punto3D(distances[distance_index], intensities[intensity_index], azimuths[azimuth_index], getAngle(i));
						p->CalculateCoordinates(CALIBRATE_X, CALIBRATE_Y, CALIBRATE_Z, CALIBRATE_P, CALIBRATE_R, CALIBRATE_Y);
						Puntos->Add(p);
						if (log) {
							//Azimuth, X, Y, Z, Distance;
							loger->WriteLine(frame + " " + p->visualize());
						}
					}
					distance_index++;
					intensity_index++;
					azimuth_index++;
				}
				if (log) {
					loger->Flush();
				}
			}
			azimuth_index = 0, distance_index = 0, intensity_index = 0;
		}//Try
		catch (Exception^ e)
		{
			Flags[FlagWarning] = true;
			System::Windows::Forms::MessageBox::Show(e->ToString());
		}

	}//while
}

void DataReader::Kill()
{
	thread_reader->Abort();
}

/// <summary>
/// Gets the process time.
/// </summary>
/// <returns>process_Time</returns>

/// <summary>
/// Saves the process time.
/// </summary>
/// <param name="time">The time.</param>

/// <summary>
/// Extract and interpolates the azimuths.
/// </summary>
/// <param name="ReceiveBytes">The receive bytes.</param>
/// <returns></returns>
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

/// <summary>
/// Extracts the distances.
/// </summary>
/// <param name="ReceiveBytes">The receive bytes.</param>
/// <returns></returns>
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

/// <summary>
/// Extracts the intensities.
/// </summary>
/// <param name="ReceiveBytes">The receive bytes.</param>
/// <returns></returns>
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

void DataReader::copiarPuntos()
{
	puntosController->Clear();
	Sleep(50);
	puntosController->AddRange(Puntos);
	
	if (Flags[FlagOpenGlOn]) {
		Dibujador->modificarPuntos(puntosController);
	}
	//Controller de colision
	if (Flags[FlagTratamiento] == 0 && Flags[FlagAnalisysOn]) {
		Flags[FlagWarning] = 1;
		//mensaje pantalla
	}
	Flags[FlagTratamiento] = 0;
	Puntos->Clear();
}

/// <summary>
/// Gets the angle.
/// </summary>
/// <param name="channel">The channel.</param>
/// <returns></returns>
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
