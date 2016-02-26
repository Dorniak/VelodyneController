#include "Punto3D.h"
#define PI 3.14159265
#pragma region Constructors
//Copy constructor
Punto3D::Punto3D(const Punto3D %copy)
{
	Distance = copy.Distance;
	Obstacle = copy.Obstacle;
	Intensity = copy.Intensity;
	Azimuth = copy.Azimuth;
	Angle = copy.Angle;
	x = copy.x;
	y = copy.y;
	z = copy.z;
}

/// <summary>
/// Initializes a new instance of the <see cref="Punto3D"/> class.
/// </summary>
/// <param name="d">The distance.</param>
/// <param name="i">The intensity.</param>
/// <param name="r">The horizontal angle.</param>
/// <param name="a">The vertical angle.</param>
Punto3D::Punto3D(double d, double i, double r, double a) {
	Distance = d;
	Intensity = i;
	Azimuth = r;
	Angle = a;
}
Punto3D::Punto3D(double xx, double yy, double zz)
{
	x = xx;
	y = yy;
	z = zz;
	Distance = -1;
	Intensity = -1;
	Azimuth = -1;
	Angle = -1;
}
/// <summary>
/// Initializes a new instance of the <see cref="Punto3D"/> class.
/// </summary>
Punto3D::Punto3D() {
	Distance = -1;
	Intensity = -1;
	Azimuth = -1;
	Angle = -1;
	x = 0;
	y = 0;
	z = 0;
}

#pragma endregion

#pragma region Setters Implementations

/// <summary>
/// Sets the obstacle which contains the point.
/// </summary>
/// <param name="Obs">The number of the obstacle which contains the point.</param>
void Punto3D::setObstacle(int Obs)
{
	Obstacle = Obs;
}
/// <summary>
/// Sets the coordinates x.
/// </summary>
/// <param name="cx">The x coordinate.</param>
void Punto3D::setCoordinatesX(double cx) {
	x = cx;
}
/// <summary>
/// Sets the coordinates y.
/// </summary>
/// <param name="cy">The y coordinate.</param>
void Punto3D::setCoordinatesY(double cy) {
	y = cy;
}
/// <summary>
/// Sets the coordinates z.
/// </summary>
/// <param name="cz">The z coordinate.</param>
void Punto3D::setCoordinatesZ(double cz) {
	z = cz;
}
/// <summary>
/// Sets the distance.
/// </summary>
/// <param name="d">The distance.</param>
void Punto3D::setDistance(double d) {
	Distance = d;
}
/// <summary>
/// Sets the intensity.
/// </summary>
/// <param name="i">The intensity.</param>
void Punto3D::setIntensity(double i) {
	Intensity = i;
}
/// <summary>
/// Sets the azimuth.
/// </summary>
/// <param name="r">The horizontal angle.</param>
void Punto3D::setAzimuth(double r) {
	Azimuth = r;
}
/// <summary>
/// Sets the vertical angle.
/// </summary>
/// <param name="channel">The channel.</param>
void Punto3D::setAngle(int channel)
{
	switch (channel)
	{
	case 0: Angle = -15; break;
	case 1: Angle = 1; break;
	case 2: Angle = -13; break;
	case 3: Angle = 3; break;
	case 4: Angle = -11; break;
	case 5: Angle = 5; break;
	case 6: Angle = -9; break;
	case 7: Angle = 7; break;
	case 8: Angle = -7; break;
	case 9: Angle = 9; break;
	case 10: Angle = -5; break;
	case 11: Angle = 11; break;
	case 12: Angle = -3; break;
	case 13: Angle = 13; break;
	case 14: Angle = -1; break;
	case 15: Angle = 15; break;
	}
}

#pragma endregion

#pragma region Getters Implementation

