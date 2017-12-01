#include "PrincipalCinco.h"
//#include "Actividad5Uno.h"
//#include "Actividad5Dos.h"
//#include "Actividad5Tres.h"
//#include "Actividad5Cuatro.h"
//#include "Actividad5Cinco.h"
//#include "Actividad5Seis.h"
//#include "Actividad5Siete.h"
#include "Niveles.h"
#include <windows.h>
#include <MMSystem.h>

System::Void Proyecto_DCL::PrincipalCinco::inicializarTam() {
	wVolver = this->btnVolver->Size.Width;
	hVolver = this->btnVolver->Size.Height;
	wUno = this->btnUno->Size.Width;
	hUno = this->btnUno->Size.Height;
	wDos = this->btnDos->Size.Width;
	hDos = this->btnDos->Size.Height;
	wTres = this->btnTres->Size.Width;
	hTres = this->btnTres->Size.Height;
	wCuatro = this->btnCuatro->Size.Width;
	hCuatro = this->btnCuatro->Size.Height;
	wCinco = this->btnCinco->Size.Width;
	hCinco = this->btnCinco->Size.Height;
	wSeis = this->btnSeis->Size.Width;
	hSeis = this->btnSeis->Size.Height;
	wSiete = this->btnSiete->Size.Width;
	hSiete = this->btnSiete->Size.Height;
}
System::Void Proyecto_DCL::PrincipalCinco::inicializarComponentesBD() {
	manejadorBD->setNombreNivel("Espacio");
	manejadorBD->setNombreHabilidad("Comprension_inferencial");
	int totalEstr = manejadorBD->seleccionarCantEstrellasHabilidad();
	int act = manejadorBD->seleccionarActividadActual();
	// Cargar los componentes segun la BD
	switch (act) {
		case 1:
			cargarActUno(true);
			break;
		case 2:
			cargarActUno(false);
			cargarActDos(true);
			break;
		case 3:
			cargarActUno(false);
			cargarActDos(false);
			cargarActTres(true);
			break;
		case 4:
			cargarActUno(false);
			cargarActDos(false);
			cargarActTres(false);
			cargarActCuatro(true);
			break;
		case 5:
			cargarActUno(false);
			cargarActDos(false);
			cargarActTres(false);
			cargarActCuatro(false);
			cargarActCinco(true);
			break;
		case 6:
			cargarActUno(false);
			cargarActDos(false);
			cargarActTres(false);
			cargarActCuatro(false);
			cargarActCinco(false);
			cargarActSeis(true);
			break;
		case 7:
			cargarActUno(false);
			cargarActDos(false);
			cargarActTres(false);
			cargarActCuatro(false);
			cargarActCinco(false);
			cargarActSeis(false);
			cargarActSiete(true);
			break;
	}
	this->lblEstrellas->Text = System::Convert::ToString(totalEstr);
}
System::Void Proyecto_DCL::PrincipalCinco::cargarActUno(bool destacado) {
	if (destacado) {
		this->btnUnoD->Visible = true;
		this->btnUnoD->Enabled = true;
		this->btnUno->Visible = false;
	}
	else {
		this->btnUnoD->Visible = false;
		this->btnUno->Visible = true;
		this->btnUno->Enabled = true;
	}
}
System::Void Proyecto_DCL::PrincipalCinco::cargarActDos(bool destacado) {
	if (destacado) {
		this->btnDosD->Visible = true;
		this->btnDosD->Enabled = true;
		this->btnDos->Visible = false;
		this->btnDosE->Visible = false;
	}
	else {
		this->btnDosD->Visible = false;
		this->btnDos->Visible = true;
		this->btnDos->Enabled = true;
		this->btnDosE->Visible = false;
	}
}
System::Void Proyecto_DCL::PrincipalCinco::cargarActTres(bool destacado) {
	if (destacado) {
		this->btnTresD->Visible = true;
		this->btnTresD->Enabled = true;
		this->btnTres->Visible = false;
		this->btnTresE->Visible = false;
	}
	else {
		this->btnTresD->Visible = false;
		this->btnTres->Visible = true;
		this->btnTres->Enabled = true;
		this->btnTresE->Visible = false;
	}
}
System::Void Proyecto_DCL::PrincipalCinco::cargarActCuatro(bool destacado) {
	if (destacado) {
		this->btnCuatroD->Visible = true;
		this->btnCuatroD->Enabled = true;
		this->btnCuatro->Visible = false;
		this->btnCuatroE->Visible = false;
	}
	else {
		this->btnCuatroD->Visible = false;
		this->btnCuatro->Visible = true;
		this->btnCuatro->Enabled = true;
		this->btnCuatroE->Visible = false;
	}
}
System::Void Proyecto_DCL::PrincipalCinco::cargarActCinco(bool destacado) {
	if (destacado) {
		this->btnCincoD->Visible = true;
		this->btnCincoD->Enabled = true;
		this->btnCinco->Visible = false;
		this->btnCincoE->Visible = false;
	}
	else {
		this->btnCincoD->Visible = false;
		this->btnCinco->Visible = true;
		this->btnCinco->Enabled = true;
		this->btnCincoE->Visible = false;
	}
}
System::Void Proyecto_DCL::PrincipalCinco::cargarActSeis(bool destacado) {
	if (destacado) {
		this->btnSeisD->Visible = true;
		this->btnSeisD->Enabled = true;
		this->btnSeis->Visible = false;
		this->btnSeisE->Visible = false;
	}
	else {
		this->btnSeisD->Visible = false;
		this->btnSeis->Visible = true;
		this->btnSeis->Enabled = true;
		this->btnSeisE->Visible = false;
	}
}
System::Void Proyecto_DCL::PrincipalCinco::cargarActSiete(bool destacado) {
	if (destacado) {
		this->btnSieteD->Visible = true;
		this->btnSieteD->Enabled = true;
		this->btnSiete->Visible = false;
	}
	else {
		this->btnSieteD->Visible = false;
		this->btnSiete->Visible = true;
		this->btnSiete->Enabled = true;
	}
}
System::Void Proyecto_DCL::PrincipalCinco::btnVolver_Click(System::Object^  sender, System::EventArgs^  e) {
	//gcnew Niveles(this, manejadorBD);
}
System::Void Proyecto_DCL::PrincipalCinco::btnVolver_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnVolver->Size = System::Drawing::Size(wVolver + 10, hVolver + 10);
}
System::Void Proyecto_DCL::PrincipalCinco::btnVolver_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnVolver->Size = System::Drawing::Size(wVolver, hVolver);
}
System::Void Proyecto_DCL::PrincipalCinco::btnUno_Click(System::Object^  sender, System::EventArgs^  e) {
	//gcnew Actividad5Uno(this, btnDosE, btnDos, manejadorBD);
}
System::Void Proyecto_DCL::PrincipalCinco::btnDos_Click(System::Object^  sender, System::EventArgs^  e) {
	//gcnew Actividad5Dos(this, btnTresE, btnTres, manejadorBD);
}
System::Void Proyecto_DCL::PrincipalCinco::btnTres_Click(System::Object^  sender, System::EventArgs^  e) {
	//gcnew Actividad5Tres(this, btnCuatroE, btnCuatro, manejadorBD);
}
System::Void Proyecto_DCL::PrincipalCinco::btnCuatro_Click(System::Object^  sender, System::EventArgs^  e) {
	//gcnew Actividad5Cuatro(this, btnCincoE, btnCinco, manejadorBD);
}
System::Void Proyecto_DCL::PrincipalCinco::btnCinco_Click(System::Object^  sender, System::EventArgs^  e) {
	//gcnew Actividad5Cinco(this, btnSeisE, btnSeis, manejadorBD);
}
System::Void Proyecto_DCL::PrincipalCinco::btnSeis_Click(System::Object^  sender, System::EventArgs^  e) {
	//gcnew Actividad5Seis(this, btnSieteE, btnSiete, manejadorBD);
}
System::Void Proyecto_DCL::PrincipalCinco::btnSiete_Click(System::Object^  sender, System::EventArgs^  e) {
	//gcnew Actividad5Siete(this, btnSieteE, btnSiete, manejadorBD);
}
System::Void Proyecto_DCL::PrincipalCinco::btnUnoD_Click(System::Object^  sender, System::EventArgs^  e) {
	this->btnUno->Visible = true;
	this->btnUno->Enabled = true;
	this->btnUnoD->Visible = false;
	this->btnUnoD->Enabled = false;
	//gcnew Actividad5Uno(this, btnDosE, btnDosD, manejadorBD);
}
System::Void Proyecto_DCL::PrincipalCinco::btnDosD_Click(System::Object^  sender, System::EventArgs^  e) {
	this->btnDos->Visible = true;
	this->btnDos->Enabled = true;
	this->btnDosD->Visible = false;
	this->btnDosD->Enabled = false;
	//gcnew Actividad5Dos(this, btnTresE, btnTresD, manejadorBD);
}
System::Void Proyecto_DCL::PrincipalCinco::btnTresD_Click(System::Object^  sender, System::EventArgs^  e) {
	this->btnTres->Visible = true;
	this->btnTres->Enabled = true;
	this->btnTresD->Visible = false;
	this->btnTresD->Enabled = false;
	//gcnew Actividad5Tres(this, btnCuatroE, btnCuatroD, manejadorBD);
}
System::Void Proyecto_DCL::PrincipalCinco::btnCuatroD_Click(System::Object^  sender, System::EventArgs^  e) {
	this->btnCuatro->Visible = true;
	this->btnCuatro->Enabled = true;
	this->btnCuatroD->Visible = false;
	this->btnCuatroD->Enabled = false;
	//gcnew Actividad5Cuatro(this, btnCincoE, btnCincoD, manejadorBD);
}
System::Void Proyecto_DCL::PrincipalCinco::btnCincoD_Click(System::Object^  sender, System::EventArgs^  e) {
	this->btnCinco->Visible = true;
	this->btnCinco->Enabled = true;
	this->btnCincoD->Visible = false;
	this->btnCincoD->Enabled = false;
	//gcnew Actividad5Cinco(this, btnSeisE, btnSeisD, manejadorBD);
}
System::Void Proyecto_DCL::PrincipalCinco::btnSeisD_Click(System::Object^  sender, System::EventArgs^  e) {
	this->btnSeis->Visible = true;
	this->btnSeis->Enabled = true;
	this->btnSeisD->Visible = false;
	this->btnSeisD->Enabled = false;
	//gcnew Actividad5Seis(this, btnSieteE, btnSieteD, manejadorBD);
}
System::Void Proyecto_DCL::PrincipalCinco::btnSieteD_Click(System::Object^  sender, System::EventArgs^  e) {
	this->btnSeis->Visible = true;
	this->btnSeis->Enabled = true;
	this->btnSeisD->Visible = false;
	this->btnSeisD->Enabled = false;
	//gcnew Actividad5Siete(this, btnSieteE, btnSieteD, manejadorBD);
}
System::Void Proyecto_DCL::PrincipalCinco::btnUno_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnUno->Size = System::Drawing::Size(wUno + 20, hUno + 20);
	SonidoUno();
}
System::Void Proyecto_DCL::PrincipalCinco::btnUno_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnUno->Size = System::Drawing::Size(wUno, hUno);
}
System::Void Proyecto_DCL::PrincipalCinco::btnDos_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnDos->Size = System::Drawing::Size(wDos + 20, hDos + 20);
	SonidoDos();
}
System::Void Proyecto_DCL::PrincipalCinco::btnDos_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnDos->Size = System::Drawing::Size(wDos, hDos);
}
System::Void Proyecto_DCL::PrincipalCinco::btnTres_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnTres->Size = System::Drawing::Size(wTres + 20, hTres + 20);
	SonidoTres();
}
System::Void Proyecto_DCL::PrincipalCinco::btnTres_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnTres->Size = System::Drawing::Size(wTres, hTres);
}
System::Void Proyecto_DCL::PrincipalCinco::btnCuatro_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnCuatro->Size = System::Drawing::Size(wCuatro + 20, hCuatro + 20);
	SonidoCuatro();
}
System::Void Proyecto_DCL::PrincipalCinco::btnCuatro_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnCuatro->Size = System::Drawing::Size(wCuatro, hCuatro);
}
System::Void Proyecto_DCL::PrincipalCinco::btnCinco_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnCinco->Size = System::Drawing::Size(wCinco + 20, hCinco + 20);
	SonidoCinco();
}
System::Void Proyecto_DCL::PrincipalCinco::btnCinco_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnCinco->Size = System::Drawing::Size(wCinco, hCinco);
}
System::Void Proyecto_DCL::PrincipalCinco::btnSeis_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnSeis->Size = System::Drawing::Size(wSeis + 20, hSeis + 20);
	SonidoSeis();
}
System::Void Proyecto_DCL::PrincipalCinco::btnSeis_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnSeis->Size = System::Drawing::Size(wSeis, hSeis);
}
System::Void Proyecto_DCL::PrincipalCinco::btnSiete_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnSiete->Size = System::Drawing::Size(wSiete + 20, hSiete + 20);
	SonidoSiete();
}
System::Void Proyecto_DCL::PrincipalCinco::btnSiete_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnSiete->Size = System::Drawing::Size(wSiete, hSiete);
}
System::Void Proyecto_DCL::PrincipalCinco::btnUnoD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnUnoD->Size = System::Drawing::Size(wUno + 20, hUno + 20);
	SonidoUno();
}
System::Void Proyecto_DCL::PrincipalCinco::btnUnoD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnUnoD->Size = System::Drawing::Size(wUno, hUno);
}
System::Void Proyecto_DCL::PrincipalCinco::btnDosD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnDosD->Size = System::Drawing::Size(wDos + 20, hDos + 20);
	SonidoDos();
}
System::Void Proyecto_DCL::PrincipalCinco::btnDosD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnDosD->Size = System::Drawing::Size(wDos, hDos);
}
System::Void Proyecto_DCL::PrincipalCinco::btnTresD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnTresD->Size = System::Drawing::Size(wTres + 20, hTres + 20);
	SonidoTres();
}
System::Void Proyecto_DCL::PrincipalCinco::btnTresD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnTresD->Size = System::Drawing::Size(wTres, hTres);
}
System::Void Proyecto_DCL::PrincipalCinco::btnCuatroD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnCuatroD->Size = System::Drawing::Size(wCuatro + 20, hCuatro + 20);
	SonidoCuatro();
}
System::Void Proyecto_DCL::PrincipalCinco::btnCuatroD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnCuatroD->Size = System::Drawing::Size(wCuatro, hCuatro);
}
System::Void Proyecto_DCL::PrincipalCinco::btnCincoD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnCincoD->Size = System::Drawing::Size(wCinco + 20, hCinco + 20);
	SonidoCinco();
}
System::Void Proyecto_DCL::PrincipalCinco::btnCincoD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnCincoD->Size = System::Drawing::Size(wCinco, hCinco);
}
System::Void Proyecto_DCL::PrincipalCinco::btnSeisD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnSeisD->Size = System::Drawing::Size(wSeis + 20, hSeis + 20);
	SonidoSeis();
}
System::Void Proyecto_DCL::PrincipalCinco::btnSeisD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnSeisD->Size = System::Drawing::Size(wSeis, hSeis);
}
System::Void Proyecto_DCL::PrincipalCinco::btnSieteD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnSieteD->Size = System::Drawing::Size(wSiete + 20, hSiete + 20);
	SonidoSiete();
}
System::Void Proyecto_DCL::PrincipalCinco::btnSieteD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnSieteD->Size = System::Drawing::Size(wSiete, hSiete);
}
System::Void Proyecto_DCL::PrincipalCinco::SonidoUno() {
	PlaySound(TEXT("Audios/Espacio/Gru.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::PrincipalCinco::SonidoDos() {
	PlaySound(TEXT("Audios/Espacio/Minions2.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::PrincipalCinco::SonidoTres() {
	PlaySound(TEXT("Audios/Espacio/Agnes.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::PrincipalCinco::SonidoCuatro() {
	PlaySound(TEXT("Audios/Espacio/Lucy.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::PrincipalCinco::SonidoCinco() {
	PlaySound(TEXT("Audios/Espacio/Nefario.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::PrincipalCinco::SonidoSeis() {
	PlaySound(TEXT("Audios/Espacio/Vector.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::PrincipalCinco::SonidoSiete() {
	PlaySound(TEXT("Audios/Espacio/Minions1.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::PrincipalCinco::SonidoGruFinal() {
	PlaySound(TEXT("Audios/Espacio/Gru-Final.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::PrincipalCinco::SonidoInicial() {
	PlaySound(TEXT("Audios/Espacio/Inicio_Espacio.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::PrincipalCinco::btnPlay_Click(System::Object^  sender, System::EventArgs^  e) {
	SonidoInicial();
}
System::Void Proyecto_DCL::PrincipalCinco::timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	this->Opacity += .1;
	//Detener el timer
	if (this->Opacity == 1) {
		this->timer1->Stop();
		SonidoInicial();
		this->form->Close();
	}
}
System::Void Proyecto_DCL::PrincipalCinco::PrincipalCinco_Load(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
}
System::Void Proyecto_DCL::PrincipalCinco::picCerrar_Click(System::Object^  sender, System::EventArgs^  e) {
	Application::Exit();
}
System::Void Proyecto_DCL::PrincipalCinco::picMinimizar_Click(System::Object^  sender, System::EventArgs^  e) {
	this->WindowState = FormWindowState::Minimized;
}
System::Void Proyecto_DCL::PrincipalCinco::PrincipalCinco_Activated(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
}
System::Void Proyecto_DCL::PrincipalCinco::PrincipalCinco_Deactivate(System::Object^  sender, System::EventArgs^  e) {
	if (this->WindowState == FormWindowState::Minimized) {
		this->Opacity = 0;
	}
}
