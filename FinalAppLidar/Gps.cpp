#include "Gps.h"
#include "Parametros.h"
#include "OpenGl.h"
Gps::Gps(cli::array<Object^>^ ArrayGps)
{
	parametros = ArrayGps;
	serialPort = gcnew SerialPort();
	Thread^ gps_thread = gcnew Thread(gcnew ThreadStart(this, &Gps::Esperar));
	gps_thread->Start();
}
void Gps::Read() {
	serialPort->Open();
	while (Convert::ToBoolean(parametros[START])) {
		String^ data = serialPort->ReadLine();
		if (data->Contains(parametros[TIPO_TRAMA]->ToString()))
		parametros[TRAMA] = data;
	}
	serialPort->Close();
	Esperar();
}

void Gps::Esperar() {
	while (!Convert::ToBoolean(parametros[START]))
	{
		Sleep(100);
	}
	try
	{
		serialPort->PortName = parametros[COM]->ToString();
		serialPort->Parity = Parity::None;
		serialPort->StopBits = StopBits::One;
		serialPort->DataBits = 8;
		serialPort->Handshake = Handshake::None;
	}
	catch (Exception^ e)
	{
		MessageBox::Show("Error en gps", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	Read();
}
