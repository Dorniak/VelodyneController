#include "Logger.h"
#include "../Parametros/Parametros.h"


Logger::Logger()
{
	Buffer1 = gcnew List<Punto3D^>(NUMBER_OF_POINTS);
	Buffer2 = gcnew List<Punto3D^>(NUMBER_OF_POINTS);
	sb = gcnew StringBuilder(NUMBER_OF_POINTS * 77, NUMBER_OF_POINTS * 85); //77 = Caracteres por punto.
	pts = Buffer1;
	kill_me = false;
	gps = "";
	buff = false;
	thread_logger = gcnew Thread(gcnew ThreadStart(this, &Logger::StartLoggin));
	thread_logger->Start();
}

void Logger::setPath(String^ p)
{
	path = p;
}

void Logger::init()
{
	path += "\\" + DateTime::Now.ToString("dd-MMMM-yyyy-HH-mm-ss");
	Directory::CreateDirectory(path);
	log = gcnew StreamWriter(path + "\\log.log", false, Encoding::UTF8, 4096);
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
	if (log)
		log->Close();
	Buffer1->Clear();
	Buffer2->Clear();
	sb->Clear();
	pts->Clear();
	Esperar();
}

void Logger::recordData()
{
	try
	{
		if (buff) {
			sb->AppendLine(Buffer1[0]->visualize() + gps);
			for (int i = 1; i < Buffer1->Count; i++)
			{
				sb->AppendLine(Buffer1[i]->visualize());
			}
			log->Write(sb);
		}
		else {
			sb->AppendLine(Buffer2[0]->visualize() + gps);
			for (int i = 1; i < Buffer2->Count; i++)
			{
				sb->AppendLine(Buffer2[i]->visualize());
			}
			log->Write(sb);
		}
		sb->Clear();
		log->Flush();
	}
	catch (Exception^ e)
	{
		System::Windows::Forms::MessageBox::Show("Error al guardar los datos: " + e->Message, "Error", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
		if (log)
			log->Close();
		Buffer1->Clear();
		Buffer2->Clear();
		sb->Clear();
		pts->Clear();
		Esperar();
	}
}

void Logger::addToBuffer(List<Punto3D^>^ pointlist, String^ gps_in)
{
	pts->AddRange(pointlist);
	gps = gps_in;
}

void Logger::close()
{
	try
	{
		log->Close();
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
		sb->Clear();
	}
	catch (Exception^ e)
	{
		System::Windows::Forms::MessageBox::Show("Error al limpiar los buffers: " + e->Message, "Error", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
		if (log)
			log->Close();
		Buffer1->Clear();
		Buffer2->Clear();
		sb->Clear();
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
