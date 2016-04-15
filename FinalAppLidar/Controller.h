#pragma once
#include "reader.h"
#include "DataAnalisys.h"
#include "OpenGl.h"
#include "stdlib.h"
#include "Gps.h"

ref class Controller {
public:
	
	String^ Informe;
	//Constructor
	Controller();
	Controller(System::Windows::Forms::TextBox^  Consola);
	//Lista de Obstaculos
	List<Obstaculo^>^ Obstaculos;
	//Lista de puntos
	List<Punto3D^>^ Puntos;
	//Lista de conclusiones
	List<int>^ Conclusiones;
	//Array de flags que sincroniza los threads
	cli::array<bool>^ Flags;
	//Conjunto de parametros que necesita el DataAnalisys en tiempo de ejecucion
	cli::array<Object^>^ ArrayDataAnalisys;
	cli::array<Object^>^ ArrayDataReader;
	cli::array<Object^>^ ArrayGps;
	//Pone el flag de conclusion a 1 para que la aplicacion que lo recoja sepa que las conclusiones estan listas
	void setFlagTratamiento();
	//Array de threads para apagarlos y encenderlos
	cli::array<Thread^>^ Threads = gcnew cli::array<Thread^>(3); 
	//Thread de interpretar conclusiones
	void ThreadInterpretarConclusiones();
	//Consola
	System::Windows::Forms::TextBox^  Consola;
	void EscribirInforme();
private:
	Thread^ thread_Conclusiones;
	//Objeto DataAnalisys
	DataAnalisys^ Analisys;
	//Objeto OpenGl
	//Objeto DataReader
	//Funcion final de la que se sacan las conclusiones del vehiculo
	void interpretarConclusiones();
	//Funcion que inicia cada objeto con todos los parametros necesarios
};