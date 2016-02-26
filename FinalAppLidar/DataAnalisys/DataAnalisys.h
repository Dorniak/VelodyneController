#pragma once
#include "Obstaculo.h"
#include <math.h>
#include "OpenGl.h"
//#include <timeApi.h>

//#include <cliext/vector> para clases referenciadas
#define NUMERO_FILAS 16 //Coincide con el numero de canales
#define TAMAÑO_MINIMO_OBSTACULO 20
#define TIEMPO_MARGEN 0.3 //TODO: Ajustar parametro
#define DISTANCIA_MAXIMA 2
#define PI 3.14159265

//Vector de flags
#define FlagTratamiento 0
#define FlagTratamiento 1
#define FlagTratamiento 2
#define FlagTratamiento 3
#define FlagWarning 4
#define FlagPausa 5
#define FlagAnalisysOn 6
#define FlagOpenGlOn 7
#define FlagLogOn 8

//Vector Analisys

#define posResolucion 0
#define posApertura 1
#define posVcoche 2

using namespace std;
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Threading;
//using namespace cliext;
ref class DataAnalisys {
public:
	//Constructor
	DataAnalisys();
	//Funcion que arranca el thread de analisis
	void Analisys(List<Punto3D^>^ puntosControl, List<Obstaculo^>^ ObstaculosControl, cli::array<double>^ ParamAnalisys,List<int>^ Conclusiones, cli::array<bool>^ Flags, cli::array<Thread^>^ Threads,OpenGl^ Dibujador);
	//Funcion de thread
	void AnalisysThread();
	//Funcion para abortar el thread
	void Kill();

private:
	OpenGl^ Dibujador;

	//Funcion que copia los obstaculos de la vuelta actual a la anterior y al control
	void copiarObstaculos();
	//Puntero al array de thread
	cli::array<Thread^>^ Threads;
	//Puntero al array de flags
	cli::array<bool>^ Flags;
	//Puntero a la lista de conclusiones
	List<int>^ Conclusiones;
	//array de parametros del DataAnalisys
	cli::array<double>^ parametros;
	//Valor de consigna de velocidad para el vector de conclusiones
	double  consigna_velocidad;
	//Valor de consigna de volante para el vector de conclusiones
	double  consigna_volante;
	
	double apertura;

	int indice;

	int menor;
	//Velocidad actual del coche
	double VCOCHE;

	double resolution;
	//numero de barridos que es variable por la configuracion del laser
	int NUMERO_COLUMNAS;
	//Lista de obstaculos obtenidos en el analisys de la vuelta actual
	List<Obstaculo^>^ Obstaculos = gcnew List<Obstaculo^>();
	//Lista de obstaculos de la vuelta anterior
	List<Obstaculo^>^ ObstaculosvAnt = gcnew List<Obstaculo^>();
	//Lista usada para ordenacion
	List<double>^ listMenor = gcnew List<double>();
	//Funcion encargada de agrupar puntos en obstaculos
	void Segmentacion(List<Punto3D^>^ matrix,double apertura);

	void prepararObstaculos();
	//Funcion encargada de eliminar obstaculos no validos
	void EliminarObstaculos();
	//Funcion encargada de relacionar los obstaculos obtenidos en la vuelta actual con los de la anterior
	void RelacionarObstaculos();
	//Funcion para relacionar los obstaculos por su velocidad
	void relacionarVel(int i, int j);
	//Funcion para relacionar los obstaculos por su posicion
	void relacionarPos(int i, int j, int VelC, int Res);
	//Funcion encargada de comprobar su existe un bloqueo frente al vehiculo
	bool comprobarBloqueo(List<Punto3D^>^ matriz);
	//Funcion que se encarga de decidir si dos puntos estan lo suficientemente cerca
	//para considerarse parte de un mismo obstaculo
	bool puntosCercanos(Punto3D^ p1, Punto3D^ p2);
	//COnvierte una coordenada en el plano en una posicion de la lista de puntos
	int convaPos(int a, int b);
	//LIsta en la que se guardan los puntos de esta vuelta
	List<Punto3D^>^ matriz;
	//Objeto thread del analisys
	Thread^ thread_analysis;
};