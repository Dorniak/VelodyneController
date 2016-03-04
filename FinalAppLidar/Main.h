#pragma once
#include "Controller.h"
//Vector de flags
#define FlagTratamiento 0
#define FlagTratamiento 1
#define FlagTratamiento 2
#define FlagTratamiento 3
#define FlagWarning 4
#define FlagPausa 5
#define FlagAnalisysOn 6
#define FlagOpenGlOn 7
#define FlagLogOn 8

namespace FinalAppLidar {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Main
	/// </summary>
	public ref class Main : public System::Windows::Forms::Form
	{
	public:
		Main(void)
		{
			InitializeComponent();
			Controlador = gcnew Controller();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:












	private: Controller^ Controlador;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton1;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel2;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::CheckBox^  ActivarLector;
	private: System::Windows::Forms::CheckBox^  ActivarLogs;
	private: System::Windows::Forms::GroupBox^  groupBox5;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel5;
	private: System::Windows::Forms::CheckBox^  ActivarOpenGl;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel4;
	private: System::Windows::Forms::CheckBox^  ActivarGPS;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel3;
	private: System::Windows::Forms::CheckBox^  ActivarAnalisys;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog1;
	private: System::Windows::Forms::TextBox^  textBox3;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox4;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Main::typeid));
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->flowLayoutPanel5 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->ActivarOpenGl = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->flowLayoutPanel4 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->ActivarGPS = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->flowLayoutPanel3 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->ActivarAnalisys = (gcnew System::Windows::Forms::CheckBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->flowLayoutPanel2 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->ActivarLector = (gcnew System::Windows::Forms::CheckBox());
			this->ActivarLogs = (gcnew System::Windows::Forms::CheckBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->toolStrip1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->flowLayoutPanel5->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->flowLayoutPanel4->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->flowLayoutPanel3->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->flowLayoutPanel2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->flowLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// toolStrip1
			// 
			this->toolStrip1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripButton1 });
			this->toolStrip1->Location = System::Drawing::Point(0, 701);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(1294, 25);
			this->toolStrip1->TabIndex = 1;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripButton1
			// 
			this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton1.Image")));
			this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton1->Name = L"toolStripButton1";
			this->toolStripButton1->Size = System::Drawing::Size(23, 22);
			this->toolStripButton1->Text = L"toolStripButton1";
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Left;
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(200, 701);
			this->tabControl1->TabIndex = 2;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->groupBox5);
			this->tabPage1->Controls->Add(this->groupBox4);
			this->tabPage1->Controls->Add(this->groupBox3);
			this->tabPage1->Controls->Add(this->groupBox2);
			this->tabPage1->Controls->Add(this->groupBox1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(192, 675);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Lidar";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->flowLayoutPanel5);
			this->groupBox5->Dock = System::Windows::Forms::DockStyle::Top;
			this->groupBox5->Location = System::Drawing::Point(3, 460);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(186, 100);
			this->groupBox5->TabIndex = 4;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Visor";
			// 
			// flowLayoutPanel5
			// 
			this->flowLayoutPanel5->Controls->Add(this->ActivarOpenGl);
			this->flowLayoutPanel5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flowLayoutPanel5->Location = System::Drawing::Point(3, 16);
			this->flowLayoutPanel5->Name = L"flowLayoutPanel5";
			this->flowLayoutPanel5->Size = System::Drawing::Size(180, 81);
			this->flowLayoutPanel5->TabIndex = 0;
			// 
			// ActivarOpenGl
			// 
			this->ActivarOpenGl->Appearance = System::Windows::Forms::Appearance::Button;
			this->ActivarOpenGl->AutoSize = true;
			this->ActivarOpenGl->BackColor = System::Drawing::Color::IndianRed;
			this->ActivarOpenGl->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ActivarOpenGl->Location = System::Drawing::Point(3, 3);
			this->ActivarOpenGl->Name = L"ActivarOpenGl";
			this->ActivarOpenGl->Size = System::Drawing::Size(50, 23);
			this->ActivarOpenGl->TabIndex = 1;
			this->ActivarOpenGl->Text = L"Activar";
			this->ActivarOpenGl->UseVisualStyleBackColor = false;
			this->ActivarOpenGl->CheckedChanged += gcnew System::EventHandler(this, &Main::ActivarOpenGl_CheckedChanged);
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->flowLayoutPanel4);
			this->groupBox4->Dock = System::Windows::Forms::DockStyle::Top;
			this->groupBox4->Location = System::Drawing::Point(3, 360);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(186, 100);
			this->groupBox4->TabIndex = 3;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"GPS";
			// 
			// flowLayoutPanel4
			// 
			this->flowLayoutPanel4->Controls->Add(this->ActivarGPS);
			this->flowLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flowLayoutPanel4->Location = System::Drawing::Point(3, 16);
			this->flowLayoutPanel4->Name = L"flowLayoutPanel4";
			this->flowLayoutPanel4->Size = System::Drawing::Size(180, 81);
			this->flowLayoutPanel4->TabIndex = 0;
			// 
			// ActivarGPS
			// 
			this->ActivarGPS->Appearance = System::Windows::Forms::Appearance::Button;
			this->ActivarGPS->AutoSize = true;
			this->ActivarGPS->BackColor = System::Drawing::Color::IndianRed;
			this->ActivarGPS->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ActivarGPS->Location = System::Drawing::Point(3, 3);
			this->ActivarGPS->Name = L"ActivarGPS";
			this->ActivarGPS->Size = System::Drawing::Size(50, 23);
			this->ActivarGPS->TabIndex = 1;
			this->ActivarGPS->Text = L"Activar";
			this->ActivarGPS->UseVisualStyleBackColor = false;
			this->ActivarGPS->CheckedChanged += gcnew System::EventHandler(this, &Main::ActivarGPS_CheckedChanged);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->flowLayoutPanel3);
			this->groupBox3->Dock = System::Windows::Forms::DockStyle::Top;
			this->groupBox3->Location = System::Drawing::Point(3, 260);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(186, 100);
			this->groupBox3->TabIndex = 2;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Análisis";
			// 
			// flowLayoutPanel3
			// 
			this->flowLayoutPanel3->Controls->Add(this->ActivarAnalisys);
			this->flowLayoutPanel3->Controls->Add(this->label4);
			this->flowLayoutPanel3->Controls->Add(this->textBox4);
			this->flowLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flowLayoutPanel3->Location = System::Drawing::Point(3, 16);
			this->flowLayoutPanel3->Name = L"flowLayoutPanel3";
			this->flowLayoutPanel3->Size = System::Drawing::Size(180, 81);
			this->flowLayoutPanel3->TabIndex = 0;
			// 
			// ActivarAnalisys
			// 
			this->ActivarAnalisys->Appearance = System::Windows::Forms::Appearance::Button;
			this->ActivarAnalisys->AutoSize = true;
			this->ActivarAnalisys->BackColor = System::Drawing::Color::IndianRed;
			this->ActivarAnalisys->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ActivarAnalisys->Location = System::Drawing::Point(3, 3);
			this->ActivarAnalisys->Name = L"ActivarAnalisys";
			this->ActivarAnalisys->Size = System::Drawing::Size(50, 23);
			this->ActivarAnalisys->TabIndex = 1;
			this->ActivarAnalisys->Text = L"Activar";
			this->ActivarAnalisys->UseVisualStyleBackColor = false;
			this->ActivarAnalisys->CheckedChanged += gcnew System::EventHandler(this, &Main::ActivarAnalisys_CheckedChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(59, 0);
			this->label4->Name = L"label4";
			this->label4->Padding = System::Windows::Forms::Padding(0, 8, 0, 0);
			this->label4->Size = System::Drawing::Size(63, 21);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Frecuencia:";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(128, 3);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(28, 20);
			this->textBox4->TabIndex = 4;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->flowLayoutPanel2);
			this->groupBox2->Dock = System::Windows::Forms::DockStyle::Top;
			this->groupBox2->Location = System::Drawing::Point(3, 110);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(186, 150);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Lector";
			// 
			// flowLayoutPanel2
			// 
			this->flowLayoutPanel2->Controls->Add(this->ActivarLector);
			this->flowLayoutPanel2->Controls->Add(this->ActivarLogs);
			this->flowLayoutPanel2->Controls->Add(this->button2);
			this->flowLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flowLayoutPanel2->Location = System::Drawing::Point(3, 16);
			this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
			this->flowLayoutPanel2->Size = System::Drawing::Size(180, 131);
			this->flowLayoutPanel2->TabIndex = 0;
			// 
			// ActivarLector
			// 
			this->ActivarLector->Appearance = System::Windows::Forms::Appearance::Button;
			this->ActivarLector->AutoSize = true;
			this->ActivarLector->BackColor = System::Drawing::Color::IndianRed;
			this->ActivarLector->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ActivarLector->Location = System::Drawing::Point(3, 3);
			this->ActivarLector->Name = L"ActivarLector";
			this->ActivarLector->Size = System::Drawing::Size(50, 23);
			this->ActivarLector->TabIndex = 0;
			this->ActivarLector->Text = L"Activar";
			this->ActivarLector->UseVisualStyleBackColor = false;
			this->ActivarLector->CheckedChanged += gcnew System::EventHandler(this, &Main::ActivarLector_CheckedChanged);
			// 
			// ActivarLogs
			// 
			this->ActivarLogs->Appearance = System::Windows::Forms::Appearance::Button;
			this->ActivarLogs->AutoSize = true;
			this->ActivarLogs->BackColor = System::Drawing::Color::IndianRed;
			this->ActivarLogs->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ActivarLogs->Location = System::Drawing::Point(59, 3);
			this->ActivarLogs->Name = L"ActivarLogs";
			this->ActivarLogs->Size = System::Drawing::Size(40, 23);
			this->ActivarLogs->TabIndex = 1;
			this->ActivarLogs->Text = L"Logs";
			this->ActivarLogs->UseVisualStyleBackColor = false;
			this->ActivarLogs->CheckedChanged += gcnew System::EventHandler(this, &Main::ActivarLogs_CheckedChanged);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(105, 3);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(72, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Directorio";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Main::button2_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->flowLayoutPanel1);
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Top;
			this->groupBox1->Location = System::Drawing::Point(3, 3);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(186, 107);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Conexión";
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Controls->Add(this->label1);
			this->flowLayoutPanel1->Controls->Add(this->textBox1);
			this->flowLayoutPanel1->Controls->Add(this->label2);
			this->flowLayoutPanel1->Controls->Add(this->textBox2);
			this->flowLayoutPanel1->Controls->Add(this->button1);
			this->flowLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flowLayoutPanel1->Location = System::Drawing::Point(3, 16);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(180, 88);
			this->flowLayoutPanel1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 0);
			this->label1->Name = L"label1";
			this->label1->Padding = System::Windows::Forms::Padding(0, 5, 0, 0);
			this->label1->Size = System::Drawing::Size(20, 18);
			this->label1->TabIndex = 0;
			this->label1->Text = L"IP:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(29, 3);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(127, 20);
			this->textBox1->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(3, 26);
			this->label2->Name = L"label2";
			this->label2->Padding = System::Windows::Forms::Padding(0, 5, 0, 0);
			this->label2->Size = System::Drawing::Size(41, 18);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Puerto:";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(50, 29);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 3;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(3, 55);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Conectar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Main::button1_Click);
			// 
			// tabPage2
			// 
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(192, 675);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Visor";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(438, 89);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(598, 235);
			this->textBox3->TabIndex = 3;
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1294, 726);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->toolStrip1);
			this->Name = L"Main";
			this->Text = L"LidarController";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->groupBox5->ResumeLayout(false);
			this->flowLayoutPanel5->ResumeLayout(false);
			this->flowLayoutPanel5->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->flowLayoutPanel4->ResumeLayout(false);
			this->flowLayoutPanel4->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->flowLayoutPanel3->ResumeLayout(false);
			this->flowLayoutPanel3->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->flowLayoutPanel2->ResumeLayout(false);
			this->flowLayoutPanel2->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->flowLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void ActivarLector_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (ActivarLector->Checked) {
			ActivarLector->BackColor = System::Drawing::Color::PaleGreen;
			Controlador->reActivar();
		}
		else {
			ActivarLector->BackColor = System::Drawing::Color::IndianRed;
			Controlador->Parar();
		}

		//TODO: MANDAR A CONTROL 

	}
	private: System::Void ActivarLogs_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (ActivarLogs->Checked)
			ActivarLogs->BackColor = System::Drawing::Color::PaleGreen;
		else
			ActivarLogs->BackColor = System::Drawing::Color::IndianRed;
		//TODO: MANDAR A CONTROL //TODO: MANDAR A CONTROL 
	}
	private: System::Void ActivarGPS_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (ActivarGPS->Checked)
			ActivarGPS->BackColor = System::Drawing::Color::PaleGreen;
		else
			ActivarGPS->BackColor = System::Drawing::Color::IndianRed;
		//TODO: MANDAR A CONTROL 
	}
	private: System::Void ActivarAnalisys_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (ActivarAnalisys->Checked)
		{
			ActivarAnalisys->BackColor = System::Drawing::Color::PaleGreen;
			Controlador->Flags[FlagAnalisysOn] = true;
		}
		else
		{
			ActivarAnalisys->BackColor = System::Drawing::Color::IndianRed;
			Controlador->Flags[FlagAnalisysOn] = false;
		}
		//TODO: MANDAR A CONTROL 

	}
	private: System::Void ActivarOpenGl_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (ActivarOpenGl->Checked) {
			ActivarOpenGl->BackColor = System::Drawing::Color::PaleGreen;
			Controlador->Flags[FlagOpenGlOn] = true;
		}
		else {
			ActivarOpenGl->BackColor = System::Drawing::Color::IndianRed;
			Controlador->Flags[FlagOpenGlOn] = false;
		}
	}

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		System::Windows::Forms::DialogResult result = folderBrowserDialog1->ShowDialog();
		//TODO: MANDAR A CONTROL 
		textBox3->Text = folderBrowserDialog1->SelectedPath;

	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		IPEndPoint^ Connect = gcnew IPEndPoint(0xC901A8C0, Convert::ToInt32(textBox2->Text));
		textBox3->Text = Connect->Address->ToString();
		Controlador->ArrayDataReader[Ip] = Connect;
	}
	};
}