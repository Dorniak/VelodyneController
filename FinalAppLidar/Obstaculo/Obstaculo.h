#pragma once
#include "Punto3D.h"
#include <limits.h>

using namespace std;
using namespace System;
using namespace System::Collections::Generic;
ref class Obstaculo
{
public:
	Obstaculo::Obstaculo(const Obstaculo %copy);
#pragma region Constructors
	Obstaculo();
#pragma endregion

#pragma region Getters Definitions

	Punto3D^ getCenter();//Devuelve el centro del obstaculo
	Punto3D^ getPrediceCenter();//Devuelve el centro predicho del obstaculo
	Punto3D^ getNorth();
	Punto3D^ getSouth();
	Punto3D^ getEast();
	Punto3D^ getWest();
	double getVelocity();//Devuelve a la velocidad a la que va el obstaculo

#pragma endregion

#pragma region Setters Definitions

	void setNorth(Punto3D^ p);
	void setSouth(Punto3D^ p);
	void setEast(Punto3D^ p);
	void setWest(Punto3D^ p);
	void setDirection(Punto3D^ Previous_Position);//Pone la direccion al obstaculo
	void setVelocity(double Car_velocity, double Frecuency);//Pone la velocidad a partir del modulo del vector de direccion

#pragma endregion

#pragma region Others

	void calculateCenter();//Calcula el centro del obstaculo
	void calculatePrediceCenter();//Calcula el centro predicho a partir de la velocidad del coche y el vector de direccion
	void calculateTimeToCollision(double vel);//Calcula el tiempo de colision del obstaculo con el coche
	void prepareObstacle();
	List<Punto3D^>^ components;
#pragma endregion

private:

#pragma region Propieties

	Punto3D^ North;
	Punto3D^ South;
	Punto3D^ East;
	Punto3D^ West;
	Punto3D^ Closer;
	Punto3D^ Farthest;
	Punto3D^ Center;
	Punto3D^ Predice_Center;
	Punto3D^ Direction;
	double Velocity;

#pragma endregion
};