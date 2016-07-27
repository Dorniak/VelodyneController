#include "DetectorMuro.h"

//PARAMETROS DBSCAN
#define MIN_PTS 250
#define EPSILON 0.5


DetectorMuro::DetectorMuro(List<Punto3D^>^ puntosController, List<Obstaculo^>^ ObstaculosController, List<double>^ Conclusiones, cli::array<bool>^ Flags)
{
	try {
		xmax = 2;
		xmin = -2;
		ymax = 5;
		ymin = -5;
		zmax = 1;
		zmin = -1;
		this->Flags = Flags;
		this->Conclusiones = Conclusiones;
		matriz_pointer = puntosController;
		matriz = gcnew List<Punto3D^>(NUMBER_OF_POINTS);
		ObstaculosvAnt = ObstaculosController;
		Obstaculos = gcnew List<Obstaculo^>(NUMBER_OBSTACLES);
		if (!thread_analysis) {
			thread_analysis = gcnew Thread(gcnew ThreadStart(this, &DetectorMuro::Esperar));
		}
		thread_analysis->Start();
		//Guarda el identificador de thread en el array de threads del Controllerador 
	}
	catch (Exception^ e) {

	}
}

void DetectorMuro::AnalisysThread()
{
	List<Punto3D^>^ matriz_zona_interes = gcnew List<Punto3D^>(1000);
	while (Flags[FLAG_ANALISYS_MURO] && !Flags[FLAG_WARNING] && !Flags[FLAG_PAUSA])
	{
		try
		{
			if (!Flags[FLAG_TRATAMIENTO]) {
				matriz->AddRange(matriz_pointer);
				NUMERO_COLUMNAS = matriz->Count / NUMERO_FILAS;

				//SACAR ZONA DE INTERES
				int xx, yy, zz;
				for (int i = 0; i < matriz->Count; i++)
				{
					xx = matriz[i]->getCoordinatesX();
					yy = matriz[i]->getCoordinatesY();
					zz = matriz[i]->getCoordinatesZ();
					if (xx > xmax && xx<xmin)
						if (yy > ymax && yy < ymax)
							if (zz > zmax && zz < zmax)
								matriz_zona_interes->Add(matriz[i]);
				}
				cli::array<Punto3D^, 2>^ tri = Delaunay(matriz_zona_interes);
				int numero_triangulos = tri->Length;
				Punto3D^ normal;
				double angulo;
				List<Punto3D^>^ matriz_puntos_muro;
				for (int i = 0; i < numero_triangulos; i++)
				{
					normal = calcula_normal_triangulo(tri[i, 0], tri[i, 1], tri[i, 2]);
					angulo = acos(normal->getCoordinatesZ()*PI / 180);
					if (angulo >= 75 && angulo <= 90) {
						if (!matriz_puntos_muro->Contains(tri[i, 0]))
							matriz_puntos_muro->Add(tri[i, 0]);
						if (!matriz_puntos_muro->Contains(tri[i, 1]))
							matriz_puntos_muro->Add(tri[i, 1]);
						if (!matriz_puntos_muro->Contains(tri[i, 2]))
							matriz_puntos_muro->Add(tri[i, 2]);
					}
				}
				int numero_puntos_muro = matriz_puntos_muro->Count;
				cli::array<Obstaculo^>^ muros = Clustering(matriz_puntos_muro, 0.5, 200);
				Obstaculo^ muro;
				//MURO MAS GRANDE
				for (int i = 0; i < muros->Length; i++)
				{
					if (muros[i]->components->Count > muro->components->Count)
						muro = muros[i];
				}

				cli::array<double>^ p = Regresion(muro);
				Conclusiones = CalculaParametros(p);

				Flags[FLAG_TRATAMIENTO] = true;
				matriz->Clear();
			}
		}
		catch (Exception^ e)
		{
			Flags[FLAG_WARNING] = true;
		}
	}
	//En caso de que se desactive y se reactive despues hay que limpiar los objetos
	ObstaculosvAnt->Clear();
	Esperar();
}

void DetectorMuro::Esperar()
{
	while (Flags[FLAG_WARNING] || Flags[FLAG_PAUSA] || !Flags[FLAG_ANALISYS]) {
		Thread::Sleep(200);
	}
	AnalisysThread();
}

