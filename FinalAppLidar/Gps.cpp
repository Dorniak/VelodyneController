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
	
	serialPort->Open();
	
	if (!serialPort->IsOpen){
		MessageBox::Show("Error al conectar en el puerto" + parametros[COM], "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		Esperar();
	}
	parametros[ESTADO] = 1;
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
	parametros[ESTADO] = 0;
	while (!Convert::ToBoolean(parametros[START]))
	{
		Sleep(100);
	}
	try
	{
		serialPort->PortName = parametros[COM]->ToString();
		serialPort->StopBits = StopBits::One;
		serialPort->DataBits = 8;
		serialPort->BaudRate = Convert::ToInt32(parametros[RATE]);
		serialPort->ReadTimeout = 1500;
	}
	catch (Exception^ e)
	{
		MessageBox::Show("Error al configurara el puerto serie", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	Read();
}
void Gps::ExtraerGGA(String^ data) {
	try
	{
		cli::array<String^>^ partes = data->Split(',');
		
		if (parametros[QUALITY] != partes[6])
			parametros[QUALITY] = partes[6];
		if (parametros[SATELITES] != partes[7] && partes[7] != "")
			parametros[SATELITES] = partes[7];
	}
	catch (Exception^ e)
	{

	}

}