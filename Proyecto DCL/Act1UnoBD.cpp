#include "Act1UnoBD.h"
#include "FormEstrella.h"
#include "Advertencia.h"
#include "PrincipalUno.h"
#include <windows.h>
#include <MMSystem.h>
#include <string>
#include <msclr\marshal_cppstd.h>

System::Void Proyecto_DCL::Act1UnoBD::inicializarTam() {
	wVolver = this->btnVolver->Size.Width;
	hVolver = this->btnVolver->Size.Height;
	wListo = this->btnListo->Size.Width;
	hListo = this->btnListo->Size.Height;
	wAyuda = this->btnAyuda->Size.Width;
	hAyuda = this->btnAyuda->Size.Height;
}
System::Void Proyecto_DCL::Act1UnoBD::comprobarRespuestas() {
	if (listoPin1 == true && listoPin2 == true && listoManta1 == true && listoManta2 == true && listoAlme1 == true && listoAlme2 == true && listoBa1 == true && listoBa2 == true) {
		this->btnListo->Visible = true;
		this->btnListo->Enabled = true;
	}
}
System::Void Proyecto_DCL::Act1UnoBD::btnVolver_Click(System::Object^  sender, System::EventArgs^  e) {
	//hiloAct->Abort();
	Advertencia^ ventana = gcnew Advertencia("etapaUno", this, false, manejadorBD);
	ventana->ShowDialog();
}
vector<TiempoMI*> Proyecto_DCL::Act1UnoBD::obtenerTiempoItems() {
	vector<TiempoMI*> tiempoItems;
	TiempoMI* tmp= new TiempoMI();
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
System::Void Proyecto_DCL::Act1UnoBD::btnListo_Click(System::Object^  sender, System::EventArgs^  e) {
	hiloAct->Abort();
	t_actividad->setIniciar(false);

	vector<TiempoMI*> tiempoItems = obtenerTiempoItems();
	TiempoMI* tiempoAct = new TiempoMI();
	tiempoAct->setMinutos(t_actividad->getMinutos());
	tiempoAct->setSegundos(t_actividad->getSegundos());

	vector<string> respuestas;
	msclr::interop::marshal_context context;

	string stringBtn1 = context.marshal_as<std::string>(this->btn1->Text->ToString());
	string stringBtn2 = context.marshal_as<std::string>(this->btn2->Text->ToString());
	string stringPin = "P" + stringBtn1 + "NGUI" + stringBtn2 + "O";
	respuestas.push_back(stringPin);
	stringBtn1.clear();
	stringBtn2.clear();

	string stringBtn3 = context.marshal_as<std::string>(this->btn3->Text->ToString());
	string stringBtn4 = context.marshal_as<std::string>(this->btn4->Text->ToString());
	string stringBa = "B" + stringBtn3 + "LLE" + stringBtn4 + "A";
	respuestas.push_back(stringBa);
	stringBtn3.clear();
	stringBtn4.clear();

	string stringBtn5 = context.marshal_as<std::string>(this->btn5->Text->ToString());
	string stringBtn6 = context.marshal_as<std::string>(this->btn6->Text->ToString());
	string stringMan = "MA" + stringBtn5 + "T" + stringBtn6 + "RRAYA";
	respuestas.push_back(stringMan);
	stringBtn5.clear();
	stringBtn6.clear();

	string stringBtn7 = context.marshal_as<std::string>(this->btn7->Text->ToString());
	string stringBtn8 = context.marshal_as<std::string>(this->btn8->Text->ToString());
	string stringAlm = "A" + stringBtn1 + "ME" + stringBtn2 + "A";
	respuestas.push_back(stringAlm);
	stringBtn7.clear();
	stringBtn8.clear();

	controlador->setPercepcionesActividad(respuestas, contAyuda, tiempoItems, tiempoAct);
	controlador->obtenerNivelLogro();
	//manejadorBD->setNumeroActividad(1);		// Eso sigue igual?
	FormEstrella^ ventana = gcnew FormEstrella(controlador, manejadorBD, "Conciencia_fonologica", this);
	ventana->ShowDialog();
}
System::Void Proyecto_DCL::Act1UnoBD::btnVolver_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnVolver->Size = System::Drawing::Size(wVolver + 5, hVolver + 5);
}
System::Void Proyecto_DCL::Act1UnoBD::btnVolver_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnVolver->Size = System::Drawing::Size(wVolver, hVolver);
}
System::Void Proyecto_DCL::Act1UnoBD::btnListo_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnListo->Size = System::Drawing::Size(wListo + 5, hListo + 5);
}
System::Void Proyecto_DCL::Act1UnoBD::btnListo_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnListo->Size = System::Drawing::Size(wListo, hListo);
}
System::Void Proyecto_DCL::Act1UnoBD::sonidoInicial() {
	//PlaySound(TEXT("Audios/Oceano/actividad_1.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::Act1UnoBD::btnAyuda_Click(System::Object^  sender, System::EventArgs^  e) {
	//sonidoInicial();
	this->contAyuda++;
}
System::Void Proyecto_DCL::Act1UnoBD::btnAyuda_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnAyuda->Size = System::Drawing::Size(wAyuda + 5, hAyuda + 5);
}
System::Void Proyecto_DCL::Act1UnoBD::btnAyuda_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnAyuda->Size = System::Drawing::Size(wAyuda, hAyuda);
}
System::Void Proyecto_DCL::Act1UnoBD::picCerrar_Click(System::Object^  sender, System::EventArgs^  e) {
	hiloAct->Abort();
	Application::Exit();
}
System::Void Proyecto_DCL::Act1UnoBD::picMinimizar_Click(System::Object^  sender, System::EventArgs^  e) {
	this->WindowState = FormWindowState::Minimized;
}
System::Void Proyecto_DCL::Act1UnoBD::timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	this->Opacity += .1;
	//Detener el timer
	if (this->Opacity == 1) {
		this->timer1->Stop();
		this->form->Close();
		sonidoInicial();
	}
}
System::Void Proyecto_DCL::Act1UnoBD::Act1UnoBD_Load(System::Object^  sender, System::EventArgs^  e) {
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
System::Void Proyecto_DCL::Act1UnoBD::Act1UnoBD_Activated(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
}
System::Void Proyecto_DCL::Act1UnoBD::Act1UnoBD_Deactivate(System::Object^  sender, System::EventArgs^  e) {
	if (this->WindowState == FormWindowState::Minimized) {
		this->Opacity = 0;
	}
}
System::Void Proyecto_DCL::Act1UnoBD::tiempo_respuesta(int numItem, TiempoGUI^ tr_item, System::Windows::Forms::Button^ btn1, System::Windows::Forms::Button^ btn2)
{
	if ((btn1->Text != "") && (btn2->Text != ""))
	{
		int tiempo_total_seg;
		switch (numItem)
		{
		case 1:
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
		case 2:
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
		case 3:
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
		case 4:
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
		if (tiempo_total_seg == tr_item->segundostotales()) {
			tr_item->setMinutos(t_actividad->getMinutos());
			tr_item->setSegundos(t_actividad->getSegundos());
		}
		else
		{
			int diferencia = t_actividad->segundostotales() - tiempo_total_seg;
			tr_item->setMinutos(diferencia / 60);
			tr_item->setSegundos(diferencia % 60);
		}

		//System::Windows::Forms::MessageBox::Show("Tiempo:\nMinutos: " + Convert::ToString(tr_item->getMinutos())+ "\nSegundos: "+ Convert::ToString(tr_item->getSegundos()));
	}
}
System::Void Proyecto_DCL::Act1UnoBD::btn1_Click(System::Object^  sender, System::EventArgs^  e) {
	this->presBtn1 = true;
}
System::Void Proyecto_DCL::Act1UnoBD::btn2_Click(System::Object^  sender, System::EventArgs^  e) {
	this->presBtn2 = true;
}
System::Void Proyecto_DCL::Act1UnoBD::btn3_Click(System::Object^  sender, System::EventArgs^  e) {
	this->presBtn3 = true;
}
System::Void Proyecto_DCL::Act1UnoBD::btn4_Click(System::Object^  sender, System::EventArgs^  e) {
	this->presBtn4 = true;
}
System::Void Proyecto_DCL::Act1UnoBD::btn5_Click(System::Object^  sender, System::EventArgs^  e) {
	this->presBtn5 = true;
}
System::Void Proyecto_DCL::Act1UnoBD::btn6_Click(System::Object^  sender, System::EventArgs^  e) {
	this->presBtn6 = true;
}
System::Void Proyecto_DCL::Act1UnoBD::btn7_Click(System::Object^  sender, System::EventArgs^  e) {
	this->presBtn7 = true;
}
System::Void Proyecto_DCL::Act1UnoBD::btn8_Click(System::Object^  sender, System::EventArgs^  e) {
	this->presBtn8 = true;
}
System::Void Proyecto_DCL::Act1UnoBD::btn1I_Click(System::Object^  sender, System::EventArgs^  e) {
	//tiempo_respuesta(1, t_item1, btn1I);
	String^ letra = btn1I->Text;
	if (this->presBtn1 == true) {
		this->btn1->Text = letra;
		tiempo_respuesta(1, t_item1, btn1, btn2);
		listoPin1 = true;
		this->presBtn1 = false;
	}
	else if (this->presBtn2 == true) {
		this->btn2->Text = letra;
		tiempo_respuesta(1, t_item1, btn1, btn2);
		listoPin2 = true;
		this->presBtn2 = false;
	}
	comprobarRespuestas();
}
System::Void Proyecto_DCL::Act1UnoBD::btn1A_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ letra = btn1A->Text;
	if (this->presBtn1 == true) {
		this->btn1->Text = letra;
		tiempo_respuesta(1, t_item1, btn1, btn2);
		listoPin1 = true;
		this->presBtn1 = false;
	}
	else if (this->presBtn2 == true) {
		this->btn2->Text = letra;
		tiempo_respuesta(1, t_item1, btn1, btn2);
		listoPin2 = true;
		this->presBtn2 = false;
	}
	comprobarRespuestas();
}
System::Void Proyecto_DCL::Act1UnoBD::btn1L_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ letra = btn1L->Text;
	if (this->presBtn1 == true) {
		this->btn1->Text = letra;
		tiempo_respuesta(1, t_item1, btn1, btn2);
		listoPin1 = true;
		this->presBtn1 = false;
	}
	else if (this->presBtn2 == true) {
		this->btn2->Text = letra;
		tiempo_respuesta(1, t_item1, btn1, btn2);
		listoPin2 = true;
		this->presBtn2 = false;
	}
	comprobarRespuestas();
}
System::Void Proyecto_DCL::Act1UnoBD::btn1N_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ letra = btn1N->Text;
	if (this->presBtn1 == true) {
		this->btn1->Text = letra;
		tiempo_respuesta(1, t_item1, btn1, btn2);
		listoPin1 = true;
		this->presBtn1 = false;
	}
	else if (this->presBtn2 == true) {
		this->btn2->Text = letra;
		tiempo_respuesta(1, t_item1, btn1, btn2);
		listoPin2 = true;
		this->presBtn2 = false;
	}
	comprobarRespuestas();
}
System::Void Proyecto_DCL::Act1UnoBD::btn2T_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ letra = btn2T->Text;
	if (this->presBtn3 == true) {
		this->btn3->Text = letra;
		tiempo_respuesta(2, t_item2, btn3, btn4);
		listoBa1 = true;
		this->presBtn3 = false;
	}
	else if (this->presBtn4 == true) {
		this->btn4->Text = letra;
		tiempo_respuesta(2, t_item2, btn3, btn4);
		listoBa2 = true;
		this->presBtn4 = false;
	}
	comprobarRespuestas();
}
System::Void Proyecto_DCL::Act1UnoBD::btn2A_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ letra = btn2A->Text;
	if (this->presBtn3 == true) {
		this->btn3->Text = letra;
		tiempo_respuesta(2, t_item2, btn3, btn4);
		listoBa1 = true;
		this->presBtn3 = false;
	}
	else if (this->presBtn4 == true) {
		this->btn4->Text = letra;
		tiempo_respuesta(2, t_item2, btn3, btn4);
		listoBa2 = true;
		this->presBtn4 = false;
	}
	comprobarRespuestas();
}
System::Void Proyecto_DCL::Act1UnoBD::btn2R_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ letra = btn2R->Text;
	if (this->presBtn3 == true) {
		this->btn3->Text = letra;
		tiempo_respuesta(2, t_item2, btn3, btn4);
		listoBa1 = true;
		this->presBtn3 = false;
	}
	else if (this->presBtn4 == true) {
		this->btn4->Text = letra;
		tiempo_respuesta(2, t_item2, btn3, btn4);
		listoBa2 = true;
		this->presBtn4 = false;
	}
	comprobarRespuestas();
}
System::Void Proyecto_DCL::Act1UnoBD::btn2N_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ letra = btn2N->Text;
	if (this->presBtn3 == true) {
		this->btn3->Text = letra;
		tiempo_respuesta(2, t_item2, btn3, btn4);
		listoBa1 = true;
		this->presBtn3 = false;
	}
	else if (this->presBtn4 == true) {
		this->btn4->Text = letra;
		tiempo_respuesta(2, t_item2, btn3, btn4);
		listoBa2 = true;
		this->presBtn4 = false;
	}
	comprobarRespuestas();
}
System::Void Proyecto_DCL::Act1UnoBD::btn3F_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ letra = btn3F->Text;
	if (this->presBtn5 == true) {
		this->btn5->Text = letra;
		tiempo_respuesta(3, t_item3, btn5, btn6);
		listoManta1 = true;
		this->presBtn5 = false;
	}
	else if (this->presBtn6 == true) {
		this->btn6->Text = letra;
		tiempo_respuesta(3, t_item3, btn5, btn6);
		listoManta2 = true;
		this->presBtn6 = false;
	}
	comprobarRespuestas();
}
System::Void Proyecto_DCL::Act1UnoBD::btn3A_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ letra = btn3A->Text;
	if (this->presBtn5 == true) {
		this->btn5->Text = letra;
		tiempo_respuesta(3, t_item3, btn5, btn6);
		listoManta1 = true;
		this->presBtn5 = false;
	}
	else if (this->presBtn6 == true) {
		this->btn6->Text = letra;
		tiempo_respuesta(3, t_item3, btn5, btn6);
		listoManta2 = true;
		this->presBtn6 = false;
	}
	comprobarRespuestas();
}
System::Void Proyecto_DCL::Act1UnoBD::btn3N_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ letra = btn3N->Text;
	if (this->presBtn5 == true) {
		this->btn5->Text = letra;
		tiempo_respuesta(3, t_item3, btn5, btn6);
		listoManta1 = true;
		this->presBtn5 = false;
	}
	else if (this->presBtn6 == true) {
		this->btn6->Text = letra;
		tiempo_respuesta(3, t_item3, btn5, btn6);
		listoManta2 = true;
		this->presBtn6 = false;
	}
	comprobarRespuestas();
}
System::Void Proyecto_DCL::Act1UnoBD::btn3M_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ letra = btn3M->Text;
	if (this->presBtn5 == true) {
		this->btn5->Text = letra;
		tiempo_respuesta(3, t_item3, btn5, btn6);
		listoManta1 = true;
		this->presBtn5 = false;
	}
	else if (this->presBtn6 == true) {
		this->btn6->Text = letra;
		tiempo_respuesta(3, t_item3, btn5, btn6);
		listoManta2 = true;
		this->presBtn6 = false;
	}
	comprobarRespuestas();
}
System::Void Proyecto_DCL::Act1UnoBD::btn4L_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ letra = btn4L->Text;
	if (this->presBtn7 == true) {
		this->btn7->Text = letra;
		tiempo_respuesta(4, t_item4, btn7, btn8);
		listoAlme1 = true;
		this->presBtn7 = false;
	}
	else if (this->presBtn8 == true) {
		this->btn8->Text = letra;
		tiempo_respuesta(4, t_item4, btn7, btn8);
		listoAlme2 = true;
		this->presBtn8 = false;
	}
	comprobarRespuestas();
}
System::Void Proyecto_DCL::Act1UnoBD::btn4F_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ letra = btn4F->Text;
	if (this->presBtn7 == true) {
		this->btn7->Text = letra;
		tiempo_respuesta(4, t_item4, btn7, btn8);
		listoAlme1 = true;
		this->presBtn7 = false;
	}
	else if (this->presBtn8 == true) {
		this->btn8->Text = letra;
		tiempo_respuesta(4, t_item4, btn7, btn8);
		listoAlme2 = true;
		this->presBtn8 = false;
	}
	comprobarRespuestas();
}
System::Void Proyecto_DCL::Act1UnoBD::btn4J_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ letra = btn4J->Text;
	if (this->presBtn7 == true) {
		this->btn7->Text = letra;
		tiempo_respuesta(4, t_item4, btn7, btn8);
		listoAlme1 = true;
		this->presBtn7 = false;
	}
	else if (this->presBtn8 == true) {
		this->btn8->Text = letra;
		tiempo_respuesta(4, t_item4, btn7, btn8);
		listoAlme2 = true;
		this->presBtn8 = false;
	}
	comprobarRespuestas();
}
System::Void Proyecto_DCL::Act1UnoBD::btn4B_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ letra = btn4B->Text;
	if (this->presBtn7 == true) {
		this->btn7->Text = letra;
		tiempo_respuesta(4, t_item4, btn7, btn8);
		listoAlme1 = true;
		this->presBtn7 = false;
	}
	else if (this->presBtn8 == true) {
		this->btn8->Text = letra;
		tiempo_respuesta(4, t_item4, btn7, btn8);
		listoAlme2 = true;
		this->presBtn8 = false;
	}
	comprobarRespuestas();
}