Punto3D^ DetectorMuro::calcula_normal_triangulo(Punto3D^ p1, Punto3D^ p2, Punto3D^ p3) {
	//VECTORES LADO TRAINGULO

	cli::array<double>^ AB = { (p2->getCoordinatesX() - p1->getCoordinatesX()),(p2->getCoordinatesY() - p1->getCoordinatesY()),(p2->getCoordinatesZ() - p1->getCoordinatesZ()) };
	cli::array<double>^ AC = { (p3->getCoordinatesX() - p1->getCoordinatesX()),(p3->getCoordinatesY() - p1->getCoordinatesY()),(p3->getCoordinatesZ() - p1->getCoordinatesZ()) };

	//CALCULO PARAMETROS
	double a, b, c, d;
	a = AB[1] * AC[2] - AB[2] * AC[1];
	b = -AB[0] * AC[2] - AB[2] * AC[0];
	c = AB[0] * AC[1] - AB[1] * AC[0];
	//d = -((a*p1->getCoordinatesX()) + (b*p1->getCoordinatesY()) + (c*p1->getCoordinatesZ()));

	//BARICENTRO

	//double x_bar, y_bar, z_bar;

	//x_bar = (p1->getCoordinatesX() + p2->getCoordinatesX() + p3->getCoordinatesX()) / 3;
	//y_bar = (p1->getCoordinatesY() + p2->getCoordinatesY() + p3->getCoordinatesY()) / 3;
	//z_bar = (p1->getCoordinatesZ() + p2->getCoordinatesZ() + p3->getCoordinatesZ()) / 3;

	//NORMALIZACION VECTOR
	a /= sqrt(pow(a, 2) + pow(b, 2) + pow(c, 2));
	b /= sqrt(pow(a, 2) + pow(b, 2) + pow(c, 2));
	c /= sqrt(pow(a, 2) + pow(b, 2) + pow(c, 2));
	Punto3D^ vector = gcnew Punto3D(a, b, c);
	//Punto3D^ baricentro = gcnew Punto3D(x_bar, y_bar, z_bar);
	return vector;
}

List<double>^ DetectorMuro::CalculaParametros(cli::array<double>^p) {

	cli::array<double>^ dp = { (2 * p[0]),p[1] };
	//2tX^3a+2tX^2b+2CtX+X^2sa+Xsb+Cs
	cli::array<double>^ prod = { (2 * dp[0] * p[0]),	((2 * dp[0] * p[1]) + (dp[1] * p[0])),
								((2 * p[2] * dp[0]) + (dp[1] * p[1])),(p[2] * dp[1]) };
	//cli::array<double>^ raices = Roots(-prod[0], -prod[1], -prod[2] - 1, -prod[3]);
	prod[0] = -prod[0];
	prod[1] = -prod[1];
	prod[2] = -prod[2] - 1;
	prod[3] = -prod[3];

	double y0 = fzero(prod);//cuando x=0;
	double x0 = eval2(p, y0);
	double d = sqrt(pow(x0, 2) + pow(y0, 2));
	double alpha = asin((y0 / d)*(PI / 180));
	List<double>^ parametros;
	parametros->Add(d);
	parametros->Add(alpha);
	return parametros;
}

double DetectorMuro::fzero(cli::array<double>^ prod) {
	//https://en.wikipedia.org/wiki/Newton%27s_method
	double valor_inicial = 0;
	cli::array<double>^ derivada = { (3 * prod[0]),(2 * prod[1]),(prod[2]) }; //3X^2+2x+C
	double tolerance = 0.0001; //Decimales que consideramos.
	double min_number = 0.00001; //No consideramos numeros menores que esto.
	int max_iterations = 30;
	bool sol = false;
	double y, yprime, x1;
	for (int i = 0; i < max_iterations; i++)
	{
		y = eval3(prod, valor_inicial);
		yprime = eval2(derivada, valor_inicial);
		if (fabs(yprime) > min_number)
		{
			x1 = (valor_inicial - y) / yprime; //newton's
			if (fabs(x1 - valor_inicial) <= tolerance*fabs(x1)) { //si es un valor acptable
				return x1; //Devolvemos la primera raiz que encontramos, la mas cercana a 0;
			}
		}
		valor_inicial = x1;
	}
}

double DetectorMuro::eval2(cli::array<double>^p, double y) {
	return p[0] * pow(y, 2) + (p[1] * y) + p[2];
}

double DetectorMuro::eval3(cli::array<double>^p, double y) {
	return (p[0] * pow(y, 3)) + (p[1] * pow(y, 2)) + (p[2] * y) + p[3];
}

