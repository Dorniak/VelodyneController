#pragma once
#include "reader.h"
#include "DataAnalisys.h"
#include "OpenGl.h"
#include "stdlib.h"

ref class Controller {
public:
	//Constructor
	Controller();
	//Lista de Obstaculos
	List<Obstaculo^>^ Obstaculos;
	//Lista de puntos
	List<Punto3D^>^ Puntos;
	//Lista de conclusiones
	List<int>^ Conclusiones;
	//Array de flags que sincroniza los threads
	cli::array<bool>^ Flags;
	//Conjunto de parametros que necesita el DataAnalisys en tiempo de ejecucion
	cli::array<double>^ ArrayDataAnalisys;
	cli::array<Object^>^ ArrayDataReader;
	//Pone el flag de conclusion a 1 para que la aplicacion que lo recoja sepa que las conclusiones estan listas
	void setFlagTratamiento();
	void Iniciar();
	void reActivar();
	void Parar();
	//Funcion que le dice al OpenGl que los puntos estan listos para ser dibujados
	void DibujarPuntos();
	//Funcion que le dice al OpenGl que los obstaculos estan listos para ser dibujados
	void DibujarObstaculos();
	//Array de threads para apagarlos y encenderlos
	cli::array<Thread^>^ Threads = gcnew cli::array<Thread^>(3); 
	//Thread de interpretar conclusiones
	void ThreadInterpretarConclusiones();
private:
	Thread^ thread_Conclusiones;
	//Objeto DataAnalisys
	DataAnalisys^ Analisys;
	//Objeto OpenGl
	OpenGl^ Dibujador;
	//Objeto DataReader
 	DataReader^ Reader;
	//Funcion final de la que se sacan las conclusiones del vehiculo
	void interpretarConclusiones();
	//Funcion que inicia cada objeto con todos los parametros necesarios
	void IniciarThreads();
};