/// <summary>
/// Gets the obstacle who contains the point.
/// </summary>
/// <returns></returns>
int Punto3D::getObstacle()
{
	return Obstacle;
}
/// <summary>
/// Gets the coordinates x.
/// </summary>
/// <returns></returns>
double Punto3D::getCoordinatesX() {
	return x;
}
/// <summary>
/// Gets the coordinates y.
/// </summary>
/// <returns></returns>
double Punto3D::getCoordinatesY() {
	return y;
}
/// <summary>
/// Gets the coordinates z.
/// </summary>
/// <returns></returns>
double Punto3D::getCoordinatesZ() {
	return z;
}
/// <summary>
/// Gets the distance.
/// </summary>
/// <returns></returns>
double Punto3D::getDistance() {
	return Distance;
}
/// <summary>
/// Gets the intensity.
/// </summary>
/// <returns></returns>
double Punto3D::getIntensity() {
	return Intensity;
}
/// <summary>
/// Gets the azimuth.
/// </summary>
/// <returns></returns>
double Punto3D::getAzimuth() {
	return Azimuth;
}
/// <summary>
/// Gets the angle.
/// </summary>
/// <returns></returns>
double Punto3D::getAngle()
{
	return Angle;
}
/// <summary>
/// Gets the module of the point.
/// </summary>
/// <returns></returns>
double Punto3D::getModule()
{
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

#pragma endregion

#pragma region Others Functions

String^ Punto3D::visualize()
{
	return "X: " + x + "\t Y: " + y + "\t Z: " + z;
}

/// <summary>
/// Calculates the coordinates.
/// </summary>
void Punto3D::CalculateCoordinates(double xx, double yy, double zz, double pitch, double roll, double yaw)
{
	if (pitch + roll + yaw != 0) {
		pitch *= PI / 180.0;
		roll *= PI / 180.0;
		yaw *= PI / 180.0;

		double tx = (Distance * cos(Angle * PI / 180.0) * sin(Azimuth * PI / 180.0));
		double ty = (Distance * cos(Angle * PI / 180.0) * cos(Azimuth * PI / 180.0));
		double tz = (Distance * sin(Angle * PI / 180.0));

		x = (((cos(pitch)*cos(yaw))*tx) + ((cos(pitch)*sin(yaw))*ty) + ((-sin(pitch))*tz)) + xx;
		y = ((((sin(roll)*sin(pitch)*cos(yaw)) - (cos(pitch)*cos(roll)*sin(yaw)))*tx) + (((cos(pitch)*cos(roll)*cos(yaw)) + (sin(roll)*sin(pitch)*sin(yaw)))*ty) + ((sin(roll)*cos(pitch))*tz)) + yy;
		z = ((((cos(pitch)*cos(roll)*sin(pitch)*cos(yaw)) + (sin(roll)*sin(yaw)))*tx) + (((cos(pitch)*cos(roll)*sin(pitch)*sin(yaw)) - (sin(roll)*cos(yaw)))*ty) + ((cos(pitch)*cos(roll)*cos(pitch))*tz)) + zz;
	}
	else {
		x = (Distance * cos(Angle * PI / 180.0) * sin(Azimuth * PI / 180.0)) + xx;
		y = (Distance * cos(Angle * PI / 180.0) * cos(Azimuth * PI / 180.0)) + yy;
		z = (Distance * sin(Angle * PI / 180.0)) + zz;
	}
}

/// <summary>
/// Distances between points.
/// </summary>
/// <param name="p">The p.</param>
/// <returns></returns>
double Punto3D::distanceToPoint(Punto3D^ p)
{
	return (p - this)->getModule();
}
#pragma endregion

#pragma region Operators

Punto3D^ Punto3D::operator+(Punto3D^ v)
{
	Punto3D^ result ;

	result->x = x + v->x;
	result->y = y + v->y;
	result->z = z + v->z;

	return result;
}
Punto3D^ Punto3D::operator*(double d)
{
	Punto3D^ result ;

	result->x = x * d;
	result->y = y * d;
	result->z = z * d;

	return result;
}
Punto3D^ Punto3D::operator-(Punto3D^ v)
{
	Punto3D^ result;

	result->x = x - v->x;
	result->y = y - v->y;
	result->z = z - v->z;

	return result;
}
Punto3D^ Punto3D::operator=(Punto3D^ v)
{
	Punto3D^ result;

	result->x = v->x;
	result->y = v->y;
	result->z = v->z;
	result->Angle = v->Angle;
	result->Azimuth = v->Azimuth;
	result->Distance = v->Distance;

	return result;
}
#pragma endregion