#include "PrincipalTres.h"
//#include "Actividad3Uno.h"
//#include "Actividad3Dos.h"
//#include "Actividad3Tres.h"
//#include "Actividad3Cuatro.h"
//#include "Actividad3Cinco.h"
//#include "Actividad3Seis.h"
#include "NivelDos.h"
#include <windows.h>
#include <MMSystem.h>

System::Void Proyecto_DCL::PrincipalTres::inicializarTam() {
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
System::Void Proyecto_DCL::PrincipalTres::inicializarComponentesBD() {
	manejadorBD->setNombreHabilidad("Vocabulario");
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
System::Void Proyecto_DCL::PrincipalTres::cargarActUno(bool destacado) {
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
System::Void Proyecto_DCL::PrincipalTres::cargarActDos(bool destacado) {
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
System::Void Proyecto_DCL::PrincipalTres::cargarActTres(bool destacado) {
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
System::Void Proyecto_DCL::PrincipalTres::cargarActCuatro(bool destacado) {
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
System::Void Proyecto_DCL::PrincipalTres::cargarActCinco(bool destacado) {
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
System::Void Proyecto_DCL::PrincipalTres::cargarActSeis(bool destacado) {
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
System::Void Proyecto_DCL::PrincipalTres::btnVolver_Click(System::Object^  sender, System::EventArgs^  e) {
	gcnew NivelDos(this, manejadorBD);
}
System::Void Proyecto_DCL::PrincipalTres::btnVolver_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnVolver->Size = System::Drawing::Size(wVolver + 10, hVolver + 10);
}
System::Void Proyecto_DCL::PrincipalTres::btnVolver_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnVolver->Size = System::Drawing::Size(wVolver, hVolver);
}
System::Void Proyecto_DCL::PrincipalTres::btnUno_Click(System::Object^  sender, System::EventArgs^  e) {
	//gcnew Actividad3Uno(this, btnDosE, btnDos, manejadorBD);
}
System::Void Proyecto_DCL::PrincipalTres::btnDos_Click(System::Object^  sender, System::EventArgs^  e) {
//	gcnew Actividad3Dos(this, btnTresE, btnTres, manejadorBD);
}
System::Void Proyecto_DCL::PrincipalTres::btnTres_Click(System::Object^  sender, System::EventArgs^  e) {
	//gcnew Actividad3Tres(this, btnCuatroE, btnCuatro, manejadorBD);
}
System::Void Proyecto_DCL::PrincipalTres::btnCuatro_Click(System::Object^  sender, System::EventArgs^  e) {
	//gcnew Actividad3Cuatro(this, btnCincoE, btnCinco, manejadorBD);
}
System::Void Proyecto_DCL::PrincipalTres::btnCinco_Click(System::Object^  sender, System::EventArgs^  e) {
	//gcnew Actividad3Cinco(this, btnSeisE, btnSeis, manejadorBD);
}
System::Void Proyecto_DCL::PrincipalTres::btnSeis_Click(System::Object^  sender, System::EventArgs^  e) {
	//gcnew Actividad3Seis(this, btnSeisE, btnSeis, manejadorBD);
}
System::Void Proyecto_DCL::PrincipalTres::btnUnoD_Click(System::Object^  sender, System::EventArgs^  e) {
	this->btnUno->Visible = true;
	this->btnUno->Enabled = true;
	this->btnUnoD->Visible = false;
	this->btnUnoD->Enabled = false;
	//gcnew Actividad3Uno(this, btnDosE, btnDosD, manejadorBD);
}
System::Void Proyecto_DCL::PrincipalTres::btnDosD_Click(System::Object^  sender, System::EventArgs^  e) {
	this->btnDos->Visible = true;
	this->btnDos->Enabled = true;
	this->btnDosD->Visible = false;
	this->btnDosD->Enabled = false;
	//gcnew Actividad3Dos(this, btnTresE, btnTresD, manejadorBD);
}
System::Void Proyecto_DCL::PrincipalTres::btnTresD_Click(System::Object^  sender, System::EventArgs^  e) {
	this->btnTres->Visible = true;
	this->btnTres->Enabled = true;
	this->btnTresD->Visible = false;
	this->btnTresD->Enabled = false;
	//gcnew Actividad3Tres(this, btnCuatroE, btnCuatroD, manejadorBD);
}
System::Void Proyecto_DCL::PrincipalTres::btnCuatroD_Click(System::Object^  sender, System::EventArgs^  e) {
	this->btnCuatro->Visible = true;
	this->btnCuatro->Enabled = true;
	this->btnCuatroD->Visible = false;
	this->btnCuatroD->Enabled = false;
	//gcnew Actividad3Cuatro(this, btnCincoE, btnCincoD, manejadorBD);
}
System::Void Proyecto_DCL::PrincipalTres::btnCincoD_Click(System::Object^  sender, System::EventArgs^  e) {
	this->btnCinco->Visible = true;
	this->btnCinco->Enabled = true;
	this->btnCincoD->Visible = false;
	this->btnCincoD->Enabled = false;
	//gcnew Actividad3Cinco(this, btnSeisE, btnSeisD, manejadorBD);
}
System::Void Proyecto_DCL::PrincipalTres::btnSeisD_Click(System::Object^  sender, System::EventArgs^  e) {
	this->btnSeis->Visible = true;
	this->btnSeis->Enabled = true;
	this->btnSeisD->Visible = false;
	this->btnSeisD->Enabled = false;
	//gcnew Actividad3Seis(this, btnSeisE, btnSeisD, manejadorBD);
}
System::Void Proyecto_DCL::PrincipalTres::btnUno_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnUno->Size = System::Drawing::Size(wUno + 20, hUno + 20);
	SonidoJudy();
}
System::Void Proyecto_DCL::PrincipalTres::btnUno_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnUno->Size = System::Drawing::Size(wUno, hUno);
}
System::Void Proyecto_DCL::PrincipalTres::btnDos_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnDos->Size = System::Drawing::Size(wDos + 20, hDos + 20);
	SonidoNick();
}
System::Void Proyecto_DCL::PrincipalTres::btnDos_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnDos->Size = System::Drawing::Size(wDos, hDos);
}
System::Void Proyecto_DCL::PrincipalTres::btnTres_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnTres->Size = System::Drawing::Size(wTres + 20, hTres + 20);
	SonidoFlash();
}
System::Void Proyecto_DCL::PrincipalTres::btnTres_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnTres->Size = System::Drawing::Size(wTres, hTres);
}
System::Void Proyecto_DCL::PrincipalTres::btnCuatro_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnCuatro->Size = System::Drawing::Size(wCuatro + 20, hCuatro + 20);
	SonidoGarraza();
}
System::Void Proyecto_DCL::PrincipalTres::btnCuatro_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnCuatro->Size = System::Drawing::Size(wCuatro, hCuatro);
}
System::Void Proyecto_DCL::PrincipalTres::btnCinco_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnCinco->Size = System::Drawing::Size(wCinco + 20, hCinco + 20);
	SonidoBig();
}
System::Void Proyecto_DCL::PrincipalTres::btnCinco_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnCinco->Size = System::Drawing::Size(wCinco, hCinco);
}
System::Void Proyecto_DCL::PrincipalTres::btnSeis_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnSeis->Size = System::Drawing::Size(wSeis + 20, hSeis + 20);
	SonidoOveja();
}
System::Void Proyecto_DCL::PrincipalTres::btnSeis_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnSeis->Size = System::Drawing::Size(wSeis, hSeis);
}
System::Void Proyecto_DCL::PrincipalTres::btnUnoD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnUnoD->Size = System::Drawing::Size(wUno + 20, hUno + 20);
	SonidoJudy();
}
System::Void Proyecto_DCL::PrincipalTres::btnUnoD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnUnoD->Size = System::Drawing::Size(wUno, hUno);
}
System::Void Proyecto_DCL::PrincipalTres::btnDosD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnDosD->Size = System::Drawing::Size(wDos + 20, hDos + 20);
	SonidoNick();
}
System::Void Proyecto_DCL::PrincipalTres::btnDosD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnDosD->Size = System::Drawing::Size(wDos, hDos);
}
System::Void Proyecto_DCL::PrincipalTres::btnTresD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnTresD->Size = System::Drawing::Size(wTres + 20, hTres + 20);
	SonidoFlash();
}
System::Void Proyecto_DCL::PrincipalTres::btnTresD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnTresD->Size = System::Drawing::Size(wTres, hTres);
}
System::Void Proyecto_DCL::PrincipalTres::btnCuatroD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnCuatroD->Size = System::Drawing::Size(wCuatro + 20, hCuatro + 20);
	SonidoGarraza();
}
System::Void Proyecto_DCL::PrincipalTres::btnCuatroD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnCuatroD->Size = System::Drawing::Size(wCuatro, hCuatro);
}
System::Void Proyecto_DCL::PrincipalTres::btnCincoD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnCincoD->Size = System::Drawing::Size(wCinco + 20, hCinco + 20);
	SonidoBig();
}
System::Void Proyecto_DCL::PrincipalTres::btnCincoD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnCincoD->Size = System::Drawing::Size(wCinco, hCinco);
}
System::Void Proyecto_DCL::PrincipalTres::btnSeisD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnSeisD->Size = System::Drawing::Size(wSeis + 20, hSeis + 20);
	SonidoOveja();
}
System::Void Proyecto_DCL::PrincipalTres::btnSeisD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnSeisD->Size = System::Drawing::Size(wSeis, hSeis);
}
System::Void Proyecto_DCL::PrincipalTres::SonidoJudy() {
	PlaySound(TEXT("Audios/Parque/Judy.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::PrincipalTres::SonidoNick() {
	PlaySound(TEXT("Audios/Parque/Nick.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::PrincipalTres::SonidoFlash() {
	PlaySound(TEXT("Audios/Parque/Flash.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::PrincipalTres::SonidoGarraza() {
	PlaySound(TEXT("Audios/Parque/Garraza.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::PrincipalTres::SonidoBig() {
	PlaySound(TEXT("Audios/Parque/Mr-Big.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::PrincipalTres::SonidoOveja() {
	PlaySound(TEXT("Audios/Parque/Oveja.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::PrincipalTres::SonidoJudyFinal() {
	PlaySound(TEXT("Audios/Parque/Judy-Final.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::PrincipalTres::SonidoInicial() {
	PlaySound(TEXT("Audios/Parque/Inicio_parque.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::PrincipalTres::btnPlay_Click(System::Object^  sender, System::EventArgs^  e) {
	SonidoInicial();
}
System::Void Proyecto_DCL::PrincipalTres::timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	this->Opacity += .1;
	//Detener el timer
	if (this->Opacity == 1) {
		this->timer1->Stop();
		SonidoInicial();
		this->form->Close();
	}
}
System::Void Proyecto_DCL::PrincipalTres::PrincipalTres_Load(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
}
System::Void Proyecto_DCL::PrincipalTres::picCerrar_Click(System::Object^  sender, System::EventArgs^  e) {
	Application::Exit();
}
System::Void Proyecto_DCL::PrincipalTres::picMinimizar_Click(System::Object^  sender, System::EventArgs^  e) {
	this->WindowState = FormWindowState::Minimized;
}
System::Void Proyecto_DCL::PrincipalTres::PrincipalTres_Activated(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
}
System::Void Proyecto_DCL::PrincipalTres::PrincipalTres_Deactivate(System::Object^  sender, System::EventArgs^  e) {
	if (this->WindowState == FormWindowState::Minimized) {
		this->Opacity = 0;
	}
}