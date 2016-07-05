#include "Logger.h"
#include "../Parametros/Parametros.h"

Logger::Logger()
{
	Buffer1 = gcnew List<Punto3D^>(NUMBER_OF_POINTS);
	Buffer2 = gcnew List<Punto3D^>(NUMBER_OF_POINTS);
	pts = Buffer1;
	kill_me = false;
	gps = "";
	buff = false;
	guardar = 0;
	grabar = 0;
	thread_logger = gcnew Thread(gcnew ThreadStart(this, &Logger::Esperar));
	thread_logger->Start();
}

void Logger::setPath(String^ p)
{
	path = p;
}

void Logger::init(double x, double y,double z,double r,double p, double w,int frecuency)
{
	path += "\\" + DateTime::Now.ToString("dd-MMMM-yyyy-HH-mm-ss");
	Directory::CreateDirectory(path);
	fs = gcnew FileStream(path + "\\log.bin", FileMode::Create);
	writer = gcnew BinaryWriter(fs);
	writer->Write(x);
	writer->Write(y);
	writer->Write(z);
	writer->Write(r);
	writer->Write(p); 
	writer->Write(y);
	writer->Write(frecuency);
	THREAD_ON = true;
}
void Logger::swapBuffers()
{
	if (buff)
		pts = Buffer1;
	else
		pts = Buffer2;
	buff = !buff;
}
void Logger::StartLoggin()
{
	while (THREAD_ON)
	{
		if (pts->Count > 10000) {
			swapBuffers();
			recordData();
			cleanBuffer();
		}
	}
	if (writer) {
		writer->Close();
		fs->Close();
	}
	Buffer1->Clear();
	Buffer2->Clear();
	pts->Clear();
	Esperar();
}

void Logger::recordData()
{
	grabar++;
	try
	{
		if (buff) {
			for (int i = 1; i < Buffer1->Count; i++)
			{
				writer->Write(Buffer1[i]->getFrame());
				writer->Write(Buffer1[i]->getAzimuth());
				//writer->Write(Buffer1[i]->getCoordinatesX());
				//writer->Write(Buffer1[i]->getCoordinatesY());
				//writer->Write(Buffer1[i]->getCoordinatesZ());
				writer->Write(Buffer1[i]->getDistance());
				writer->Write(Buffer1[i]->getAngle());
			}
		}
		else {
			for (int i = 1; i < Buffer2->Count; i++)
			{
				writer->Write(Buffer2[i]->getFrame());
				writer->Write(Buffer2[i]->getAzimuth());
				//writer->Write(Buffer2[i]->getCoordinatesX());
				//writer->Write(Buffer2[i]->getCoordinatesY());
				//writer->Write(Buffer2[i]->getCoordinatesZ());
				writer->Write(Buffer2[i]->getDistance());
				writer->Write(Buffer2[i]->getAngle());
			}
		}
		writer->Flush();
	}
	catch (Exception^ e)
	{
		System::Windows::Forms::MessageBox::Show("Error al guardar los datos: " + e->Message, "Error", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
		if (writer) {
			writer->Close();
			fs->Close();
		}
		Buffer1->Clear();
		Buffer2->Clear();
		pts->Clear();
		Esperar();
	}
}

void Logger::addToBuffer(List<Punto3D^>^ pointlist, String^ gps_in)
{
	guardar++;
	pts->AddRange(pointlist);
	gps = gps_in;
}

void Logger::close()
{
	try
	{
		writer->Close();
		fs->Close();
	}
	catch (Exception^)
	{
	}
}

void Logger::cleanBuffer() {
	try
	{
		if (buff) {
			Buffer1->Clear();
		}
		else {
			Buffer2->Clear();
		}
	}
	catch (Exception^ e)
	{
		System::Windows::Forms::MessageBox::Show("Error al limpiar los buffers: " + e->Message, "Error", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
		if (writer) {
			writer->Close();
			fs->Close();
		}
		Buffer1->Clear();
		Buffer2->Clear();
		pts->Clear();
		Esperar();
	}
}
void Logger::Stop() {
	THREAD_ON = false;
}

void Logger::kill() {
	kill_me = true;
}

void Logger::Esperar() {
	while (!THREAD_ON)
	{
		Thread::Sleep(250);
		if (kill_me)
			return;
	}
	StartLoggin();
}