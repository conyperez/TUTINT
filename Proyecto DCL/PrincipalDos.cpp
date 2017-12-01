#include "PrincipalDos.h"
//#include "Actividad2Uno.h"
//#include "Actividad2Dos.h"
//#include "Actividad2Tres.h"
//#include "Actividad2Cuatro.h"
//#include "Actividad2Cinco.h"
#include "NivelUno.h"
#include <windows.h>
#include <MMSystem.h>

System::Void Proyecto_DCL::PrincipalDos::inicializarTamBotones() {
	wBob = btnBobEsponjaD->Size.Width;
	hBob = btnBobEsponjaD->Size.Height;
	wCalamardo = btnCalamardoD->Size.Width;
	hCalamardo = btnCalamardoD->Size.Height;
	wPatricio = btnPatricioD->Size.Width;
	hPatricio = btnPatricioD->Size.Height;
	wGary = btnGaryD->Size.Width;
	hGary = btnGaryD->Size.Height;
	wArenita = btnArenitaD->Size.Width;
	hArenita = btnArenitaD->Size.Height;
	wPuff = btnPuffD->Size.Width;
	hPuff = btnPuffD->Size.Height;
	wCangrejo = btnCangrejoD->Size.Width;
	hCangrejo = btnCangrejoD->Size.Height;
	wPlankton = btnPlanktonD->Size.Width;
	hPlankton = btnPlanktonD->Size.Height;
	wPerla = btnPerlaD->Size.Width;
	hPerla = btnPerlaD->Size.Height;
	wVolver = btnVolver->Size.Width;
	hVolver = btnVolver->Size.Height;
}
System::Void Proyecto_DCL::PrincipalDos::inicializarComponentesBD() {
	controlador = new AgenteControlador("Conciencia_alfabetica", recuperacion);
	vector<string> actividad = controlador->determinarActividad();

	if (actividad[0] == "Basica") {					// Dificultad
		if (actividad[1] == "Basica") {				// Complejidad
			numAct = atoi(actividad[2].c_str());
			cargarActBB();
		}
		else if (actividad[1] == "Intermedio") {
			numAct = atoi(actividad[2].c_str());
			cargarActBI();
			//SonidoInicial();
		}
		else {
			numAct = atoi(actividad[2].c_str());
			cargarActBD();
		}
	}
	else if (actividad[0] == "Intermedio") {
		if (actividad[1] == "Basica") {				// Complejidad
			numAct = atoi(actividad[2].c_str());
			cargarActIB();
		}
		else if (actividad[1] == "Intermedio") {
			numAct = atoi(actividad[2].c_str());
			cargarActII();
		}
		else {
			numAct = atoi(actividad[2].c_str());
			cargarActID();
		}
	}
	else {
		if (actividad[1] == "Basica") {				// Complejidad
			numAct = atoi(actividad[2].c_str());
			cargarActDB();
		}
		else if (actividad[1] == "Intermedio") {
			numAct = atoi(actividad[2].c_str());
			cargarActDI();
		}
		else {
			numAct = atoi(actividad[2].c_str());
			cargarActDD();
		}
	}
	lblEstrellas->Text = System::Convert::ToString(manejadorBD->seleccionarCantEstrellasHabilidad());
}
System::Void Proyecto_DCL::PrincipalDos::cargarActBB() {
	this->btnPatricioD->Visible = true;
	this->btnPatricioD->Enabled = true;
	this->btnPatricio->Visible = false;
}
System::Void Proyecto_DCL::PrincipalDos::cargarActBI() {
	this->btnBobEsponjaD->Visible = true;
	this->btnBobEsponjaD->Enabled = true;
	this->btnBobEsponja->Visible = false;
}
System::Void Proyecto_DCL::PrincipalDos::cargarActBD() {
	this->btnPlanktonD->Visible = true;
	this->btnPlanktonD->Enabled = true;
	this->btnPlankton->Visible = false;
}
System::Void Proyecto_DCL::PrincipalDos::cargarActIB() {
	this->btnCangrejoD->Visible = true;
	this->btnCangrejoD->Enabled = true;
	this->btnCangrejo->Visible = false;
}
System::Void Proyecto_DCL::PrincipalDos::cargarActII() {
	this->btnArenitaD->Visible = true;
	this->btnArenitaD->Enabled = true;
	this->btnArenita->Visible = false;
}
System::Void Proyecto_DCL::PrincipalDos::cargarActID() {
	this->btnCalamardoD->Visible = true;
	this->btnCalamardoD->Enabled = true;
	this->btnCalamardo->Visible = false;
}
System::Void Proyecto_DCL::PrincipalDos::cargarActDB() {
	this->btnPerlaD->Visible = true;
	this->btnPerlaD->Enabled = true;
	this->btnPerla->Visible = false;
}
System::Void Proyecto_DCL::PrincipalDos::cargarActDI() {
	this->btnPuffD->Visible = true;
	this->btnPuffD->Enabled = true;
	this->btnPuff->Visible = false;
}
System::Void Proyecto_DCL::PrincipalDos::cargarActDD() {
	this->btnGaryD->Visible = true;
	this->btnGaryD->Enabled = true;
	this->btnGary->Visible = false;
}
System::Void Proyecto_DCL::PrincipalDos::btnPlanktonD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	PrincipalDos::btnPlanktonD->Size = System::Drawing::Size(wPlankton + 20, hPlankton + 20);
	SonidoPlankton();
}
System::Void Proyecto_DCL::PrincipalDos::btnPlanktonD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	PrincipalDos::btnPlanktonD->Size = System::Drawing::Size(wPlankton, hPlankton);
}
System::Void Proyecto_DCL::PrincipalDos::btnPuffD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	PrincipalDos::btnPuffD->Size = System::Drawing::Size(wPuff + 20, hPuff + 20);
	SonidoPuff();
}
System::Void Proyecto_DCL::PrincipalDos::btnPuffD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	PrincipalDos::btnPuffD->Size = System::Drawing::Size(wPuff, hPuff);
}
System::Void Proyecto_DCL::PrincipalDos::btnPerlaD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	PrincipalDos::btnPerlaD->Size = System::Drawing::Size(wPerla + 20, hPerla + 20);
	SonidoPerla();
}
System::Void Proyecto_DCL::PrincipalDos::btnPerlaD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	PrincipalDos::btnPerlaD->Size = System::Drawing::Size(wPerla, hPerla);
}
System::Void Proyecto_DCL::PrincipalDos::btnCangrejoD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	PrincipalDos::btnCangrejoD->Size = System::Drawing::Size(wCangrejo + 20, hCangrejo + 20);
	SonidoCangrejo();
}
System::Void Proyecto_DCL::PrincipalDos::btnCangrejoD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	PrincipalDos::btnCangrejoD->Size = System::Drawing::Size(wCangrejo, hCangrejo);
}
System::Void Proyecto_DCL::PrincipalDos::btnBobEsponjaD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	PrincipalDos::btnBobEsponjaD->Size = System::Drawing::Size(wBob + 20, hBob + 20);
	SonidoBob();
}
System::Void Proyecto_DCL::PrincipalDos::btnBobEsponjaD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	PrincipalDos::btnBobEsponjaD->Size = System::Drawing::Size(wBob, hBob);
}
System::Void Proyecto_DCL::PrincipalDos::btnCalamardoD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	PrincipalDos::btnCalamardoD->Size = System::Drawing::Size(wCalamardo + 20, hCalamardo + 20);
	SonidoCalamardo();
}
System::Void Proyecto_DCL::PrincipalDos::btnCalamardoD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	PrincipalDos::btnCalamardoD->Size = System::Drawing::Size(wCalamardo, hCalamardo);
}
System::Void Proyecto_DCL::PrincipalDos::btnPatricioD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	PrincipalDos::btnPatricioD->Size = System::Drawing::Size(wPatricio + 20, hPatricio + 20);
	SonidoPatricio();
}
System::Void Proyecto_DCL::PrincipalDos::btnPatricioD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	PrincipalDos::btnPatricioD->Size = System::Drawing::Size(wPatricio, hPatricio);
}
System::Void Proyecto_DCL::PrincipalDos::btnGaryD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	PrincipalDos::btnGaryD->Size = System::Drawing::Size(wGary + 20, hGary + 20);
	SonidoGary();
}
System::Void Proyecto_DCL::PrincipalDos::btnGaryD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	PrincipalDos::btnGaryD->Size = System::Drawing::Size(wGary, hGary);
}
System::Void Proyecto_DCL::PrincipalDos::btnArenitaD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	PrincipalDos::btnArenitaD->Size = System::Drawing::Size(wArenita + 20, hArenita + 20);
	SonidoArenita();
}
System::Void Proyecto_DCL::PrincipalDos::btnArenitaD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	PrincipalDos::btnArenitaD->Size = System::Drawing::Size(wArenita, hArenita);
}
System::Void Proyecto_DCL::PrincipalDos::btnPuffD_Click(System::Object^  sender, System::EventArgs^  e) {
	if (numAct == 1) {
		//gcnew Actividad2UnoDI(this, manejadorBD, controlador);
	}
	else if (numAct == 2) {
		//gcnew Actividad2DosDI(this, manejadorBD, controlador);
	}
}
System::Void Proyecto_DCL::PrincipalDos::btnPerlaD_Click(System::Object^  sender, System::EventArgs^  e) {
	if (numAct == 1) {
		//gcnew Actividad2UnoDB(this, manejadorBD, controlador);
	}
	else if (numAct == 2) {
		//gcnew Actividad2DosDB(this, manejadorBD, controlador);
	}
}
System::Void Proyecto_DCL::PrincipalDos::btnCangrejoD_Click(System::Object^  sender, System::EventArgs^  e) {
	if (numAct == 1) {
		//gcnew Actividad2UnoIB(this, manejadorBD, controlador);
	}
	else if (numAct == 2) {
		//gcnew Actividad2DosIB(this, manejadorBD, controlador);
	}
}
System::Void Proyecto_DCL::PrincipalDos::btnPlanktonD_Click(System::Object^  sender, System::EventArgs^  e) {
	if (numAct == 1) {
		//gcnew Actividad2UnoBD(this, manejadorBD, controlador);
	}
	else if (numAct == 2) {
		//gcnew Actividad2DosBD(this, manejadorBD, controlador);
	}
}
System::Void Proyecto_DCL::PrincipalDos::btnBobEsponjaD_Click(System::Object^  sender, System::EventArgs^  e) {
	if (numAct == 1) {
		//gcnew Actividad2UnoBI(this, manejadorBD, controlador);
	}
	else if (numAct == 2) {
		//gcnew Actividad2DosBI(this, manejadorBD, controlador);
	}
}
System::Void Proyecto_DCL::PrincipalDos::btnPatricioD_Click(System::Object^  sender, System::EventArgs^  e) {
	if (numAct == 1) {
		//gcnew Actividad2UnoBB(this, manejadorBD, controlador);
	}
	else if (numAct == 2) {
		//gcnew Actividad2DosBB(this, manejadorBD, controlador);
	}
}
System::Void Proyecto_DCL::PrincipalDos::btnGaryD_Click(System::Object^  sender, System::EventArgs^  e) {
	if (numAct == 1) {
		//gcnew Actividad2UnoDD(this, manejadorBD, controlador);
	}
	else if (numAct == 2) {
		//gcnew Actividad2DosDD(this, manejadorBD, controlador);
	}
}
System::Void Proyecto_DCL::PrincipalDos::btnArenitaD_Click(System::Object^  sender, System::EventArgs^  e) {
	if (numAct == 1) {
		//gcnew Actividad2UnoII(this, manejadorBD, controlador);
	}
	else if (numAct == 2) {
		//gcnew Actividad2DosII(this, manejadorBD, controlador);
	}
}
System::Void Proyecto_DCL::PrincipalDos::btnCalamardoD_Click(System::Object^  sender, System::EventArgs^  e) {
	if (numAct == 1) {
		//gcnew Actividad2UnoID(this, manejadorBD, controlador);
	}
	else if (numAct == 2) {
		//gcnew Actividad2DosID(this, manejadorBD, controlador);
	}
}
System::Void Proyecto_DCL::PrincipalDos::btnVolver_Click(System::Object^  sender, System::EventArgs^  e) {
	gcnew NivelUno(this, manejadorBD);
}
System::Void Proyecto_DCL::PrincipalDos::btnVolver_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnVolver->Size = System::Drawing::Size(wVolver + 10, hVolver + 10);
}
System::Void Proyecto_DCL::PrincipalDos::btnVolver_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnVolver->Size = System::Drawing::Size(wVolver, hVolver);
}
System::Void Proyecto_DCL::PrincipalDos::SonidoBob() {
	PlaySound(TEXT("Audios/Playa/Bob-Esponja.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::PrincipalDos::SonidoCalamardo() {
	PlaySound(TEXT("Audios/Playa/Calamardo.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::PrincipalDos::SonidoPatricio() {
	PlaySound(TEXT("Audios/Playa/Patricio.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::PrincipalDos::SonidoArenita() {
	PlaySound(TEXT("Audios/Playa/Arenita.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::PrincipalDos::SonidoGary() {
	PlaySound(TEXT("Audios/Playa/Gary.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::PrincipalDos::SonidoPuff() {
	//PlaySound(TEXT("Audios/Playa/Calamardo.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::PrincipalDos::SonidoPerla() {
	//PlaySound(TEXT("Audios/Playa/Patricio.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::PrincipalDos::SonidoPlankton() {
	//PlaySound(TEXT("Audios/Playa/Arenita.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::PrincipalDos::SonidoCangrejo() {
	//PlaySound(TEXT("Audios/Playa/Gary.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::PrincipalDos::SonidoBobGary() {
	PlaySound(TEXT("Audios/Playa/Bob-Esponja-Final.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::PrincipalDos::timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	this->Opacity += .1;
	//Detener el timer
	if (this->Opacity == 1) {
		this->timer1->Stop();
		//this->form->Hide();
	}
}
System::Void Proyecto_DCL::PrincipalDos::PrincipalDos_Load(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
}
System::Void Proyecto_DCL::PrincipalDos::picCerrar_Click(System::Object^  sender, System::EventArgs^  e) {
	Application::Exit();
}
System::Void Proyecto_DCL::PrincipalDos::picMinimizar_Click(System::Object^  sender, System::EventArgs^  e) {
	this->WindowState = FormWindowState::Minimized;
}
System::Void Proyecto_DCL::PrincipalDos::PrincipalDos_Activated(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
}
System::Void Proyecto_DCL::PrincipalDos::PrincipalDos_Deactivate(System::Object^  sender, System::EventArgs^  e) {
	if (this->WindowState == FormWindowState::Minimized) {
		this->Opacity = 0;
	}
}