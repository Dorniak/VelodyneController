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
#define numParametrosReader 10
#define numParametrosAnalisys 10
//Posicion parametros array Reader
#define Ip 1
//Posicion parametros array DataAnalisys
#define posResolucion 0
#define posApertura 1
#define posVcoche 2
//Constantes DataAnalisys
#define NUMERO_FILAS 16 //Coincide con el numero de canales
#define TAMA�O_MINIMO_OBSTACULO 20
#define TIEMPO_MARGEN 0.3 //TODO: Ajustar parametro
#define DISTANCIA_MAXIMA 2
#define PI 3.14159265

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