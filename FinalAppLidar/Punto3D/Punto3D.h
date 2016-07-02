#pragma once
#include <math.h>
using namespace System;
using namespace std;


ref class Punto3D
{

#pragma region Constructors Definitions
public:
	/// <summary>
	/// Inicializa una nueva instancia de la clase Punto. A partir de la distancia, intensidad, azimuth, ángulo y frame.
	/// Constructor por defecto para la lectura de datos. 
	/// </summary>
	/// <param name="d">La distancia.</param>
	/// <param name="i">La intensidad.</param>
	/// <param name="r">El ángulo horizontal.</param>
	/// <param name="a">El ángulo vertucal.</param>
	/// <param name="f">El frame al que pertenece</param>
	Punto3D(double d, double i, double r, double a, long f);

	/// <summary>
	/// Inicializa una nueva instancia de la clase Punto. A partir de las coordenadas.
	/// </summary>
	/// <param name="xx">Coordenada X</param>
	/// <param name="yy">Coordenada Y</param>
	/// <param name="zz">Coordenada Z</param>
	Punto3D(double xx, double yy, double zz);

	/// <summary>
	/// Inicializa una nueva instancia de la clase Punto. A partir del frame y el azimuth, Necesario para colocar los puntos no válidos.
	/// </summary>
	/// <param name="f"></param>
	/// <param name="a"></param>
	Punto3D(long f, double a);

	/// <summary>
	/// Constructor por defecto.
	/// </summary>
	Punto3D::Punto3D();

	/// <summary>
	/// Copy contstructor. Inicailiza un nuevo punto a partir de un puntero.
	/// </summary>
	/// <param name="copy"></param>
	Punto3D::Punto3D(const Punto3D %copy);
#pragma endregion

#pragma region  Setters Definitions
	/// <summary>
	/// Establece el obstaculo al que pertenece el punto.
	/// </summary>
	/// <param name="Obs">Número de obstaclo que contiene el punto.</param>
	void setObstacle(int Obs);

	/// <summary>
	/// Establece la coordenada X.
	/// </summary>
	/// <param name="cx">Coordenada X</param>
	void setCoordinatesX(double cx);

	/// <summary>
	/// Establece la coordenada Y.
	/// </summary>
	/// <param name="cy">Coordenada Y.</param>
	void setCoordinatesY(double cy);

	/// <summary>
	/// Establece la coordenada Z.
	/// </summary>
	/// <param name="cz">Coordenada Z.</param>
	void setCoordinatesZ(double cz);

	/// <summary>
	/// Establece la distancia.
	/// </summary>
	/// <param name="d">La distancia.</param>
	void setDistance(double d);

	/// <summary>
	/// Establece  la intensidad.
	/// </summary>
	/// <param name="i">La intensidad.</param>
	void setIntensity(double i);

	/// <summary>
	/// Establece el azimuth.
	/// </summary>
	/// <param name="r">El ángulo horizontal.</param>
	void setAzimuth(double r);

	/// <summary>
	/// Establece el ángulo vertical.
	/// </summary>
	/// <param name="channel">Canal de disparo.</param>
	void setAngle(int channel);
#pragma endregion

#pragma region Getters Definitions
	/// <summary>
	/// Obtiene el obstaculo que contiene el punto.
	/// </summary>
	/// <returns>Número de obstaculo</returns>
	int getObstacle();

	long getFrame();

	/// <summary>
	/// Obtiene la coordenada X.
	/// </summary>
	/// <returns>Coordenada X.</returns>
	double getCoordinatesX();

	/// <summary>
	/// Obtiene la coordenada Y.
	/// </summary>
	/// <returns>Coordenada Y.</returns>
	double getCoordinatesY();

	/// <summary>
	/// Obtiene la coordenada Z.
	/// </summary>
	/// <returns>Coordenada Z.</returns>
	double getCoordinatesZ();

	/// <summary>
	/// Obtiene la distancia.
	/// </summary>
	/// <returns>Distancia</returns>
	double getDistance();

	/// <summary>
	/// Obtiene la intensidad.
	/// </summary>
	/// <returns>Intensidad.</returns>
	double getIntensity();

	/// <summary>
	/// Obtiene el azimuth.
	/// </summary>
	/// <returns>Ángulo horizontal</returns>
	double getAzimuth();

	/// <summary>
	/// Obtiene el ángulo vertical.
	/// </summary>
	/// <returns>Ángulo vertical.</returns>
	double getAngle();

	/// <summary>
	/// Obtiene el módulo del punto.
	/// </summary>
	/// <returns>Módulo.</returns>
	double getModule();
#pragma endregion

#pragma region Others

	/// <summary>
	/// Distancia entre puntos.
	/// </summary>
	/// <param name="p">El punto.</param>
	/// <returns>Distancia entre ambos puntos.</returns>
	double distanceToPoint(Punto3D^ p);

	/// <summary>
	/// Calculala las coordenadas.
	/// </summary>
	void CalculateCoordinates(double xx, double yy, double zz, double pitch, double roll, double yaw);

	/// <summary>
	/// Función que devuelve los parámetros del puntoen formato de string.Para Logs.
	/// </summary>
	/// <returns>String con los parámetros del punto.</returns>
	String^ visualize();

	/// <summary>
	/// Operación de suma de puntos.
	/// </summary>
	/// <param name="v">Punto a sumar.</param>
	/// <returns>P1 + P2</returns>
	Punto3D^ operator+(Punto3D^ v);

	/// <summary>
	/// Operación de resta de puntos.
	/// </summary>
	/// <param name="v">Punto a restar</param>
	/// <returns>P1 - P2</returns>
	Punto3D^ operator-(Punto3D^ v);

	/// <summary>
	/// Operación de asignación de puntos.
	/// </summary>
	/// <param name="v">Punto a asignar</param>
	/// <returns>P1 = P2</returns>
	Punto3D^ operator=(Punto3D^ v);

	/// <summary>
	/// Operación de producto de puntos.
	/// </summary>
	/// <param name="d">Punto a multiplicar</param>
	/// <returns>P1 * P2</returns>
	Punto3D^ operator*(double d);
#pragma endregion

#pragma region  Propierties
private:

	/// <summary>
	/// Número de obstaculo al que pertenece.
	/// </summary>
	int Obstacle;

	/// <summary>
	/// Intensidad del punto.
	/// </summary>
	double Intensity;

	/// <summary>
	/// Distancia del punto.
	/// </summary>
	double Distance;

	/// <summary>
	/// Ángulo horizaontal del punto.
	/// </summary>
	double Azimuth;

	/// <summary>
	/// Ángulo vertical del punto.
	/// </summary>
	double Angle;

	/// <summary>
	/// Coordenada X.
	/// </summary>
	double x;

	/// <summary>
	/// Coordenada Y.
	/// </summary>
	double y;

	/// <summary>
	/// Coordenada Z.
	/// </summary>
	double z;

	/// <summary>
	/// Frame al que pertenece el punto.
	/// </summary>
	long frame;

public:

	/// <summary>
	/// Propiedad que indica si el punto es válido para el análisis.
	/// </summary>
	bool valido;
#pragma endregion
};
