#pragma once
#include "../Punto3D/Punto3D.h"
using namespace System::Text;
using namespace System::IO;
using namespace System;
using namespace System::Threading;
using namespace System::Collections::Generic;
ref class Logger
{
public:
	/// <summary>
	/// Constructor de la clase. Inicia los parámetros y el thread de log.
	/// </summary>
	Logger();

	/// <summary>
	/// Establece el directorio para el archivo.
	/// </summary>
	/// <param name="p">String que contiene el path.</param>
	void setPath(String^ p);

	/// <summary>
	/// Crea el directorio y inicializa el stream.
	/// </summary>
	void init();

	/// <summary>
	/// Intercambia los buffers.
	/// </summary>
	void swapBuffers();

	/// <summary>
	/// Escribe el buffer lleno a disco.
	/// </summary>
	void recordData();

	/// <summary>
	/// Añade la lista de puntos e información gps al buffer.
	/// </summary>
	/// <param name="pointlist">Lista de puntos.</param>
	/// <param name="gps_in">Trama GPS.</param>
	void addToBuffer(List<Punto3D^>^ pointlist,String^ gps_in);

	/// <summary>
	/// Cierra el stream.
	/// </summary>
	void close();

	void Esperar();

	void cleanBuffer();

	/// <summary>
	/// Para de guardar datos.
	/// </summary>
	void Stop();

	void kill();

private:
	/// <summary>
	/// Función principal del hilo. Espera a que el buffer se llene, lo intercambia y escribe a disco.
	/// </summary>
	void StartLoggin();

	/// <summary>
	/// Propiedad para controlar el estado del hilo.
	/// </summary>
	bool THREAD_ON;

	/// <summary>
	/// Propiedad que indica el buffer en uso. 0 -> Buffer 1    1 -> Buffer 2.
	/// </summary>
	bool buff;

	/// <summary>
	/// Lista de puntos que apunta al buffer en uso.
	/// </summary>
	List<Punto3D^>^ pts;

	/// <summary>
	/// Primer Buffer.
	/// </summary>
	List<Punto3D^>^ Buffer1;

	/// <summary>
	/// Segundo Buffer.
	/// </summary>
	List<Punto3D^>^ Buffer2;

	/// <summary>
	/// Objeto del hilo.
	/// </summary>
	Thread^ thread_logger;

	/// <summary>
	/// String que contiene el path al directorio de logging.
	/// </summary>
	String^ path;

	/// <summary>
	/// Generador de strings que aloja la memoria de forma dinámica. Por rendimiento.
	/// </summary>
//	StringBuilder^ sb;

	/// <summary>
	/// Stream para escribir a disco.
	/// </summary>
	FileStream^ fs; 
	BinaryWriter^ writer;
	/// <summary>
	/// String que contiene la trama GPS.
	/// </summary>
	String^ gps;

	bool kill_me;
};

