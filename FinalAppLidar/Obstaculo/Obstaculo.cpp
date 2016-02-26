#include "Obstaculo.h"

#pragma region Constructor

Obstaculo::Obstaculo(const Obstaculo % copy)
{
	North = copy.North;
	South = copy.South;
	East = copy.East;
	West = copy.West;
	Center = copy.Center;
	Predice_Center = copy.Predice_Center;
	Direction = copy.Direction;
	Velocity = copy.Velocity;
	components = copy.components;
}

/// <summary>
/// Initializes a new instance of the <see cref="Obstaculo"/> class.
/// </summary>
Obstaculo::Obstaculo() {
	Velocity = 0;
	Center = gcnew Punto3D();
	North = gcnew Punto3D();
	South = gcnew Punto3D();
	East = gcnew Punto3D();
	West = gcnew Punto3D();
	Closer = gcnew Punto3D();
	Farthest = gcnew Punto3D();
	Center = gcnew Punto3D();
	components = gcnew List<Punto3D^>();
}

#pragma endregion

#pragma region Getters Implementation

/// <summary>
/// Gets the north.
/// </summary>
/// <returns></returns>
Punto3D^ Obstaculo::getNorth() {
	return North;
}
/// <summary>
/// Gets the south.
/// </summary>
/// <returns></returns>
Punto3D^ Obstaculo::getSouth() {
	return South;
}
/// <summary>
/// Gets the east.
/// </summary>
/// <returns></returns>
Punto3D^ Obstaculo::getEast() {
	return East;
}
/// <summary>
/// Gets the west.
/// </summary>
/// <returns></returns>
Punto3D^ Obstaculo::getWest() {
	return West;
}
/// <summary>
/// Gets the velocity.
/// </summary>
/// <returns></returns>
double Obstaculo::getVelocity()
{
	return Velocity;
}
/// <summary>
/// Gets the center of the obstacle.
/// </summary>
/// <returns></returns>
Punto3D^ Obstaculo::getCenter()
{
	return Center;
}
/// <summary>
/// Gets the predict center.
/// </summary>
/// <returns></returns>
Punto3D^ Obstaculo::getPrediceCenter()
{
	return Predice_Center;
}

#pragma endregion

#pragma region Setters Implementation

/// <summary>
/// Sets the direction of the obstacle.
/// </summary>
/// <param name="Previous_Position">The previous_ position.</param>
void Obstaculo::setDirection(Punto3D^ Previous_Position)
{
	Direction = Center - Previous_Position;
}
/// <summary>
/// Sets the velocity.
/// </summary>
/// <param name="Car_velocity">The car velocity.</param>
/// <param name="Frecuency">The frecuency of the LIDAR.</param>
void Obstaculo::setVelocity(double Car_velocity, double Frecuency)
{
	/*Punto3D^ velocity_vector = gcnew Punto3D();*/
	Punto3D^ velocity_vector;
	velocity_vector->setCoordinatesY(Car_velocity);

	Velocity = (Direction*Frecuency - velocity_vector)->getModule();//m/s
//TODO::Calcular el modulo del vector direccion y multiplicarlo por el tiempo de barrido v a vector, direccion - v, direciona modulo/fr
}
/// <summary>
/// Sets the north.
/// </summary>
/// <param name="p">The North.</param>
void Obstaculo::setNorth(Punto3D^ p) {
	North = p;
}
/// <summary>
/// Sets the south.
/// </summary>
/// <param name="p">The South.</param>
void Obstaculo::setSouth(Punto3D^ p) {
	South = p;
}
/// <summary>
/// Sets the east.
/// </summary>
/// <param name="p">The East.</param>
void Obstaculo::setEast(Punto3D^ p) {
	East = p;
}
/// <summary>
/// Sets the west.
/// </summary>
/// <param name="p">The West.</param>
void Obstaculo::setWest(Punto3D^ p) {
	West = p;
}

#pragma endregion

#pragma region Others

/// <summary>
/// Calculates the center of the obstacle.
/// </summary>
void  Obstaculo::calculateCenter()
{
	Center->setCoordinatesX((East->getCoordinatesX() + West->getCoordinatesX()) / 2);
	Center->setCoordinatesY((East->getCoordinatesY() + West->getCoordinatesY()) / 2);
	Center->setCoordinatesZ((North->getCoordinatesZ() + South->getCoordinatesZ()) / 2);
}
/// <summary>
/// Calculates the predict center of the obstacle.
/// </summary>
void  Obstaculo::calculatePrediceCenter()
{
	Predice_Center = Direction + Center;
}
/// <summary>
/// Calculates the time to collision.
/// </summary>
void Obstaculo::calculateTimeToCollision(double vel)
{
	Punto3D^ Morro_Coche = gcnew Punto3D(0, 0, 0);
	Punto3D^ Culo_Coche = gcnew Punto3D(0, 0, 0);
	Punto3D^ Morro_Obstaculo;
	Punto3D^ Culo_Obstaculo;
	Punto3D^ Zone_in;
	Punto3D^ Zone_out;
	double car_time_in, car_time_out, obs_time_in, obs_time_out;

	if (Center->getCoordinatesX() > 0) {
		Morro_Obstaculo = West;
		Culo_Obstaculo = East;
	}
	else {
		Morro_Obstaculo = East;
		Culo_Obstaculo = West;
	}
		
	car_time_in = (Zone_in - Morro_Coche)->getModule() / vel;
	car_time_out = (Zone_out - Culo_Coche)->getModule() / vel;
	obs_time_in = (Zone_in - Morro_Obstaculo)->getModule() / Velocity;
	obs_time_out = (Zone_out - Culo_Obstaculo)->getModule() / Velocity;
	//TODO::Calcular el TTC a partir de la velocidad del coche y del veector direccion del obstaculo
}

void Obstaculo::prepareObstacle()
{
	double x, y, z;
	double x2 = INT_MAX, x1 = INT_MIN, y2 = INT_MAX, y1 = INT_MIN, z2 = INT_MAX, z1 = INT_MIN;
	int n = -1, s = -1, e = -1, w = -1, cl = -1, f = -1;
	for (int i = 0; i < components->Count; i++)
	{
		x = components[i]->getCoordinatesX();
		y = components[i]->getCoordinatesY();
		z = components[i]->getCoordinatesZ();
		//Punto mas alto
		if (z > z1) {
			z1 = z;
			n = i;
		}
		//Punto mas bajo
		if (z < z2) {
			z2 = z;
			s = i;
		}
		//Punto mas a la derecha
		if (y > y1) {
			y1 = y;
			e = i;
		}
		//Punto mas a la izquierda
		if (y < y2) {
			y2 = y;
			w = i;
		}
		//Punto mas lejano
		if (x > x1) {
			x1 = x;
			f = i;
		}
		//Punto mas cercano
		if (x < x2) {
			x2 = x;
			cl = i;
		}
	}

	Center->setCoordinatesX((x1 + x2) / 2);
	Center->setCoordinatesY((y1 + y2) / 2);
	Center->setCoordinatesZ((z1 + z2) / 2);
	North = components[n];
	South = components[s];
	East = components[e];
	West = components[w];
	Farthest = components[f];
	Closer = components[cl];
}

#pragma endregion