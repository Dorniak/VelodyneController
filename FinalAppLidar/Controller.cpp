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
	Flags[FlagTratamiento] = true;
	ArrayDataAnalisys = gcnew cli::array<Object^>(numParametrosAnalisys);
	ArrayDataReader = gcnew cli::array<Object^>(numParametrosReader);
	ArrayGps = gcnew cli::array<Object^>(GPS_SIZE);
	for (int i = 0; i < numParametrosAnalisys - 1; i++)
	{
		ArrayDataAnalisys[i] = 0;
	}

}
Controller::Controller(System::Windows::Forms::TextBox ^ Consola)
{
	this->Consola = Consola;
	Obstaculos = gcnew List<Obstaculo^>();
	Puntos = gcnew List<Punto3D^>();
	Conclusiones = gcnew List<int>();
	Flags = gcnew cli::array<bool>(ARRAYFlags_SIZE);
	for (int a = 0; a < ARRAYFlags_SIZE; a++) {
		Flags[a] = false;
	}
	Flags[FlagPausa] = true;
	Flags[FlagTratamiento] = true;
	ArrayDataAnalisys = gcnew cli::array<Object^>(numParametrosAnalisys);
	ArrayDataReader = gcnew cli::array<Object^>(numParametrosReader);
	ArrayGps = gcnew cli::array<Object^>(GPS_SIZE);
}
//Es el encargado de poner el flag de fin de tratamiento a 1 a la vez 
// que llama a la funcion de interpretar conclusiones
void Controller::setFlagTratamiento()
{
	Flags[FlagTratamiento] = 1;
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

void Controller::ThreadInterpretarConclusiones()
{
	while (true)
	{
		Sleep(50);
	}
}

void Controller::EscribirInforme()
{
	Consola->AppendText(Informe);
	Informe = "";
}