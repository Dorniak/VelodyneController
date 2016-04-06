#pragma once
#pragma warning( disable : 4244 ) //Life is not perfect
#include "Punto3D.h"
#include <cliext/vector>
#include "OpenGl.h"
#include "Parametros.h"

ref class DataReader
{

public:
	DataReader(IPEndPoint^ LaserIpEndPoint);
	~DataReader();

	void ReadData(List<Punto3D^>^ puntosController, cli::array<Object^>^ ParamReader, cli::array<bool>^ Flags, cli::array<Thread^>^ Threads, OpenGl^ Dibujador);
	void ReadData(List<Punto3D^>^ puntosController, cli::array<Object^>^ ParamReader, cli::array<bool>^ Flags, cli::array<Thread^>^ Threads);
	void ReadDataThread();
	void Kill();

	double getAngle(int channel);
	bool read;
	cli::array<Double>^ InterpolateAzimuth(cli::array<Byte>^& ReceiveBytes, int *corte, double *azi);
	cli::array<Double>^ ExtractDistances(cli::array<Byte>^& ReceiveBytes);
	cli::array<Double>^ ExtractIntensities(cli::array<Byte>^& ReceiveBytes);
	int frame;
	String^ path;


private:
	String^ Informe;
	OpenGl^ Dibujador;
	void copiarPuntos();

	//array de parametros del DataReader
	cli::array<Object^>^ ArrayDataReader;
	//Puntero al array de thread
	cli::array<Thread^>^ Threads ;
	//Puntero al array de flags
	cli::array<bool>^ Flags;
	//LIsta en la que se guardan los puntos
	List<Punto3D^>^ puntosController;



	bool log = true;
	List<Punto3D^>^ Puntos = gcnew List<Punto3D^>;

	/*Client for the UDP connection*/
	UdpClient^ ClientLIDAR;

	/*Client configuration object.Also here is save the info about client(LIDAR)*/
	IPEndPoint^ LaserIpEndPoint;
	Thread^ thread_reader;
	StreamWriter^ loger;
};

