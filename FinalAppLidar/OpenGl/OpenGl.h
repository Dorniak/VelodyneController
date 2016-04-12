#pragma once
#include <../../packages/nupengl.core.0.1.0.1/build/native/include/GL/freeglut.h>
#include <math.h>
#include <stdio.h>
#include "Punto3D.h"
#include "Obstaculo.h"
#include "Parametros.h"
ref class OpenGl {
public:
	void constructor(cli::array<Thread^>^ Threads,String^* Informe);
	void limpiarListas(int a);
	void modificarPuntos(List<Punto3D^>^ listEntradaPuntos);
	void modificarObstaculos(List<Obstaculo^>^ listEntradaObstaculos);
	static List<Punto3D^>^ puntos = gcnew List<Punto3D^>();
	static List<Punto3D^>^ obstaculos = gcnew List<Punto3D^>();
	static bool listo = false;
private:
	void Informar(String^ Entrada);
	String^* Informe;
	Thread^ ThreadDIO;
	cli::array<Thread^>^ Threads;
	void threadconstructor();
	void iniciarPuntos();
	void iniciarObstaculos();
	int puntosAnterior;
	
};