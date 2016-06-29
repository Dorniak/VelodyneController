#pragma once
#include "../Parametros/Parametros.h"
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
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;

	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripLabel^  toolStripLabel1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripLabel^  toolStripLabel2;
			 String^ path_out;

#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Required method for Designer support - do not modify
			 /// the contents of this method with the code editor.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
				 this->textBox1 = (gcnew System::Windows::Forms::TextBox());
				 this->button1 = (gcnew System::Windows::Forms::Button());
				 this->textBox2 = (gcnew System::Windows::Forms::TextBox());
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
				 this->panel1 = (gcnew System::Windows::Forms::Panel());
				 this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
				 this->toolStripLabel1 = (gcnew System::Windows::Forms::ToolStripLabel());
				 this->button2 = (gcnew System::Windows::Forms::Button());
				 this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
				 this->toolStripLabel2 = (gcnew System::Windows::Forms::ToolStripLabel());
				 this->panel1->SuspendLayout();
				 this->toolStrip1->SuspendLayout();
				 this->SuspendLayout();
				 // 
				 // openFileDialog1
				 // 
				 this->openFileDialog1->FileName = L"openFileDialog1";
				 this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &PostProceso::openFileDialog1_FileOk);
				 // 
				 // textBox1
				 // 
				 this->textBox1->Location = System::Drawing::Point(12, 269);
				 this->textBox1->Multiline = true;
				 this->textBox1->Name = L"textBox1";
				 this->textBox1->Size = System::Drawing::Size(383, 199);
				 this->textBox1->TabIndex = 0;
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
				 // checkBox1
				 // 
				 this->checkBox1->AutoSize = true;
				 this->checkBox1->Dock = System::Windows::Forms::DockStyle::Fill;
				 this->checkBox1->Location = System::Drawing::Point(0, 0);
				 this->checkBox1->Name = L"checkBox1";
				 this->checkBox1->Size = System::Drawing::Size(412, 24);
				 this->checkBox1->TabIndex = 5;
				 this->checkBox1->Text = L"Separar Frames";
				 this->checkBox1->UseVisualStyleBackColor = true;
				 // 
				 // panel1
				 // 
				 this->panel1->Controls->Add(this->checkBox1);
				 this->panel1->Location = System::Drawing::Point(12, 32);
				 this->panel1->Name = L"panel1";
				 this->panel1->Size = System::Drawing::Size(412, 24);
				 this->panel1->TabIndex = 6;
				 // 
				 // toolStrip1
				 // 
				 this->toolStrip1->Dock = System::Windows::Forms::DockStyle::Bottom;
				 this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
					 this->toolStripLabel1,
						 this->toolStripSeparator1, this->toolStripLabel2
				 });
				 this->toolStrip1->Location = System::Drawing::Point(0, 471);
				 this->toolStrip1->Name = L"toolStrip1";
				 this->toolStrip1->Size = System::Drawing::Size(429, 25);
				 this->toolStrip1->TabIndex = 7;
				 this->toolStrip1->Text = L"toolStrip1";
				 // 
				 // toolStripLabel1
				 // 
				 this->toolStripLabel1->Name = L"toolStripLabel1";
				 this->toolStripLabel1->Size = System::Drawing::Size(56, 22);
				 this->toolStripLabel1->Text = L"Puntos: 0";
				 // 
				 // button2
				 // 
				 this->button2->Location = System::Drawing::Point(319, 224);
				 this->button2->Name = L"button2";
				 this->button2->Size = System::Drawing::Size(76, 39);
				 this->button2->TabIndex = 8;
				 this->button2->Text = L"button2";
				 this->button2->UseVisualStyleBackColor = true;
				 this->button2->Click += gcnew System::EventHandler(this, &PostProceso::button2_Click_1);
				 // 
				 // toolStripSeparator1
				 // 
				 this->toolStripSeparator1->Name = L"toolStripSeparator1";
				 this->toolStripSeparator1->Size = System::Drawing::Size(6, 25);
				 // 
				 // toolStripLabel2
				 // 
				 this->toolStripLabel2->Name = L"toolStripLabel2";
				 this->toolStripLabel2->Size = System::Drawing::Size(52, 22);
				 this->toolStripLabel2->Text = L"Frame: 0";
				 // 
				 // PostProceso
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(429, 496);
				 this->Controls->Add(this->button2);
				 this->Controls->Add(this->toolStrip1);
				 this->Controls->Add(this->panel1);
				 this->Controls->Add(this->label1);
				 this->Controls->Add(this->textBox2);
				 this->Controls->Add(this->button1);
				 this->Controls->Add(this->textBox1);
				 this->Name = L"PostProceso";
				 this->Text = L"PostProceso";
				 this->panel1->ResumeLayout(false);
				 this->panel1->PerformLayout();
				 this->toolStrip1->ResumeLayout(false);
				 this->toolStrip1->PerformLayout();
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
			 void Splitter() {
				 String^ linea = "";
				 Int64 frame = 0;
				 Int64 anterior = 0;
				 StreamReader^ file_in = File::OpenText(path_in);
				 StreamWriter^ file_out = File::CreateText(path_out + "Frame_" + frame + ".csv");
				 file_out->WriteLine("Azimuth,X,Y,Z,Distancia,Intensidad,Angulo,GPS");
				 while ((linea = file_in->ReadLine()) != nullptr) {
					 if (linea->Length > 5) {
						 frame = Convert::ToInt64(linea->Substring(0, linea->IndexOf(',')));
						 if (frame != anterior) {
							 anterior = frame;
							 file_out->Close();
							 toolStripLabel2->Text = "Frame" + frame;
							 file_out = File::CreateText(path_out + "Frame_" + frame + ".csv");
							 file_out->WriteLine("Azimuth,X,Y,Z,Distancia,Intensidad,Angulo,GPS");
						 }
						 file_out->WriteLine(linea->Substring(linea->IndexOf(',') + 1));
					 }
				 }
				 file_in->Close();
				 file_out->Close();
				 MessageBox::Show("Fin");
			 }

			 Int64 ContarLineas() {
				 StreamReader^ file = File::OpenText(path_in);
				 long lines = file->ReadToEnd()->Split('\n')->Length;
				 file->Close();
				 return lines;
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
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		textBox1->AppendText(path_in + "\n");
		textBox1->AppendText(path_out + "\n");
	}
	private: System::Void button2_Click_1(System::Object^  sender, System::EventArgs^  e) {
		Splitter();
	}

	};
}
