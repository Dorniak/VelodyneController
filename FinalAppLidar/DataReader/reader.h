#pragma once
#pragma once
#pragma warning( disable : 4244 ) //Life is not perfect
#include "Punto3D.h"
#include <cliext/vector>
#include "OpenGl.h"

//Vector de flags
#define FlagTratamiento 0
#define FlagLogOn 1
#define FlagWarning 2
#define FlagPausa 3
#define FlagAnalisysOn 4
#define FlagOpenGlOn 5


using namespace std;
using namespace System;
using namespace System::Net;
using namespace System::Text;
using namespace System::Net::Sockets;
using namespace System::IO;
using namespace System::Text;
using namespace System::Threading;

using namespace System::Collections::Generic;
ref class DataReader
{

public:
	DataReader(IPEndPoint^ LaserIpEndPoint);
	~DataReader();

	void ReadData(List<Punto3D^>^ puntosController, cli::array<Object^>^ ParamReader, cli::array<bool>^ Flags, cli::array<Thread^>^ Threads, OpenGl^ Dibujador);
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
	OpenGl^ Dibujador;
	void copiarPuntos();

	//array de parametros del DataReader
	cli::array<Object^>^ ArrayDataReader;
	//Puntero al array de thread
	cli::array<Thread^>^ Threads;
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
	//Objeto thread del Reader
	Thread^ thread_Reader;
};

