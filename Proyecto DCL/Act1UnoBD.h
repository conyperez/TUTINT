#pragma once
#include "ManejadorBD.h"
#include "AgenteControlador.h"
#include "TiempoMI.h"
#include "TiempoGUI.h"

namespace Proyecto_DCL {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Act1UnoBD
	/// </summary>
	public ref class Act1UnoBD : public System::Windows::Forms::Form
	{
	public:
		Act1UnoBD(void)
		{
			InitializeComponent();
		}
		Act1UnoBD(Form^ f, ManejadorBD^ manejador, AgenteControlador* control)
		{
			form = f;
			manejadorBD = manejador;
			controlador = control;
			InitializeComponent();
			inicializarTam();
			this->Size = System::Drawing::Size(1050, 598);
			this->Show();
		}
	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Act1UnoBD()
		{
			if (components)
			{
				delete components;
			}
		}
	private: int contAyuda = 0;
	private: ManejadorBD^ manejadorBD;
	private: AgenteControlador* controlador;
	private: int segundos, minutos, horas;			// Para el form
	private: TiempoGUI^ t_actividad, ^t_item1, ^t_item2, ^t_item3, ^t_item4;
	private: Thread^ hiloAct;
	private: System::Windows::Forms::Form^ form;
	private: System::Windows::Forms::PictureBox^ botonCambio;
	private: System::Windows::Forms::PictureBox^ botonReal;
	private: int wVolver, hVolver, wListo, hListo, wAyuda, hAyuda;
	private: bool listoPin1 = false, listoPin2 = false, listoManta1 = false, listoManta2 = false, listoBa1 = false, listoBa2 = false, listoAlme1 = false, listoAlme2 = false;
	private: bool presBtn1 = false, presBtn2 = false, presBtn3 = false, presBtn4 = false, presBtn5 = false, presBtn6 = false, presBtn7 = false, presBtn8 = false;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Panel^  panelPrincipal;
	private: System::Windows::Forms::Panel^  panel5;
	private: System::Windows::Forms::PictureBox^  btnListo;
	private: System::Windows::Forms::PictureBox^  btnVolver;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::PictureBox^  btnAyuda;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel5;
	private: System::Windows::Forms::Button^  btn4F;
	private: System::Windows::Forms::Button^  btn4L;
	private: System::Windows::Forms::Button^  btn4J;
	private: System::Windows::Forms::Button^  btn4B;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;
	private: System::Windows::Forms::Button^  btn3A;
	private: System::Windows::Forms::Button^  btn3F;
	private: System::Windows::Forms::Button^  btn3N;
	private: System::Windows::Forms::Button^  btn3M;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::Button^  btn2A;
	private: System::Windows::Forms::Button^  btn2T;
	private: System::Windows::Forms::Button^  btn2R;
	private: System::Windows::Forms::Button^  btn2N;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::Button^  btn1A;
	private: System::Windows::Forms::Button^  btn1I;
	private: System::Windows::Forms::Button^  btn1L;
	private: System::Windows::Forms::Button^  btn1N;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::PictureBox^  pictureBox4;
	private: System::Windows::Forms::Label^  lblCamaron;
	private: System::Windows::Forms::Panel^  panel6;
	private: System::Windows::Forms::PictureBox^  pictureBox7;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::PictureBox^  picMinimizar;
	private: System::Windows::Forms::PictureBox^  picCerrar;

	private: System::Windows::Forms::Button^  btn8;
	private: System::Windows::Forms::Button^  btn7;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Panel^  panel7;
	private: System::Windows::Forms::Button^  btn6;
	private: System::Windows::Forms::Button^  btn5;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Button^  btn4;
	private: System::Windows::Forms::Button^  btn3;
	private: System::Windows::Forms::Label^  label2;

	private: System::Windows::Forms::Button^  btn2;
	private: System::Windows::Forms::Button^  btn1;

	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Panel^  panel12;
	private: System::Windows::Forms::Panel^  panel11;


private: System::Windows::Forms::Panel^  panel14;
private: System::Windows::Forms::Panel^  panel13;
private: System::Windows::Forms::Panel^  panel15;
private: System::Windows::Forms::Panel^  panel16;
private: System::Windows::Forms::Panel^  panel17;
private: System::Windows::Forms::Panel^  panel18;
private: System::Windows::Forms::Panel^  panel19;
private: System::Windows::Forms::Label^  label10;
private: System::Windows::Forms::Panel^  panel20;
private: System::Windows::Forms::Panel^  panel21;
private: System::Windows::Forms::Label^  label11;
private: System::Windows::Forms::Panel^  panel9;
private: System::Windows::Forms::Panel^  panel10;
private: System::Windows::Forms::Panel^  panel22;
private: System::Windows::Forms::Panel^  panel23;
private: System::Windows::Forms::Label^  label12;
private: System::Windows::Forms::Panel^  panel24;
private: System::Windows::Forms::Panel^  panel25;
private: System::Windows::Forms::Label^  label13;
private: System::Windows::Forms::Panel^  panel8;
private: System::Windows::Forms::Panel^  panel26;
private: System::Windows::Forms::Panel^  panel27;
private: System::Windows::Forms::Panel^  panel28;
private: System::Windows::Forms::Label^  label15;
private: System::Windows::Forms::Panel^  panel29;
private: System::Windows::Forms::Panel^  panel30;
private: System::Windows::Forms::Label^  label16;


	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Act1UnoBD::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panelPrincipal = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->btnListo = (gcnew System::Windows::Forms::PictureBox());
			this->btnVolver = (gcnew System::Windows::Forms::PictureBox());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->btnAyuda = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btn8 = (gcnew System::Windows::Forms::Button());
			this->btn7 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->btn6 = (gcnew System::Windows::Forms::Button());
			this->btn5 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->btn4 = (gcnew System::Windows::Forms::Button());
			this->btn3 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btn4F = (gcnew System::Windows::Forms::Button());
			this->btn4L = (gcnew System::Windows::Forms::Button());
			this->btn4J = (gcnew System::Windows::Forms::Button());
			this->btn4B = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btn3A = (gcnew System::Windows::Forms::Button());
			this->btn3F = (gcnew System::Windows::Forms::Button());
			this->btn3N = (gcnew System::Windows::Forms::Button());
			this->btn3M = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btn2A = (gcnew System::Windows::Forms::Button());
			this->btn2T = (gcnew System::Windows::Forms::Button());
			this->btn2R = (gcnew System::Windows::Forms::Button());
			this->btn2N = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btn1A = (gcnew System::Windows::Forms::Button());
			this->btn1I = (gcnew System::Windows::Forms::Button());
			this->btn1L = (gcnew System::Windows::Forms::Button());
			this->btn1N = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->btn2 = (gcnew System::Windows::Forms::Button());
			this->btn1 = (gcnew System::Windows::Forms::Button());
			this->lblCamaron = (gcnew System::Windows::Forms::Label());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->picMinimizar = (gcnew System::Windows::Forms::PictureBox());
			this->picCerrar = (gcnew System::Windows::Forms::PictureBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel11 = (gcnew System::Windows::Forms::Panel());
			this->panel12 = (gcnew System::Windows::Forms::Panel());
			this->panel13 = (gcnew System::Windows::Forms::Panel());
			this->panel14 = (gcnew System::Windows::Forms::Panel());
			this->panel15 = (gcnew System::Windows::Forms::Panel());
			this->panel16 = (gcnew System::Windows::Forms::Panel());
			this->panel17 = (gcnew System::Windows::Forms::Panel());
			this->panel18 = (gcnew System::Windows::Forms::Panel());
			this->panel19 = (gcnew System::Windows::Forms::Panel());
			this->panel20 = (gcnew System::Windows::Forms::Panel());
			this->panel21 = (gcnew System::Windows::Forms::Panel());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->panel10 = (gcnew System::Windows::Forms::Panel());
			this->panel22 = (gcnew System::Windows::Forms::Panel());
			this->panel23 = (gcnew System::Windows::Forms::Panel());
			this->panel24 = (gcnew System::Windows::Forms::Panel());
			this->panel25 = (gcnew System::Windows::Forms::Panel());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->panel26 = (gcnew System::Windows::Forms::Panel());
			this->panel27 = (gcnew System::Windows::Forms::Panel());
			this->panel28 = (gcnew System::Windows::Forms::Panel());
			this->panel29 = (gcnew System::Windows::Forms::Panel());
			this->panel30 = (gcnew System::Windows::Forms::Panel());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->panelPrincipal->SuspendLayout();
			this->panel5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnListo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnVolver))->BeginInit();
			this->panel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnAyuda))->BeginInit();
			this->panel1->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->panel7->SuspendLayout();
			this->panel3->SuspendLayout();
			this->tableLayoutPanel5->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->panel6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picMinimizar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCerrar))->BeginInit();
			this->panel2->SuspendLayout();
			this->panel11->SuspendLayout();
			this->panel12->SuspendLayout();
			this->panel13->SuspendLayout();
			this->panel14->SuspendLayout();
			this->panel15->SuspendLayout();
			this->panel16->SuspendLayout();
			this->panel17->SuspendLayout();
			this->panel18->SuspendLayout();
			this->panel19->SuspendLayout();
			this->panel20->SuspendLayout();
			this->panel21->SuspendLayout();
			this->panel9->SuspendLayout();
			this->panel10->SuspendLayout();
			this->panel22->SuspendLayout();
			this->panel23->SuspendLayout();
			this->panel24->SuspendLayout();
			this->panel25->SuspendLayout();
			this->panel8->SuspendLayout();
			this->panel26->SuspendLayout();
			this->panel27->SuspendLayout();
			this->panel28->SuspendLayout();
			this->panel29->SuspendLayout();
			this->panel30->SuspendLayout();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &Act1UnoBD::timer1_Tick);
			// 
			// panelPrincipal
			// 
			this->panelPrincipal->BackColor = System::Drawing::Color::Transparent;
			this->panelPrincipal->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panelPrincipal.BackgroundImage")));
			this->panelPrincipal->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panelPrincipal->Controls->Add(this->panel5);
			this->panelPrincipal->Controls->Add(this->panel4);
			this->panelPrincipal->Controls->Add(this->btnAyuda);
			this->panelPrincipal->Controls->Add(this->panel1);
			this->panelPrincipal->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelPrincipal->Location = System::Drawing::Point(0, 70);
			this->panelPrincipal->Name = L"panelPrincipal";
			this->panelPrincipal->Size = System::Drawing::Size(2414, 1237);
			this->panelPrincipal->TabIndex = 4;
			// 
			// panel5
			// 
			this->panel5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel5.BackgroundImage")));
			this->panel5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel5->Controls->Add(this->btnListo);
			this->panel5->Controls->Add(this->btnVolver);
			this->panel5->Location = System::Drawing::Point(40, 722);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(484, 512);
			this->panel5->TabIndex = 10;
			// 
			// btnListo
			// 
			this->btnListo->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnListo.BackgroundImage")));
			this->btnListo->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnListo->Enabled = false;
			this->btnListo->Location = System::Drawing::Point(59, 200);
			this->btnListo->Name = L"btnListo";
			this->btnListo->Size = System::Drawing::Size(398, 147);
			this->btnListo->TabIndex = 1;
			this->btnListo->TabStop = false;
			this->btnListo->Visible = false;
			this->btnListo->Click += gcnew System::EventHandler(this, &Act1UnoBD::btnListo_Click);
			this->btnListo->MouseLeave += gcnew System::EventHandler(this, &Act1UnoBD::btnListo_MouseLeave);
			this->btnListo->MouseHover += gcnew System::EventHandler(this, &Act1UnoBD::btnListo_MouseHover);
			// 
			// btnVolver
			// 
			this->btnVolver->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnVolver.BackgroundImage")));
			this->btnVolver->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnVolver->Location = System::Drawing::Point(23, 51);
			this->btnVolver->Name = L"btnVolver";
			this->btnVolver->Size = System::Drawing::Size(422, 155);
			this->btnVolver->TabIndex = 0;
			this->btnVolver->TabStop = false;
			this->btnVolver->Click += gcnew System::EventHandler(this, &Act1UnoBD::btnVolver_Click);
			this->btnVolver->MouseLeave += gcnew System::EventHandler(this, &Act1UnoBD::btnVolver_MouseLeave);
			this->btnVolver->MouseHover += gcnew System::EventHandler(this, &Act1UnoBD::btnVolver_MouseHover);
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::Transparent;
			this->panel4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel4.BackgroundImage")));
			this->panel4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel4->Controls->Add(this->label6);
			this->panel4->Location = System::Drawing::Point(457, 15);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(1253, 92);
			this->panel4->TabIndex = 7;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::White;
			this->label6->Location = System::Drawing::Point(75, 9);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(92, 68);
			this->label6->TabIndex = 4;
			this->label6->Text = L"...";
			// 
			// btnAyuda
			// 
			this->btnAyuda->BackColor = System::Drawing::Color::Transparent;
			this->btnAyuda->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAyuda.BackgroundImage")));
			this->btnAyuda->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnAyuda->Location = System::Drawing::Point(24, 26);
			this->btnAyuda->Name = L"btnAyuda";
			this->btnAyuda->Size = System::Drawing::Size(427, 249);
			this->btnAyuda->TabIndex = 1;
			this->btnAyuda->TabStop = false;
			this->btnAyuda->Click += gcnew System::EventHandler(this, &Act1UnoBD::btnAyuda_Click);
			this->btnAyuda->MouseLeave += gcnew System::EventHandler(this, &Act1UnoBD::btnAyuda_MouseLeave);
			this->btnAyuda->MouseHover += gcnew System::EventHandler(this, &Act1UnoBD::btnAyuda_MouseHover);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel1->Controls->Add(this->tableLayoutPanel1);
			this->panel1->Location = System::Drawing::Point(575, 129);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1753, 1142);
			this->panel1->TabIndex = 0;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tableLayoutPanel1->ColumnCount = 3;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				21.03874F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				35.06456F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				43.89669F)));
			this->tableLayoutPanel1->Controls->Add(this->panel8, 2, 3);
			this->tableLayoutPanel1->Controls->Add(this->panel7, 2, 2);
			this->tableLayoutPanel1->Controls->Add(this->panel3, 2, 1);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel5, 1, 3);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel4, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel3, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox2, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox3, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox4, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->panel2, 2, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(143, 99);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 4;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1472, 955);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// btn8
			// 
			this->btn8->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn8->BackColor = System::Drawing::Color::White;
			this->btn8->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn8->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn8->ForeColor = System::Drawing::Color::Black;
			this->btn8->Location = System::Drawing::Point(3, 51);
			this->btn8->Name = L"btn8";
			this->btn8->Size = System::Drawing::Size(84, 103);
			this->btn8->TabIndex = 12;
			this->btn8->UseVisualStyleBackColor = false;
			this->btn8->Click += gcnew System::EventHandler(this, &Act1UnoBD::btn8_Click);
			// 
			// btn7
			// 
			this->btn7->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn7->BackColor = System::Drawing::Color::White;
			this->btn7->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn7->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn7->ForeColor = System::Drawing::Color::Black;
			this->btn7->Location = System::Drawing::Point(3, 51);
			this->btn7->Name = L"btn7";
			this->btn7->Size = System::Drawing::Size(84, 103);
			this->btn7->TabIndex = 11;
			this->btn7->UseVisualStyleBackColor = false;
			this->btn7->Click += gcnew System::EventHandler(this, &Act1UnoBD::btn7_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label4->Location = System::Drawing::Point(-18, 62);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(88, 98);
			this->label4->TabIndex = 10;
			this->label4->Text = L"A";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel7
			// 
			this->panel7->Controls->Add(this->panel9);
			this->panel7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel7->Location = System::Drawing::Point(828, 479);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(641, 232);
			this->panel7->TabIndex = 18;
			// 
			// btn6
			// 
			this->btn6->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn6->BackColor = System::Drawing::Color::White;
			this->btn6->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn6->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn6->ForeColor = System::Drawing::Color::Black;
			this->btn6->Location = System::Drawing::Point(1, 59);
			this->btn6->Name = L"btn6";
			this->btn6->Size = System::Drawing::Size(84, 103);
			this->btn6->TabIndex = 12;
			this->btn6->UseVisualStyleBackColor = false;
			this->btn6->Click += gcnew System::EventHandler(this, &Act1UnoBD::btn6_Click);
			// 
			// btn5
			// 
			this->btn5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn5->BackColor = System::Drawing::Color::White;
			this->btn5->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn5->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn5->ForeColor = System::Drawing::Color::Black;
			this->btn5->Location = System::Drawing::Point(2, 59);
			this->btn5->Name = L"btn5";
			this->btn5->Size = System::Drawing::Size(84, 103);
			this->btn5->TabIndex = 11;
			this->btn5->UseVisualStyleBackColor = false;
			this->btn5->Click += gcnew System::EventHandler(this, &Act1UnoBD::btn5_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label3->Location = System::Drawing::Point(-18, 66);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(272, 98);
			this->label3->TabIndex = 10;
			this->label3->Text = L"RRAYA";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->panel16);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel3->Location = System::Drawing::Point(828, 241);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(641, 232);
			this->panel3->TabIndex = 17;
			// 
			// btn4
			// 
			this->btn4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn4->BackColor = System::Drawing::Color::White;
			this->btn4->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn4->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn4->ForeColor = System::Drawing::Color::Black;
			this->btn4->Location = System::Drawing::Point(5, 59);
			this->btn4->Name = L"btn4";
			this->btn4->Size = System::Drawing::Size(84, 103);
			this->btn4->TabIndex = 12;
			this->btn4->UseVisualStyleBackColor = false;
			this->btn4->Click += gcnew System::EventHandler(this, &Act1UnoBD::btn4_Click);
			// 
			// btn3
			// 
			this->btn3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn3->BackColor = System::Drawing::Color::White;
			this->btn3->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn3->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn3->ForeColor = System::Drawing::Color::Black;
			this->btn3->Location = System::Drawing::Point(3, 59);
			this->btn3->Name = L"btn3";
			this->btn3->Size = System::Drawing::Size(84, 103);
			this->btn3->TabIndex = 11;
			this->btn3->UseVisualStyleBackColor = false;
			this->btn3->Click += gcnew System::EventHandler(this, &Act1UnoBD::btn3_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label2->Location = System::Drawing::Point(-9, 68);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(88, 98);
			this->label2->TabIndex = 10;
			this->label2->Text = L"A";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tableLayoutPanel5
			// 
			this->tableLayoutPanel5->ColumnCount = 4;
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel5->Controls->Add(this->btn4F, 0, 0);
			this->tableLayoutPanel5->Controls->Add(this->btn4L, 0, 0);
			this->tableLayoutPanel5->Controls->Add(this->btn4J, 1, 0);
			this->tableLayoutPanel5->Controls->Add(this->btn4B, 2, 0);
			this->tableLayoutPanel5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel5->Location = System::Drawing::Point(312, 717);
			this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
			this->tableLayoutPanel5->RowCount = 1;
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel5->Size = System::Drawing::Size(510, 235);
			this->tableLayoutPanel5->TabIndex = 15;
			// 
			// btn4F
			// 
			this->btn4F->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn4F->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn4F->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn4F->Font = (gcnew System::Drawing::Font(L"Consolas", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn4F->ForeColor = System::Drawing::Color::White;
			this->btn4F->Location = System::Drawing::Point(140, 67);
			this->btn4F->Name = L"btn4F";
			this->btn4F->Size = System::Drawing::Size(100, 100);
			this->btn4F->TabIndex = 3;
			this->btn4F->Text = L"F";
			this->btn4F->UseVisualStyleBackColor = false;
			this->btn4F->Click += gcnew System::EventHandler(this, &Act1UnoBD::btn4F_Click);
			// 
			// btn4L
			// 
			this->btn4L->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn4L->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn4L->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn4L->Font = (gcnew System::Drawing::Font(L"Consolas", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn4L->ForeColor = System::Drawing::Color::White;
			this->btn4L->Location = System::Drawing::Point(13, 67);
			this->btn4L->Name = L"btn4L";
			this->btn4L->Size = System::Drawing::Size(100, 100);
			this->btn4L->TabIndex = 0;
			this->btn4L->Text = L"L";
			this->btn4L->UseVisualStyleBackColor = false;
			this->btn4L->Click += gcnew System::EventHandler(this, &Act1UnoBD::btn4L_Click);
			// 
			// btn4J
			// 
			this->btn4J->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn4J->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn4J->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn4J->Font = (gcnew System::Drawing::Font(L"Consolas", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn4J->ForeColor = System::Drawing::Color::White;
			this->btn4J->Location = System::Drawing::Point(267, 67);
			this->btn4J->Name = L"btn4J";
			this->btn4J->Size = System::Drawing::Size(100, 100);
			this->btn4J->TabIndex = 1;
			this->btn4J->Text = L"J";
			this->btn4J->UseVisualStyleBackColor = false;
			this->btn4J->Click += gcnew System::EventHandler(this, &Act1UnoBD::btn4J_Click);
			// 
			// btn4B
			// 
			this->btn4B->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn4B->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn4B->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn4B->Font = (gcnew System::Drawing::Font(L"Consolas", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn4B->ForeColor = System::Drawing::Color::White;
			this->btn4B->Location = System::Drawing::Point(395, 67);
			this->btn4B->Name = L"btn4B";
			this->btn4B->Size = System::Drawing::Size(100, 100);
			this->btn4B->TabIndex = 2;
			this->btn4B->Text = L"B";
			this->btn4B->UseVisualStyleBackColor = false;
			this->btn4B->Click += gcnew System::EventHandler(this, &Act1UnoBD::btn4B_Click);
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 4;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel4->Controls->Add(this->btn3A, 0, 0);
			this->tableLayoutPanel4->Controls->Add(this->btn3F, 0, 0);
			this->tableLayoutPanel4->Controls->Add(this->btn3N, 1, 0);
			this->tableLayoutPanel4->Controls->Add(this->btn3M, 2, 0);
			this->tableLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel4->Location = System::Drawing::Point(312, 479);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 1;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(510, 232);
			this->tableLayoutPanel4->TabIndex = 14;
			// 
			// btn3A
			// 
			this->btn3A->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn3A->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn3A->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn3A->Font = (gcnew System::Drawing::Font(L"Consolas", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn3A->ForeColor = System::Drawing::Color::White;
			this->btn3A->Location = System::Drawing::Point(140, 66);
			this->btn3A->Name = L"btn3A";
			this->btn3A->Size = System::Drawing::Size(100, 100);
			this->btn3A->TabIndex = 3;
			this->btn3A->Text = L"A";
			this->btn3A->UseVisualStyleBackColor = false;
			this->btn3A->Click += gcnew System::EventHandler(this, &Act1UnoBD::btn3A_Click);
			// 
			// btn3F
			// 
			this->btn3F->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn3F->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn3F->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn3F->Font = (gcnew System::Drawing::Font(L"Consolas", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn3F->ForeColor = System::Drawing::Color::White;
			this->btn3F->Location = System::Drawing::Point(13, 66);
			this->btn3F->Name = L"btn3F";
			this->btn3F->Size = System::Drawing::Size(100, 100);
			this->btn3F->TabIndex = 0;
			this->btn3F->Text = L"F";
			this->btn3F->UseVisualStyleBackColor = false;
			this->btn3F->Click += gcnew System::EventHandler(this, &Act1UnoBD::btn3F_Click);
			// 
			// btn3N
			// 
			this->btn3N->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn3N->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn3N->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn3N->Font = (gcnew System::Drawing::Font(L"Consolas", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn3N->ForeColor = System::Drawing::Color::White;
			this->btn3N->Location = System::Drawing::Point(267, 66);
			this->btn3N->Name = L"btn3N";
			this->btn3N->Size = System::Drawing::Size(100, 100);
			this->btn3N->TabIndex = 1;
			this->btn3N->Text = L"N";
			this->btn3N->UseVisualStyleBackColor = false;
			this->btn3N->Click += gcnew System::EventHandler(this, &Act1UnoBD::btn3N_Click);
			// 
			// btn3M
			// 
			this->btn3M->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn3M->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn3M->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn3M->Font = (gcnew System::Drawing::Font(L"Consolas", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn3M->ForeColor = System::Drawing::Color::White;
			this->btn3M->Location = System::Drawing::Point(395, 66);
			this->btn3M->Name = L"btn3M";
			this->btn3M->Size = System::Drawing::Size(100, 100);
			this->btn3M->TabIndex = 2;
			this->btn3M->Text = L"M";
			this->btn3M->UseVisualStyleBackColor = false;
			this->btn3M->Click += gcnew System::EventHandler(this, &Act1UnoBD::btn3M_Click);
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 4;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel3->Controls->Add(this->btn2A, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->btn2T, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->btn2R, 1, 0);
			this->tableLayoutPanel3->Controls->Add(this->btn2N, 2, 0);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(312, 241);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 1;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(510, 232);
			this->tableLayoutPanel3->TabIndex = 11;
			// 
			// btn2A
			// 
			this->btn2A->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn2A->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn2A->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn2A->Font = (gcnew System::Drawing::Font(L"Consolas", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn2A->ForeColor = System::Drawing::Color::White;
			this->btn2A->Location = System::Drawing::Point(140, 66);
			this->btn2A->Name = L"btn2A";
			this->btn2A->Size = System::Drawing::Size(100, 100);
			this->btn2A->TabIndex = 3;
			this->btn2A->Text = L"A";
			this->btn2A->UseVisualStyleBackColor = false;
			this->btn2A->Click += gcnew System::EventHandler(this, &Act1UnoBD::btn2A_Click);
			// 
			// btn2T
			// 
			this->btn2T->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn2T->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn2T->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn2T->Font = (gcnew System::Drawing::Font(L"Consolas", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn2T->ForeColor = System::Drawing::Color::White;
			this->btn2T->Location = System::Drawing::Point(13, 66);
			this->btn2T->Name = L"btn2T";
			this->btn2T->Size = System::Drawing::Size(100, 100);
			this->btn2T->TabIndex = 0;
			this->btn2T->Text = L"T";
			this->btn2T->UseVisualStyleBackColor = false;
			this->btn2T->Click += gcnew System::EventHandler(this, &Act1UnoBD::btn2T_Click);
			// 
			// btn2R
			// 
			this->btn2R->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn2R->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn2R->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn2R->Font = (gcnew System::Drawing::Font(L"Consolas", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn2R->ForeColor = System::Drawing::Color::White;
			this->btn2R->Location = System::Drawing::Point(267, 66);
			this->btn2R->Name = L"btn2R";
			this->btn2R->Size = System::Drawing::Size(100, 100);
			this->btn2R->TabIndex = 1;
			this->btn2R->Text = L"R";
			this->btn2R->UseVisualStyleBackColor = false;
			this->btn2R->Click += gcnew System::EventHandler(this, &Act1UnoBD::btn2R_Click);
			// 
			// btn2N
			// 
			this->btn2N->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn2N->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn2N->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn2N->Font = (gcnew System::Drawing::Font(L"Consolas", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn2N->ForeColor = System::Drawing::Color::White;
			this->btn2N->Location = System::Drawing::Point(395, 66);
			this->btn2N->Name = L"btn2N";
			this->btn2N->Size = System::Drawing::Size(100, 100);
			this->btn2N->TabIndex = 2;
			this->btn2N->Text = L"N";
			this->btn2N->UseVisualStyleBackColor = false;
			this->btn2N->Click += gcnew System::EventHandler(this, &Act1UnoBD::btn2N_Click);
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 4;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel2->Controls->Add(this->btn1A, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->btn1I, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->btn1L, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->btn1N, 2, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(312, 3);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(510, 232);
			this->tableLayoutPanel2->TabIndex = 11;
			// 
			// btn1A
			// 
			this->btn1A->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn1A->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn1A->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn1A->Font = (gcnew System::Drawing::Font(L"Consolas", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn1A->ForeColor = System::Drawing::Color::White;
			this->btn1A->Location = System::Drawing::Point(140, 66);
			this->btn1A->Name = L"btn1A";
			this->btn1A->Size = System::Drawing::Size(100, 100);
			this->btn1A->TabIndex = 3;
			this->btn1A->Text = L"A";
			this->btn1A->UseVisualStyleBackColor = false;
			this->btn1A->Click += gcnew System::EventHandler(this, &Act1UnoBD::btn1A_Click);
			// 
			// btn1I
			// 
			this->btn1I->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn1I->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn1I->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn1I->Font = (gcnew System::Drawing::Font(L"Consolas", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn1I->ForeColor = System::Drawing::Color::White;
			this->btn1I->Location = System::Drawing::Point(13, 66);
			this->btn1I->Name = L"btn1I";
			this->btn1I->Size = System::Drawing::Size(100, 100);
			this->btn1I->TabIndex = 0;
			this->btn1I->Text = L"I";
			this->btn1I->UseVisualStyleBackColor = false;
			this->btn1I->Click += gcnew System::EventHandler(this, &Act1UnoBD::btn1I_Click);
			// 
			// btn1L
			// 
			this->btn1L->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn1L->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn1L->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn1L->Font = (gcnew System::Drawing::Font(L"Consolas", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn1L->ForeColor = System::Drawing::Color::White;
			this->btn1L->Location = System::Drawing::Point(267, 66);
			this->btn1L->Name = L"btn1L";
			this->btn1L->Size = System::Drawing::Size(100, 100);
			this->btn1L->TabIndex = 1;
			this->btn1L->Text = L"L";
			this->btn1L->UseVisualStyleBackColor = false;
			this->btn1L->Click += gcnew System::EventHandler(this, &Act1UnoBD::btn1L_Click);
			// 
			// btn1N
			// 
			this->btn1N->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn1N->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn1N->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn1N->Font = (gcnew System::Drawing::Font(L"Consolas", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn1N->ForeColor = System::Drawing::Color::White;
			this->btn1N->Location = System::Drawing::Point(395, 66);
			this->btn1N->Name = L"btn1N";
			this->btn1N->Size = System::Drawing::Size(100, 100);
			this->btn1N->TabIndex = 2;
			this->btn1N->Text = L"N";
			this->btn1N->UseVisualStyleBackColor = false;
			this->btn1N->Click += gcnew System::EventHandler(this, &Act1UnoBD::btn1N_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(27, 11);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(254, 215);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->Location = System::Drawing::Point(4, 249);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(301, 215);
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->pictureBox3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.BackgroundImage")));
			this->pictureBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox3->Location = System::Drawing::Point(4, 498);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(301, 193);
			this->pictureBox3->TabIndex = 2;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->pictureBox4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.BackgroundImage")));
			this->pictureBox4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox4->Location = System::Drawing::Point(9, 735);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(290, 198);
			this->pictureBox4->TabIndex = 3;
			this->pictureBox4->TabStop = false;
			// 
			// btn2
			// 
			this->btn2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn2->BackColor = System::Drawing::Color::White;
			this->btn2->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn2->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn2->ForeColor = System::Drawing::Color::Black;
			this->btn2->Location = System::Drawing::Point(3, 53);
			this->btn2->Name = L"btn2";
			this->btn2->Size = System::Drawing::Size(84, 103);
			this->btn2->TabIndex = 12;
			this->btn2->UseVisualStyleBackColor = false;
			this->btn2->Click += gcnew System::EventHandler(this, &Act1UnoBD::btn2_Click);
			// 
			// btn1
			// 
			this->btn1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn1->BackColor = System::Drawing::Color::White;
			this->btn1->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn1->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn1->ForeColor = System::Drawing::Color::Black;
			this->btn1->Location = System::Drawing::Point(2, 59);
			this->btn1->Name = L"btn1";
			this->btn1->Size = System::Drawing::Size(84, 103);
			this->btn1->TabIndex = 11;
			this->btn1->UseVisualStyleBackColor = false;
			this->btn1->Click += gcnew System::EventHandler(this, &Act1UnoBD::btn1_Click);
			// 
			// lblCamaron
			// 
			this->lblCamaron->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblCamaron->AutoSize = true;
			this->lblCamaron->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCamaron->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lblCamaron->Location = System::Drawing::Point(-18, 68);
			this->lblCamaron->Name = L"lblCamaron";
			this->lblCamaron->Size = System::Drawing::Size(226, 98);
			this->lblCamaron->TabIndex = 10;
			this->lblCamaron->Text = L"NGÜI";
			this->lblCamaron->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel6
			// 
			this->panel6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel6.BackgroundImage")));
			this->panel6->Controls->Add(this->pictureBox7);
			this->panel6->Controls->Add(this->label1);
			this->panel6->Controls->Add(this->picMinimizar);
			this->panel6->Controls->Add(this->picCerrar);
			this->panel6->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel6->Location = System::Drawing::Point(0, 0);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(2414, 70);
			this->panel6->TabIndex = 5;
			// 
			// pictureBox7
			// 
			this->pictureBox7->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.BackgroundImage")));
			this->pictureBox7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox7->Location = System::Drawing::Point(12, 4);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(72, 63);
			this->pictureBox7->TabIndex = 33;
			this->pictureBox7->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(81, 7);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(212, 55);
			this->label1->TabIndex = 32;
			this->label1->Text = L"TUTINT";
			// 
			// picMinimizar
			// 
			this->picMinimizar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->picMinimizar->BackColor = System::Drawing::Color::Transparent;
			this->picMinimizar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picMinimizar.BackgroundImage")));
			this->picMinimizar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->picMinimizar->Location = System::Drawing::Point(2264, 5);
			this->picMinimizar->Name = L"picMinimizar";
			this->picMinimizar->Size = System::Drawing::Size(64, 59);
			this->picMinimizar->TabIndex = 31;
			this->picMinimizar->TabStop = false;
			this->picMinimizar->Click += gcnew System::EventHandler(this, &Act1UnoBD::picMinimizar_Click);
			// 
			// picCerrar
			// 
			this->picCerrar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->picCerrar->BackColor = System::Drawing::Color::Transparent;
			this->picCerrar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picCerrar.BackgroundImage")));
			this->picCerrar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->picCerrar->Location = System::Drawing::Point(2339, 5);
			this->picCerrar->Name = L"picCerrar";
			this->picCerrar->Size = System::Drawing::Size(64, 59);
			this->picCerrar->TabIndex = 30;
			this->picCerrar->TabStop = false;
			this->picCerrar->Click += gcnew System::EventHandler(this, &Act1UnoBD::picCerrar_Click);
			// 
			// label5
			// 
			this->label5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label5->Location = System::Drawing::Point(6, 66);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(88, 98);
			this->label5->TabIndex = 11;
			this->label5->Text = L"P";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label7
			// 
			this->label7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label7->Location = System::Drawing::Point(-13, 68);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(88, 98);
			this->label7->TabIndex = 11;
			this->label7->Text = L"O";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->panel15);
			this->panel2->Controls->Add(this->panel14);
			this->panel2->Controls->Add(this->panel13);
			this->panel2->Controls->Add(this->panel12);
			this->panel2->Controls->Add(this->panel11);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(828, 3);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(641, 232);
			this->panel2->TabIndex = 11;
			// 
			// panel11
			// 
			this->panel11->Controls->Add(this->label5);
			this->panel11->Location = System::Drawing::Point(56, 2);
			this->panel11->Name = L"panel11";
			this->panel11->Size = System::Drawing::Size(77, 232);
			this->panel11->TabIndex = 14;
			// 
			// panel12
			// 
			this->panel12->Controls->Add(this->btn1);
			this->panel12->Location = System::Drawing::Point(130, 0);
			this->panel12->Name = L"panel12";
			this->panel12->Size = System::Drawing::Size(89, 232);
			this->panel12->TabIndex = 15;
			// 
			// panel13
			// 
			this->panel13->Controls->Add(this->lblCamaron);
			this->panel13->Location = System::Drawing::Point(221, 0);
			this->panel13->Name = L"panel13";
			this->panel13->Size = System::Drawing::Size(192, 232);
			this->panel13->TabIndex = 16;
			// 
			// panel14
			// 
			this->panel14->Controls->Add(this->btn2);
			this->panel14->Location = System::Drawing::Point(409, 0);
			this->panel14->Name = L"panel14";
			this->panel14->Size = System::Drawing::Size(100, 232);
			this->panel14->TabIndex = 17;
			// 
			// panel15
			// 
			this->panel15->Controls->Add(this->label7);
			this->panel15->Location = System::Drawing::Point(502, 0);
			this->panel15->Name = L"panel15";
			this->panel15->Size = System::Drawing::Size(100, 232);
			this->panel15->TabIndex = 18;
			// 
			// panel16
			// 
			this->panel16->Controls->Add(this->panel17);
			this->panel16->Controls->Add(this->panel18);
			this->panel16->Controls->Add(this->panel19);
			this->panel16->Controls->Add(this->panel20);
			this->panel16->Controls->Add(this->panel21);
			this->panel16->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel16->Location = System::Drawing::Point(0, 0);
			this->panel16->Name = L"panel16";
			this->panel16->Size = System::Drawing::Size(641, 232);
			this->panel16->TabIndex = 12;
			// 
			// panel17
			// 
			this->panel17->Controls->Add(this->label2);
			this->panel17->Location = System::Drawing::Point(462, 0);
			this->panel17->Name = L"panel17";
			this->panel17->Size = System::Drawing::Size(100, 232);
			this->panel17->TabIndex = 18;
			// 
			// panel18
			// 
			this->panel18->Controls->Add(this->btn4);
			this->panel18->Location = System::Drawing::Point(368, 0);
			this->panel18->Name = L"panel18";
			this->panel18->Size = System::Drawing::Size(100, 232);
			this->panel18->TabIndex = 17;
			// 
			// panel19
			// 
			this->panel19->Controls->Add(this->label10);
			this->panel19->Location = System::Drawing::Point(236, 0);
			this->panel19->Name = L"panel19";
			this->panel19->Size = System::Drawing::Size(175, 232);
			this->panel19->TabIndex = 16;
			// 
			// panel20
			// 
			this->panel20->Controls->Add(this->btn3);
			this->panel20->Location = System::Drawing::Point(145, 0);
			this->panel20->Name = L"panel20";
			this->panel20->Size = System::Drawing::Size(89, 232);
			this->panel20->TabIndex = 15;
			// 
			// panel21
			// 
			this->panel21->Controls->Add(this->label11);
			this->panel21->Location = System::Drawing::Point(67, 2);
			this->panel21->Name = L"panel21";
			this->panel21->Size = System::Drawing::Size(77, 232);
			this->panel21->TabIndex = 14;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label10->Location = System::Drawing::Point(-22, 68);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(180, 98);
			this->label10->TabIndex = 13;
			this->label10->Text = L"LLE";
			this->label10->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label11->Location = System::Drawing::Point(7, 66);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(88, 98);
			this->label11->TabIndex = 14;
			this->label11->Text = L"B";
			this->label11->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel9
			// 
			this->panel9->Controls->Add(this->panel10);
			this->panel9->Controls->Add(this->panel22);
			this->panel9->Controls->Add(this->panel23);
			this->panel9->Controls->Add(this->panel24);
			this->panel9->Controls->Add(this->panel25);
			this->panel9->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel9->Location = System::Drawing::Point(0, 0);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(641, 232);
			this->panel9->TabIndex = 12;
			// 
			// panel10
			// 
			this->panel10->Controls->Add(this->label3);
			this->panel10->Location = System::Drawing::Point(372, 0);
			this->panel10->Name = L"panel10";
			this->panel10->Size = System::Drawing::Size(242, 232);
			this->panel10->TabIndex = 18;
			// 
			// panel22
			// 
			this->panel22->Controls->Add(this->btn6);
			this->panel22->Location = System::Drawing::Point(286, 0);
			this->panel22->Name = L"panel22";
			this->panel22->Size = System::Drawing::Size(86, 232);
			this->panel22->TabIndex = 17;
			// 
			// panel23
			// 
			this->panel23->Controls->Add(this->label12);
			this->panel23->Location = System::Drawing::Point(233, 0);
			this->panel23->Name = L"panel23";
			this->panel23->Size = System::Drawing::Size(51, 232);
			this->panel23->TabIndex = 16;
			// 
			// panel24
			// 
			this->panel24->Controls->Add(this->btn5);
			this->panel24->Location = System::Drawing::Point(147, 0);
			this->panel24->Name = L"panel24";
			this->panel24->Size = System::Drawing::Size(89, 232);
			this->panel24->TabIndex = 15;
			// 
			// panel25
			// 
			this->panel25->Controls->Add(this->label13);
			this->panel25->Location = System::Drawing::Point(35, 2);
			this->panel25->Name = L"panel25";
			this->panel25->Size = System::Drawing::Size(110, 232);
			this->panel25->TabIndex = 14;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label12->Location = System::Drawing::Point(-14, 66);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(88, 98);
			this->label12->TabIndex = 11;
			this->label12->Text = L"T";
			this->label12->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label13->Location = System::Drawing::Point(-6, 64);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(134, 98);
			this->label13->TabIndex = 12;
			this->label13->Text = L"MA";
			this->label13->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel8
			// 
			this->panel8->Controls->Add(this->panel26);
			this->panel8->Controls->Add(this->panel27);
			this->panel8->Controls->Add(this->panel28);
			this->panel8->Controls->Add(this->panel29);
			this->panel8->Controls->Add(this->panel30);
			this->panel8->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel8->Location = System::Drawing::Point(828, 717);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(641, 235);
			this->panel8->TabIndex = 19;
			// 
			// panel26
			// 
			this->panel26->Controls->Add(this->label4);
			this->panel26->Location = System::Drawing::Point(439, 0);
			this->panel26->Name = L"panel26";
			this->panel26->Size = System::Drawing::Size(100, 232);
			this->panel26->TabIndex = 18;
			// 
			// panel27
			// 
			this->panel27->Controls->Add(this->btn8);
			this->panel27->Location = System::Drawing::Point(347, 0);
			this->panel27->Name = L"panel27";
			this->panel27->Size = System::Drawing::Size(100, 232);
			this->panel27->TabIndex = 17;
			// 
			// panel28
			// 
			this->panel28->Controls->Add(this->label15);
			this->panel28->Location = System::Drawing::Point(250, 0);
			this->panel28->Name = L"panel28";
			this->panel28->Size = System::Drawing::Size(96, 232);
			this->panel28->TabIndex = 16;
			// 
			// panel29
			// 
			this->panel29->Controls->Add(this->btn7);
			this->panel29->Location = System::Drawing::Point(159, 0);
			this->panel29->Name = L"panel29";
			this->panel29->Size = System::Drawing::Size(89, 232);
			this->panel29->TabIndex = 15;
			// 
			// panel30
			// 
			this->panel30->Controls->Add(this->label16);
			this->panel30->Location = System::Drawing::Point(85, 2);
			this->panel30->Name = L"panel30";
			this->panel30->Size = System::Drawing::Size(77, 232);
			this->panel30->TabIndex = 14;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label15->Location = System::Drawing::Point(-14, 62);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(134, 98);
			this->label15->TabIndex = 11;
			this->label15->Text = L"ME";
			this->label15->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label16->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label16->Location = System::Drawing::Point(10, 60);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(88, 98);
			this->label16->TabIndex = 12;
			this->label16->Text = L"A";
			this->label16->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Act1UnoBD
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(14, 29);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(2414, 1307);
			this->Controls->Add(this->panelPrincipal);
			this->Controls->Add(this->panel6);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Act1UnoBD";
			this->Opacity = 0;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Act1UnoBD";
			this->Activated += gcnew System::EventHandler(this, &Act1UnoBD::Act1UnoBD_Activated);
			this->Deactivate += gcnew System::EventHandler(this, &Act1UnoBD::Act1UnoBD_Deactivate);
			this->Load += gcnew System::EventHandler(this, &Act1UnoBD::Act1UnoBD_Load);
			this->panelPrincipal->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnListo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnVolver))->EndInit();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnAyuda))->EndInit();
			this->panel1->ResumeLayout(false);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->panel7->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->tableLayoutPanel5->ResumeLayout(false);
			this->tableLayoutPanel4->ResumeLayout(false);
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picMinimizar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCerrar))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel11->ResumeLayout(false);
			this->panel11->PerformLayout();
			this->panel12->ResumeLayout(false);
			this->panel13->ResumeLayout(false);
			this->panel13->PerformLayout();
			this->panel14->ResumeLayout(false);
			this->panel15->ResumeLayout(false);
			this->panel15->PerformLayout();
			this->panel16->ResumeLayout(false);
			this->panel17->ResumeLayout(false);
			this->panel17->PerformLayout();
			this->panel18->ResumeLayout(false);
			this->panel19->ResumeLayout(false);
			this->panel19->PerformLayout();
			this->panel20->ResumeLayout(false);
			this->panel21->ResumeLayout(false);
			this->panel21->PerformLayout();
			this->panel9->ResumeLayout(false);
			this->panel10->ResumeLayout(false);
			this->panel10->PerformLayout();
			this->panel22->ResumeLayout(false);
			this->panel23->ResumeLayout(false);
			this->panel23->PerformLayout();
			this->panel24->ResumeLayout(false);
			this->panel25->ResumeLayout(false);
			this->panel25->PerformLayout();
			this->panel8->ResumeLayout(false);
			this->panel26->ResumeLayout(false);
			this->panel26->PerformLayout();
			this->panel27->ResumeLayout(false);
			this->panel28->ResumeLayout(false);
			this->panel28->PerformLayout();
			this->panel29->ResumeLayout(false);
			this->panel30->ResumeLayout(false);
			this->panel30->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		private: void inicializarTam();
		private: void comprobarRespuestas();
		private: void sonidoInicial();
		private: System::Void btnAyuda_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void btnVolver_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void btnListo_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void btnAyuda_MouseHover(System::Object^  sender, System::EventArgs^  e);
		private: System::Void btnAyuda_MouseLeave(System::Object^  sender, System::EventArgs^  e);
		private: System::Void btnVolver_MouseHover(System::Object^  sender, System::EventArgs^  e);
		private: System::Void btnVolver_MouseLeave(System::Object^  sender, System::EventArgs^  e);
		private: System::Void btnListo_MouseHover(System::Object^  sender, System::EventArgs^  e);
		private: System::Void btnListo_MouseLeave(System::Object^  sender, System::EventArgs^  e);
		private: System::Void picCerrar_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void picMinimizar_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void Act1UnoBD_Load(System::Object^  sender, System::EventArgs^  e);
		private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e);
		private: System::Void Act1UnoBD_Activated(System::Object^  sender, System::EventArgs^  e);
		private: System::Void Act1UnoBD_Deactivate(System::Object^  sender, System::EventArgs^  e);
		private: System::Void btn1I_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void btn1A_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void btn1L_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void btn1N_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void btn2T_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void btn2A_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void btn2R_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void btn2N_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void btn3F_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void btn3A_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void btn3N_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void btn3M_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void btn4L_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void btn4F_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void btn4J_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void btn4B_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void btn1_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void btn2_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void btn3_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void btn4_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void btn5_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void btn6_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void btn7_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void btn8_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void tiempo_respuesta(int numItem, TiempoGUI^ tr_item, System::Windows::Forms::Button^ btn1, System::Windows::Forms::Button^ btn2);
		private: vector<TiempoMI*> obtenerTiempoItems();
	};
}
