#include "Controller.h"

Controller::Controller()
{
	Obstaculos = gcnew List<Obstaculo^>();
	Puntos = gcnew List<Punto3D^>();
	Conclusiones = gcnew List<int>();
	Flags = gcnew cli::array<bool>(ARRAYFlags_SIZE);
	for (int a = 0; a < ARRAYFlags_SIZE; a++) {
		Flags[a] = false;
	}
	Flags[FlagPausa] = true;
	ArrayDataAnalisys = gcnew cli::array<double>(numParametrosAnalisys);
	ArrayDataReader = gcnew cli::array<Object^>(numParametrosReader);
}
//Es el encargado de poner el flag de fin de tratamiento a 1 a la vez 
// que llama a la funcion de interpretar conclusiones
void Controller::setFlagTratamiento()
{
	Flags[FlagTratamiento]=1;
	interpretarConclusiones();
}

void Controller::interpretarConclusiones()
{
	if (!thread_Conclusiones) {
		thread_Conclusiones = gcnew Thread(gcnew ThreadStart(this, &Controller::ThreadInterpretarConclusiones));
	}
	thread_Conclusiones->Start();
	Threads[2] = thread_Conclusiones;
}

void Controller::Iniciar()
{
	if (Flags[FlagAnalisysOn]==true) {
		//Crear objeto DataAnalisys
		Analisys = gcnew DataAnalisys();
	}
	if (Flags[FlagOpenGlOn] == true) {
		//Crear objeto OpenGl
		Dibujador = gcnew OpenGl();
	}
	//Crear objeto DataReader
	Reader = gcnew DataReader((IPEndPoint^)ArrayDataReader[Ip]);
	IniciarThreads();
}

void Controller::IniciarThreads()
{
	Reader->ReadData(Puntos,ArrayDataReader, Flags, Threads, Dibujador);
	if (FlagAnalisysOn) {
		Analisys->Analisys(Puntos, Obstaculos, ArrayDataAnalisys, Conclusiones, Flags, Threads, Dibujador);
	}
}

void Controller::reActivar()
{
	Flags[FlagPausa] = false;
	Reader->ReadData(Puntos, ArrayDataReader, Flags, Threads, Dibujador);
	if (FlagAnalisysOn) {
		Analisys->Analisys(Puntos, Obstaculos, ArrayDataAnalisys, Conclusiones, Flags, Threads, Dibujador);
	}
}
void Controller::Parar()
{
	Flags[FlagPausa] = true;
}

void Controller::DibujarPuntos()
{
	Dibujador->modificarPuntos(Puntos);
}

void Controller::DibujarObstaculos()
{
	Dibujador->modificarObstaculos(Obstaculos);
}

void Controller::ThreadInterpretarConclusiones()
{
	while (true)
	{
		Sleep(50);
	}
}
