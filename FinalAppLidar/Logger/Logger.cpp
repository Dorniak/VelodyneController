#include "Logger.h"
#include "../Parametros/Parametros.h"


Logger::Logger()
{
	Buffer1 = gcnew List<Punto3D^>(14000);
	Buffer2 = gcnew List<Punto3D^>(14000);
	sb = gcnew StringBuilder(1000000);
	pts = Buffer1;
	gps = "";
	buff = false;
	THREAD_ON = true;
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
		}
		else
			Thread::Sleep(10);
	}
	if (log)
		log->Close();
	delete Buffer1;
	delete Buffer2;
	delete	sb;
	delete pts;
	delete log;
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
			Buffer1->Clear();
		}
		else {
			sb->AppendLine(Buffer2[0]->visualize() + gps);
			for (int i = 1; i < Buffer2->Count; i++)
			{
				sb->AppendLine(Buffer2[i]->visualize());
			}
			log->Write(sb);
			Buffer2->Clear();
		}
		sb->Clear();
	}
	catch (Exception^)
	{

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
void Logger::kill() {
	THREAD_ON = false;
}
