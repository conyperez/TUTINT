#include "Act1DosBB.h"
#include "ManejadorMI.h"
#include "FormEstrella.h"
#include "Advertencia.h"
#include "PrincipalUno.h"
#include <windows.h>
#include <MMSystem.h>
#include <string>
#include <msclr\marshal_cppstd.h>

System::Void Proyecto_DCL::Act1DosBB::inicializarTam() {
	wVolver = this->btnVolver->Size.Width;
	hVolver = this->btnVolver->Size.Height;
	wListo = this->btnListo->Size.Width;
	hListo = this->btnListo->Size.Height;
	wAyuda = this->btnAyuda->Size.Width;
	hAyuda = this->btnAyuda->Size.Height;
}
System::Void Proyecto_DCL::Act1DosBB::comprobarRespuestas() {
	if (listoPez == true && listoSol == true && listoPelota == true && listoSirena == true) {
		this->btnListo->Visible = true;
		this->btnListo->Enabled = true;
	}
}
System::Void Proyecto_DCL::Act1DosBB::btnVolver_Click(System::Object^  sender, System::EventArgs^  e) {
	//hiloAct->Abort();
	Advertencia^ ventana = gcnew Advertencia("etapaUno", this, false, manejadorBD);
	ventana->ShowDialog();
}
vector<TiempoMI*> Proyecto_DCL::Act1DosBB::obtenerTiempoItems() {
	vector<TiempoMI*> tiempoItems;
	TiempoMI* tmp = new TiempoMI();
	tmp->setMinutos(t_item1->getMinutos());
	tmp->setSegundos(t_item1->getSegundos());
	tiempoItems.push_back(tmp);
	tmp->setMinutos(t_item2->getMinutos());
	tmp->setSegundos(t_item2->getSegundos());
	tiempoItems.push_back(tmp);
	tmp->setMinutos(t_item3->getMinutos());
	tmp->setSegundos(t_item3->getSegundos());
	tiempoItems.push_back(tmp);
	tmp->setMinutos(t_item4->getMinutos());
	tmp->setSegundos(t_item4->getSegundos());
	tiempoItems.push_back(tmp);

	return tiempoItems;
}
System::Void Proyecto_DCL::Act1DosBB::btnListo_Click(System::Object^  sender, System::EventArgs^  e) {
	hiloAct->Abort();
	t_actividad->setIniciar(false);

	vector<TiempoMI*> tiempoItems = obtenerTiempoItems();
	TiempoMI* tiempoAct = new TiempoMI();
	tiempoAct->setMinutos(t_actividad->getMinutos());
	tiempoAct->setSegundos(t_actividad->getSegundos());

	vector<string> respuestas;
	msclr::interop::marshal_context context;

	string stringBtn1 = context.marshal_as<std::string>(this->btn1->Text->ToString());
	string stringRoca = stringBtn1 + "OCA";
	respuestas.push_back(stringRoca);
	stringBtn1.clear();

	string stringBtn2 = context.marshal_as<std::string>(this->btn2->Text->ToString());
	string stringDelfin = stringBtn2 + "ELFIN";
	respuestas.push_back(stringDelfin);
	stringBtn2.clear();

	string stringBtn3 = context.marshal_as<std::string>(this->btn3->Text->ToString());
	string stringMedusa = stringBtn3 + "EDUSA";
	respuestas.push_back(stringMedusa);
	stringBtn3.clear();

	string stringBtn4 = context.marshal_as<std::string>(this->btn4->Text->ToString());
	string stringPulpo = stringBtn4 + "ULPO";
	respuestas.push_back(stringPulpo);
	stringBtn4.clear();

	controlador->setPercepcionesActividad(respuestas, contAyuda, tiempoItems, tiempoAct);
	controlador->obtenerNivelLogro();
	//manejadorBD->setNumeroActividad(1);		// Eso sigue igual?
	FormEstrella^ ventana = gcnew FormEstrella(controlador, manejadorBD, "Conciencia_fonologica", this);
	ventana->ShowDialog();
}
System::Void Proyecto_DCL::Act1DosBB::btnVolver_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnVolver->Size = System::Drawing::Size(wVolver + 5, hVolver + 5);
}
System::Void Proyecto_DCL::Act1DosBB::btnVolver_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnVolver->Size = System::Drawing::Size(wVolver, hVolver);
}
System::Void Proyecto_DCL::Act1DosBB::btnListo_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnListo->Size = System::Drawing::Size(wListo + 5, hListo + 5);
}
System::Void Proyecto_DCL::Act1DosBB::btnListo_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnListo->Size = System::Drawing::Size(wListo, hListo);
}
System::Void Proyecto_DCL::Act1DosBB::btnAyuda_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnAyuda->Size = System::Drawing::Size(wAyuda + 5, hAyuda + 5);
}
System::Void Proyecto_DCL::Act1DosBB::btnAyuda_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnAyuda->Size = System::Drawing::Size(wAyuda, hAyuda);
}
System::Void Proyecto_DCL::Act1DosBB::sonidoInicial() {
	//PlaySound(TEXT("Audios/Oceano/actividad_1.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::Act1DosBB::btnAyuda_Click(System::Object^  sender, System::EventArgs^  e) {
	//sonidoInicial();
	this->contAyuda++;
}
System::Void Proyecto_DCL::Act1DosBB::picCerrar_Click(System::Object^  sender, System::EventArgs^  e) {
	hiloAct->Abort();
	Application::Exit();
}
System::Void Proyecto_DCL::Act1DosBB::picMinimizar_Click(System::Object^  sender, System::EventArgs^  e) {
	this->WindowState = FormWindowState::Minimized;
}
System::Void Proyecto_DCL::Act1DosBB::timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	this->Opacity += .1;
	//Detener el timer
	if (this->Opacity == 1) {
		this->timer1->Stop();
		this->form->Close();
		//sonidoInicial();
	}
}
System::Void Proyecto_DCL::Act1DosBB::Act1DosBB_Load(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
	//sumar tiempo que demora en dar la instrucción a t_actividad
	t_actividad = gcnew TiempoGUI();
	//t_actividad->setSegundos(tiempo de reproduccion de actividad);
	t_item1 = gcnew TiempoGUI();
	t_item2 = gcnew TiempoGUI();
	t_item3 = gcnew TiempoGUI();
	t_item4 = gcnew TiempoGUI();
	hiloAct = gcnew Thread(gcnew ThreadStart(t_actividad, &TiempoGUI::cronometro));
	hiloAct->Start();
}
System::Void Proyecto_DCL::Act1DosBB::Act1DosBB_Activated(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
}
System::Void Proyecto_DCL::Act1DosBB::Act1DosBB_Deactivate(System::Object^  sender, System::EventArgs^  e) {
	if (this->WindowState == FormWindowState::Minimized) {
		this->Opacity = 0;
	}
}
System::Void Proyecto_DCL::Act1DosBB::tiempo_respuesta(int numItem, TiempoGUI^ tr_item, System::Windows::Forms::Button^ btn)
{
	if (btn->BackColor != System::Drawing::Color::ForestGreen) {
		int tiempo_total_seg;
		if (numItem == 1)
		{
			tiempo_total_seg = t_item1->segundostotales();
			if (tiempo_total_seg < t_item2->segundostotales()) {
				tiempo_total_seg = t_item2->segundostotales();
			}
			if (tiempo_total_seg < t_item3->segundostotales()) {
				tiempo_total_seg = t_item3->segundostotales();
			}
			if (tiempo_total_seg < t_item4->segundostotales()) {
				tiempo_total_seg = t_item4->segundostotales();
			}
		}
		else if (numItem == 2)
		{
			tiempo_total_seg = t_item2->segundostotales();
			if (tiempo_total_seg < t_item1->segundostotales()) {
				tiempo_total_seg = t_item1->segundostotales();
			}
			else if (tiempo_total_seg < t_item3->segundostotales()) {
				tiempo_total_seg = t_item3->segundostotales();
			}
			else if (tiempo_total_seg < t_item4->segundostotales()) {
				tiempo_total_seg = t_item4->segundostotales();
			}

		}
		else if (numItem == 3)
		{
			tiempo_total_seg = t_item3->segundostotales();
			if (tiempo_total_seg < t_item1->segundostotales()) {
				tiempo_total_seg = t_item1->segundostotales();
			}
			if (tiempo_total_seg < t_item2->segundostotales()) {
				tiempo_total_seg = t_item2->segundostotales();
			}
			if (tiempo_total_seg < t_item4->segundostotales()) {
				tiempo_total_seg = t_item4->segundostotales();
			}
		}
		else if (numItem == 4)
		{
			tiempo_total_seg = t_item4->segundostotales();
			if (tiempo_total_seg < t_item1->segundostotales()) {
				tiempo_total_seg = t_item1->segundostotales();
			}
			if (tiempo_total_seg < t_item2->segundostotales()) {
				tiempo_total_seg = t_item2->segundostotales();
			}
			if (tiempo_total_seg < t_item3->segundostotales()) {
				tiempo_total_seg = t_item3->segundostotales();
			}
		}
		//comparo la diferencia de tiempo entre el tr mayor y el de la actividad para sacar un tiempo de respuesta vertical.
		int diferencia = t_actividad->segundostotales() - tiempo_total_seg;
		tr_item->setMinutos(diferencia / 60);
		tr_item->setSegundos(diferencia % 60);
		//System::Windows::Forms::MessageBox::Show("Tiempo:\nMinutos: " + Convert::ToString(tr_item->getMinutos())+ "\nSegundos: "+ Convert::ToString(tr_item->getSegundos()));
	}
	else {
		//System::Windows::Forms::MessageBox::Show("Ya se clickeo");
	}
}
System::Void Proyecto_DCL::Act1DosBB::inicializarColor1() {
	this->btn1R->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
		static_cast<System::Int32>(static_cast<System::Byte>(0)));
	this->btn1T->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
		static_cast<System::Int32>(static_cast<System::Byte>(0)));
	this->btn1S->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
		static_cast<System::Int32>(static_cast<System::Byte>(0)));
}
System::Void Proyecto_DCL::Act1DosBB::inicializarColor2() {
	this->btn2M->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
		static_cast<System::Int32>(static_cast<System::Byte>(0)));
	this->btn2R->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
		static_cast<System::Int32>(static_cast<System::Byte>(0)));
	this->btn2D->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
		static_cast<System::Int32>(static_cast<System::Byte>(0)));
}
System::Void Proyecto_DCL::Act1DosBB::inicializarColor3() {
	this->btn3D->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
		static_cast<System::Int32>(static_cast<System::Byte>(0)));
	this->btn3P->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
		static_cast<System::Int32>(static_cast<System::Byte>(0)));
	this->btn3M->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
		static_cast<System::Int32>(static_cast<System::Byte>(0)));
}
System::Void Proyecto_DCL::Act1DosBB::inicializarColor4() {
	this->btn4B->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
		static_cast<System::Int32>(static_cast<System::Byte>(0)));
	this->btn4P->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
		static_cast<System::Int32>(static_cast<System::Byte>(0)));
	this->btn4R->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
		static_cast<System::Int32>(static_cast<System::Byte>(0)));
}
System::Void Proyecto_DCL::Act1DosBB::btn1R_Click(System::Object^  sender, System::EventArgs^  e) {
	tiempo_respuesta(1, t_item1, btn1R);
	inicializarColor1();
	btn1R->BackColor = System::Drawing::Color::ForestGreen;
	String^ letra = btn1R->Text;
	this->btn1->Text = letra;
	listoPez = true;
	comprobarRespuestas();
}
System::Void Proyecto_DCL::Act1DosBB::btn1T_Click(System::Object^  sender, System::EventArgs^  e) {
	tiempo_respuesta(1, t_item1, btn1T);
	inicializarColor1();
	btn1T->BackColor = System::Drawing::Color::ForestGreen;
	String^ letra = btn1T->Text;
	this->btn1->Text = letra;
	listoPez = true;
	comprobarRespuestas();
}
System::Void Proyecto_DCL::Act1DosBB::btn1S_Click(System::Object^  sender, System::EventArgs^  e) {
	tiempo_respuesta(1, t_item1, btn1S);
	inicializarColor1();
	btn1S->BackColor = System::Drawing::Color::ForestGreen;
	String^ letra = btn1S->Text;
	this->btn1->Text = letra;
	listoPez = true;
	comprobarRespuestas();
}
System::Void Proyecto_DCL::Act1DosBB::btn2M_Click(System::Object^  sender, System::EventArgs^  e) {
	tiempo_respuesta(2, t_item2, btn2M);
	inicializarColor2();
	btn2M->BackColor = System::Drawing::Color::ForestGreen;
	String^ letra = btn2M->Text;
	this->btn2->Text = letra;
	listoSol = true;
	comprobarRespuestas();
}
System::Void Proyecto_DCL::Act1DosBB::btn2R_Click(System::Object^  sender, System::EventArgs^  e) {
	tiempo_respuesta(2, t_item2, btn2R);
	inicializarColor2();
	btn2R->BackColor = System::Drawing::Color::ForestGreen;
	String^ letra = btn2R->Text;
	this->btn2->Text = letra;
	listoSol = true;
	comprobarRespuestas();
}
System::Void Proyecto_DCL::Act1DosBB::btn2D_Click(System::Object^  sender, System::EventArgs^  e) {
	tiempo_respuesta(2, t_item2, btn2D);
	inicializarColor2();
	btn2D->BackColor = System::Drawing::Color::ForestGreen;
	String^ letra = btn2D->Text;
	this->btn2->Text = letra;
	listoSol = true;
	comprobarRespuestas();
}
System::Void Proyecto_DCL::Act1DosBB::btn3D_Click(System::Object^  sender, System::EventArgs^  e) {
	tiempo_respuesta(3, t_item3, btn3D);
	inicializarColor3();
	btn3D->BackColor = System::Drawing::Color::ForestGreen;
	String^ letra = btn3D->Text;
	this->btn3->Text = letra;
	listoPelota = true;
	comprobarRespuestas();
}
System::Void Proyecto_DCL::Act1DosBB::btn3P_Click(System::Object^  sender, System::EventArgs^  e) {
	tiempo_respuesta(3, t_item3, btn3P);
	inicializarColor3();
	btn3P->BackColor = System::Drawing::Color::ForestGreen;
	String^ letra = btn3P->Text;
	this->btn3->Text = letra;
	listoPelota = true;
	comprobarRespuestas();
}
System::Void Proyecto_DCL::Act1DosBB::btn3M_Click(System::Object^  sender, System::EventArgs^  e) {
	tiempo_respuesta(3, t_item3, btn3M);
	inicializarColor3();
	btn3M->BackColor = System::Drawing::Color::ForestGreen;
	String^ letra = btn3M->Text;
	this->btn3->Text = letra;
	listoPelota = true;
	comprobarRespuestas();
}
System::Void Proyecto_DCL::Act1DosBB::btn4B_Click(System::Object^  sender, System::EventArgs^  e) {
	tiempo_respuesta(4, t_item4, btn4B);
	inicializarColor4();
	btn4B->BackColor = System::Drawing::Color::ForestGreen;
	String^ letra = btn4B->Text;
	this->btn4->Text = letra;
	listoSirena = true;
	comprobarRespuestas();
}
System::Void Proyecto_DCL::Act1DosBB::btn4P_Click(System::Object^  sender, System::EventArgs^  e) {
	tiempo_respuesta(4, t_item4, btn4P);
	inicializarColor4();
	btn4P->BackColor = System::Drawing::Color::ForestGreen;
	String^ letra = btn4P->Text;
	this->btn4->Text = letra;
	listoSirena = true;
	comprobarRespuestas();
}
System::Void Proyecto_DCL::Act1DosBB::btn4R_Click(System::Object^  sender, System::EventArgs^  e) {
	tiempo_respuesta(4, t_item4, btn4R);
	inicializarColor4();
	btn4R->BackColor = System::Drawing::Color::ForestGreen;
	String^ letra = btn4R->Text;
	this->btn4->Text = letra;
	listoSirena = true;
	comprobarRespuestas();
}


