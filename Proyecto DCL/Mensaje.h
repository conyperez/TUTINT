#pragma once

namespace Proyecto_DCL {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Mensaje
	/// </summary>
	public ref class Mensaje : public System::Windows::Forms::Form
	{
	public:
		Mensaje(void)
		{
			InitializeComponent();
		}
		Mensaje(int hab)
		{
			habilidad = hab;
			InitializeComponent();
			inicializar();
		}
	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Mensaje()
		{
			if (components)
			{
				delete components;
			}
		}
	private: int habilidad;
	private: System::Windows::Forms::Panel^  panelUno;
	private: System::Windows::Forms::PictureBox^  picUno;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::PictureBox^  picCinco;
	private: System::Windows::Forms::PictureBox^  picCuatro;
	private: System::Windows::Forms::PictureBox^  picTres;
	private: System::Windows::Forms::PictureBox^  picDos;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Panel^  panel1;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Mensaje::typeid));
			this->panelUno = (gcnew System::Windows::Forms::Panel());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->picCinco = (gcnew System::Windows::Forms::PictureBox());
			this->picCuatro = (gcnew System::Windows::Forms::PictureBox());
			this->picTres = (gcnew System::Windows::Forms::PictureBox());
			this->picDos = (gcnew System::Windows::Forms::PictureBox());
			this->picUno = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panelUno->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCinco))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCuatro))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picTres))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picDos))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picUno))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panelUno
			// 
			this->panelUno->BackColor = System::Drawing::Color::Transparent;
			this->panelUno->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panelUno.BackgroundImage")));
			this->panelUno->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panelUno->Controls->Add(this->pictureBox2);
			this->panelUno->Controls->Add(this->pictureBox1);
			this->panelUno->Controls->Add(this->picCinco);
			this->panelUno->Controls->Add(this->picCuatro);
			this->panelUno->Controls->Add(this->picTres);
			this->panelUno->Controls->Add(this->picDos);
			this->panelUno->Controls->Add(this->picUno);
			this->panelUno->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelUno->Location = System::Drawing::Point(0, 0);
			this->panelUno->Margin = System::Windows::Forms::Padding(4);
			this->panelUno->Name = L"panelUno";
			this->panelUno->Size = System::Drawing::Size(1657, 774);
			this->panelUno->TabIndex = 0;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->Location = System::Drawing::Point(391, 12);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(856, 221);
			this->pictureBox2->TabIndex = 10;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(532, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(635, 187);
			this->pictureBox1->TabIndex = 9;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Visible = false;
			// 
			// picCinco
			// 
			this->picCinco->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->picCinco->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picCinco.BackgroundImage")));
			this->picCinco->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->picCinco->Location = System::Drawing::Point(355, 291);
			this->picCinco->Margin = System::Windows::Forms::Padding(4);
			this->picCinco->Name = L"picCinco";
			this->picCinco->Size = System::Drawing::Size(912, 478);
			this->picCinco->TabIndex = 7;
			this->picCinco->TabStop = false;
			this->picCinco->Visible = false;
			// 
			// picCuatro
			// 
			this->picCuatro->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->picCuatro->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picCuatro.BackgroundImage")));
			this->picCuatro->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->picCuatro->Location = System::Drawing::Point(378, 273);
			this->picCuatro->Margin = System::Windows::Forms::Padding(4);
			this->picCuatro->Name = L"picCuatro";
			this->picCuatro->Size = System::Drawing::Size(873, 478);
			this->picCuatro->TabIndex = 6;
			this->picCuatro->TabStop = false;
			this->picCuatro->Visible = false;
			// 
			// picTres
			// 
			this->picTres->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->picTres->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picTres.BackgroundImage")));
			this->picTres->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->picTres->Location = System::Drawing::Point(582, 273);
			this->picTres->Margin = System::Windows::Forms::Padding(4);
			this->picTres->Name = L"picTres";
			this->picTres->Size = System::Drawing::Size(493, 494);
			this->picTres->TabIndex = 5;
			this->picTres->TabStop = false;
			this->picTres->Visible = false;
			// 
			// picDos
			// 
			this->picDos->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->picDos->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picDos.BackgroundImage")));
			this->picDos->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->picDos->Location = System::Drawing::Point(483, 273);
			this->picDos->Margin = System::Windows::Forms::Padding(4);
			this->picDos->Name = L"picDos";
			this->picDos->Size = System::Drawing::Size(736, 478);
			this->picDos->TabIndex = 4;
			this->picDos->TabStop = false;
			this->picDos->Visible = false;
			// 
			// picUno
			// 
			this->picUno->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->picUno->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picUno.BackgroundImage")));
			this->picUno->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->picUno->Location = System::Drawing::Point(483, 273);
			this->picUno->Margin = System::Windows::Forms::Padding(4);
			this->picUno->Name = L"picUno";
			this->picUno->Size = System::Drawing::Size(711, 491);
			this->picUno->TabIndex = 0;
			this->picUno->TabStop = false;
			this->picUno->Visible = false;
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->button1->BackColor = System::Drawing::Color::OliveDrab;
			this->button1->Font = (gcnew System::Drawing::Font(L"Candara", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(643, 8);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(366, 73);
			this->button1->TabIndex = 2;
			this->button1->Text = L"CONTINUAR";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Mensaje::button1_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &Mensaje::timer1_Tick);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->Controls->Add(this->button1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel1->Location = System::Drawing::Point(0, 774);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1657, 101);
			this->panel1->TabIndex = 11;
			// 
			// Mensaje
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(14, 29);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1657, 875);
			this->Controls->Add(this->panelUno);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Mensaje";
			this->Opacity = 0;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Mensaje";
			this->Load += gcnew System::EventHandler(this, &Mensaje::Mensaje_Load);
			this->panelUno->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCinco))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCuatro))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picTres))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picDos))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picUno))->EndInit();
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
		private: void SonidoUno();
		private: void SonidoDos();
		private: void SonidoTres();
		private: void SonidoCuatro();
		private: void SonidoCinco();
		private: void iniciarPic();
		private: void inicializar();
		private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void Mensaje_Load(System::Object^  sender, System::EventArgs^  e);
		private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e);
	};
}
