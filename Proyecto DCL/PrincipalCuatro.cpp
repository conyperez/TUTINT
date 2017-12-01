#include "PrincipalCuatro.h"
//#include "Actividad4Uno.h"
//#include "Actividad4Dos.h"
//#include "Actividad4Tres.h"
//#include "Actividad4Cuatro.h"
//#include "Actividad4Cinco.h"
//#include "Actividad4Seis.h"
#include "NivelDos.h"
#include <windows.h>
#include <MMSystem.h>

System::Void Proyecto_DCL::PrincipalCuatro::inicializarTam() {
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
}
System::Void Proyecto_DCL::PrincipalCuatro::inicializarComponentesBD() {
	manejadorBD->setNombreHabilidad("Comprension_literal");
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
	}
	this->lblEstrellas->Text = System::Convert::ToString(totalEstr);
}
System::Void Proyecto_DCL::PrincipalCuatro::cargarActUno(bool destacado) {
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
System::Void Proyecto_DCL::PrincipalCuatro::cargarActDos(bool destacado) {
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
System::Void Proyecto_DCL::PrincipalCuatro::cargarActTres(bool destacado) {
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
System::Void Proyecto_DCL::PrincipalCuatro::cargarActCuatro(bool destacado) {
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
System::Void Proyecto_DCL::PrincipalCuatro::cargarActCinco(bool destacado) {
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
System::Void Proyecto_DCL::PrincipalCuatro::cargarActSeis(bool destacado) {
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
System::Void Proyecto_DCL::PrincipalCuatro::btnVolver_Click(System::Object^  sender, System::EventArgs^  e) {
	gcnew NivelDos(this, manejadorBD);
}
System::Void Proyecto_DCL::PrincipalCuatro::btnVolver_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnVolver->Size = System::Drawing::Size(wVolver + 10, hVolver + 10);
}
System::Void Proyecto_DCL::PrincipalCuatro::btnVolver_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnVolver->Size = System::Drawing::Size(wVolver, hVolver);
}
System::Void Proyecto_DCL::PrincipalCuatro::btnUno_Click(System::Object^  sender, System::EventArgs^  e) {
	//gcnew Actividad4Uno(this, btnDosE, btnDos, manejadorBD);
}
System::Void Proyecto_DCL::PrincipalCuatro::btnDos_Click(System::Object^  sender, System::EventArgs^  e) {
	//gcnew Actividad4Dos(this, btnTresE, btnTres, manejadorBD);
}
System::Void Proyecto_DCL::PrincipalCuatro::btnTres_Click(System::Object^  sender, System::EventArgs^  e) {
	//gcnew Actividad4Tres(this, btnCuatroE, btnCuatro, manejadorBD);
}
System::Void Proyecto_DCL::PrincipalCuatro::btnCuatro_Click(System::Object^  sender, System::EventArgs^  e) {
	//gcnew Actividad4Cuatro(this, btnCincoE, btnCinco, manejadorBD);
}
System::Void Proyecto_DCL::PrincipalCuatro::btnCinco_Click(System::Object^  sender, System::EventArgs^  e) {
	//gcnew Actividad4Cinco(this, btnSeisE, btnSeis, manejadorBD);
}
System::Void Proyecto_DCL::PrincipalCuatro::btnSeis_Click(System::Object^  sender, System::EventArgs^  e) {
	//gcnew Actividad4Seis(this, btnSeisE, btnSeis, manejadorBD);
}
System::Void Proyecto_DCL::PrincipalCuatro::btnUnoD_Click(System::Object^  sender, System::EventArgs^  e) {
	this->btnUno->Visible = true;
	this->btnUno->Enabled = true;
	this->btnUnoD->Visible = false;
	this->btnUnoD->Enabled = false;
	//gcnew Actividad4Uno(this, btnDosE, btnDosD, manejadorBD);
}
System::Void Proyecto_DCL::PrincipalCuatro::btnDosD_Click(System::Object^  sender, System::EventArgs^  e) {
	this->btnDos->Visible = true;
	this->btnDos->Enabled = true;
	this->btnDosD->Visible = false;
	this->btnDosD->Enabled = false;
	//gcnew Actividad4Dos(this, btnTresE, btnTresD, manejadorBD);
}
System::Void Proyecto_DCL::PrincipalCuatro::btnTresD_Click(System::Object^  sender, System::EventArgs^  e) {
	this->btnTres->Visible = true;
	this->btnTres->Enabled = true;
	this->btnTresD->Visible = false;
	this->btnTresD->Enabled = false;
	//gcnew Actividad4Tres(this, btnCuatroE, btnCuatroD, manejadorBD);
}
System::Void Proyecto_DCL::PrincipalCuatro::btnCuatroD_Click(System::Object^  sender, System::EventArgs^  e) {
	this->btnCuatro->Visible = true;
	this->btnCuatro->Enabled = true;
	this->btnCuatroD->Visible = false;
	this->btnCuatroD->Enabled = false;
	//gcnew Actividad4Cuatro(this, btnCincoE, btnCincoD, manejadorBD);
}
System::Void Proyecto_DCL::PrincipalCuatro::btnCincoD_Click(System::Object^  sender, System::EventArgs^  e) {
	this->btnCinco->Visible = true;
	this->btnCinco->Enabled = true;
	this->btnCincoD->Visible = false;
	this->btnCincoD->Enabled = false;
	//gcnew Actividad4Cinco(this, btnSeisE, btnSeisD, manejadorBD);
}
System::Void Proyecto_DCL::PrincipalCuatro::btnSeisD_Click(System::Object^  sender, System::EventArgs^  e) {
	this->btnSeis->Visible = true;
	this->btnSeis->Enabled = true;
	this->btnSeisD->Visible = false;
	this->btnSeisD->Enabled = false;
	//gcnew Actividad4Seis(this, btnSeisE, btnSeisD, manejadorBD);
}
System::Void Proyecto_DCL::PrincipalCuatro::btnUno_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnUno->Size = System::Drawing::Size(wUno + 20, hUno + 20);
	SonidoUno();
}
System::Void Proyecto_DCL::PrincipalCuatro::btnUno_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnUno->Size = System::Drawing::Size(wUno, hUno);
}
System::Void Proyecto_DCL::PrincipalCuatro::btnDos_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnDos->Size = System::Drawing::Size(wDos + 20, hDos + 20);
	SonidoDos();
}
System::Void Proyecto_DCL::PrincipalCuatro::btnDos_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnDos->Size = System::Drawing::Size(wDos, hDos);
}
System::Void Proyecto_DCL::PrincipalCuatro::btnTres_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnTres->Size = System::Drawing::Size(wTres + 20, hTres + 20);
	SonidoTres();
}
System::Void Proyecto_DCL::PrincipalCuatro::btnTres_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnTres->Size = System::Drawing::Size(wTres, hTres);
}
System::Void Proyecto_DCL::PrincipalCuatro::btnCuatro_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnCuatro->Size = System::Drawing::Size(wCuatro + 20, hCuatro + 20);
	SonidoCuatro();
}
System::Void Proyecto_DCL::PrincipalCuatro::btnCuatro_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnCuatro->Size = System::Drawing::Size(wCuatro, hCuatro);
}
System::Void Proyecto_DCL::PrincipalCuatro::btnCinco_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnCinco->Size = System::Drawing::Size(wCinco + 20, hCinco + 20);
	SonidoCinco();
}
System::Void Proyecto_DCL::PrincipalCuatro::btnCinco_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnCinco->Size = System::Drawing::Size(wCinco, hCinco);
}
System::Void Proyecto_DCL::PrincipalCuatro::btnSeis_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnSeis->Size = System::Drawing::Size(wSeis + 20, hSeis + 20);
	SonidoSeis();
}
System::Void Proyecto_DCL::PrincipalCuatro::btnSeis_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnSeis->Size = System::Drawing::Size(wSeis, hSeis);
}
System::Void Proyecto_DCL::PrincipalCuatro::btnUnoD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnUnoD->Size = System::Drawing::Size(wUno + 20, hUno + 20);
	SonidoUno();
}
System::Void Proyecto_DCL::PrincipalCuatro::btnUnoD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnUnoD->Size = System::Drawing::Size(wUno, hUno);
}
System::Void Proyecto_DCL::PrincipalCuatro::btnDosD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnDosD->Size = System::Drawing::Size(wDos + 20, hDos + 20);
	SonidoDos();
}
System::Void Proyecto_DCL::PrincipalCuatro::btnDosD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnDosD->Size = System::Drawing::Size(wDos, hDos);
}
System::Void Proyecto_DCL::PrincipalCuatro::btnTresD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnTresD->Size = System::Drawing::Size(wTres + 20, hTres + 20);
	SonidoTres();
}
System::Void Proyecto_DCL::PrincipalCuatro::btnTresD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnTresD->Size = System::Drawing::Size(wTres, hTres);
}
System::Void Proyecto_DCL::PrincipalCuatro::btnCuatroD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnCuatroD->Size = System::Drawing::Size(wCuatro + 20, hCuatro + 20);
	SonidoCuatro();
}
System::Void Proyecto_DCL::PrincipalCuatro::btnCuatroD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnCuatroD->Size = System::Drawing::Size(wCuatro, hCuatro);
}
System::Void Proyecto_DCL::PrincipalCuatro::btnCincoD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnCincoD->Size = System::Drawing::Size(wCinco + 20, hCinco + 20);
	SonidoCinco();
}
System::Void Proyecto_DCL::PrincipalCuatro::btnCincoD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnCincoD->Size = System::Drawing::Size(wCinco, hCinco);
}
System::Void Proyecto_DCL::PrincipalCuatro::btnSeisD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnSeisD->Size = System::Drawing::Size(wSeis + 20, hSeis + 20);
	SonidoSeis();
}
System::Void Proyecto_DCL::PrincipalCuatro::btnSeisD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnSeisD->Size = System::Drawing::Size(wSeis, hSeis);
}
System::Void Proyecto_DCL::PrincipalCuatro::SonidoUno() {
	PlaySound(TEXT("Audios/Zoologico/Martin.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::PrincipalCuatro::SonidoDos() {
	PlaySound(TEXT("Audios/Zoologico/Gloria.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::PrincipalCuatro::SonidoTres() {
	PlaySound(TEXT("Audios/Zoologico/Alex.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::PrincipalCuatro::SonidoCuatro() {
	PlaySound(TEXT("Audios/Zoologico/Melman.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::PrincipalCuatro::SonidoCinco() {
	PlaySound(TEXT("Audios/Zoologico/Mover.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::PrincipalCuatro::SonidoSeis() {
	PlaySound(TEXT("Audios/Zoologico/Pinguinos.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::PrincipalCuatro::SonidoInicial() {
	PlaySound(TEXT("Audios/Zoologico/Inicio_Zoologico.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::PrincipalCuatro::SonidoFinal() {
	PlaySound(TEXT("Audios/Zoologico/Marty-Final.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::PrincipalCuatro::btnPlay_Click(System::Object^  sender, System::EventArgs^  e) {
	SonidoInicial();
}
System::Void Proyecto_DCL::PrincipalCuatro::picCerrar_Click(System::Object^  sender, System::EventArgs^  e) {
	Application::Exit();
}
System::Void Proyecto_DCL::PrincipalCuatro::picMinimizar_Click(System::Object^  sender, System::EventArgs^  e) {
	this->WindowState = FormWindowState::Minimized;
}
System::Void Proyecto_DCL::PrincipalCuatro::timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	this->Opacity += .1;
	//Detener el timer
	if (this->Opacity == 1) {
		this->timer1->Stop();
		SonidoInicial();
		this->form->Close();
	}
}
System::Void Proyecto_DCL::PrincipalCuatro::PrincipalCuatro_Load(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
}
System::Void Proyecto_DCL::PrincipalCuatro::PrincipalCuatro_Activated(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
}
System::Void Proyecto_DCL::PrincipalCuatro::PrincipalCuatro_Deactivate(System::Object^  sender, System::EventArgs^  e) {
	if (this->WindowState == FormWindowState::Minimized) {
		this->Opacity = 0;
	}
}