#pragma once
using namespace std;
using namespace System::IO::Ports;
using namespace System::Threading;
ref class Gps
{
public:
	Gps();
	SerialPort^ serialPort;
	
};

