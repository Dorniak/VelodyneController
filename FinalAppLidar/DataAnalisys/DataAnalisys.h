#pragma once
#include "../Obstaculo/Obstaculo.h"
#include <math.h>
#include "../OpenGl/OpenGl.h"
#include <timeApi.h>
#include "../Parametros/Parametros.h"

ref class DataAnalisys {
public:
	DataAnalisys(List<Punto3D^>^ puntosController, List<Obstaculo^>^ ObstaculosController, cli::array<Object^>^ ParamAnalisys, List<int>^ Conclusiones, cli::array<bool>^ Flags, cli::array<Thread^>^ Threads, OpenGl^ Dibujador);
	void AnalisysThread();
	void Esperar();

private:
	Punto3D zero;
	Punto3D uno;
	int NUMERO_COLUMNAS;
	int numCercanos;
	int localizador;
	int Obstmenor;
	int cambios;
	int indice;
	int menor;
	double apertura;
	double  consigna_velocidad;
	double  consigna_volante;
	double VCOCHE;
	bool iguales;
	double resolutionH;
	double resolutionV;
	double tolerancia;
	String^* Informe;
	OpenGl^ Dibujador;
	cli::array<Object^>^ parametros;
	cli::array<Thread^>^ Threads;
	cli::array<bool>^ Flags;
	cli::array<bool>^ Cercanos;
	cli::array<Punto3D^>^ PCercanos;
	List<int>^ Conclusiones;
	List<Obstaculo^>^ Obstaculos;
	List<Obstaculo^>^ ObstaculosvAnt;
	List<Punto3D^>^ matriz;
	List<Punto3D^>^ matriz_pointer;
	void Segmentacion(List<Punto3D^>^ matrix, double apertura);
	void Informar(String^ Entrada);
	void ResetParametros();
	void copiarObstaculos();
	void prepararObstaculos();
	void EliminarObstaculos();
	void RelacionarObstaculos();
	void relacionarVel(int i, int j);
	void MoverObstaculo(int Obst1, int Obst2);
	void relacionarPos(int i, int j, int VelC, int Res);
	bool comprobarBloqueo(List<Punto3D^>^ matriz);
	bool puntosCercanosV(Punto3D ^ p1, Punto3D ^ p2);
	bool puntosCercanosD(Punto3D ^ p1, Punto3D ^ p2);
	bool puntosCercanosH(Punto3D^ p1, Punto3D^ p2);
	int convaPos(int columna, int fila);
	Thread^ thread_analysis;
	
};