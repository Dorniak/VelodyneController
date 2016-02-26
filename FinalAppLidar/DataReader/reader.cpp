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
	LaserIpEndPoint = LIp;
	ClientLIDAR = gcnew UdpClient(LIp);
	read = true;
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
	this->Threads = Threads;
	this->Flags = Flags;
	ArrayDataReader = ParamReader;
	this->puntosController = puntosController;
	this->Dibujador = Dibujador;

	if (!thread_reader) {
		thread_reader = gcnew Thread(gcnew ThreadStart(this, &DataReader::ReadDataThread));
	}
	thread_reader->Start();
	Threads[0] = thread_Reader;
}
void DataReader::ReadDataThread()
{
	if (Flags[FlagLogOn]) {
		path = (String^)ArrayDataReader[0] + "\\" + DateTime::Now.ToString("dd - MMMM - yyyy - HH - mm - ss");
		Directory::CreateDirectory(path);
		frame = 0;
		loger = gcnew StreamWriter(path + "\\frame-" + frame + ".log", false, Encoding::ASCII, 4096);
		loger->AutoFlush = false;
		log = true;
	}
	else {
		log = false;
	}
	double CALIBRATE_X, CALIBRATE_Y, CALIBRATE_Z, CALIBRATE_R, CALIBRATE_P, CALIBRATE_W, max, min;
	CALIBRATE_X = Convert::ToDouble(ArrayDataReader[0]);
	CALIBRATE_Y = Convert::ToDouble(ArrayDataReader[1]);
	CALIBRATE_Z = Convert::ToDouble(ArrayDataReader[2]);
	CALIBRATE_R = Convert::ToDouble(ArrayDataReader[3]);
	CALIBRATE_P = Convert::ToDouble(ArrayDataReader[4]);
	CALIBRATE_Y = Convert::ToDouble(ArrayDataReader[5]);
	max = Convert::ToDouble(ArrayDataReader[11]);
	min = Convert::ToDouble(ArrayDataReader[12]);
	int azimuth_index = 0, distance_index = 0, intensity_index = 0;
	cli::array<Byte>^ ReceiveBytes;
	cli::array<Double>^ azimuths;
	cli::array<Double>^ distances;
	cli::array<Double>^ intensities;
	Punto3D^ p;
	int corte = -1;
	double dist, ang, az, azi = -1;


	while (Flags[FlagWarning] && !Flags[FlagPausa]) {
		try
		{
			ReceiveBytes = ClientLIDAR->Receive(LaserIpEndPoint);

			azimuths = InterpolateAzimuth(ReceiveBytes, &corte, &azi);
			distances = ExtractDistances(ReceiveBytes);
			intensities = ExtractIntensities(ReceiveBytes);

			for (int block = 0; block < 12; block++) {
				for (int i = 0; i < NUMBER_OF_CHANNELS; i++) {
					//	if (corte == azimuth_index) {
					if (azimuth_index > 0 && azimuths[azimuth_index] < azimuths[azimuth_index - 1]) {
						loger->Close();
						copiarPuntos();
						loger = gcnew StreamWriter(path + "\\frame-" + frame + ".log", false, Encoding::ASCII, 4096);
						corte = -1;
						frame++;
					}
					if (distances[distance_index] >= min && distances[distance_index] <= max) {
						dist = distances[distance_index];
						az = azimuths[azimuth_index];
						ang = getAngle(i);
						p = gcnew Punto3D(dist, intensities[intensity_index], az, ang);
						p->CalculateCoordinates(CALIBRATE_X, CALIBRATE_Y, CALIBRATE_Z, CALIBRATE_P, CALIBRATE_R, CALIBRATE_Y);
						Puntos->Add(p);
						if (log) {
							loger->WriteLine();
						}

					}
					distance_index++;
					intensity_index++;
					azimuth_index++;
				}
				loger->Flush();
			}
			azimuth_index = 0, distance_index = 0, intensity_index = 0;

		}//Try
		catch (Exception^ e)
		{
			Flags[FlagWarning] = true;
			//	System::Windows::Forms::MessageBox::Show(e->ToString());
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

	cli::array<Double>^ result = gcnew cli::array<Double>(384);
	cli::array<Double>^ azimuths = gcnew cli::array<Double>(12);
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

			if (result[j + (32 * k)] > 359.99) {
				result[j + (32 * k)] -= 359.99;

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
	Dibujador->modificarPuntos(puntosController);
	puntosController->Clear();
	puntosController->AddRange(Puntos);
	//Controller de colision
	if (Flags[FlagTratamiento] == 0) {
		Flags[FlagWarning] = 1;
		//mensaje pantalla
	}
	Flags[FlagTratamiento] = 0;
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
