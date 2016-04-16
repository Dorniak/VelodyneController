#pragma once
//Posicion parametros array Flags
#define ARRAYFlags_SIZE 6

#define FlagTratamiento 0
#define FlagLogOn 1
#define FlagWarning 2
#define FlagPausa 3
#define FlagAnalisysOn 4
#define FlagOpenGlOn 5


//Numero de parametros de los arrays
#define numParametrosReader 11
#define numParametrosAnalisys 6
//Posicion parametros array Reader
#define Ppath 0
#define IP 1
#define PCALIBRATE_X 2
#define PCALIBRATE_Y 3
#define PCALIBRATE_Z 4
#define PCALIBRATE_R 5
#define PCALIBRATE_P 6
#define PCALIBRATE_W 7
#define Pmax 8
#define Pmin 9
#define INFORME 10


#define NUMBER_OF_BLOCKS 12
#define NUMBER_OF_CHANNELS 32


//Analisys puntos
#define ToleranciaVertical 10
#define ToleranciaDiagonal 10
#define ToleranciaHorizontal 10


//Posicion parametros array DataAnalisys
#define posResolucionH 0
#define posResolucionV 1
#define posApertura 2
#define posVcoche 3
#define posInforme 4
#define posTolerancia 5

//Constantes DataAnalisys
#define NUMERO_FILAS 16 //Coincide con el numero de canales
#define TAMAÑO_MINIMO_OBSTACULO 20
#define TIEMPO_MARGEN 0.3 //TODO: Ajustar parametro
#define DISTANCIA_MAXIMA 2
#define PI Math::PI

//Constantes OpenGl
#define NUM_OBSTACULOS 10

//Constantes GPS
#define GPS_SIZE 6
#define TIPO_TRAMA 0
#define TRAMA 1
#define START 2
#define COM 3
#define QUALITY 4
#define SATELITES 5
//THREADS
#define NUMERO_THREADS 4 
#define THREAD_READER 0
#define THREAD_ANALISIS 1
#define THREAD_OPENGL 2
#define THREAD_GPS 3 
//Includes para las clases Controller Reader DataAnalisys y OpenGl
using namespace std;
using namespace System;
using namespace System::Net;
using namespace System::Text;
using namespace System::Net::Sockets;
using namespace System::IO;
using namespace System::Text;
using namespace System::Threading;
using namespace System::Collections::Generic;



ref class Parametros {

};