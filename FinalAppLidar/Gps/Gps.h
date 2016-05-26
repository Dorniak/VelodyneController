#pragma once
using namespace std;
using namespace System;
using namespace System::IO::Ports;
using namespace System::Threading;
using namespace System::Windows::Forms;
ref class Gps
{
public:
	/// <summary>
	/// Constructor de la clase Gps. Se inicializa el puerto serie y el thread.
	/// </summary>
	/// <param name="ArrayGps">Array de par�metros propios. Se obtiene de la capa controladora.</param>
	/// <param name="Threads_in">Array de Threads de la capa controladora.</param>
	Gps(cli::array<Object^>^ ArrayGps, cli::array<Thread^>^ Threads_in);

	/// <summary>
	/// Lee las tramas NMEA a trav�s del puerto serie. Se Extrae la informaci�n sobre se�al, satelites... 
	/// </summary>
	void Read();

	/// <summary>
	/// Entrada del Thread. Queda a la espera de la orden de activar lectura.
	/// </summary>
	void Gps::Esperar();

	/// <summary>
	/// Objeto SerialPort para la lectura del puerto serie.
	/// </summary>
	SerialPort^ serialPort;
private:
	/// <summary>
	/// Array de par�metros internos.
	/// </summary>
	cli::array<Object^>^ parametros;

	/// <summary>
	/// Extra la informaci�n de la trama para sacar sat�lites  y calidad de la se�al.
	/// </summary>
	/// <param name="data">Datos le�dos por el puerto serie.</param>
	void Gps::ExtraerGGA(String^ data);
};

