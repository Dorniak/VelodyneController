#pragma once
//##########################  FLAGS  ########################## 
#define SIZE_ARRAY_FLAGS 6

#define FLAG_TRATAMIENTO 0
#define FLAG_LOG 1
#define FLAG_WARNING 2
#define FLAG_PAUSA 3
#define FLAG_ANALISYS 4
#define FLAG_OPENGL 5

//##########################  READER  ########################## 
#define SIZE_ARRAY_READER 16

#define PATH_LOG 0
#define IP 1
#define PCALIBRATE_X 2
#define PCALIBRATE_Y 3
#define PCALIBRATE_Z 4
#define PCALIBRATE_R 5
#define PCALIBRATE_P 6
#define PCALIBRATE_W 7
#define MAX_DISTANCE 8
#define MIN_DISTANCE 9
#define INFORME 10
#define FRECUENCY_TIME 11
#define PROCESS_TIME 12
#define FRECUENCY 13
#define HAY 14
#define MAXIMO 15

#define NUMBER_OF_BLOCKS 12
#define NUMBER_OF_CHANNELS 32

//##########################  ANÁLISIS  ########################## 
#define SIZE_ARRAY_ANALISYS 6

#define HORIZONTAL_RESOLUTION 0
#define VERTICAL_RESOLUTION 1
#define OPENING 2
#define CAR_VELOCITY 3
#define INFORME_ANALISYS 4
#define TOLERANCE 5

#define ALTURA_MINIMA_OBST 0.2
#define VERTICAL_TOLERANCE 1200
#define DIAGONAL_TOLERANCE 500
#define HORIZONTAL_TOLERANCE 500
#define NUMERO_FILAS 16 //Coincide con el numero de canales
#define TAMAÑO_MINIMO_OBSTACULO 20
#define TIEMPO_MARGEN 0.3 //TODO: Ajustar parametro
#define DISTANCIA_MAXIMA 2
#define PI Math::PI

//##########################  OPENGL  ########################## 
#define NUMBER_OBSTACLES 250

//##########################  GPS  ########################## 
#define SIZE_ARRAY_GPS 8

#define TIPO_TRAMA 0
#define TRAMA 1
#define START 2
#define COM 3
#define QUALITY 4
#define SATELITES 5
#define RATE 6
#define ESTADO 7

//##########################  THREADS  ########################## 
#define NUMERO_THREADS 4 

#define THREAD_READER 0
#define THREAD_ANALISIS 1
#define THREAD_OPENGL 2
#define THREAD_GPS 3 

//##########################  LOGGER  ########################## 
#define SIZE_ARRAY_LOGGER 1
#define BUFFER 0

//##########################  CONTROLLER  ########################## 
#define NUMBER_OF_POINTS 15000

//Includes para las clases Controller Reader DataAnalisys y OpenGl
using namespace std;
using namespace System;
using namespace System::IO;
using namespace System::Net;
using namespace System::Text;
using namespace System::Threading;
using namespace System::Diagnostics;
using namespace System::Net::Sockets;
using namespace System::Collections::Generic;
