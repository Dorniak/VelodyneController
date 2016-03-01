#pragma once
#include <../../packages/nupengl.core.0.1.0.1/build/native/include/GL/freeglut.h>
#include <math.h>
#include <stdio.h>
#include "Punto3D.h"
#include "Obstaculo.h"
#include "Parametros.h"
ref class OpenGl {
public:
	void constructor();
	void modificarPuntos(List<Punto3D^>^ listEntradaPuntos);
	void modificarObstaculos(List<Obstaculo^>^ listEntradaObstaculos);
	void dibujar();
	static List<Punto3D^>^ puntos = gcnew List<Punto3D^>();
	static List<Punto3D^>^ obstaculos = gcnew List<Punto3D^>();
	static bool listo = false;
private:
	
	void threadconstructor();
	void iniciarPuntos();
	void iniciarObstaculos();
	void limpiarListas();
	
};