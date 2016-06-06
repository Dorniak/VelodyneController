#pragma once
#include "../Punto3D/Punto3D.h"
using namespace System::Text;
using namespace System::IO;
using namespace System;
using namespace System::Threading;
using namespace System::Collections::Generic;
using namespace std;
ref class Logger
{
public:
	Logger();
	void setPath(String^ p);
	void init();
	void swapBuffers();
	void cleanBuffer();
	void recordData();
	void addToBuffer(List<Punto3D^>^ in);
	void close();
	void kill();
	bool THREAD_ON;
private:
	void StartLoggin();
	bool buff;
	List<Punto3D^>^ pts;
	List<Punto3D^>^ Buffer1;
	List<Punto3D^>^ Buffer2;
	Thread^ thread_logger;
	String^ path;
	StringBuilder^ sb;
	StreamWriter^ log;
};

