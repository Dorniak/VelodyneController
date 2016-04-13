#pragma once
using namespace std;
using namespace System;
using namespace System::IO::Ports;
using namespace System::Threading;
using namespace System::Windows::Forms;
ref class Gps
{
public:
	Gps(cli::array<Object^>^ ArrayGps);
	void Read();
	void Gps::Esperar();
	SerialPort^ serialPort;
private:
	cli::array<Object^>^ parametros;
};

