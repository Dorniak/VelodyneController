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
			Controlador = gcnew Controller();
			Controlador->ArrayGps[START] = false;
			Controlador->ArrayGps[TIPO_TRAMA] = "";
			Controlador->ArrayGps[TRAMA] = "";
			Controlador->ArrayGps[COM] = "COM1";
			gps = gcnew	Gps(Controlador->ArrayGps, Controlador->Threads);
			Dibujador = gcnew OpenGl(Controlador->Threads);
			Reader = gcnew DataReader(Controlador->Puntos, Controlador->ArrayDataReader, Controlador->Flags, Controlador->Threads, Dibujador, Controlador->ArrayGps);
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


	private: Gps^ gps;
	private: DataReader^ Reader;
	private: Controller^ Controlador;
	private: OpenGl^ Dibujador;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;

	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel2;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;


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

	private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog1;
	private: System::Windows::Forms::TextBox^  Consola;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox4;

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
	private: System::Windows::Forms::TrackBar^  trackBar1;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;






	private: System::Windows::Forms::Timer^  timer2;
	private: System::Windows::Forms::ImageList^  imageList1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::ComboBox^  comboBox1;

	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Timer^  timer3;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Label^  label1;
private: System::Windows::Forms::ToolStripLabel^  toolStripLabel1;
private: System::Windows::Forms::ToolStripLabel^  toolStripLabel2;
private: System::Windows::Forms::ToolStripLabel^  toolStripLabel3;
private: System::Windows::Forms::ToolStripLabel^  toolStripLabel4;
private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;



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
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Main::typeid));
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripLabel1 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->toolStripLabel2 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->flowLayoutPanel5 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->ActivarOpenGl = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->flowLayoutPanel4 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->ActivarGPS = (gcnew System::Windows::Forms::CheckBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->flowLayoutPanel3 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->ActivarAnalisys = (gcnew System::Windows::Forms::CheckBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->flowLayoutPanel2 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->ActivarLector = (gcnew System::Windows::Forms::CheckBox());
			this->ActivarLogs = (gcnew System::Windows::Forms::CheckBox());
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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->Consola = (gcnew System::Windows::Forms::TextBox());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->timer3 = (gcnew System::Windows::Forms::Timer(this->components));
			this->toolStripLabel3 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->toolStripLabel4 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStrip1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->flowLayoutPanel5->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->flowLayoutPanel4->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->flowLayoutPanel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->flowLayoutPanel2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->flowLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// toolStrip1
			// 
			this->toolStrip1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->toolStripLabel1,
					this->toolStripLabel2, this->toolStripLabel3, this->toolStripLabel4, this->toolStripSeparator1
			});
			this->toolStrip1->Location = System::Drawing::Point(0, 708);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(1222, 25);
			this->toolStrip1->TabIndex = 1;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripLabel1
			// 
			this->toolStripLabel1->Name = L"toolStripLabel1";
			this->toolStripLabel1->Size = System::Drawing::Size(93, 22);
			this->toolStripLabel1->Text = L"Frecuencia: 0 Hz";
			// 
			// toolStripLabel2
			// 
			this->toolStripLabel2->Name = L"toolStripLabel2";
			this->toolStripLabel2->Size = System::Drawing::Size(71, 22);
			this->toolStripLabel2->Text = L"Lector: 0 ms";
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Left;
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(200, 708);
			this->tabControl1->TabIndex = 2;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->label14);
			this->tabPage1->Controls->Add(this->button3);
			this->tabPage1->Controls->Add(this->groupBox5);
			this->tabPage1->Controls->Add(this->groupBox4);
			this->tabPage1->Controls->Add(this->groupBox3);
			this->tabPage1->Controls->Add(this->groupBox2);
			this->tabPage1->Controls->Add(this->groupBox1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(192, 682);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Lidar";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Dock = System::Windows::Forms::DockStyle::Top;
			this->label14->Location = System::Drawing::Point(3, 711);
			this->label14->Name = L"label14";
			this->label14->Padding = System::Windows::Forms::Padding(35, 0, 0, 0);
			this->label14->Size = System::Drawing::Size(152, 13);
			this->label14->TabIndex = 4;
			this->label14->Text = L"Procesado de Archivos";
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Transparent;
			this->button3->Dock = System::Windows::Forms::DockStyle::Top;
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->ImageIndex = 9;
			this->button3->ImageList = this->imageList1;
			this->button3->Location = System::Drawing::Point(3, 671);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(186, 40);
			this->button3->TabIndex = 4;
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Main::button3_Click);
			// 
			// imageList1
			// 
			this->imageList1->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^>(resources->GetObject(L"imageList1.ImageStream")));
			this->imageList1->TransparentColor = System::Drawing::Color::Transparent;
			this->imageList1->Images->SetKeyName(0, L"conenct.png");
			this->imageList1->Images->SetKeyName(1, L"disconenct.png");
			this->imageList1->Images->SetKeyName(2, L"noun_419262_cc.png");
			this->imageList1->Images->SetKeyName(3, L"noun_122890_cc.png");
			this->imageList1->Images->SetKeyName(4, L"noun_111371_cc.png");
			this->imageList1->Images->SetKeyName(5, L"fhfg.png");
			this->imageList1->Images->SetKeyName(6, L"noun_216295_cc.png");
			this->imageList1->Images->SetKeyName(7, L"noun_216296_cc.png");
			this->imageList1->Images->SetKeyName(8, L"noun_18974_cc.png");
			this->imageList1->Images->SetKeyName(9, L"noun_7991_cc.png");
			this->imageList1->Images->SetKeyName(10, L"noun_5350_cc.png");
			this->imageList1->Images->SetKeyName(11, L"signal0.png");
			this->imageList1->Images->SetKeyName(12, L"signal1.png");
			this->imageList1->Images->SetKeyName(13, L"signal2.png");
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->flowLayoutPanel5);
			this->groupBox5->Dock = System::Windows::Forms::DockStyle::Top;
			this->groupBox5->Location = System::Drawing::Point(3, 571);
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
			this->ActivarOpenGl->BackColor = System::Drawing::Color::Transparent;
			this->ActivarOpenGl->FlatAppearance->BorderSize = 0;
			this->ActivarOpenGl->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ActivarOpenGl->ImageIndex = 7;
			this->ActivarOpenGl->ImageList = this->imageList1;
			this->ActivarOpenGl->Location = System::Drawing::Point(3, 3);
			this->ActivarOpenGl->Name = L"ActivarOpenGl";
			this->ActivarOpenGl->Size = System::Drawing::Size(38, 38);
			this->ActivarOpenGl->TabIndex = 1;
			this->ActivarOpenGl->UseVisualStyleBackColor = false;
			this->ActivarOpenGl->CheckedChanged += gcnew System::EventHandler(this, &Main::ActivarOpenGl_CheckedChanged);
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->flowLayoutPanel4);
			this->groupBox4->Dock = System::Windows::Forms::DockStyle::Top;
			this->groupBox4->Location = System::Drawing::Point(3, 441);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(186, 130);
			this->groupBox4->TabIndex = 3;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"GPS";
			// 
			// flowLayoutPanel4
			// 
			this->flowLayoutPanel4->Controls->Add(this->ActivarGPS);
			this->flowLayoutPanel4->Controls->Add(this->label15);
			this->flowLayoutPanel4->Controls->Add(this->comboBox1);
			this->flowLayoutPanel4->Controls->Add(this->button4);
			this->flowLayoutPanel4->Controls->Add(this->label16);
			this->flowLayoutPanel4->Controls->Add(this->comboBox2);
			this->flowLayoutPanel4->Controls->Add(this->label1);
			this->flowLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flowLayoutPanel4->Location = System::Drawing::Point(3, 16);
			this->flowLayoutPanel4->Name = L"flowLayoutPanel4";
			this->flowLayoutPanel4->Size = System::Drawing::Size(180, 111);
			this->flowLayoutPanel4->TabIndex = 0;
			// 
			// ActivarGPS
			// 
			this->ActivarGPS->Appearance = System::Windows::Forms::Appearance::Button;
			this->ActivarGPS->AutoSize = true;
			this->ActivarGPS->BackColor = System::Drawing::Color::Transparent;
			this->ActivarGPS->FlatAppearance->BorderSize = 0;
			this->ActivarGPS->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ActivarGPS->ImageIndex = 7;
			this->ActivarGPS->ImageList = this->imageList1;
			this->ActivarGPS->Location = System::Drawing::Point(3, 3);
			this->ActivarGPS->Name = L"ActivarGPS";
			this->ActivarGPS->Size = System::Drawing::Size(38, 38);
			this->ActivarGPS->TabIndex = 1;
			this->ActivarGPS->UseVisualStyleBackColor = false;
			this->ActivarGPS->CheckedChanged += gcnew System::EventHandler(this, &Main::ActivarGPS_CheckedChanged);
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(47, 0);
			this->label15->Name = L"label15";
			this->label15->Padding = System::Windows::Forms::Padding(0, 13, 0, 0);
			this->label15->Size = System::Drawing::Size(38, 26);
			this->label15->TabIndex = 4;
			this->label15->Text = L"Puerto";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(91, 6);
			this->comboBox1->Margin = System::Windows::Forms::Padding(3, 6, 3, 3);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(77, 21);
			this->comboBox1->TabIndex = 2;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Main::comboBox1_SelectedIndexChanged);
			// 
			// button4
			// 
			this->button4->AutoSize = true;
			this->button4->FlatAppearance->BorderSize = 0;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->ImageIndex = 10;
			this->button4->ImageList = this->imageList1;
			this->button4->Location = System::Drawing::Point(3, 47);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(48, 38);
			this->button4->TabIndex = 6;
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Main::button4_Click);
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(54, 44);
			this->label16->Margin = System::Windows::Forms::Padding(0);
			this->label16->Name = L"label16";
			this->label16->Padding = System::Windows::Forms::Padding(0, 10, 0, 0);
			this->label16->Size = System::Drawing::Size(37, 23);
			this->label16->TabIndex = 5;
			this->label16->Text = L"Trama";
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"GPGGA", L"GPRMC", L"GPVTG" });
			this->comboBox2->Location = System::Drawing::Point(94, 47);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(75, 21);
			this->comboBox2->TabIndex = 3;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &Main::comboBox2_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 88);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(53, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Satélites: ";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->flowLayoutPanel3);
			this->groupBox3->Dock = System::Windows::Forms::DockStyle::Top;
			this->groupBox3->Location = System::Drawing::Point(3, 292);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(186, 149);
			this->groupBox3->TabIndex = 2;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Análisis";
			// 
			// flowLayoutPanel3
			// 
			this->flowLayoutPanel3->Controls->Add(this->ActivarAnalisys);
			this->flowLayoutPanel3->Controls->Add(this->label4);
			this->flowLayoutPanel3->Controls->Add(this->textBox4);
			this->flowLayoutPanel3->Controls->Add(this->label12);
			this->flowLayoutPanel3->Controls->Add(this->trackBar1);
			this->flowLayoutPanel3->Controls->Add(this->label13);
			this->flowLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flowLayoutPanel3->Location = System::Drawing::Point(3, 16);
			this->flowLayoutPanel3->Name = L"flowLayoutPanel3";
			this->flowLayoutPanel3->Size = System::Drawing::Size(180, 130);
			this->flowLayoutPanel3->TabIndex = 0;
			// 
			// ActivarAnalisys
			// 
			this->ActivarAnalisys->Appearance = System::Windows::Forms::Appearance::Button;
			this->ActivarAnalisys->AutoSize = true;
			this->ActivarAnalisys->BackColor = System::Drawing::Color::Transparent;
			this->ActivarAnalisys->FlatAppearance->BorderSize = 0;
			this->ActivarAnalisys->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ActivarAnalisys->ImageIndex = 7;
			this->ActivarAnalisys->ImageList = this->imageList1;
			this->ActivarAnalisys->Location = System::Drawing::Point(3, 3);
			this->ActivarAnalisys->Name = L"ActivarAnalisys";
			this->ActivarAnalisys->Size = System::Drawing::Size(38, 38);
			this->ActivarAnalisys->TabIndex = 1;
			this->ActivarAnalisys->UseVisualStyleBackColor = false;
			this->ActivarAnalisys->CheckedChanged += gcnew System::EventHandler(this, &Main::ActivarAnalisys_CheckedChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(47, 0);
			this->label4->Name = L"label4";
			this->label4->Padding = System::Windows::Forms::Padding(0, 16, 0, 0);
			this->label4->Size = System::Drawing::Size(63, 29);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Frecuencia:";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(116, 10);
			this->textBox4->Margin = System::Windows::Forms::Padding(3, 10, 3, 3);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(28, 20);
			this->textBox4->TabIndex = 4;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(3, 44);
			this->label12->Name = L"label12";
			this->label12->Padding = System::Windows::Forms::Padding(0, 5, 0, 0);
			this->label12->Size = System::Drawing::Size(57, 18);
			this->label12->TabIndex = 5;
			this->label12->Text = L"Tolerancia";
			// 
			// trackBar1
			// 
			this->trackBar1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->trackBar1->Location = System::Drawing::Point(3, 65);
			this->trackBar1->Maximum = 100;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(174, 45);
			this->trackBar1->TabIndex = 5;
			this->trackBar1->TickStyle = System::Windows::Forms::TickStyle::Both;
			this->trackBar1->Value = 10;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &Main::trackBar1_Scroll);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(3, 113);
			this->label13->Name = L"label13";
			this->label13->Padding = System::Windows::Forms::Padding(10, 0, 0, 0);
			this->label13->Size = System::Drawing::Size(40, 13);
			this->label13->TabIndex = 6;
			this->label13->Text = L"10 %";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->flowLayoutPanel2);
			this->groupBox2->Dock = System::Windows::Forms::DockStyle::Top;
			this->groupBox2->Location = System::Drawing::Point(3, 95);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(186, 197);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Lector";
			// 
			// flowLayoutPanel2
			// 
			this->flowLayoutPanel2->Controls->Add(this->ActivarLector);
			this->flowLayoutPanel2->Controls->Add(this->ActivarLogs);
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
			this->flowLayoutPanel2->Size = System::Drawing::Size(180, 178);
			this->flowLayoutPanel2->TabIndex = 0;
			// 
			// ActivarLector
			// 
			this->ActivarLector->Appearance = System::Windows::Forms::Appearance::Button;
			this->ActivarLector->AutoSize = true;
			this->ActivarLector->BackColor = System::Drawing::Color::Transparent;
			this->ActivarLector->Dock = System::Windows::Forms::DockStyle::Right;
			this->ActivarLector->FlatAppearance->BorderSize = 0;
			this->ActivarLector->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ActivarLector->ImageIndex = 2;
			this->ActivarLector->ImageList = this->imageList1;
			this->ActivarLector->Location = System::Drawing::Point(3, 3);
			this->ActivarLector->Name = L"ActivarLector";
			this->ActivarLector->Size = System::Drawing::Size(38, 38);
			this->ActivarLector->TabIndex = 0;
			this->ActivarLector->UseVisualStyleBackColor = false;
			this->ActivarLector->CheckedChanged += gcnew System::EventHandler(this, &Main::ActivarLector_CheckedChanged);
			// 
			// ActivarLogs
			// 
			this->ActivarLogs->Appearance = System::Windows::Forms::Appearance::Button;
			this->ActivarLogs->AutoSize = true;
			this->ActivarLogs->BackColor = System::Drawing::Color::Transparent;
			this->ActivarLogs->FlatAppearance->BorderSize = 0;
			this->ActivarLogs->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->flowLayoutPanel2->SetFlowBreak(this->ActivarLogs, true);
			this->ActivarLogs->ImageIndex = 4;
			this->ActivarLogs->ImageList = this->imageList1;
			this->ActivarLogs->Location = System::Drawing::Point(47, 3);
			this->ActivarLogs->Name = L"ActivarLogs";
			this->ActivarLogs->Size = System::Drawing::Size(38, 38);
			this->ActivarLogs->TabIndex = 1;
			this->ActivarLogs->UseVisualStyleBackColor = false;
			this->ActivarLogs->CheckedChanged += gcnew System::EventHandler(this, &Main::ActivarLogs_CheckedChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(3, 44);
			this->label3->Name = L"label3";
			this->label3->Padding = System::Windows::Forms::Padding(0, 5, 0, 0);
			this->label3->Size = System::Drawing::Size(42, 18);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Mínimo";
			// 
			// Minimo
			// 
			this->Minimo->Location = System::Drawing::Point(51, 47);
			this->Minimo->Name = L"Minimo";
			this->Minimo->Size = System::Drawing::Size(120, 20);
			this->Minimo->TabIndex = 4;
			this->Minimo->Text = L"0";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(3, 70);
			this->label5->Name = L"label5";
			this->label5->Padding = System::Windows::Forms::Padding(0, 5, 0, 0);
			this->label5->Size = System::Drawing::Size(43, 18);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Máximo";
			// 
			// Maximo
			// 
			this->Maximo->Location = System::Drawing::Point(52, 73);
			this->Maximo->Name = L"Maximo";
			this->Maximo->Size = System::Drawing::Size(119, 20);
			this->Maximo->TabIndex = 6;
			this->Maximo->Text = L"80";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(3, 96);
			this->label6->Name = L"label6";
			this->label6->Padding = System::Windows::Forms::Padding(0, 5, 0, 0);
			this->label6->Size = System::Drawing::Size(14, 18);
			this->label6->TabIndex = 7;
			this->label6->Text = L"X";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(23, 99);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(55, 20);
			this->textBox5->TabIndex = 8;
			this->textBox5->Text = L"0";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(84, 96);
			this->label7->Name = L"label7";
			this->label7->Padding = System::Windows::Forms::Padding(0, 5, 0, 0);
			this->label7->Size = System::Drawing::Size(15, 18);
			this->label7->TabIndex = 9;
			this->label7->Text = L"R";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(105, 99);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(55, 20);
			this->textBox6->TabIndex = 10;
			this->textBox6->Text = L"0";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(3, 122);
			this->label8->Name = L"label8";
			this->label8->Padding = System::Windows::Forms::Padding(0, 5, 0, 0);
			this->label8->Size = System::Drawing::Size(14, 18);
			this->label8->TabIndex = 11;
			this->label8->Text = L"Y";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(23, 125);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(55, 20);
			this->textBox7->TabIndex = 12;
			this->textBox7->Text = L"0";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(84, 122);
			this->label9->Name = L"label9";
			this->label9->Padding = System::Windows::Forms::Padding(0, 5, 0, 0);
			this->label9->Size = System::Drawing::Size(14, 18);
			this->label9->TabIndex = 13;
			this->label9->Text = L"P";
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(104, 125);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(56, 20);
			this->textBox8->TabIndex = 14;
			this->textBox8->Text = L"0";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(3, 148);
			this->label10->Name = L"label10";
			this->label10->Padding = System::Windows::Forms::Padding(0, 5, 0, 0);
			this->label10->Size = System::Drawing::Size(14, 18);
			this->label10->TabIndex = 15;
			this->label10->Text = L"Z";
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(23, 151);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(55, 20);
			this->textBox9->TabIndex = 16;
			this->textBox9->Text = L"0";
			// 
			// label11
			// 
			this->label11->Location = System::Drawing::Point(84, 148);
			this->label11->Name = L"label11";
			this->label11->Padding = System::Windows::Forms::Padding(0, 5, 0, 0);
			this->label11->Size = System::Drawing::Size(14, 18);
			this->label11->TabIndex = 17;
			this->label11->Text = L"W";
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(104, 151);
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
			this->groupBox1->Size = System::Drawing::Size(186, 92);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Conexión";
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Controls->Add(this->label2);
			this->flowLayoutPanel1->Controls->Add(this->textBox2);
			this->flowLayoutPanel1->Controls->Add(this->tableLayoutPanel1);
			this->flowLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flowLayoutPanel1->Location = System::Drawing::Point(3, 16);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(180, 73);
			this->flowLayoutPanel1->TabIndex = 0;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(3, 0);
			this->label2->Name = L"label2";
			this->label2->Padding = System::Windows::Forms::Padding(0, 5, 0, 0);
			this->label2->Size = System::Drawing::Size(41, 18);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Puerto:";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(50, 3);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 3;
			this->textBox2->Text = L"2368";
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 3;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel1->Controls->Add(this->button1, 1, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(3, 29);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(174, 40);
			this->tableLayoutPanel1->TabIndex = 4;
			// 
			// button1
			// 
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->button1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->ForeColor = System::Drawing::Color::Transparent;
			this->button1->ImageIndex = 1;
			this->button1->ImageList = this->imageList1;
			this->button1->Location = System::Drawing::Point(46, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(81, 34);
			this->button1->TabIndex = 4;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Main::button1_Click);
			// 
			// tabPage2
			// 
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(192, 682);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Visor";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// Consola
			// 
			this->Consola->Location = System::Drawing::Point(218, 25);
			this->Consola->Multiline = true;
			this->Consola->Name = L"Consola";
			this->Consola->Size = System::Drawing::Size(590, 405);
			this->Consola->TabIndex = 3;
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Tick += gcnew System::EventHandler(this, &Main::timer2_Tick);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(218, 477);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(968, 168);
			this->textBox3->TabIndex = 5;
			// 
			// timer3
			// 
			this->timer3->Interval = 500;
			this->timer3->Tick += gcnew System::EventHandler(this, &Main::timer3_Tick);
			// 
			// toolStripLabel3
			// 
			this->toolStripLabel3->Name = L"toolStripLabel3";
			this->toolStripLabel3->Size = System::Drawing::Size(78, 22);
			this->toolStripLabel3->Text = L"Análisis: 0 ms";
			// 
			// toolStripLabel4
			// 
			this->toolStripLabel4->Name = L"toolStripLabel4";
			this->toolStripLabel4->Size = System::Drawing::Size(0, 22);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(6, 25);
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1222, 733);
			this->Controls->Add(this->textBox3);
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
			this->tabPage1->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->flowLayoutPanel5->ResumeLayout(false);
			this->flowLayoutPanel5->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->flowLayoutPanel4->ResumeLayout(false);
			this->flowLayoutPanel4->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->flowLayoutPanel3->ResumeLayout(false);
			this->flowLayoutPanel3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->flowLayoutPanel2->ResumeLayout(false);
			this->flowLayoutPanel2->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->flowLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->PerformLayout();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void ActivarLector_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (ActivarLector->Checked) {
			Controlador->ArrayDataReader[MIN_DISTANCE] = Convert::ToDouble(Minimo->Text);
			Controlador->ArrayDataReader[MAX_DISTANCE] = Convert::ToDouble(Maximo->Text);
			Controlador->ArrayDataReader[PCALIBRATE_X] = Convert::ToDouble(textBox5->Text);
			Controlador->ArrayDataReader[PCALIBRATE_Y] = Convert::ToDouble(textBox7->Text);
			Controlador->ArrayDataReader[PCALIBRATE_Z] = Convert::ToDouble(textBox9->Text);
			Controlador->ArrayDataReader[PCALIBRATE_R] = Convert::ToDouble(textBox6->Text);
			Controlador->ArrayDataReader[PCALIBRATE_P] = Convert::ToDouble(textBox8->Text);
			Controlador->ArrayDataReader[PCALIBRATE_W] = Convert::ToDouble(textBox10->Text);

			Controlador->Flags[FLAG_PAUSA] = false;

			//Bloquear botones al pulsar el activar
			ActivarOpenGl->Enabled = false;
			groupBox3->Enabled = false;
			groupBox4->Enabled = false;
			groupBox5->Enabled = false;
			ActivarLogs->Enabled = false;
			textBox5->Enabled = false;
			textBox6->Enabled = false;
			textBox7->Enabled = false;
			textBox8->Enabled = false;
			textBox9->Enabled = false;
			textBox10->Enabled = false;
			Maximo->Enabled = false;
			Minimo->Enabled = false;
			ActivarLector->ImageIndex = 3;
		}
		else {
			Controlador->Flags[FLAG_PAUSA] = true;
			ActivarLector->ImageIndex = 2;
			ActivarOpenGl->Enabled = true;
			groupBox3->Enabled = true;
			groupBox4->Enabled = true;
			groupBox5->Enabled = true;
			ActivarLogs->Enabled = true;
			Maximo->Enabled = true;
			Minimo->Enabled = true;
			textBox5->Enabled = true;
			textBox6->Enabled = true;
			textBox7->Enabled = true;
			textBox8->Enabled = true;
			textBox9->Enabled = true;
			textBox10->Enabled = true;
		}
		//TODO: MANDAR A CONTROL 

	}
	private: System::Void ActivarLogs_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (ActivarLogs->Checked) {
			ActivarLogs->ImageIndex = 5;
			folderBrowserDialog1->ShowDialog();
			if (folderBrowserDialog1->SelectedPath != "") {
				Controlador->ArrayDataReader[PATH_LOG] = folderBrowserDialog1->SelectedPath;
				Controlador->Flags[FLAG_LOG] = true;
			}
			else {
				ActivarLogs->Checked = false;
				ActivarLogs->ImageIndex = 4;
			}
		}
		else {
			ActivarLogs->ImageIndex = 4;
			Controlador->Flags[FLAG_LOG] = false;
		}
		//TODO: MANDAR A CONTROL //TODO: MANDAR A CONTROL 
	}
	private: System::Void ActivarGPS_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (ActivarGPS->Checked) {
			ActivarGPS->ImageIndex = 6;
			comboBox1->BeginUpdate();
			cli::array<String^>^ coms = gps->serialPort->GetPortNames();
			comboBox1->Items->Clear();
			for (int i = 0; i < coms->Length; i++)
			{
				comboBox1->Items->Add(coms[i]);
			}
			comboBox1->SelectedItem = comboBox1->Items[0];
			comboBox1->EndUpdate();
			comboBox2->SelectedIndex = 1;
		}
		else {
			Controlador->ArrayGps[START] = false;
			comboBox1->Items->Clear();
			button4->ImageIndex = 10;
			label1->Text = "Satélites:";
			gps->serialPort->Close();
			ActivarGPS->ImageIndex = 7;
			timer3->Enabled = false;
		}

		//TODO: MANDAR A CONTROL 
	}
	private: System::Void ActivarAnalisys_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (ActivarAnalisys->Checked)
		{
			ActivarAnalisys->ImageIndex = 6;
			Controlador->Flags[FLAG_ANALISYS] = true;
		}
		else
		{
			ActivarAnalisys->ImageIndex = 7;
			Controlador->Flags[FLAG_ANALISYS] = true;
		}
	}
	private: System::Void ActivarOpenGl_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (ActivarOpenGl->Checked) {
			ActivarOpenGl->ImageIndex = 6;
			Controlador->Flags[FLAG_OPENGL] = true;
		}
		else {
			ActivarOpenGl->ImageIndex = 7;
			Controlador->Flags[FLAG_OPENGL] = false;
		}
	}

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		folderBrowserDialog1->ShowDialog();
		Controlador->ArrayDataReader[PATH_LOG] = folderBrowserDialog1->SelectedPath;
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		try
		{
			if (button1->ImageIndex == 1) {
				IPEndPoint^ Connect = gcnew IPEndPoint(IPAddress::Any, Convert::ToInt32(textBox2->Text));//0xC901A8C0   IPAddress::Any
				Controlador->ArrayDataReader[IP] = Connect;
				UdpClient^ Client = gcnew UdpClient(Connect);
				if (true) {//Client->Available > 0
					button3->Visible = false;
					groupBox5->Visible = true;
					groupBox4->Visible = true;
					groupBox3->Visible = true;
					groupBox2->Visible = true;
					button1->ImageIndex = 0;
				}
				else {
					MessageBox::Show("Error al conectar con el laser" + Client->Available, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
				Client->Close();
				delete Client;
			}
			else {
				button3->Visible = true;
				button1->ImageIndex = 1;
				groupBox5->Visible = false;
				groupBox4->Visible = false;
				groupBox3->Visible = false;
				groupBox2->Visible = false;
			}
		}
		catch (Exception^ e)
		{
			System::Windows::Forms::MessageBox::Show(e->ToString());
			MessageBox::Show("Error en el proceso de conexión:\r\n" + e->ToString(), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

	}
	private: System::Void Main_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		gps->serialPort->Close();
		for (int i = 0; i < Controlador->Threads->Length; i++)
		{
			if (Controlador->Threads[i])
				Controlador->Threads[i]->Abort();
		}
		delete Controlador;
		delete timer2;
		delete timer3;
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		PostProceso^ p = gcnew PostProceso();
		p->Show();
	}
	private: System::Void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e) {
		if (trackBar1->Value < 10)
			trackBar1->Value = 10;
		Controlador->ArrayDataAnalisys[TOLERANCE] = trackBar1->Value;
		label13->Text = trackBar1->Value.ToString() + " %";
	}

	private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) {

		int fr = Convert::ToInt32(Controlador->ArrayDataReader[FRECUENCY_TIME]);
		int lec = Convert::ToInt32(Controlador->ArrayDataReader[PROCESS_TIME]);
		String ^ info = Controlador->ArrayDataReader[INFORME]->ToString();
		Controlador->ArrayDataReader[INFORME] = "";
		if (fr > 0)
		{
			toolStripLabel1->Text = "Frecuencia: " + (1 / fr) * 1000 + " Hz";
		}
		else {
			toolStripLabel1->Text = "Frecuencia: 0 Hz";
		}
		toolStripLabel2->Text = "Lector: " + lec + " ms";
		Consola->AppendText(info);
	}

	private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		Controlador->ArrayGps[COM] = comboBox1->SelectedItem->ToString();
	}
	private: System::Void timer3_Tick(System::Object^  sender, System::EventArgs^  e) {
		bool start = (bool)Controlador->ArrayGps[START];
		if (start) {
			String^ trama = Controlador->ArrayGps[TRAMA]->ToString();
			int sig = Convert::ToInt32(Controlador->ArrayGps[QUALITY]);
			int sat = Convert::ToInt32(Controlador->ArrayGps[SATELITES]);
			if (trama->Length > 0)
				textBox3->AppendText(trama + "\n");

			switch (sig)
			{
			case 1: button4->ImageIndex = 12;label1->Text = "Satélites: " + sat;break;
			case 2: button4->ImageIndex = 13;label1->Text = "Satélites: " + sat;break;
			default:
				button4->ImageIndex = 11;
				label1->Text = "Satélites: Buscando...";
				break;
			}
		}
		else {
			button4->ImageIndex = 10;
			label1->Text = "Satélites:";
		}
	}
	private: System::Void comboBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		Controlador->ArrayGps[TIPO_TRAMA] = comboBox2->SelectedItem->ToString();
	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		if ((bool)Controlador->ArrayGps[START]) {
			button4->ImageIndex = 10;
			Controlador->ArrayGps[START] = false;
			timer3->Enabled = false;
		}
		else
		{
			button4->ImageIndex = 11;
			Controlador->ArrayGps[START] = true;
			timer3->Enabled = true;
		}

	}
	};
}