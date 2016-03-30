#pragma once
#include "Controller.h"
#include "PostProceso.h"
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
			Controlador = gcnew Controller(Consola);
			groupBox2->Visible = false;
			groupBox3->Visible = false;
			groupBox4->Visible = false;
			groupBox5->Visible = false;
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

	private:
		bool Iniciado = false;












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
	private: System::Windows::Forms::TextBox^  Consola;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  Minimo;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  Maximo;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TextBox^  textBox9;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::TextBox^  textBox10;
	private: System::Windows::Forms::Button^  button3;

	private: System::ComponentModel::IContainer^  components;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


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
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->Minimo = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->Maximo = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->Consola = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
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
			this->groupBox5->Location = System::Drawing::Point(3, 488);
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
			this->groupBox4->Location = System::Drawing::Point(3, 388);
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
			this->groupBox3->Location = System::Drawing::Point(3, 294);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(186, 94);
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
			this->flowLayoutPanel3->Size = System::Drawing::Size(180, 75);
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
			this->groupBox2->Size = System::Drawing::Size(186, 184);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Lector";
			// 
			// flowLayoutPanel2
			// 
			this->flowLayoutPanel2->Controls->Add(this->ActivarLector);
			this->flowLayoutPanel2->Controls->Add(this->ActivarLogs);
			this->flowLayoutPanel2->Controls->Add(this->button2);
			this->flowLayoutPanel2->Controls->Add(this->label3);
			this->flowLayoutPanel2->Controls->Add(this->Minimo);
			this->flowLayoutPanel2->Controls->Add(this->label5);
			this->flowLayoutPanel2->Controls->Add(this->Maximo);
			this->flowLayoutPanel2->Controls->Add(this->label6);
			this->flowLayoutPanel2->Controls->Add(this->textBox5);
			this->flowLayoutPanel2->Controls->Add(this->label7);
			this->flowLayoutPanel2->Controls->Add(this->textBox6);
			this->flowLayoutPanel2->Controls->Add(this->label8);
			this->flowLayoutPanel2->Controls->Add(this->textBox7);
			this->flowLayoutPanel2->Controls->Add(this->label9);
			this->flowLayoutPanel2->Controls->Add(this->textBox8);
			this->flowLayoutPanel2->Controls->Add(this->label10);
			this->flowLayoutPanel2->Controls->Add(this->textBox9);
			this->flowLayoutPanel2->Controls->Add(this->label11);
			this->flowLayoutPanel2->Controls->Add(this->textBox10);
			this->flowLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flowLayoutPanel2->Location = System::Drawing::Point(3, 16);
			this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
			this->flowLayoutPanel2->Size = System::Drawing::Size(180, 165);
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
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(3, 29);
			this->label3->Name = L"label3";
			this->label3->Padding = System::Windows::Forms::Padding(0, 5, 0, 0);
			this->label3->Size = System::Drawing::Size(42, 18);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Mínimo";
			// 
			// Minimo
			// 
			this->Minimo->Location = System::Drawing::Point(51, 32);
			this->Minimo->Name = L"Minimo";
			this->Minimo->Size = System::Drawing::Size(120, 20);
			this->Minimo->TabIndex = 4;
			this->Minimo->Text = L"0";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(3, 55);
			this->label5->Name = L"label5";
			this->label5->Padding = System::Windows::Forms::Padding(0, 5, 0, 0);
			this->label5->Size = System::Drawing::Size(43, 18);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Máximo";
			// 
			// Maximo
			// 
			this->Maximo->Location = System::Drawing::Point(52, 58);
			this->Maximo->Name = L"Maximo";
			this->Maximo->Size = System::Drawing::Size(119, 20);
			this->Maximo->TabIndex = 6;
			this->Maximo->Text = L"80";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(3, 81);
			this->label6->Name = L"label6";
			this->label6->Padding = System::Windows::Forms::Padding(0, 5, 0, 0);
			this->label6->Size = System::Drawing::Size(14, 18);
			this->label6->TabIndex = 7;
			this->label6->Text = L"X";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(23, 84);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(55, 20);
			this->textBox5->TabIndex = 8;
			this->textBox5->Text = L"0";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(84, 81);
			this->label7->Name = L"label7";
			this->label7->Padding = System::Windows::Forms::Padding(0, 5, 0, 0);
			this->label7->Size = System::Drawing::Size(15, 18);
			this->label7->TabIndex = 9;
			this->label7->Text = L"R";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(105, 84);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(55, 20);
			this->textBox6->TabIndex = 10;
			this->textBox6->Text = L"0";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(3, 107);
			this->label8->Name = L"label8";
			this->label8->Padding = System::Windows::Forms::Padding(0, 5, 0, 0);
			this->label8->Size = System::Drawing::Size(14, 18);
			this->label8->TabIndex = 11;
			this->label8->Text = L"Y";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(23, 110);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(55, 20);
			this->textBox7->TabIndex = 12;
			this->textBox7->Text = L"0";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(84, 107);
			this->label9->Name = L"label9";
			this->label9->Padding = System::Windows::Forms::Padding(0, 5, 0, 0);
			this->label9->Size = System::Drawing::Size(14, 18);
			this->label9->TabIndex = 13;
			this->label9->Text = L"P";
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(104, 110);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(56, 20);
			this->textBox8->TabIndex = 14;
			this->textBox8->Text = L"0";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(3, 133);
			this->label10->Name = L"label10";
			this->label10->Padding = System::Windows::Forms::Padding(0, 5, 0, 0);
			this->label10->Size = System::Drawing::Size(14, 18);
			this->label10->TabIndex = 15;
			this->label10->Text = L"Z";
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(23, 136);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(55, 20);
			this->textBox9->TabIndex = 16;
			this->textBox9->Text = L"0";
			// 
			// label11
			// 
			this->label11->Location = System::Drawing::Point(84, 133);
			this->label11->Name = L"label11";
			this->label11->Padding = System::Windows::Forms::Padding(0, 5, 0, 0);
			this->label11->Size = System::Drawing::Size(14, 18);
			this->label11->TabIndex = 17;
			this->label11->Text = L"W";
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(104, 136);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(56, 20);
			this->textBox10->TabIndex = 18;
			this->textBox10->Text = L"0";
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
			this->textBox1->Text = L"192.168.1.201";
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
			this->textBox2->Text = L"2368";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(3, 55);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(174, 23);
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
			// Consola
			// 
			this->Consola->Location = System::Drawing::Point(430, 64);
			this->Consola->Multiline = true;
			this->Consola->Name = L"Consola";
			this->Consola->Size = System::Drawing::Size(598, 235);
			this->Consola->TabIndex = 3;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(299, 66);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 4;
			this->button3->Text = L"button3";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Main::button3_Click);
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1294, 726);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->Consola);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->toolStrip1);
			this->Name = L"Main";
			this->Text = L"LidarController";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Main::Main_FormClosing);
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
			Controlador->ArrayDataReader[Pmin] = Convert::ToDouble(Minimo->Text);
			Controlador->ArrayDataReader[Pmax] = Convert::ToDouble(Maximo->Text);
			Controlador->ArrayDataReader[PCALIBRATE_X] = Convert::ToDouble(textBox5->Text);
			Controlador->ArrayDataReader[PCALIBRATE_Y] = Convert::ToDouble(textBox7->Text);
			Controlador->ArrayDataReader[PCALIBRATE_Z] = Convert::ToDouble(textBox9->Text);
			Controlador->ArrayDataReader[PCALIBRATE_R] = Convert::ToDouble(textBox6->Text);
			Controlador->ArrayDataReader[PCALIBRATE_P] = Convert::ToDouble(textBox8->Text);
			Controlador->ArrayDataReader[PCALIBRATE_W] = Convert::ToDouble(textBox10->Text);

			ActivarLector->BackColor = System::Drawing::Color::PaleGreen;
			if (!Iniciado) {
				Controlador->Iniciar();
				Iniciado = true;
			}
			Controlador->reActivar();

			//Bloquear botones al pulsar el activar
			ActivarOpenGl->Enabled = false;


		}
		else {
			ActivarLector->BackColor = System::Drawing::Color::IndianRed;
			Controlador->Parar();
		}

		//TODO: MANDAR A CONTROL 

	}
	private: System::Void ActivarLogs_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (ActivarLogs->Checked) {
			ActivarLogs->BackColor = System::Drawing::Color::PaleGreen;
			Controlador->Flags[FlagLogOn] = true;
		}
		else {
			ActivarLogs->BackColor = System::Drawing::Color::IndianRed;
			Controlador->Flags[FlagLogOn] = false;
		}
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
		Controlador->ArrayDataReader[Ppath] = folderBrowserDialog1->SelectedPath;
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		try
		{
			IPAddress^ lidarIP = IPAddress::Parse(textBox1->Text);
			IPEndPoint^ Connect = gcnew IPEndPoint(IPAddress::Any, Convert::ToInt32(textBox2->Text));//0xC901A8C0   IPAddress::Any
			Controlador->ArrayDataReader[Ip] = Connect;
			UdpClient^ Client = gcnew UdpClient(Connect);
			if (true) {//Client->Available > 0
				button1->BackColor = System::Drawing::Color::PaleGreen;
				groupBox5->Visible = true;
				groupBox4->Visible = true;
				groupBox3->Visible = true;
				groupBox2->Visible = true;
			}
			else {
				button1->BackColor = System::Drawing::Color::IndianRed;
			}
			Client->Close();
			delete Client;
		}
		catch (Exception^ e)
		{
			System::Windows::Forms::MessageBox::Show(e->ToString());
		}

	}
	private: System::Void Main_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {

		for (int i = 0; i < Controlador->Threads->Length; i++)
		{
			if (Controlador->Threads[i])
				Controlador->Threads[i]->Abort();
		}
	}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	PostProceso^ p = gcnew PostProceso();
	p->Show();
}
};
}