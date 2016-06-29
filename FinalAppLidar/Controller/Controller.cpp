#include "Controller.h"
#include "../Parametros/Parametros.h"
Controller::Controller()
{
	InitFlags();
	InitArrays();
	InitObjects();
}
void Controller::InitArrays()
{
	ArrayDataAnalisys = gcnew cli::array<Object^>(SIZE_ARRAY_ANALISYS);
	ArrayDataReader = gcnew cli::array<Object^>(SIZE_ARRAY_READER);
	ArrayGps = gcnew cli::array<Object^>(SIZE_ARRAY_GPS);
	Threads = gcnew cli::array<Thread^>(NUMERO_THREADS);
	for (int i = 0; i < SIZE_ARRAY_ANALISYS - 1; i++)
	{
		ArrayDataAnalisys[i] = safe_cast<System::Object^>(0);
	}
}
void Controller::InitFlags()
{
	Flags = gcnew cli::array<bool>(SIZE_ARRAY_FLAGS);
	for (int a = 0; a < SIZE_ARRAY_FLAGS; a++) {
		Flags[a] = false;
	}
	Flags[FLAG_PAUSA] = true;
	Flags[FLAG_TRATAMIENTO] = true;
}
void Controller::InitObjects()
{
	Obstaculos = gcnew List<Obstaculo^>(NUMBER_OBSTACLES);
	Puntos = gcnew List<Punto3D^>(NUMBER_OF_POINTS);
	Conclusiones = gcnew List<double>();
	Conclusiones->Add(0);
	Conclusiones->Add(0);
}
//TODO: INPLEMENTAR LA INTERPRETACIÓN DE CONCLUSIONES.
