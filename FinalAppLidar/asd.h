#pragma once
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
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	protected:

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::CheckBox^  frames_check;

	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::CheckBox^  checkBox10;
	private: System::Windows::Forms::CheckBox^  checkBox9;
	private: System::Windows::Forms::CheckBox^  checkBox8;
	private: System::Windows::Forms::CheckBox^  checkBox7;
	private: System::Windows::Forms::CheckBox^  checkBox6;
	private: System::Windows::Forms::CheckBox^  checkBox5;
	private: System::Windows::Forms::CheckBox^  checkBox4;
	private: System::Windows::Forms::CheckBox^  checkBox3;
	private: System::Windows::Forms::CheckBox^  param_check;


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::CheckBox^  f1_check;
	private: System::Windows::Forms::CheckBox^  f2_check;


	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::ComboBox^  comboBox3;
	private: System::Windows::Forms::ComboBox^  comboBox4;
	private: System::Windows::Forms::CheckBox^  f3_check;

	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::ComboBox^  comboBox5;
	private: System::Windows::Forms::ComboBox^  comboBox6;
	private: System::Windows::Forms::CheckBox^  f4_check;

	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::ComboBox^  comboBox7;
	private: System::Windows::Forms::ComboBox^  comboBox8;
	private: System::Windows::Forms::Label^  label3;
	private: String^ path;









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
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->frames_check = (gcnew System::Windows::Forms::CheckBox());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->checkBox10 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox9 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox8 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox7 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox6 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->param_check = (gcnew System::Windows::Forms::CheckBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->f4_check = (gcnew System::Windows::Forms::CheckBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox7 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox8 = (gcnew System::Windows::Forms::ComboBox());
			this->f3_check = (gcnew System::Windows::Forms::CheckBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox5 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox6 = (gcnew System::Windows::Forms::ComboBox());
			this->f2_check = (gcnew System::Windows::Forms::CheckBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->f1_check = (gcnew System::Windows::Forms::CheckBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tabControl1->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(380, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(82, 24);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Seleccionar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &PostProceso::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(57, 12);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(317, 22);
			this->textBox1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(5, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Archivo:";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(387, 239);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Iniciar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &PostProceso::button2_Click);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(8, 239);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(373, 23);
			this->progressBar1->Step = 1;
			this->progressBar1->TabIndex = 4;
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(8, 42);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(458, 180);
			this->tabControl1->TabIndex = 6;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->frames_check);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(450, 154);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Frames";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// frames_check
			// 
			this->frames_check->AutoSize = true;
			this->frames_check->Location = System::Drawing::Point(7, 7);
			this->frames_check->Name = L"frames_check";
			this->frames_check->Size = System::Drawing::Size(115, 17);
			this->frames_check->TabIndex = 0;
			this->frames_check->Text = L"Separar en Frames";
			this->frames_check->UseVisualStyleBackColor = true;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->checkBox10);
			this->tabPage1->Controls->Add(this->checkBox9);
			this->tabPage1->Controls->Add(this->checkBox8);
			this->tabPage1->Controls->Add(this->checkBox7);
			this->tabPage1->Controls->Add(this->checkBox6);
			this->tabPage1->Controls->Add(this->checkBox5);
			this->tabPage1->Controls->Add(this->checkBox4);
			this->tabPage1->Controls->Add(this->checkBox3);
			this->tabPage1->Controls->Add(this->param_check);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(450, 154);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Par嫥etros";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// checkBox10
			// 
			this->checkBox10->Appearance = System::Windows::Forms::Appearance::Button;
			this->checkBox10->AutoSize = true;
			this->checkBox10->BackColor = System::Drawing::Color::IndianRed;
			this->checkBox10->Enabled = false;
			this->checkBox10->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->checkBox10->Location = System::Drawing::Point(332, 30);
			this->checkBox10->Name = L"checkBox10";
			this->checkBox10->Size = System::Drawing::Size(39, 23);
			this->checkBox10->TabIndex = 8;
			this->checkBox10->Text = L"GPS";
			this->checkBox10->UseVisualStyleBackColor = false;
			this->checkBox10->CheckedChanged += gcnew System::EventHandler(this, &PostProceso::checkBox10_CheckedChanged);
			// 
			// checkBox9
			// 
			this->checkBox9->Appearance = System::Windows::Forms::Appearance::Button;
			this->checkBox9->AutoSize = true;
			this->checkBox9->BackColor = System::Drawing::Color::IndianRed;
			this->checkBox9->Enabled = false;
			this->checkBox9->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->checkBox9->Location = System::Drawing::Point(276, 30);
			this->checkBox9->Name = L"checkBox9";
			this->checkBox9->Size = System::Drawing::Size(50, 23);
			this->checkBox9->TabIndex = 7;
			this->checkBox9->Text = L"聲gulo";
			this->checkBox9->UseVisualStyleBackColor = false;
			this->checkBox9->CheckedChanged += gcnew System::EventHandler(this, &PostProceso::checkBox9_CheckedChanged);
			// 
			// checkBox8
			// 
			this->checkBox8->Appearance = System::Windows::Forms::Appearance::Button;
			this->checkBox8->AutoSize = true;
			this->checkBox8->BackColor = System::Drawing::Color::IndianRed;
			this->checkBox8->Enabled = false;
			this->checkBox8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->checkBox8->Location = System::Drawing::Point(209, 30);
			this->checkBox8->Name = L"checkBox8";
			this->checkBox8->Size = System::Drawing::Size(61, 23);
			this->checkBox8->TabIndex = 6;
			this->checkBox8->Text = L"Distancia";
			this->checkBox8->UseVisualStyleBackColor = false;
			this->checkBox8->CheckedChanged += gcnew System::EventHandler(this, &PostProceso::checkBox8_CheckedChanged);
			// 
			// checkBox7
			// 
			this->checkBox7->Appearance = System::Windows::Forms::Appearance::Button;
			this->checkBox7->AutoSize = true;
			this->checkBox7->BackColor = System::Drawing::Color::IndianRed;
			this->checkBox7->Enabled = false;
			this->checkBox7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->checkBox7->Location = System::Drawing::Point(7, 30);
			this->checkBox7->Name = L"checkBox7";
			this->checkBox7->Size = System::Drawing::Size(46, 23);
			this->checkBox7->TabIndex = 5;
			this->checkBox7->Text = L"Frame";
			this->checkBox7->UseVisualStyleBackColor = false;
			this->checkBox7->CheckedChanged += gcnew System::EventHandler(this, &PostProceso::checkBox7_CheckedChanged);
			// 
			// checkBox6
			// 
			this->checkBox6->Appearance = System::Windows::Forms::Appearance::Button;
			this->checkBox6->AutoSize = true;
			this->checkBox6->BackColor = System::Drawing::Color::IndianRed;
			this->checkBox6->Enabled = false;
			this->checkBox6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->checkBox6->Location = System::Drawing::Point(59, 30);
			this->checkBox6->Name = L"checkBox6";
			this->checkBox6->Size = System::Drawing::Size(54, 23);
			this->checkBox6->TabIndex = 4;
			this->checkBox6->Text = L"Azimuth";
			this->checkBox6->UseVisualStyleBackColor = false;
			this->checkBox6->CheckedChanged += gcnew System::EventHandler(this, &PostProceso::checkBox6_CheckedChanged);
			// 
			// checkBox5
			// 
			this->checkBox5->Appearance = System::Windows::Forms::Appearance::Button;
			this->checkBox5->AutoSize = true;
			this->checkBox5->BackColor = System::Drawing::Color::IndianRed;
			this->checkBox5->Enabled = false;
			this->checkBox5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->checkBox5->Location = System::Drawing::Point(179, 30);
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->Size = System::Drawing::Size(24, 23);
			this->checkBox5->TabIndex = 3;
			this->checkBox5->Text = L"Z";
			this->checkBox5->UseVisualStyleBackColor = false;
			this->checkBox5->CheckedChanged += gcnew System::EventHandler(this, &PostProceso::checkBox5_CheckedChanged);
			// 
			// checkBox4
			// 
			this->checkBox4->Appearance = System::Windows::Forms::Appearance::Button;
			this->checkBox4->AutoSize = true;
			this->checkBox4->BackColor = System::Drawing::Color::IndianRed;
			this->checkBox4->Enabled = false;
			this->checkBox4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->checkBox4->Location = System::Drawing::Point(149, 30);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(24, 23);
			this->checkBox4->TabIndex = 2;
			this->checkBox4->Text = L"Y";
			this->checkBox4->UseVisualStyleBackColor = false;
			this->checkBox4->CheckedChanged += gcnew System::EventHandler(this, &PostProceso::checkBox4_CheckedChanged);
			// 
			// checkBox3
			// 
			this->checkBox3->Appearance = System::Windows::Forms::Appearance::Button;
			this->checkBox3->AutoSize = true;
			this->checkBox3->BackColor = System::Drawing::Color::IndianRed;
			this->checkBox3->Enabled = false;
			this->checkBox3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->checkBox3->Location = System::Drawing::Point(119, 30);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(24, 23);
			this->checkBox3->TabIndex = 1;
			this->checkBox3->Text = L"X";
			this->checkBox3->UseVisualStyleBackColor = false;
			this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &PostProceso::checkBox3_CheckedChanged);
			// 
			// param_check
			// 
			this->param_check->AutoSize = true;
			this->param_check->Location = System::Drawing::Point(7, 7);
			this->param_check->Name = L"param_check";
			this->param_check->Size = System::Drawing::Size(107, 17);
			this->param_check->TabIndex = 0;
			this->param_check->Text = L"Filtrar Par嫥etros";
			this->param_check->UseVisualStyleBackColor = true;
			this->param_check->CheckedChanged += gcnew System::EventHandler(this, &PostProceso::param_check_CheckedChanged);
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->f4_check);
			this->tabPage2->Controls->Add(this->textBox5);
			this->tabPage2->Controls->Add(this->comboBox7);
			this->tabPage2->Controls->Add(this->comboBox8);
			this->tabPage2->Controls->Add(this->f3_check);
			this->tabPage2->Controls->Add(this->textBox4);
			this->tabPage2->Controls->Add(this->comboBox5);
			this->tabPage2->Controls->Add(this->comboBox6);
			this->tabPage2->Controls->Add(this->f2_check);
			this->tabPage2->Controls->Add(this->textBox3);
			this->tabPage2->Controls->Add(this->comboBox3);
			this->tabPage2->Controls->Add(this->comboBox4);
			this->tabPage2->Controls->Add(this->f1_check);
			this->tabPage2->Controls->Add(this->textBox2);
			this->tabPage2->Controls->Add(this->comboBox2);
			this->tabPage2->Controls->Add(this->label2);
			this->tabPage2->Controls->Add(this->comboBox1);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(450, 154);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Filtro";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// f4_check
			// 
			this->f4_check->AutoSize = true;
			this->f4_check->Enabled = false;
			this->f4_check->Location = System::Drawing::Point(10, 129);
			this->f4_check->Name = L"f4_check";
			this->f4_check->Size = System::Drawing::Size(15, 14);
			this->f4_check->TabIndex = 17;
			this->f4_check->UseVisualStyleBackColor = true;
			this->f4_check->Visible = false;
			this->f4_check->CheckedChanged += gcnew System::EventHandler(this, &PostProceso::f4_check_CheckedChanged);
			// 
			// textBox5
			// 
			this->textBox5->Enabled = false;
			this->textBox5->Location = System::Drawing::Point(202, 122);
			this->textBox5->Margin = System::Windows::Forms::Padding(0);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(88, 20);
			this->textBox5->TabIndex = 16;
			this->textBox5->Text = L"0";
			this->textBox5->Visible = false;
			// 
			// comboBox7
			// 
			this->comboBox7->Enabled = false;
			this->comboBox7->FormattingEnabled = true;
			this->comboBox7->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L">", L"<", L"=", L"!=" });
			this->comboBox7->Location = System::Drawing::Point(158, 122);
			this->comboBox7->Margin = System::Windows::Forms::Padding(0);
			this->comboBox7->Name = L"comboBox7";
			this->comboBox7->Size = System::Drawing::Size(37, 21);
			this->comboBox7->TabIndex = 15;
			this->comboBox7->Text = L"Op";
			this->comboBox7->Visible = false;
			// 
			// comboBox8
			// 
			this->comboBox8->Enabled = false;
			this->comboBox8->FormattingEnabled = true;
			this->comboBox8->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"Frame", L"Azimuth", L"X", L"Y", L"Z", L"Distancia",
					L"聲gulo"
			});
			this->comboBox8->Location = System::Drawing::Point(31, 122);
			this->comboBox8->Margin = System::Windows::Forms::Padding(0);
			this->comboBox8->Name = L"comboBox8";
			this->comboBox8->Size = System::Drawing::Size(121, 21);
			this->comboBox8->TabIndex = 14;
			this->comboBox8->Text = L"Par嫥etro";
			this->comboBox8->Visible = false;
			// 
			// f3_check
			// 
			this->f3_check->AutoSize = true;
			this->f3_check->Enabled = false;
			this->f3_check->Location = System::Drawing::Point(10, 99);
			this->f3_check->Name = L"f3_check";
			this->f3_check->Size = System::Drawing::Size(15, 14);
			this->f3_check->TabIndex = 13;
			this->f3_check->UseVisualStyleBackColor = true;
			this->f3_check->Visible = false;
			this->f3_check->CheckedChanged += gcnew System::EventHandler(this, &PostProceso::f3_check_CheckedChanged);
			// 
			// textBox4
			// 
			this->textBox4->Enabled = false;
			this->textBox4->Location = System::Drawing::Point(202, 92);
			this->textBox4->Margin = System::Windows::Forms::Padding(0);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(88, 20);
			this->textBox4->TabIndex = 12;
			this->textBox4->Text = L"0";
			this->textBox4->Visible = false;
			// 
			// comboBox5
			// 
			this->comboBox5->Enabled = false;
			this->comboBox5->FormattingEnabled = true;
			this->comboBox5->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L">", L"<", L"=", L"!=" });
			this->comboBox5->Location = System::Drawing::Point(158, 92);
			this->comboBox5->Margin = System::Windows::Forms::Padding(0);
			this->comboBox5->Name = L"comboBox5";
			this->comboBox5->Size = System::Drawing::Size(37, 21);
			this->comboBox5->TabIndex = 11;
			this->comboBox5->Text = L"Op";
			this->comboBox5->Visible = false;
			// 
			// comboBox6
			// 
			this->comboBox6->Enabled = false;
			this->comboBox6->FormattingEnabled = true;
			this->comboBox6->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"Frame", L"Azimuth", L"X", L"Y", L"Z", L"Distancia",
					L"聲gulo"
			});
			this->comboBox6->Location = System::Drawing::Point(31, 92);
			this->comboBox6->Margin = System::Windows::Forms::Padding(0);
			this->comboBox6->Name = L"comboBox6";
			this->comboBox6->Size = System::Drawing::Size(121, 21);
			this->comboBox6->TabIndex = 10;
			this->comboBox6->Text = L"Par嫥etro";
			this->comboBox6->Visible = false;
			// 
			// f2_check
			// 
			this->f2_check->AutoSize = true;
			this->f2_check->Enabled = false;
			this->f2_check->Location = System::Drawing::Point(10, 70);
			this->f2_check->Name = L"f2_check";
			this->f2_check->Size = System::Drawing::Size(15, 14);
			this->f2_check->TabIndex = 9;
			this->f2_check->UseVisualStyleBackColor = true;
			this->f2_check->Visible = false;
			this->f2_check->CheckedChanged += gcnew System::EventHandler(this, &PostProceso::f2_check_CheckedChanged);
			// 
			// textBox3
			// 
			this->textBox3->Enabled = false;
			this->textBox3->Location = System::Drawing::Point(202, 63);
			this->textBox3->Margin = System::Windows::Forms::Padding(0);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(88, 20);
			this->textBox3->TabIndex = 8;
			this->textBox3->Text = L"0";
			this->textBox3->Visible = false;
			// 
			// comboBox3
			// 
			this->comboBox3->Enabled = false;
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L">", L"<", L"=", L"!=" });
			this->comboBox3->Location = System::Drawing::Point(158, 63);
			this->comboBox3->Margin = System::Windows::Forms::Padding(0);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(37, 21);
			this->comboBox3->TabIndex = 7;
			this->comboBox3->Text = L"Op";
			this->comboBox3->Visible = false;
			// 
			// comboBox4
			// 
			this->comboBox4->Enabled = false;
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"Frame", L"Azimuth", L"X", L"Y", L"Z", L"Distancia",
					L"聲gulo"
			});
			this->comboBox4->Location = System::Drawing::Point(31, 63);
			this->comboBox4->Margin = System::Windows::Forms::Padding(0);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(121, 21);
			this->comboBox4->TabIndex = 6;
			this->comboBox4->Text = L"Par嫥etro";
			this->comboBox4->Visible = false;
			// 
			// f1_check
			// 
			this->f1_check->AutoSize = true;
			this->f1_check->Location = System::Drawing::Point(10, 40);
			this->f1_check->Name = L"f1_check";
			this->f1_check->Size = System::Drawing::Size(15, 14);
			this->f1_check->TabIndex = 5;
			this->f1_check->UseVisualStyleBackColor = true;
			this->f1_check->CheckedChanged += gcnew System::EventHandler(this, &PostProceso::f1_check_CheckedChanged);
			// 
			// textBox2
			// 
			this->textBox2->Enabled = false;
			this->textBox2->Location = System::Drawing::Point(202, 33);
			this->textBox2->Margin = System::Windows::Forms::Padding(0);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(88, 20);
			this->textBox2->TabIndex = 3;
			this->textBox2->Text = L"0";
			// 
			// comboBox2
			// 
			this->comboBox2->Enabled = false;
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L">", L"<", L"=", L"!=" });
			this->comboBox2->Location = System::Drawing::Point(158, 33);
			this->comboBox2->Margin = System::Windows::Forms::Padding(0);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(37, 21);
			this->comboBox2->TabIndex = 2;
			this->comboBox2->Text = L"Op";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(7, 7);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(101, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Guardar puntos con";
			// 
			// comboBox1
			// 
			this->comboBox1->Enabled = false;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"Frame", L"Azimuth", L"X", L"Y", L"Z", L"Distancia",
					L"聲gulo"
			});
			this->comboBox1->Location = System::Drawing::Point(31, 33);
			this->comboBox1->Margin = System::Windows::Forms::Padding(0);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 0;
			this->comboBox1->Text = L"Par嫥etro";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(180, 244);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(31, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Total";
			// 
			// PostProceso
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(468, 274);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"PostProceso";
			this->Text = L"PostProceso";
			this->tabControl1->ResumeLayout(false);
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ folder = "C:\\";
		cli::array<String^>^ dir = Directory::GetDirectories(folder);
		cli::array<String^>^ file = Directory::GetFiles(folder);
		openFileDialog1->ShowDialog();
		textBox1->Text = openFileDialog1->FileName;
	}

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		/*try
		{*/
			StreamReader^ din = File::OpenText(textBox1->Text);
			long lines = din->ReadToEnd()->Split('\n')->Length;
			din->DiscardBufferedData();
			din->Close();
			System::Drawing::Size form_size = this->Size;
			int pasos_totales = 0;
			int paso = 0;
			if ((bool)param_check->CheckState)
				pasos_totales++;
			if ((bool)f1_check->CheckState)
				pasos_totales++;
			if ((bool)f2_check->CheckState)
				pasos_totales++;
			if ((bool)f3_check->CheckState)
				pasos_totales++;
			if ((bool)f4_check->CheckState)
				pasos_totales++;
			if ((bool)frames_check->CheckState)
				pasos_totales++;
			progressBar1->Maximum = pasos_totales;
			System::Collections::Generic::List<ProgressBar^>^ prgbar = gcnew System::Collections::Generic::List<ProgressBar^>();
			for (int i = 0; i < pasos_totales; i++)
			{
				prgbar->Add(gcnew ProgressBar());
				prgbar[i]->Location = System::Drawing::Point(progressBar1->Location.X, progressBar1->Location.Y + ((i + 1) * 30));
				prgbar[i]->Size = this->progressBar1->Size;
				prgbar[i]->Maximum = lines;
				this->Controls->Add(prgbar[i]);
				this->Size = System::Drawing::Size(this->Size.Width, this->Size.Height + 33);
			}
			path = textBox1->Text->Substring(0, textBox1->Text->LastIndexOf('\\')) + "\\Procesado\\";
			Directory::CreateDirectory(path);
			if (f1_check->Checked) {
				procesar_filtros(prgbar[paso]);
				paso++;
				progressBar1->PerformStep();
			}
			/*if ((bool)contenido_check->CheckState)
				procesar_contenido();
			if ((bool)f1_check->CheckState)
				procesar_f1();
			if ((bool)f2_check->CheckState)
				procesar_f2();
			if ((bool)f3_check->CheckState)
				procesar_f3();
			if ((bool)f4_check->CheckState)
				procesar_f4();
			if ((bool)frames_check->CheckState)
				procesar_f1();*/
			/*int frame_Act = 0, frame_Ant = -1;
			Directory::CreateDirectory("D:\\AAA");
			StreamReader^ din = File::OpenText(textBox1->Text);
			long lines = din->ReadToEnd()->Split('\n')->Length;
			din->DiscardBufferedData();
			progressBar1->Maximum = lines;
			progressBar1->Minimum = 0;
			din->Close();
			din = File::OpenText(textBox1->Text);
			StreamWriter^ out = gcnew StreamWriter("D:\\AAA\\a.txt");
			String^ str;
			while ((str = din->ReadLine()) != nullptr)
			{
				str = din->ReadLine();
				progressBar1->PerformStep();
				frame_Act = Convert::ToInt32(str->Substring(0, str->IndexOf(" ")));
				if (frame_Act != frame_Ant) {
					out->Close();
					out = gcnew StreamWriter("D:\\AAA\\" + frame_Act + ".txt");
				}
				out->WriteLine(str);
				frame_Ant = frame_Act;
			}
			din->Close();
			out->Close();
			System::Windows::Forms::MessageBox::Show("Archivo separado correctamente\nLineas:" + lines + "\nFrames" + frame_Act);*/
			for (int i = 0; i < pasos_totales; i++)
			{
				this->Controls->Remove(prgbar[i]);
			}
			prgbar->Clear();
			this->Size = form_size;
		/*}
		catch (Exception^ e)
		{
			System::Windows::Forms::MessageBox::Show("Error al tratar al archivo");
		}*/
	}
	private: System::Void checkBox7_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (checkBox7->Checked)
		{
			checkBox7->BackColor = System::Drawing::Color::PaleGreen;
		}
		else
		{
			checkBox7->BackColor = System::Drawing::Color::IndianRed;
		}
	};
	private: System::Void checkBox6_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (checkBox6->Checked)
		{
			checkBox6->BackColor = System::Drawing::Color::PaleGreen;
		}
		else
		{
			checkBox6->BackColor = System::Drawing::Color::IndianRed;
		}
	}
	private: System::Void checkBox3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (checkBox3->Checked)
		{
			checkBox3->BackColor = System::Drawing::Color::PaleGreen;
		}
		else
		{
			checkBox3->BackColor = System::Drawing::Color::IndianRed;
		}
	}
	private: System::Void checkBox4_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (checkBox4->Checked)
		{
			checkBox4->BackColor = System::Drawing::Color::PaleGreen;
		}
		else
		{
			checkBox4->BackColor = System::Drawing::Color::IndianRed;
		}
	}
	private: System::Void checkBox5_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (checkBox5->Checked)
		{
			checkBox5->BackColor = System::Drawing::Color::PaleGreen;
		}
		else
		{
			checkBox5->BackColor = System::Drawing::Color::IndianRed;
		}
	}
	private: System::Void checkBox8_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (checkBox8->Checked)
		{
			checkBox8->BackColor = System::Drawing::Color::PaleGreen;
		}
		else
		{
			checkBox8->BackColor = System::Drawing::Color::IndianRed;
		}
	}
	private: System::Void checkBox9_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (checkBox9->Checked)
		{
			checkBox9->BackColor = System::Drawing::Color::PaleGreen;
		}
		else
		{
			checkBox9->BackColor = System::Drawing::Color::IndianRed;
		}
	}
	private: System::Void checkBox10_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (checkBox10->Checked)
		{
			checkBox10->BackColor = System::Drawing::Color::PaleGreen;
		}
		else
		{
			checkBox10->BackColor = System::Drawing::Color::IndianRed;
		}
	}
	private: System::Void param_check_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		checkBox3->Enabled = param_check->Checked;
		checkBox4->Enabled = param_check->Checked;
		checkBox5->Enabled = param_check->Checked;
		checkBox6->Enabled = param_check->Checked;
		checkBox7->Enabled = param_check->Checked;
		checkBox8->Enabled = param_check->Checked;
		checkBox9->Enabled = param_check->Checked;
		checkBox10->Enabled = param_check->Checked;
	}
	private: System::Void f1_check_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		comboBox1->Enabled = (bool)f1_check->CheckState;
		comboBox2->Enabled = (bool)f1_check->CheckState;
		textBox2->Enabled = (bool)f1_check->CheckState;
		comboBox3->Visible = (bool)f1_check->CheckState;
		comboBox4->Visible = (bool)f1_check->CheckState;
		textBox3->Visible = (bool)f1_check->CheckState;
		f2_check->Visible = (bool)f1_check->CheckState;
		f2_check->Enabled = (bool)f1_check->CheckState;
	}
	private: System::Void f2_check_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		comboBox3->Enabled = (bool)f2_check->CheckState;
		comboBox4->Enabled = (bool)f2_check->CheckState;
		textBox3->Enabled = (bool)f2_check->CheckState;
		comboBox5->Visible = (bool)f2_check->CheckState;
		comboBox6->Visible = (bool)f2_check->CheckState;
		textBox4->Visible = (bool)f2_check->CheckState;
		f3_check->Visible = (bool)f2_check->CheckState;
		f3_check->Enabled = (bool)f2_check->CheckState;
	}
	private: System::Void f3_check_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		comboBox5->Enabled = (bool)f3_check->CheckState;
		comboBox6->Enabled = (bool)f3_check->CheckState;
		textBox4->Enabled = (bool)f3_check->CheckState;
		comboBox7->Visible = (bool)f3_check->CheckState;
		comboBox8->Visible = (bool)f3_check->CheckState;
		textBox5->Visible = (bool)f3_check->CheckState;
		f4_check->Visible = (bool)f3_check->CheckState;
		f4_check->Enabled = (bool)f3_check->CheckState;
	}
	private: System::Void f4_check_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		comboBox7->Enabled = (bool)f4_check->CheckState;
		comboBox8->Enabled = (bool)f4_check->CheckState;
		textBox5->Enabled = (bool)f4_check->CheckState;
	}
	private: void procesar_filtros(ProgressBar^ bar) {
		bar->Step = 1;
		int filtros=0;
		if ((bool)f1_check->Checked)
			filtros++;
		if ((bool)f3_check->Checked)
			filtros++;
		if ((bool)f3_check->Checked)
			filtros++;
		if ((bool)f4_check->Checked)
			filtros++;
		cli::array<int>^ parametros = gcnew cli::array<int>(4);
		cli::array<int>^ op = gcnew cli::array<int>(4);
		cli::array<double>^ valores = gcnew cli::array<double>(4);
		parametros[0] = comboBox1->SelectedIndex;
		parametros[1] = comboBox4->SelectedIndex;
		parametros[2] = comboBox6->SelectedIndex;
		parametros[3] = comboBox8->SelectedIndex;
		op[0] = comboBox2->SelectedIndex;
		op[1] = comboBox3->SelectedIndex;
		op[2] = comboBox5->SelectedIndex;
		op[3] = comboBox7->SelectedIndex;
		valores[0] = Convert::ToDouble(textBox2->Text);
		valores[1] = Convert::ToDouble(textBox2->Text);
		valores[2] = Convert::ToDouble(textBox2->Text);
		valores[3] = Convert::ToDouble(textBox2->Text);
		StreamReader^ din = File::OpenText(textBox1->Text);
		StreamWriter^ out = gcnew StreamWriter(path+"\\filtro.txt");
		String^ line;
		bar->Maximum;
		int l=0;
		while ((line = din->ReadLine()) != nullptr)
		{
			l++;
			bar->PerformStep();
			cli::array<String^>^ parts = line->Split(',');
			bool write = false;
			for (int i = 0; i < filtros; i++)
			{
				if (filter(op[i], Convert::ToDouble(parts[parametros[i]]), valores[i]))
					write = true;
				else {
					write = false;
					break;
				}
			}
			if (write)
				out->WriteLine(line);
		}
		System::Windows::Forms::MessageBox::Show("Fin");
		din->Close();
		out->Close();
	}
	private: bool filter(int op, double p, double v) {
		switch (op)
		{
		case 0: return mayor(p, v);
			break;
		case 1: return menor(p, v);
			break;
		case 2: return igual(p, v);
			break;
		case 3: return distinto(p, v);
			break;
		default:
			break;
		}
	}
	private: bool mayor(double param, double valor) {
		if (param > valor)
			return true;
		else
			return false;
	}
	private: bool menor(double param, double valor) {
		if (param < valor)
			return true;
		else
			return false;
	}
	private: bool igual(double param, double valor) {
		if (param == valor)
			return true;
		else
			return false;
	}
	private: bool distinto(double param, double valor) {
		if (param != valor)
			return true;
		else
			return false;
	}
	};
}
