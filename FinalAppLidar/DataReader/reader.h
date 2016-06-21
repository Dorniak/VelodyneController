#pragma once
#pragma warning( disable : 4244 ) //Life is not perfect
#include "../Punto3D/Punto3D.h"
#include <cliext/vector>
#include "../OpenGl/OpenGl.h"
#include "../Parametros/Parametros.h"
#include "../Logger/Logger.h"
ref class DataReader
{

public:
	/// <summary>
	/// Constructor de la clase DataReader.Creación del Thread e inicialización de los parametros necesarios.
	/// </summary>
	/// <param name="puntosController">Lista de puntos donde se guardaran los datos leidos.</param>
	/// <param name="ParamReader">Array de parámetros propios desde la capa controladora.</param>
	/// <param name="Flags">Array de flags del sistema.</param>
	/// <param name="Threads">Array de Threads de la capa controladora.</param>
	/// <param name="Dibujador_in">Objeto OpenGl para la representación.</param>
	/// <param name="gps_in">Array de datos del objeto Gps</param>
	DataReader(List<Punto3D^>^ puntosController, cli::array<Object^>^ ParamReader, cli::array<bool>^ Flags, cli::array<Thread^>^ Threads, OpenGl^ Dibujador_in, cli::array<Object^>^ gps_in,Logger^ lg);
	
	/// <summary>
	/// Destructor de la clase DataReader.
	/// </summary>
	~DataReader();

	/// <summary>
	/// Función de lectura de datos por la red.
	///Lee el stream de bytes del LIDAR y obtiene las propiedades del punto retornadas, así como se calculan aquellas
	/// que pueden inducirse de estas primeras. Con esta inforación se construye y almacena el punto, cada paquete consta de 1206 bytes
	/// Esta información se guarda en la lista <see cref="puntosController"/> y al finalizar la vuelta son enviados a la capa controladora 
	/// para su uso en el análisis y la representación.
	/// </summary>
	void Read();

	/// <summary>
	/// Llama a Thread->Abort() para finalizar el hilo de ejecución.
	/// </summary>
	void Kill();

	/// <summary>
	/// Devuelve el ángulo en grados, correspondiente al canal de disparo.
	/// </summary>
	/// <param name="channel">Canal de disparo</param>
	/// <returns>Ángulo en grados correspondiente al canal.</returns>
	double getAngle(int channel);

	/// <summary>
	/// Extrae y calcula los ángulos intermedios que no son proporcionados por el laser. Para ello se le pasa como parámetro el área de datos del paquete recibido. De este área 
	/// de datos se accede a las posiciones con información sobre el ángulo horizontal de disparo. Se obtienen 12 azimuths correspondientes al primer disparo de cada fase.
	/// El resto de azimuths se obtiene por interpolación, consiguiendo los 348 azimuths. En el calculo se tiene en cuenta la frecuencia de giro y tiempo del disparo.
	/// La función devuelve un array con los 384 azimuths.
	/// </summary>
	/// <param name="ReceiveBytes">Área  de datos del paquete recibido.</param>
	/// <param name="corte">Variable para indicar si el princio de vuelta se da entre dos paquetes.</param>
	/// <param name="azi">último azimuth de la vueta anterior.</param>
	/// <returns>Array de azimuths.</returns>
	cli::array<Double>^ InterpolateAzimuth(cli::array<Byte>^& ReceiveBytes, bool *corte, double *azi);

	/// <summary>
	/// Extrae las distancias pertinentes a cada punto. Se recorre el área de datos del paquete en busca de la información de distancias.
	/// </summary>
	/// <param name="ReceiveBytes">Área  de datos del paquete recibido.</param>
	/// <returns>Array de distancias.</returns>
	cli::array<Double>^ ExtractDistances(cli::array<Byte>^& ReceiveBytes);

	/// <summary>
	/// Extrae la intensidad de rebote del haz laser.Se recorre el área de datos del paquete en busca de la información de intensidad.
	/// </summary>
	/// <param name="ReceiveBytes">Área  de datos del paquete recibido.</param>
	/// <returns>Array de intensidades.</returns>
	cli::array<Double>^ ExtractIntensities(cli::array<Byte>^& ReceiveBytes);

private:
	/// <summary>
	/// Variable para contabilizar el número de vueltas.
	/// </summary>
	long frame;

	/// <summary>
	/// Variable para guardar el puntero de acceso al objeto dibujador.
	/// </summary>
	OpenGl^ Dibujador;


	/// <summary>
	/// Objeto para el logeo de datos
	/// </summary>
	Logger^ log;

	/// <summary>
	/// Array de parámetros propio de la clase. Se obtiene de la capa controladora.
	/// </summary>
	cli::array<Object^>^ ArrayDataReader;

	/// <summary>
	/// Array para guardar y obtener el estado de los threads. Se obtiene de la capa controladora.
	/// </summary>
	cli::array<Thread^>^ Threads;

	/// <summary>
	/// Array de flags de la clase controladora.
	/// </summary>
	cli::array<bool>^ Flags;

	/// <summary>
	/// Array  de parámetros de la clase Gps. Se utiliza para loguear la información de este. Se obtiene de la capa controladora.
	/// </summary>
	cli::array<Object^>^ ArrayGps;

	/// <summary>
	/// Lista donde se guardan los puntos para mandarlos a la capa controladora y que las demás clases puedan haceder a el. Se obtiene de la capa controladora.
	/// </summary>
	List<Punto3D^>^ puntosController;

	/// <summary>
	/// Variables necesarias para la calibración de las coordenadas del laser.
	/// </summary>
	double CALIBRATE_X, CALIBRATE_Y, CALIBRATE_Z, CALIBRATE_R, CALIBRATE_P, CALIBRATE_W, max, min, recorrido_disparo, recorrido_recarga;

	/// <summary>
	/// Lista interna para guardar los puntos. Esta lista es la que se copia a <see cref="puntosController"/>.
	/// </summary>
	List<Punto3D^>^ Puntos;

	/// <summary>
	/// Cliente para la lectura de datos por UDP.
	/// </summary>
	UdpClient^ ClientLIDAR;

	/// <summary>
	/// Variable que almacena los datos necesarios para que <see cref="ClientLIDAR"/> pueda leer.
	/// </summary>
	IPEndPoint^ LaserIpEndPoint;

	/// <summary>
	/// Variable interna para la creación del thread.
	/// </summary>
	Thread^ thread_reader;

	/// <summary>
	/// Copia el contenido de <see cref="Puntos"/> a <see cref="puntosController"/> para subirlo a la capa controladora.
 	/// </summary>
	void copiarPuntos();

	bool timeToSplit(int azimuth_index, cli::array<Double>^ azimuths);

	/// <summary>
	/// Función de entrada y pausa del thread. Se queda a  la espera de la activación del flag de lectura.
	/// </summary>
	void Esperar();

	/// <summary>
	/// Para el debug.
	/// </summary>
	/// <param name="Entrada">String a sacar por pantalla.</param>
	void Informar(String^ Entrada);

	/// <summary>
	/// Calibra la posición del laser.
	/// </summary>
	void calibrate();
};

