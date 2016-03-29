#include "DataAnalisys.h"
DataAnalisys::DataAnalisys()
{
	timeBeginPeriod(1);
	indice = -1;
	menor = -1;
	for (int k = 0; k < 4; k++)
	{
		listMenor[k] = 0;
	}
}
//matriz::Lista de puntos
//resolucionAngular::resolucion del laser
//Vcoche::velocidad actual del coche
//consigna velocidad:: puntero para devolucion de parametro de velocidad
//consigna volante:: puntero para devolucion de parametro de volante
//apertura::Angulo de interes de lectura en grados
void DataAnalisys::Analisys(List<Punto3D^>^ puntosController, List<Obstaculo^>^ ObstaculosController, array<double>^ ParamAnalisys, List<int>^ Conclusiones, array<bool>^ Flags, array<Thread^>^ Threads, OpenGl^ Dibujador)
{
	this->Dibujador = Dibujador;
	this->Threads = Threads;
	this->Flags = Flags;
	parametros = ParamAnalisys;
	this->Conclusiones = Conclusiones;
	matriz = puntosController;
	ObstaculosvAnt = ObstaculosController;
	Obstaculos->Clear();
	if (!thread_analysis) {
		thread_analysis = gcnew Thread(gcnew ThreadStart(this, &DataAnalisys::AnalisysThread));
	}
	thread_analysis->Start();
	//Guarda el identificador de thread en el array de threads del Controllerador 
	Threads[1] = thread_analysis;
}
void DataAnalisys::Analisys(List<Punto3D^>^ puntosController, List<Obstaculo^>^ ObstaculosController, cli::array<double>^ ParamAnalisys, List<int>^ Conclusiones, cli::array<bool>^ Flags, cli::array<Thread^>^ Threads) 
{
	this->Threads = Threads;
	this->Flags = Flags;
	parametros = ParamAnalisys;
	this->Conclusiones = Conclusiones;
	matriz = puntosController;
	ObstaculosvAnt = ObstaculosController;
	Obstaculos->Clear();
	if (!thread_analysis) {
		thread_analysis = gcnew Thread(gcnew ThreadStart(this, &DataAnalisys::AnalisysThread));
	}
	thread_analysis->Start();
	//Guarda el identificador de thread en el array de threads del Controllerador 
	Threads[1] = thread_analysis;
}
//List<Punto3D^>^ matriz, double resolucionAngular,double Vcoche, double &consigna_velocidad, double &consigna_volante, double apertura
void DataAnalisys::AnalisysThread() 
{
	//En caso de que se desactive y se reactive despues hay que limpiar los objetos
	ObstaculosvAnt->Clear();

	while (Flags[FlagAnalisysOn] && Flags[FlagWarning] && !Flags[FlagPausa]) 
	{
		try
		{
			if (Flags[FlagTratamiento] == 0) {
				//matriz = Controllerador->Puntos;  La matriz es siempre igual a la matriz de puntos
				resolutionH = parametros[posResolucionH];//Resolucion
				resolutionV = parametros[posResolucionV];//Resolucion
				VCOCHE = parametros[posApertura];//Vcoche
				apertura = parametros[posVcoche];//Apertura
				NUMERO_COLUMNAS = matriz->Count / NUMERO_FILAS;

				//Trabajo

				if (VCOCHE > 5) {
					if (!comprobarBloqueo(matriz))
					{
						Segmentacion(matriz, apertura);
						//TODO::Identificar tipo de obstaculo
						EliminarObstaculos();
						prepararObstaculos();
						RelacionarObstaculos();
						//TODO::Calcular TTC y actualizar consignas
					}
					else consigna_velocidad = 0.0;
				}

				//Fin tratamiento

				//Copiar el vector de obstaculos obtenido en Controller y comprueba colisiones
				copiarObstaculos();

				//Actualizar consignas en el vector de conclusiones
				Conclusiones[0] = consigna_velocidad;
				Conclusiones[1] = consigna_volante;
			}
		}
		catch (Exception^ e)
		{
			Flags[FlagWarning] = true;
			//	System::Windows::Forms::MessageBox::Show(e->ToString());
		}
		Sleep(10);
	}
}

void DataAnalisys::Kill()
{
	thread_analysis->Abort();
}

void DataAnalisys::copiarObstaculos()
{
	ObstaculosvAnt->Clear();
	ObstaculosvAnt->AddRange(Obstaculos);
	if (Flags[FlagOpenGlOn]) {
		Dibujador->modificarObstaculos(ObstaculosvAnt);
	}
	//Controller de collision
	if (Flags[FlagTratamiento] == 1) {
		Flags[FlagWarning] = 1;
		//mensaje pantalla
	}
	Flags[FlagTratamiento] = 1;
}

