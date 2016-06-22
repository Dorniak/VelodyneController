#pragma once
#include "../DataReader/reader.h"
#include "../DataAnalisys/DataAnalisys.h"
#include "../OpenGl/OpenGl.h"
#include "stdlib.h"
#include "../Gps/Gps.h"
#include "../Logger/Logger.h"

ref class Controller {
public:
	
	/// <summary>
	/// Constructor de la clase Controller. Actúa como capa controladora del resto de componentes. Inicializa todos los componentes necesarios para la comunicación entre 
	/// clases.
	/// </summary>
	Controller();

	/// <summary>
	/// Lista  de obstáculos.
	/// </summary>
	List<Obstaculo^>^ Obstaculos;

	/// <summary>
	/// Lista de puntos.
	/// </summary>
	List<Punto3D^>^ Puntos;

	/// <summary>
	/// Array de flags del sistema.
	/// </summary>
	cli::array<bool>^ Flags;

	/// <summary>
	/// Array de parámetros de la clase <see cref="DataAnalisys"/>.
	/// </summary>
	cli::array<Object^>^ ArrayDataAnalisys;

	/// <summary>
	/// Array de parámetros de la clase <see cref="reader"/>.
	/// </summary>
	cli::array<Object^>^ ArrayDataReader;

	/// <summary>
	/// Array de parámetros de la clase <see cref="reader"/>.
	/// </summary>
	cli::array<Object^>^ ArrayLogger;

	/// <summary>
	/// Array de parámetros de la clase <see cref="Gps"/>.
	/// </summary>
	cli::array<Object^>^ ArrayGps;

	/// <summary>
	/// Array que contiene todos los threads.
	/// </summary>
	cli::array<Thread^>^ Threads;

	List<int>^ Conclusiones;

private:
	void InitArrays();
	void InitFlags();
	void InitObjects();
};