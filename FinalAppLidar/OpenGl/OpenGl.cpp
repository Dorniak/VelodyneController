#include "OpenGl.h"
//Librerias para las listas de puntos
using namespace System;
using namespace System::Collections::Generic;

// ----------------------------------------------------------
// Prototipos de función OpenGl
// ----------------------------------------------------------
void init();
void display(void);
void keyboard(unsigned char, int , int );
void centerOnScreen();
void trabajo();
void specialKeys(int key, int x, int y);
void timerFunc(int time);
int radio1 = 3;
int radio2 = 20;
int radio3 = 50;
// ----------------------------------------------------------
// Variables globales
// ----------------------------------------------------------
//Variables de tamaño de pantalla
int window_x;
int window_y;

int hazPerspectiva = 0;

GLint ancho = 400;
GLint alto = 400;
//  variables representing the window size
int window_width = 600;
int window_height = 600;

//  variable representing the window title
char *window_title = "Sample OpenGL FreeGlut App";


void OpenGl::threadconstructor()
{
	iniciarPuntos();
	iniciarObstaculos();
	int argc = 0;
	char **argv;
	glutInit(&argc, argv);
	trabajo();
	//  Start GLUT event processing loop
	glutDisplayFunc(display);
	glutMainLoop();
}

//-------------------------------------------------------------------------
//  Program Main method.
//-------------------------------------------------------------------------
void OpenGl::constructor(cli::array<Thread^>^ Threads)
{
	try
	{
		this->Threads = Threads;
		if (!ThreadDIO)
			ThreadDIO = gcnew Thread(gcnew ThreadStart(this, &OpenGl::threadconstructor));
		ThreadDIO->Start();
		this->Threads[2] = ThreadDIO;
	}
	catch (Exception^ e)
	{
		System::Windows::Forms::MessageBox::Show(e->ToString());
	}
}
void OpenGl::modificarPuntos(List<Punto3D^>^ listEntradaPuntos)
{
	listo = false;
	if (listEntradaPuntos->Count < puntos->Count) {
		limpiarListas(listEntradaPuntos->Count);
	}
	for (int recorridoP = 0; recorridoP < listEntradaPuntos->Count; recorridoP++) {
		puntos[recorridoP]->setCoordinatesX(listEntradaPuntos[recorridoP]->getCoordinatesX());
		puntos[recorridoP]->setCoordinatesY(listEntradaPuntos[recorridoP]->getCoordinatesY());
		puntos[recorridoP]->setCoordinatesZ(-listEntradaPuntos[recorridoP]->getCoordinatesZ());
	}
	listo = true;
}
void OpenGl::modificarObstaculos(List<Obstaculo^>^ listEntradaObstaculos)
{
	/*for (int recorridoO = 0; recorridoO < listEntradaObstaculos->Count; recorridoO++) {
		obstaculos[recorridoO]->setCoordinatesX(listEntradaObstaculos[recorridoO]->getCoordinatesX());
		obstaculos[recorridoO]->setCoordinatesY(listEntradaObstaculos[recorridoO]->getCoordinatesY());
		obstaculos[recorridoO]->setCoordinatesZ(listEntradaObstaculos[recorridoO]->getCoordinatesZ());
	}*/
}
void OpenGl::iniciarPuntos()
{
	Punto3D^ a;
	for (int llenarPuntos = 0; llenarPuntos < 500000; llenarPuntos++) {
		a = gcnew Punto3D(0, 0, 0);
		puntos->Add(a);
	}
	puntosAnterior = puntos->Count;
}
void OpenGl::iniciarObstaculos()
{
	Punto3D^ b;
	for (int llenarObstaculos = 0; llenarObstaculos < 400; llenarObstaculos++) {
		b = gcnew Punto3D(0, 0, 0);
		obstaculos->Add(b);
	}
}
void OpenGl::limpiarListas(int a)
{
	for (int recorrerListaPuntos = a; recorrerListaPuntos < puntosAnterior; recorrerListaPuntos++) {
		puntos[recorrerListaPuntos]->setCoordinatesX(0);
		puntos[recorrerListaPuntos]->setCoordinatesY(0);
		puntos[recorrerListaPuntos]->setCoordinatesZ(0);
	}
	for (int recorrerListaObstaculos = 0; recorrerListaObstaculos < obstaculos->Count; recorrerListaObstaculos++) {
		obstaculos[recorrerListaObstaculos]->setCoordinatesX(0);
		obstaculos[recorrerListaObstaculos]->setCoordinatesY(0);
		obstaculos[recorrerListaObstaculos]->setCoordinatesZ(0);
	}
}

