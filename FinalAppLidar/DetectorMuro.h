#pragma once
#include "Obstaculo/Obstaculo.h"
#include <math.h>
#include "Parametros/Parametros.h"
ref class DetectorMuro
{
public:
	DetectorMuro(List<Punto3D^>^ puntosController, List<Obstaculo^>^ ObstaculosController, List<double>^ Conclusiones, cli::array<bool>^ Flags);
	/// <summary>
	/// Numero de columnas de la vuelta actual considerando la lista de entrada como una matriz de 16 filas y n columnas
	/// </summary>
	int NUMERO_COLUMNAS;
	/// <summary>
	/// Lista de entrada de parametros que vienen de la interfaz
	/// </summary>
	cli::array<Object^>^ parametros;
	/// <summary>
	/// Array de threads necesario para guardar el identificador de thread creado y asi poder cerrarlo al finalizar la ejecución
	/// </summary>
	cli::array<Thread^>^ Threads;
	/// <summary>
	/// Array de flags que indican los servicios levantados
	/// </summary>
	cli::array<bool>^ Flags;
	/// <summary>
	/// Lista de conclusiones que se envia al controlador para que ejecute las medidas necesarias
	/// </summary>
	List<double>^ Conclusiones;
	/// <summary>
	/// Lista de obstaculos obtenidos de los puntos de la vuelta actual
	/// </summary>
	List<Obstaculo^>^ Obstaculos;
	/// <summary>
	/// Lista de obstaculos obtenidos de los puntos de la vuelta anterior
	/// </summary>
	List<Obstaculo^>^ ObstaculosvAnt;
	/// <summary>
	/// Matriz de puntos interna al DataAnalisys
	/// </summary>
	List<Punto3D^>^ matriz;
	/// <summary>
	/// Enlace a la matriz de puntos real localizada en el controlador
	/// </summary>
	List<Punto3D^>^ matriz_pointer;
	
	/// <summary>
	/// Objeto thread en el que se guarda el thread del DataAnalisys
	/// </summary>
	Thread^ thread_analysis;
	int xmin, xmax, ymin, ymax, zmin, zmax;

	void AnalisysThread();
	void Esperar();
	cli::array<Punto3D^, 2>^ Delaunay(List<Punto3D^>^);
	Punto3D^ calcula_normal_triangulo(Punto3D^ p1, Punto3D^ p2, Punto3D^ p3);
	cli::array<Obstaculo^>^ Clustering(List<Punto3D^>^ puntos,double eps, int minpts);
	cli::array<double>^ Regresion(Obstaculo^ muro);
	List<double>^ CalculaParametros(cli::array<double>^ p);
	double fzero(cli::array<double>^ prod);
	double eval2(cli::array<double>^ p,double y);
	double eval3(cli::array<double>^ p, double y);
	List<Punto3D^>^ vecinos(int punto, List<Punto3D^>^ puntos, cli::array<double, 2>^ D);
	Obstaculo^ ExpandCluster(int i, List<Punto3D^>^ vecinosp,cli::array<double, 2>^ D, cli::array<bool>^ visitados);
};

