#pragma once
#include "../Parametros/Parametros.h"
#include <locale.h>
namespace FinalAppLidar {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for PostProceso
	/// </summary>
	public ref class PostProceso : public System::Windows::Forms::Form
	{
	public:
		PostProceso(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PostProceso()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		String^ path_in;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;

	private: System::Windows::Forms::Button^  button1;

	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label1;




	private: System::Windows::Forms::Button^  button2;


			 String^ path_out;

#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Required method for Designer support - do not modify
			 /// the contents of this method with the code editor.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
				 this->button1 = (gcnew System::Windows::Forms::Button());
				 this->textBox2 = (gcnew System::Windows::Forms::TextBox());
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->button2 = (gcnew System::Windows::Forms::Button());
				 this->SuspendLayout();
				 // 
				 // openFileDialog1
				 // 
				 this->openFileDialog1->FileName = L"openFileDialog1";
				 this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &PostProceso::openFileDialog1_FileOk);
				 // 
				 // button1
				 // 
				 this->button1->Location = System::Drawing::Point(349, 3);
				 this->button1->Name = L"button1";
				 this->button1->Size = System::Drawing::Size(75, 23);
				 this->button1->TabIndex = 1;
				 this->button1->Text = L"Buscar...";
				 this->button1->UseVisualStyleBackColor = true;
				 this->button1->Click += gcnew System::EventHandler(this, &PostProceso::button1_Click);
				 // 
				 // textBox2
				 // 
				 this->textBox2->Location = System::Drawing::Point(61, 6);
				 this->textBox2->Name = L"textBox2";
				 this->textBox2->Size = System::Drawing::Size(282, 20);
				 this->textBox2->TabIndex = 3;
				 // 
				 // label1
				 // 
				 this->label1->AutoSize = true;
				 this->label1->Location = System::Drawing::Point(9, 9);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(46, 13);
				 this->label1->TabIndex = 4;
				 this->label1->Text = L"Archivo:";
				 // 
				 // button2
				 // 
				 this->button2->Location = System::Drawing::Point(172, 64);
				 this->button2->Name = L"button2";
				 this->button2->Size = System::Drawing::Size(76, 39);
				 this->button2->TabIndex = 8;
				 this->button2->Text = L"bin -> txt";
				 this->button2->UseVisualStyleBackColor = true;
				 this->button2->Click += gcnew System::EventHandler(this, &PostProceso::button2_Click_1);
				 // 
				 // PostProceso
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(429, 125);
				 this->Controls->Add(this->button2);
				 this->Controls->Add(this->label1);
				 this->Controls->Add(this->textBox2);
				 this->Controls->Add(this->button1);
				 this->Name = L"PostProceso";
				 this->Text = L"PostProceso";
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
			 void Splitter() {
				 setlocale(LC_NUMERIC, "es_ES");
				 BinaryReader^ file_in = gcnew BinaryReader(File::OpenRead(path_in));
				 StreamWriter^ file_out = File::CreateText(path_out + "log.csv");
				 double x, y, z, az, ds, an;
				 long frame;
				 try
				 {
				 file_out->WriteLine("Frame,Azimuth,X,Y,Z,Distancia,Intensidad,Angulo");
					 //Por algún motivo se añaden exponentes extraños
					 while (file_in->PeekChar() != -1) {
						 frame = file_in->ReadInt32();
						 az = file_in->ReadDouble();
						 x = file_in->ReadDouble();
						 y = file_in->ReadDouble();
						 z = file_in->ReadDouble();
						 ds = file_in->ReadDouble();
						 an = file_in->ReadDouble();
						 file_out->WriteLine(frame.ToString()+","+az.ToString()+","+x.ToString()+","+y.ToString()+","+z.ToString()+","+ds.ToString()+","+an.ToString());
					 }
				 }
				 catch (Exception^)
				 {

				 }
				 file_in->Close();
				 file_out->Close();
				 MessageBox::Show("Fin");
			 }

#pragma endregion
	private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
		path_in = openFileDialog1->FileName;
		textBox2->Text = openFileDialog1->FileName;
		path_out = path_in->Substring(0, path_in->LastIndexOf('\\')) + "\\Procesado\\";
		try
		{
			Directory::CreateDirectory(path_out);
		}
		catch (Exception^)
		{
			MessageBox::Show("Error al crear el directorio " + path_out, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		//toolStripLabel1->Text = "Puntos: " + ContarLineas();
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		openFileDialog1->ShowDialog();
	}
	private: System::Void button2_Click_1(System::Object^  sender, System::EventArgs^  e) {
		Splitter();
	}

	};
}
