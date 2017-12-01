#pragma once
#include "BaseDeDatos.h"

namespace Proyecto_DCL {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Login
	/// </summary>
	public ref class Login : public System::Windows::Forms::Form
	{
	public:
		Login(Form^ f)
		{
			manejadorBD = gcnew BaseDeDatos();
			form = f;
			InitializeComponent();
			inicializarTam();
			this->Size = System::Drawing::Size(1050, 598);
			this->Show();
		}
		Login()
		{
			InitializeComponent();
			inicializarTam();
		}
	protected:
		/// Limpiar los recursos que se est�n usando.
		~Login()
		{
			if (components)
			{
				delete components;
			}
		}
	private: BaseDeDatos^ manejadorBD;
	private: int wPic2, hPic2;
	private: System::Windows::Forms::Form^  form;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Panel^  panelSecundario;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::PictureBox^  picMinimizar;
	private: System::Windows::Forms::PictureBox^  picCerrar;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::DataGridView^  dgv1;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Login::typeid));
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->dgv1 = (gcnew System::Windows::Forms::DataGridView());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->picMinimizar = (gcnew System::Windows::Forms::PictureBox());
			this->picCerrar = (gcnew System::Windows::Forms::PictureBox());
			this->panelSecundario = (gcnew System::Windows::Forms::Panel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv1))->BeginInit();
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picMinimizar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCerrar))->BeginInit();
			this->SuspendLayout();
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Transparent;
			this->panel2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel2.BackgroundImage")));
			this->panel2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel2->Controls->Add(this->dgv1);
			this->panel2->Controls->Add(this->panel3);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Controls->Add(this->pictureBox1);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(0, 70);
			this->panel2->Margin = System::Windows::Forms::Padding(4);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(2414, 1237);
			this->panel2->TabIndex = 0;
			// 
			// dgv1
			// 
			this->dgv1->AllowUserToAddRows = false;
			this->dgv1->AllowUserToDeleteRows = false;
			this->dgv1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgv1->BackgroundColor = System::Drawing::Color::DarkOliveGreen;
			this->dgv1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dgv1->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
			this->dgv1->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::DarkOliveGreen;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::Color::OliveDrab;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgv1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dgv1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv1->ColumnHeadersVisible = false;
			this->dgv1->Cursor = System::Windows::Forms::Cursors::Hand;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::DarkOliveGreen;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 20));
			dataGridViewCellStyle2->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::Color::OliveDrab;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dgv1->DefaultCellStyle = dataGridViewCellStyle2;
			this->dgv1->GridColor = System::Drawing::Color::DarkOliveGreen;
			this->dgv1->Location = System::Drawing::Point(770, 233);
			this->dgv1->Margin = System::Windows::Forms::Padding(5);
			this->dgv1->MultiSelect = false;
			this->dgv1->Name = L"dgv1";
			this->dgv1->ReadOnly = true;
			this->dgv1->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle3->BackColor = System::Drawing::Color::DarkOliveGreen;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 20));
			dataGridViewCellStyle3->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::Color::OliveDrab;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgv1->RowHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->dgv1->RowHeadersVisible = false;
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->dgv1->RowsDefaultCellStyle = dataGridViewCellStyle4;
			this->dgv1->RowTemplate->Height = 50;
			this->dgv1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgv1->Size = System::Drawing::Size(820, 660);
			this->dgv1->TabIndex = 1;
			this->dgv1->DoubleClick += gcnew System::EventHandler(this, &Login::dgv1_DoubleClick);
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::SeaGreen;
			this->panel3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel3.BackgroundImage")));
			this->panel3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel3->Controls->Add(this->label1);
			this->panel3->Controls->Add(this->pictureBox3);
			this->panel3->Location = System::Drawing::Point(756, 127);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(850, 783);
			this->panel3->TabIndex = 10;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(84, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(300, 70);
			this->label1->TabIndex = 8;
			this->label1->Text = L"NOMBRE";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.BackgroundImage")));
			this->pictureBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox3->Location = System::Drawing::Point(573, 14);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(95, 87);
			this->pictureBox3->TabIndex = 7;
			this->pictureBox3->TabStop = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Candara", 22.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(742, 34);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(408, 82);
			this->label3->TabIndex = 2;
			this->label3->Text = L"JUGADORES:";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(770, 947);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(824, 196);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->WaitOnLoad = true;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &Login::pictureBox1_Click);
			this->pictureBox1->MouseLeave += gcnew System::EventHandler(this, &Login::pictureBox1_MouseLeave);
			this->pictureBox1->MouseHover += gcnew System::EventHandler(this, &Login::pictureBox1_MouseHover);
			// 
			// panel1
			// 
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->Controls->Add(this->pictureBox2);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->picMinimizar);
			this->panel1->Controls->Add(this->picCerrar);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(2414, 70);
			this->panel1->TabIndex = 3;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->Location = System::Drawing::Point(17, 3);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(72, 63);
			this->pictureBox2->TabIndex = 25;
			this->pictureBox2->TabStop = false;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::White;
			this->label6->Location = System::Drawing::Point(86, 6);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(212, 55);
			this->label6->TabIndex = 24;
			this->label6->Text = L"TUTINT";
			// 
			// picMinimizar
			// 
			this->picMinimizar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->picMinimizar->BackColor = System::Drawing::Color::Transparent;
			this->picMinimizar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picMinimizar.BackgroundImage")));
			this->picMinimizar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->picMinimizar->Location = System::Drawing::Point(2270, 4);
			this->picMinimizar->Name = L"picMinimizar";
			this->picMinimizar->Size = System::Drawing::Size(64, 59);
			this->picMinimizar->TabIndex = 5;
			this->picMinimizar->TabStop = false;
			this->picMinimizar->Click += gcnew System::EventHandler(this, &Login::picMinimizar_Click);
			// 
			// picCerrar
			// 
			this->picCerrar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->picCerrar->BackColor = System::Drawing::Color::Transparent;
			this->picCerrar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picCerrar.BackgroundImage")));
			this->picCerrar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->picCerrar->Location = System::Drawing::Point(2345, 4);
			this->picCerrar->Name = L"picCerrar";
			this->picCerrar->Size = System::Drawing::Size(64, 59);
			this->picCerrar->TabIndex = 4;
			this->picCerrar->TabStop = false;
			this->picCerrar->Click += gcnew System::EventHandler(this, &Login::picCerrar_Click);
			// 
			// panelSecundario
			// 
			this->panelSecundario->BackColor = System::Drawing::Color::Transparent;
			this->panelSecundario->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelSecundario->Enabled = false;
			this->panelSecundario->Location = System::Drawing::Point(0, 0);
			this->panelSecundario->Margin = System::Windows::Forms::Padding(4);
			this->panelSecundario->Name = L"panelSecundario";
			this->panelSecundario->Size = System::Drawing::Size(2414, 1307);
			this->panelSecundario->TabIndex = 2;
			this->panelSecundario->Visible = false;
			// 
			// timer1
			// 
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &Login::timer1_Tick);
			// 
			// Login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(14, 29);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(2414, 1307);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panelSecundario);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Login";
			this->Opacity = 0;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Login";
			this->Activated += gcnew System::EventHandler(this, &Login::Login_Activated);
			this->Deactivate += gcnew System::EventHandler(this, &Login::Login_Deactivate);
			this->Load += gcnew System::EventHandler(this, &Login::Login_Load);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv1))->EndInit();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picMinimizar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCerrar))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		private: void inicializarTam();
		private: System::Void pictureBox1_MouseHover(System::Object^  sender, System::EventArgs^  e);
		private: System::Void pictureBox1_MouseLeave(System::Object^  sender, System::EventArgs^  e);
		private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e);
		private: System::Void Login_Load(System::Object^  sender, System::EventArgs^  e);
		private: System::Void picCerrar_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void picMinimizar_Click(System::Object^  sender, System::EventArgs^  e); 
		private: System::Void Login_Activated(System::Object^  sender, System::EventArgs^  e);
		private: System::Void Login_Deactivate(System::Object^  sender, System::EventArgs^  e);
		private: System::Void dgv1_DoubleClick(System::Object^  sender, System::EventArgs^  e);
	};
}