void DataAnalisys::Segmentacion(List<Punto3D^>^ matrix, double apertura)
{
	int aprr = (apertura / 2) / resolutionH;
	int inicio = (NUMERO_COLUMNAS / 2) - aprr;
	int final = (NUMERO_COLUMNAS / 2) + aprr;
	//Se recorre la matriz linealmente
	for (int j = NUMERO_FILAS; j <= 0; j++)
	{
		for (int i = inicio; i < final; i++)
		{
			//Se comprubea si el punto a tratar Existe
			if (matrix[convaPos(i, j)]->getDistance() > 0)
			{
				//En caso de que sea el primer punto se asigna directamente al obstaculo 1
				if (i == 0 && j == NUMERO_FILAS)
				{
					//Mete al final del vector de obstaculos un obstaculo que crea
					Obstaculos->Add(gcnew Obstaculo());
					matrix[convaPos(i, j)]->setObstacle(0);
					//Accede al obstaculo 0, al vector de componentes, mente el punto en el vector de componentes
					Obstaculos[0]->components->Add(matrix[convaPos(i, j)]);
				}
				else {
					//Se compara cada punto a tratar con sus puntos adyacentes ya tratados

					if (j < NUMERO_FILAS)
					{
						//Resolver ambiguedades
						//Punto de encima
						if (puntosCercanosV(matrix[convaPos(i, j)], matrix[convaPos(i, j + 1)]))
						{
							Cercanos[0] = true;
							PCercanos[0] = matrix[convaPos(i, j + 1)];
						}
						if (j > 0)
						{
							//Punto de encima a la izquierda
							if (puntosCercanosD(matrix[convaPos(i, j)], matrix[convaPos(i - 1, j + 1)]))
							{
								Cercanos[1] = true;
								PCercanos[0] = matrix[convaPos(i - 1, j + 1)];
							}
						}
						if (i > 0 && j < NUMERO_COLUMNAS)
						{
							//Punto de encima a la derecha
							if (puntosCercanosD(matrix[convaPos(i, j)], matrix[convaPos(i + 1, j + 1)]))
							{
								Cercanos[2] = true;
								PCercanos[0] = matrix[convaPos(i + 1, j + 1)];
							}
						}
					}
					if (j > 0)
					{
						//Punto de la izquierda
						if (puntosCercanosH(matrix[convaPos(i, j)], matrix[convaPos(i - 1, j)]))
						{
							Cercanos[3] = true;
							PCercanos[0] = matrix[convaPos(i - 1, j)];
						}
					}

					int numCercanos = 0;
					int localizador;
					for (int recorrido = 0; recorrido < 4; recorrido++)
					{
						if (Cercanos[recorrido])
						{
							numCercanos++;
							localizador = recorrido;
						}
					}

					if (numCercanos == 0)
					{
						Obstaculos->Add(gcnew Obstaculo());
						matrix[convaPos(i, j)]->setObstacle((int)Obstaculos->Count - 1);
						Obstaculos[Obstaculos->Count - 1]->components->Add(matrix[convaPos(i, j)]);
					}
					else if (numCercanos == 1) {
						int VarX, VarY;
						matrix[convaPos(i, j)]->setObstacle(PCercanos[localizador]->getObstacle());
						Obstaculos[matrix[convaPos(i, j)]->getObstacle()]->components->Add(matrix[convaPos(i, j)]);
					}
					else {
						bool iguales = true;
						int Obs;
						int Obstmenor = -1;
						for (int recorrido = 0; recorrido < 4; recorrido++)
						{
							if (Cercanos[recorrido]) {
								if (Obstmenor == -1) {
									Obstmenor = PCercanos[recorrido]->getObstacle();
								}
								else if (PCercanos[recorrido]->getObstacle() != Obstmenor) {
									iguales = false;
									if (PCercanos[recorrido]->getObstacle() < Obstmenor)
									{
										Obstmenor = PCercanos[recorrido]->getObstacle();
									}
								}
							}
						}
						if (iguales) {
							matrix[convaPos(i, j)]->setObstacle(Obstmenor);
							Obstaculos[Obstmenor]->components->Add(matrix[convaPos(i, j)]);
						}
						else {
							for (int recorrido = 0; recorrido < 4; recorrido++) {
								if (Cercanos[recorrido]) {
									if (PCercanos[recorrido]->getObstacle() != Obstmenor)
										MoverObstaculo(PCercanos[recorrido]->getObstacle(), Obstmenor);
								}
							}
							matrix[convaPos(i, j)]->setObstacle(Obstmenor);
							Obstaculos[Obstmenor]->components->Add(matrix[convaPos(i, j)]);
						}
					}
					//TODO::Recorrer la lista y eliminar puntos no validos
					//TODO::resolver ambiguedades:si un punto puede pertenecer a dos obstaculos unir dichos obstaculos

					//Si los puntos adyacentes no existen se incluye este punto en un obstaculo




					//TODO::Ver como se guarda la matriz

				}
			}
		}
	}
}
void DataAnalisys::prepararObstaculos()
{
	for (int i = 0; i < Obstaculos->Count; i++)
	{
		Obstaculos[i]->prepareObstacle();//TODO::Calcular centro,cubo,y todo lo necesario
	}
}
void DataAnalisys::EliminarObstaculos()
{
	for (int p = 0; p < Obstaculos->Count; p++)
	{
		if (Obstaculos[p]->components->Count < TAMAÑO_MINIMO_OBSTACULO)
		{
			//TODO::Ajustar el numero minimo de puntos para considerarlo un obstaculo
			Obstaculos->RemoveAt(p);
			p--;
		}
	}
}
void DataAnalisys::RelacionarObstaculos()
{
	//TODO::Ajustar variables para este laser
	for (int i = 0; i < Obstaculos->Count; i++)
	{
		indice = -1;
		for (int j = 0; j < ObstaculosvAnt->Count; j++)
		{
			if (ObstaculosvAnt[j]->getVelocity() >= 1)
			{
				//0.3 es la distancia maxima que que puede recorrer entre barridos
				if (Obstaculos[i]->getCenter()->distanceToPoint(ObstaculosvAnt[j]->getPrediceCenter()) < (VCOCHE / 3.6) * TIEMPO_MARGEN)// POrque 0.3??  = 0.0833
				{
					relacionarVel(i, j);
					indice = j;
				}
			}
			else if (Obstaculos[i]->getCenter()->distanceToPoint(ObstaculosvAnt[j]->getCenter()) < DISTANCIA_MAXIMA /*&& fabs(Obstaculos[i].getYaw() - Obstaculos[i].getYaw()) < 5*/)
			{
				relacionarPos(i, j, VCOCHE, resolutionH);
				indice = j;
			}
		}
	}
}
void DataAnalisys::relacionarVel(int i, int j)
{
	Obstaculos[i]->setDirection(ObstaculosvAnt[j]->getCenter());
	Obstaculos[i]->calculatePrediceCenter();
	Obstaculos[i]->setVelocity(VCOCHE, resolutionH);
	Obstaculos[i]->calculateTimeToCollision(VCOCHE);
}
void DataAnalisys::relacionarPos(int i, int j, int VelC, int Res)
{
	Obstaculos[i]->setDirection(ObstaculosvAnt[j]->getCenter());
	Obstaculos[i]->calculatePrediceCenter();
	Obstaculos[i]->setVelocity(VCOCHE, resolutionH);
}
bool DataAnalisys::comprobarBloqueo(List<Punto3D^>^ matriz)
{
	//Devuelve true cuando hay bloqueo
	int medio = matriz->Count / 2;
	for (int k = medio - 20; k < medio + 20; k++) {
		for (int i = 0; i < NUMERO_FILAS; i++) {
			if (matriz[convaPos(i, k)]->getDistance() < 15) {
				return true;
			}
		}
	}
	return false;
}
bool DataAnalisys::puntosCercanosH(Punto3D^ p1, Punto3D^ p2)
{
	double s0 = 1.4;
	double s1 = sqrt(2 - (2 * cos(2 * resolutionH*PI / 180)));
	double r = p1->getDistance();
	if (p1->getDistance() > p2->getDistance())
		r = p2->getDistance();
	double tolererancia = s0 + (s1 * r);

	return (tolererancia > p1->distanceToPoint(p2));
}
bool DataAnalisys::puntosCercanosV(Punto3D^ p1, Punto3D^ p2)
{
	double tolerancia = p1->getDistance() * tan(resolutionV  * PI / 180);
	tolerancia = tolerancia * ((100 + ToleranciaVertical) / 100);
	return(tolerancia > p1->distanceToPoint(p2));
}
bool DataAnalisys::puntosCercanosD(Punto3D^ p1, Punto3D^ p2)
{
	double toleranciaV = p1->getDistance() * tan(resolutionV  * PI / 180);
	double toleranciaH = p1->getDistance() * tan(resolutionH  * PI / 180);
	Punto3D ^a = gcnew Punto3D(toleranciaH, toleranciaV, 0);
	double tolerancia = a->getModule();
	tolerancia = tolerancia * ((100 + ToleranciaDiagonal) / 100);
	return(tolerancia > p1->distanceToPoint(p2));
}
int DataAnalisys::convaPos(int a, int b) {
	//return (a - 1) * 16 + b;
	return a * 16 + b;
}

void DataAnalisys::MoverObstaculo(int Obst1, int Obst2)
{
	throw gcnew System::NotImplementedException();
}
