#include "Gps.h"
#include "Parametros.h"
#include "OpenGl.h"
Gps::Gps(cli::array<Object^>^ ArrayGps, cli::array<Thread^>^ Threads_in)
{
	parametros = ArrayGps;
	serialPort = gcnew SerialPort();
	Thread^ gps_thread = gcnew Thread(gcnew ThreadStart(this, &Gps::Esperar));
	Threads_in[THREAD_GPS] = gps_thread;
	gps_thread->Start();
}
void Gps::Read() {
	serialPort->BaudRate = Convert::ToInt32(parametros[RATE]);
	serialPort->ReadTimeout = 2000;
	serialPort->Open();
	
	if (!serialPort->IsOpen)
		MessageBox::Show("Error al conectar en el puerto" + parametros[COM], "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	String^ data;
	while (Convert::ToBoolean(parametros[START])) {
		try
		{
			data = serialPort->ReadLine();
		}
		catch (Exception^ e)
		{
			parametros[START] = false;
			serialPort->Close();
			MessageBox::Show("No se reciben datos en el puerto" + parametros[COM], "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			Esperar();
		}
		if (data->Contains("GGA"))
			ExtraerGGA(data);
		if (data->Contains(parametros[TIPO_TRAMA]->ToString()))
			parametros[TRAMA] = "," + data->Substring(0,data->Length-1);
	}
	parametros[TRAMA] = "";
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
void Gps::ExtraerGGA(String^ data) {
	try
	{
		cli::array<String^>^ partes = data->Split(',');
		/*for (int i = 0; i < partes->Length; i++)
		{
			parametros[TRAMA] += "["+i+"]="+partes[i]+"  ";
		}
		parametros[TRAMA] += "\r\n";*/
		parametros[QUALITY] = partes[6];
		parametros[SATELITES] = partes[7];
	}
	catch (Exception^ e)
	{

	}

}