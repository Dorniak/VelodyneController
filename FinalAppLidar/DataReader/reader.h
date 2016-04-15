#pragma once
#pragma warning( disable : 4244 ) //Life is not perfect
#include "Punto3D.h"
#include <cliext/vector>
#include "OpenGl.h"
#include "Parametros.h"

ref class DataReader
{

public:
	DataReader(List<Punto3D^>^ puntosController, cli::array<Object^>^ ParamReader, cli::array<bool>^ Flags, cli::array<Thread^>^ Threads, OpenGl^ Dibujador_in, cli::array<Object^>^ gps_in);
	~DataReader();
	void Read();
	void Kill();

	double getAngle(int channel);
	cli::array<Double>^ InterpolateAzimuth(cli::array<Byte>^& ReceiveBytes, int *corte, double *azi);
	cli::array<Double>^ ExtractDistances(cli::array<Byte>^& ReceiveBytes);
	cli::array<Double>^ ExtractIntensities(cli::array<Byte>^& ReceiveBytes);
	int frame;
	String^ path;


private:
	void Informar(String^ Entrada);
	OpenGl^ Dibujador;
	void copiarPuntos();
	void Esperar();
	//array de parametros del DataReader
	cli::array<Object^>^ ArrayDataReader;
	//Puntero al array de thread
	cli::array<Thread^>^ Threads;
	//Puntero al array de flags
	cli::array<bool>^ Flags;
	cli::array<Object^>^ ArrayGps;
	//LIsta en la que se guardan los puntos
	List<Punto3D^>^ puntosController;
	double CALIBRATE_X, CALIBRATE_Y, CALIBRATE_Z, CALIBRATE_R, CALIBRATE_P, CALIBRATE_W, max, min;
	int azimuth_index, distance_index, intensity_index;

	bool log = true;
	List<Punto3D^>^ Puntos = gcnew List<Punto3D^>;

	/*Client for the UDP connection*/
	UdpClient^ ClientLIDAR;

	/*Client configuration object.Also here is save the info about client(LIDAR)*/
	IPEndPoint^ LaserIpEndPoint;
	Thread^ thread_reader;
	StreamWriter^ loger;
};

