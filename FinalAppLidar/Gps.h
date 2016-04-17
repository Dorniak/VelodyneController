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
	/// <param name="ArrayGps">Array de parámetros propios. Se obtiene de la capa controladora.</param>
	/// <param name="Threads_in">Array de Threads de la capa controladora.</param>
	Gps(cli::array<Object^>^ ArrayGps, cli::array<Thread^>^ Threads_in);

	/// <summary>
	/// Lee las tramas NMEA a través del puerto serie. Se Extrae la información sobre señal, satelites... 
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
	/// Array de parámetros internos.
	/// </summary>
	cli::array<Object^>^ parametros;

	/// <summary>
	/// Extra la información de la trama para sacar satélites  y calidad de la señal.
	/// </summary>
	/// <param name="data">Datos leídos por el puerto serie.</param>
	void Gps::ExtraerGGA(String^ data);
};