void trabajo()
{
	centerOnScreen();
	glutInitWindowSize(window_width, window_height);
	glutInitWindowPosition(window_x, window_y);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutCreateWindow(window_title);

	//  Set OpenGL program initial state.
	init();
	// Set the callback functions
	//glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKeys);
	glutTimerFunc(2000, timerFunc, 0);
}

//-------------------------------------------------------------------------
//  Set OpenGL program initial state.
//-------------------------------------------------------------------------
void init()
{
	glEnable(GL_DEPTH_TEST);
	//  Set the frame buffer clear color to black. 
	glClearColor(0.0, 0.0, 0.0, 0.0);
}
//-------------------------------------------------------------------------
//  Funcion que se encarga de meter en el buffer de pintura las dos listas
//-------------------------------------------------------------------------
void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glFlush();
	//Pintar ejes
	glPointSize(2);
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.6f, 0.6f);  // activamos el color rojo claro
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(1000.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-1000.0f, 0.0f, 0.0f);
	glColor3f(0.6f, 1.0f, 0.6f);  // activamos el color verde claro
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 1000.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, -1000.0f, 0.0f);
	glColor3f(0.6f, 0.6f, 1.0f);  // activamos el color azul claro
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 1000.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, -1000.0f);
	glEnd();

	glColor3f(1.0f, 1.0f, 1.0f);      // activamos el color blanco
	//Dibuja circunferencia 3m de diametro
	glBegin(GL_LINE_STRIP);
	glColor3f(1.0f, 0.0f, 0.0f);      // activamos el color rojo
	for (int i = 0; i<360; i++) {
		float x = (float)cos(i * 2 * PI / 360);
		float y = (float)sin(i * 2 * PI / 360);
		glVertex3f(x * radio1, y * radio1, 0);
	}
	glEnd();
	//Dibuja circunferencia 20m de diametro
	glBegin(GL_LINE_STRIP);
	glColor3f(1.0f, 0.5f, 0.0f);      // activamos el color naranja
	for (int i = 0; i<360; i++) {
		float x = (float)cos(i * 2 * PI / 360);
		float y = (float)sin(i * 2 * PI / 360);
		glVertex3f(x * radio2, y * radio2, 0);
	}
	glEnd();
	//Dibuja circunferencia 50m de diametro
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f, 1.0f, 0.0f);      // activamos el color verde
	for (int i = 0; i<360; i++) {
		float x = (float)cos(i * 2 * PI / 360);
		float y = (float)sin(i * 2 * PI / 360);
		glVertex3f(x * radio3, y * radio3, 0);
	}
	glEnd();
	//Dibuja cono de accion 3 m
	glBegin(GL_LINE_STRIP);
	glColor3f(1.0f, 0.0f, 0.0f);      // activamos el color rojo
	glVertex3f(0, 0, 0);
	for (int i = 75; i<105; i++) {
		float x = (float)cos(i * 2 * PI / 360);
		float y = (float)sin(i * 2 * PI / 360);
		glVertex3f(x * radio1, y * radio1, 0);
	}
	glVertex3f(0, 0, 0);
	glEnd();
	//Dibuja cono de accion 20 m
	glBegin(GL_LINE_STRIP);
	glColor3f(1.0f, 0.5f, 0.0f);      // activamos el color naranja
	glVertex3f(0, 0, 0);
	for (int i = 75; i<105; i++) {
		float x = (float)cos(i * 2 * PI / 360);
		float y = (float)sin(i * 2 * PI / 360);
		glVertex3f(x * radio2, y * radio2, 0);
	}
	glVertex3f(0, 0, 0);
	glEnd();
	//Dibuja cono de accion 50 m
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f, 1.0f, 0.0f);      // activamos el color verde
	glVertex3f(0, 0, 0);
	for (int i = 75; i<105; i++) {
		float x = (float)cos(i * 2 * PI / 360);
		float y = (float)sin(i * 2 * PI / 360);
		glVertex3f(x * radio3, y * radio3, 0);
	}
	glVertex3f(0, 0, 0);
	glEnd();


	glColor3f(1.0f, 1.0f, 1.0f);      // activamos el color blanco
	//-------------------------------------------------------------------------
	//  Mete en el buffer la lista de puntos
	//-------------------------------------------------------------------------
	glPointSize(2);
	glBegin(GL_POINTS);
	glColor3f(0.8f, 0.6f, 1.0f);  // activamos el color rojo claro
	for (int i = 0; i < OpenGl::puntos->Count; i++) {
		glVertex3d(OpenGl::puntos[i]->getCoordinatesX(), OpenGl::puntos[i]->getCoordinatesY(), OpenGl::puntos[i]->getCoordinatesZ());
	}
	glEnd();
	//-------------------------------------------------------------------------
	//  Mete en el buffer la lista de obstaculos
	//-------------------------------------------------------------------------
	glPointSize(2);
	glBegin(GL_LINE_STRIP);
	glColor3f(1.0f, 1.0f, 1.0f);      // activamos el color blanco
	for (int j = 0; j < OpenGl::obstaculos->Count; j = j + 4) {
		for (int k = j; k < j+4; k++) {
		glVertex3d(OpenGl::obstaculos[k]->getCoordinatesX(), OpenGl::obstaculos[k]->getCoordinatesY(), OpenGl::obstaculos[k]->getCoordinatesZ());
		}
		glEnd();
	}
	glFlush();
	glutSwapBuffers();

}
//Funcion inhabilitada
void timerFunc(int time) {
	if (OpenGl::listo) {
		glutPostRedisplay();
		glFlush();
	}
	glutTimerFunc(50, timerFunc, 0);
}
//-------------------------------------------------------------------------
//  This function sets the window x and y coordinates
//  such that the window becomes centered
//-------------------------------------------------------------------------
void centerOnScreen()
{
	window_x = (glutGet(GLUT_SCREEN_WIDTH) - window_width) / 2;
	window_y = (glutGet(GLUT_SCREEN_HEIGHT) - window_height) / 2;
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	/*case 'p':
	case 'P':
		hazPerspectiva = 1;
		reshape(ancho, alto);
		break;

	case 'o':
	case 'O':
		hazPerspectiva = 0;
		reshape(ancho, alto);
		break;*/
	case 'h':
		printf("o = Perspectiva ortogonal");
		printf("p = perspectiva de proyeccion");
		printf("c - Toggle culling\n");
		printf("ESC = escape");
		break;
	case '5':
		glRotatef(1.0, 0., 0., 1.);
		break;
	case '6':
		glRotatef(1.0, 0., 0., -1.);
		break;
	case '7':
		glScalef(0.5,0.5,0.5);
		break;
	case '8':
		glScalef(2, 2, 2);
		break;
	case 'a':
		gluLookAt(-0.1, 0, 0, 0, 0, 0, 0, 1, 0);
		break;
	case 'r':
		glScalef(1.0, 1.0, 1.0);
		break;
	case '9':
		OpenGl::puntos[1]->setCoordinatesX(2);
		break;
	case 27:
		exit(0);
		break;
	case 43:
		glScalef(1.1, 1.1, 1.1);
		break;
	case 45:
		glScalef(0.9, 0.9, 0.9);
		break;
	case 32:
		glLoadIdentity();
		glScalef(0.05, 0.05, 0.05);
		break;
	}
	glutPostRedisplay();
}
void specialKeys(int key, int x, int y) {
	//glLoadIdentity();
	if (key == GLUT_KEY_RIGHT) {
		glRotatef(1, 0.0, 1.0, 0.0);
	}
	else if (key == GLUT_KEY_LEFT) {
		glRotatef(-1, 0.0, 1.0, 0.0);
	}
	else if (key == GLUT_KEY_UP)
		glRotatef(1, 1.0, 0.0, 0.0);

	else if (key == GLUT_KEY_DOWN)
		glRotatef(-1, 1.0, 0.0, 0.0);
	//  Solicitud para actualizar la pantalla
	glutPostRedisplay();
}