cli::array<Obstaculo^>^ DetectorMuro::Clustering(List<Punto3D^>^ puntos, double eps, int minpts) {
	int  sizep = puntos->Count;
	double dist;
	int num_obstaculo = 0;
	cli::array<Obstaculo^>^ obstaculos;
	List<Punto3D^>^ vecinosp;
	//Calculo de las distancias entre puntos.
	cli::array<double, 2>^ distancias;
	for (int fila = 0; fila < sizep - 1; fila++)
	{
		for (int columna = fila; columna < sizep - 1; columna++)
		{
			dist = puntos[fila]->distanceToPoint(puntos[columna]);
			distancias[fila, columna] = dist;
			distancias[columna, fila] = dist;
		}
	}
	cli::array<bool>^ visitados = gcnew cli::array<bool>(sizep);
	cli::array<bool>^ noise = gcnew cli::array<bool>(sizep);
	for (int i = 0; i < visitados->Length; i++)
	{
		visitados[i] = false;
		noise[i] = false;
	}

	for (int i = 0; i < sizep - 1; i++)
	{
		if (!visitados[i]) {
			visitados[i] = true;
			vecinosp = vecinos(i, puntos, distancias);
			if (vecinosp->Count < MIN_PTS)
				noise[i] = true;
			else
			{
				obstaculos[num_obstaculo] = ExpandCluster(i, vecinosp, distancias, visitados);
				num_obstaculo++;
			}
		}
	}
	return obstaculos;
}

cli::array<double>^ DetectorMuro::Regresion(Obstaculo^ muro) {
	//https://es.wikipedia.org/wiki/Regresi%C3%B3n_no_lineal
	double sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2y = 0, sum_x2 = 0, sum_x3 = 0, sum_x4 = 0;
	for (int i = 0; i < muro->components->Count; i++)
	{
		sum_x2 += pow(muro->components[i]->getCoordinatesX(), 2);
		sum_x3 += pow(muro->components[i]->getCoordinatesX(), 3);
		sum_x4 += pow(muro->components[i]->getCoordinatesX(), 4);
		sum_x += muro->components[i]->getCoordinatesX();
		sum_y += muro->components[i]->getCoordinatesY();
		sum_xy += muro->components[i]->getCoordinatesX() * muro->components[i]->getCoordinatesY();
		sum_x2y += pow(muro->components[i]->getCoordinatesX(), 2)* muro->components[i]->getCoordinatesY();
	}
	double d;
	cli::array<double, 2>^ gauss;
	gauss[0, 0] = muro->components->Count;
	gauss[0, 1] = sum_x;
	gauss[0, 2] = sum_x2;
	gauss[0, 3] = sum_y;
	gauss[1, 0] = sum_x;
	gauss[1, 1] = sum_x2;
	gauss[1, 2] = sum_x3;
	gauss[1, 3] = sum_xy;
	gauss[2, 0] = sum_x2;
	gauss[2, 1] = sum_x3;
	gauss[2, 2] = sum_x4;
	gauss[2, 3] = sum_x2y;
	//http://www.cplusplus.com/forum/beginner/124448/
	/************** Partial pivoting **************/

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (j == (i + 3))
				gauss[i, j] = 1;
		}
	}

	for (int i = 3; i > 1; i--)
	{
		if (gauss[i - 1, 1] < gauss[i, 1])
			for (int j = 0; j < 7; j++)
			{
				d = gauss[i, j];
				gauss[i, j] = gauss[i - 1, j];
				gauss[i - 1, j] = d;
			}
	}

	/********** Reducing To Diagonal Matrix ***********/

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 7; j++)
			if (j != i)
			{
				d = gauss[j, i] / gauss[i, i];
				for (int k = 0; k < 6; k++)
					gauss[j, k] -= gauss[i, k] * d;
			}
	}

	/************** Reducing To Unit Matrix *************/
	for (int i = 0; i < 3; i++)
	{
		d = gauss[i, i];
		for (int j = 0; j < 7; j++)
			gauss[i, j] = gauss[i, j] / d;
	}


	//Your solutions
	cli::array<double>^ sol;
	for (int i = 0; i < 3; i++)
	{
		sol[i] = gauss[i, 7];
	}
	return sol;
}

List<Punto3D^>^ DetectorMuro::vecinos(int punto, List<Punto3D^>^ puntos, cli::array<double, 2>^ D) {
	List<Punto3D^>^ vecinos;
	for (int i = punto; i < puntos->Count; i++)
	{
		if (D[punto, i] < EPSILON) {
			vecinos->Add(puntos[i]);
		}
	}
	return vecinos;
}

Obstaculo^ DetectorMuro::ExpandCluster(int p, List<Punto3D^>^ vecinosp, cli::array<double, 2>^ D, cli::array<bool>^ visitados) {
	Obstaculo^ obs = gcnew Obstaculo();
	List<Punto3D^>^ vcns;
	obs->components->AddRange(vecinosp);
	for (int i = p; i < vecinosp->Count; i++)
	{
		if (!visitados[i]) {
			visitados[i] = true;
			vcns = vecinos(i, vecinosp, D);
			if (vecinosp->Count > MIN_PTS) {
				obs->components->AddRange(vcns);
			}
		}
	}
	return obs;
}

cli::array<Punto3D^, 2>^ DetectorMuro::Delaunay(List<Punto3D^>^) {
	cli::array<Punto3D^, 2>^ result;
	return result;
}