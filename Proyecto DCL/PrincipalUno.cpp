#include "PrincipalUno.h"
//#include "Actividad1Uno.h"
//#include "Actividad1Dos.h"
//#include "Actividad1Tres.h"
//#include "Actividad1Cuatro.h"
//#include "Actividad1Cinco.h"
#include "NivelUno.h"
#include <windows.h>
#include <MMSystem.h>

System::Void Proyecto_DCL::PrincipalUno::SonidoInicio() {
	PlaySound(TEXT("Audios/Oceano/Marlin.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::PrincipalUno::SonidoDory() {
	PlaySound(TEXT("Audios/Oceano/Dory.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::PrincipalUno::SonidoTiburones() {
	PlaySound(TEXT("Audios/Oceano/Tiburones.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::PrincipalUno::SonidoTortugas() {
	PlaySound(TEXT("Audios/Oceano/Tortugas.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::PrincipalUno::SonidoNemo() {
	PlaySound(TEXT("Audios/Oceano/Nemo.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::PrincipalUno::SonidoNemoPapa() {
	PlaySound(TEXT("Audios/Oceano/Nemo-Papa.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::PrincipalUno::SonidoPulpo() {
	//PlaySound(TEXT("Audios/Oceano/Tiburones.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::PrincipalUno::SonidoPezAma() {
	//PlaySound(TEXT("Audios/Oceano/Tortugas.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::PrincipalUno::SonidoPezGlobo() {
	//PlaySound(TEXT("Audios/Oceano/Nemo.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::PrincipalUno::SonidoTortu() {
	//PlaySound(TEXT("Audios/Oceano/Nemo-Papa.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::PrincipalUno::SonidoInicial() {
	PlaySound(TEXT("Audios/Oceano/Inicio_mundo_del_oceano.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::PrincipalUno::inicializarTamBotones() {
	wMarlin = btnMarlinD->Size.Width;
	hMarlin = btnMarlinD->Size.Height;
	wDory = btnDoryD->Size.Width;
	hDory = btnDoryD->Size.Height;
	wTiburones = btnTiburonesD->Size.Width;
	hTiburones = btnTiburonesD->Size.Height;
	wTortugas = btnTortugasD->Size.Width;
	hTortugas = btnTortugasD->Size.Height;
	wNemo = btnNemoD->Size.Width;
	hNemo = btnNemoD->Size.Height;
	hTortuH = btnTortuD->Size.Height;
	wTortuH = btnTortuD->Size.Width;
	hPulpo = btnPulpoD->Size.Height;
	wPulpo = btnPulpoD->Size.Width;
	hPezGlobo = btnPezGloD->Size.Height;
	wPezGlobo = btnPezGloD->Size.Width;
	hPezAma = btnPezAmaD->Size.Height;
	wPezAma = btnPezAmaD->Size.Width;
	wVolver = btnVolver->Size.Width;
	hVolver = btnVolver->Size.Height;
}
// Se llama al Agente Controlador para ver que actividad (personaje) desbloquear
System::Void Proyecto_DCL::PrincipalUno::inicializarComponentesBD() {
	controlador = new AgenteControlador("Conciencia_fonologica", recuperacion);
	vector<string> actividad = controlador->determinarActividad();
	
	if (actividad[0] == "Basica") {					// Dificultad
		if (actividad[1] == "Basica") {				// Complejidad
			numAct = atoi(actividad[2].c_str());
			cargarActBB();
		}
		else if (actividad[1] == "Intermedio") {
			numAct = atoi(actividad[2].c_str());
			cargarActBI();
			SonidoInicial();
		}
		else {
			numAct = atoi(actividad[2].c_str());
			cargarActBD();
		}
	}
	else if (actividad[0] == "Intermedio") {
		if (actividad[1] == "Basica") {			
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
		if (actividad[1] == "Basica") {		
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
System::Void Proyecto_DCL::PrincipalUno::cargarActBB() {
	this->btnMarlinD->Visible = true;
	this->btnMarlinD->Enabled = true;
	this->btnMarlin->Visible = false;
}
System::Void Proyecto_DCL::PrincipalUno::cargarActBI() {
	this->btnDoryD->Visible = true;
	this->btnDoryD->Enabled = true;
	this->btnDory->Visible = false;
}
System::Void Proyecto_DCL::PrincipalUno::cargarActBD() {
	this->btnPulpoD->Visible = true;
	this->btnPulpoD->Enabled = true;
	this->btnPulpo->Visible = false;
}
System::Void Proyecto_DCL::PrincipalUno::cargarActIB() {
	this->btnTortuD->Visible = true;
	this->btnTortuD->Enabled = true;
	this->btnTortu->Visible = false;
}
System::Void Proyecto_DCL::PrincipalUno::cargarActII() {
	this->btnTiburonesD->Visible = true;
	this->btnTiburonesD->Enabled = true;
	this->btnTiburones->Visible = false;
}
System::Void Proyecto_DCL::PrincipalUno::cargarActID() {
	this->btnPezAmaD->Visible = true;
	this->btnPezAmaD->Enabled = true;
	this->btnPezAma->Visible = false;
}
System::Void Proyecto_DCL::PrincipalUno::cargarActDB() {
	this->btnTortugasD->Visible = true;
	this->btnTortugasD->Enabled = true;
	this->btnTortugas->Visible = false;
}
System::Void Proyecto_DCL::PrincipalUno::cargarActDI() {
	this->btnPezGloD->Visible = true;
	this->btnPezGloD->Enabled = true;
	this->btnPezGlo->Visible = false;
}
System::Void Proyecto_DCL::PrincipalUno::cargarActDD() {
	this->btnNemoD->Visible = true;
	this->btnNemoD->Enabled = true;
	this->btnNemo->Visible = false;
}
System::Void Proyecto_DCL::PrincipalUno::btnTortuD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	PrincipalUno::btnTortuD->Size = System::Drawing::Size(wTortuH, hTortuH);
}
System::Void Proyecto_DCL::PrincipalUno::btnTortuD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	PrincipalUno::btnTortuD->Size = System::Drawing::Size(wTortuH + 20, hTortuH + 20);
	SonidoTortu();
}
System::Void Proyecto_DCL::PrincipalUno::btnPezAmaD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	PrincipalUno::btnPezAmaD->Size = System::Drawing::Size(wPezAma + 20, hPezAma + 20);
	SonidoPezAma();
}
System::Void Proyecto_DCL::PrincipalUno::btnPezAmaD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	PrincipalUno::btnPezAmaD->Size = System::Drawing::Size(wPezAma, hPezAma);
}
System::Void Proyecto_DCL::PrincipalUno::btnPezGloD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	PrincipalUno::btnPezGloD->Size = System::Drawing::Size(wPezGlobo, hPezGlobo);
}
System::Void Proyecto_DCL::PrincipalUno::btnPezGloD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	PrincipalUno::btnPezGloD->Size = System::Drawing::Size(wPezGlobo + 20, hPezGlobo + 20);
	SonidoPezGlobo();
}
System::Void Proyecto_DCL::PrincipalUno::btnPulpoD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	PrincipalUno::btnPulpoD->Size = System::Drawing::Size(wPulpo + 20, hPulpo + 20);
	SonidoPulpo();
}
System::Void Proyecto_DCL::PrincipalUno::btnPulpoD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	PrincipalUno::btnPulpoD->Size = System::Drawing::Size(wPulpo, hPulpo);
}
System::Void Proyecto_DCL::PrincipalUno::btnMarlinD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	PrincipalUno::btnMarlinD->Size = System::Drawing::Size(wMarlin + 20, hMarlin + 20);
	SonidoInicio();
}
System::Void Proyecto_DCL::PrincipalUno::btnMarlinD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	PrincipalUno::btnMarlinD->Size = System::Drawing::Size(wMarlin, hMarlin);
}
System::Void Proyecto_DCL::PrincipalUno::btnDoryD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	PrincipalUno::btnDoryD->Size = System::Drawing::Size(wDory, hDory);
}
System::Void Proyecto_DCL::PrincipalUno::btnDoryD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	PrincipalUno::btnDoryD->Size = System::Drawing::Size(wDory + 20, hDory + 20);
	SonidoDory();
}
System::Void Proyecto_DCL::PrincipalUno::btnTiburonesD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	PrincipalUno::btnTiburonesD->Size = System::Drawing::Size(wTiburones + 20, hTiburones + 20);
	SonidoTiburones();
}
System::Void Proyecto_DCL::PrincipalUno::btnTiburonesD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	PrincipalUno::btnTiburonesD->Size = System::Drawing::Size(wTiburones, hTiburones);
}
System::Void Proyecto_DCL::PrincipalUno::btnTortugasD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	PrincipalUno::btnTortugasD->Size = System::Drawing::Size(wTortugas, hTortugas);
}
System::Void Proyecto_DCL::PrincipalUno::btnTortugasD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	PrincipalUno::btnTortugasD->Size = System::Drawing::Size(wTortugas + 20, hTortugas + 20);
	SonidoTortugas();
}
System::Void Proyecto_DCL::PrincipalUno::btnNemoD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	PrincipalUno::btnNemoD->Size = System::Drawing::Size(wNemo + 20, hNemo + 20);
	SonidoNemo();
}
System::Void Proyecto_DCL::PrincipalUno::btnNemoD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	PrincipalUno::btnNemoD->Size = System::Drawing::Size(wNemo, hNemo);
}
System::Void Proyecto_DCL::PrincipalUno::btnTortuD_Click(System::Object^  sender, System::EventArgs^  e) {
	if (numAct == 1) {
		//gcnew Actividad1UnoIB(this, manejadorBD, controlador);
	}
	else if (numAct == 2) {
		//gcnew Actividad1DosIB(this, manejadorBD, controlador);
	}
}
System::Void Proyecto_DCL::PrincipalUno::btnPezAmaD_Click(System::Object^  sender, System::EventArgs^  e) {
	if (numAct == 1) {
		//gcnew Actividad1UnoID(this, manejadorBD, controlador);
	}
	else if (numAct == 2) {
		//gcnew Actividad1DosID(this, manejadorBD, controlador);
	}
}
System::Void Proyecto_DCL::PrincipalUno::btnPezGloD_Click(System::Object^  sender, System::EventArgs^  e) {
	if (numAct == 1) {
		//gcnew Actividad1UnoDI(this, manejadorBD, controlador);
	}
	else if (numAct == 2) {
		//gcnew Actividad1DosDI(this, manejadorBD, controlador);
	}
}
System::Void Proyecto_DCL::PrincipalUno::btnPulpoD_Click(System::Object^  sender, System::EventArgs^  e) {
	if (numAct == 1) {
		//gcnew Actividad1UnoBD(this, manejadorBD, controlador);
	}
	else if (numAct == 2) {
		//gcnew Actividad1DosBD(this, manejadorBD, controlador);
	}
}
System::Void Proyecto_DCL::PrincipalUno::btnMarlinD_Click(System::Object^  sender, System::EventArgs^  e) {
	if (numAct == 1) {
		//gcnew Actividad1UnoBB(this, manejadorBD, controlador);
	}
	else if (numAct == 2) {
		//gcnew Actividad1DosBB(this, manejadorBD, controlador);
	}
}
System::Void Proyecto_DCL::PrincipalUno::btnDoryD_Click(System::Object^  sender, System::EventArgs^  e) {
	if (numAct == 1) {
		//gcnew Actividad1UnoBI(this, manejadorBD, controlador);
	}
	else if (numAct == 2) {
		//gcnew Actividad1DosBI(this, manejadorBD, controlador);
	}
}
System::Void Proyecto_DCL::PrincipalUno::btnTiburonesD_Click(System::Object^  sender, System::EventArgs^  e) {
	if (numAct == 1) {
		//gcnew Actividad1UnoII(this, manejadorBD, controlador);
	}
	else if (numAct == 2) {
		//gcnew Actividad1DosII(this, manejadorBD, controlador);
	}
}
System::Void Proyecto_DCL::PrincipalUno::btnTortugasD_Click(System::Object^  sender, System::EventArgs^  e) {
	if (numAct == 1) {
		//gcnew Actividad1UnoDB(this, manejadorBD, controlador);
	}
	else if (numAct == 2) {
		//gcnew Actividad1DosDB(this, manejadorBD, controlador);
	}
}
System::Void Proyecto_DCL::PrincipalUno::btnNemoD_Click(System::Object^  sender, System::EventArgs^  e) {
	if (numAct == 1) {
		//gcnew Actividad1UnoDD(this, manejadorBD, controlador);
	}
	else if (numAct == 2) {
		//gcnew Actividad1DosDD(this, manejadorBD, controlador);
	}
}
System::Void Proyecto_DCL::PrincipalUno::btnVolver_Click(System::Object^  sender, System::EventArgs^  e) {
	gcnew NivelUno(this, manejadorBD);
}
System::Void Proyecto_DCL::PrincipalUno::btnVolver_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnVolver->Size = System::Drawing::Size(wVolver + 10, hVolver + 10);
}
System::Void Proyecto_DCL::PrincipalUno::btnVolver_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnVolver->Size = System::Drawing::Size(wVolver, hVolver);
}
System::Void Proyecto_DCL::PrincipalUno::btnPlay_Click(System::Object^  sender, System::EventArgs^  e) {
	SonidoInicial();
}
System::Void Proyecto_DCL::PrincipalUno::timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	this->Opacity += .1;
	//Detener el timer
	if (this->Opacity == 1) {
		this->timer1->Stop();
		this->form->Hide();
	}
}
System::Void Proyecto_DCL::PrincipalUno::PrincipalUno_Load(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
}
System::Void Proyecto_DCL::PrincipalUno::picCerrar_Click(System::Object^  sender, System::EventArgs^  e) {
	Application::Exit();
}
System::Void Proyecto_DCL::PrincipalUno::picMinimizar_Click(System::Object^  sender, System::EventArgs^  e) {
	this->WindowState = FormWindowState::Minimized;
}
System::Void Proyecto_DCL::PrincipalUno::PrincipalUno_Activated(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
}
System::Void Proyecto_DCL::PrincipalUno::PrincipalUno_Deactivate(System::Object^  sender, System::EventArgs^  e) {
	if (this->WindowState == FormWindowState::Minimized) {
		this->Opacity = 0;
	}
}

