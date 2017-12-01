#include "NivelUno.h"
#include "PrincipalUno.h"
#include "PrincipalDos.h"
#include "Niveles.h"
#include <list>
#include <string>

System::Void Proyecto_DCL::NivelUno::inicializarTam() {
	wUno = this->picHab1->Size.Width;
	hUno = this->picHab1->Size.Height;
	wDos = this->picHab2->Size.Width;
	hDos = this->picHab2->Size.Height;
	wVolver = this->btnVolver->Size.Width;
	hVolver = this->btnVolver->Size.Height;
}
System::Void Proyecto_DCL::NivelUno::inicializarComponentesBD() {
	manejadorBD->setNombreNivel("Playa");
	int totalEstr = manejadorBD->seleccionarCantEstrellasNivel();
	std::list<std::string> lista = manejadorBD->seleccionarHabilidadActual();
	// Se carga los componentes del nivel uno
	std::list<std::string>::iterator i;
	for (i = lista.begin(); i != lista.end(); i++) {
		if (*i == "Conciencia_fonologica") {
			this->picHab1->Visible = true;
		}
		else if (*i == "Conciencia_alfabetica") {
			this->picHab2->Visible = true;
			this->picHab2E->Visible = false;
		}
	}
	this->lblEstrellas->Text = System::Convert::ToString(totalEstr);
}
System::Void Proyecto_DCL::NivelUno::picHab1_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->picHab1->Size = System::Drawing::Size(wUno + 10, hUno + 10);
}
System::Void Proyecto_DCL::NivelUno::picHab1_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->picHab1->Size = System::Drawing::Size(wUno, hUno);
}
System::Void Proyecto_DCL::NivelUno::picHab2_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->picHab2->Size = System::Drawing::Size(wDos + 10, hDos + 10);
}
System::Void Proyecto_DCL::NivelUno::picHab2_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->picHab2->Size = System::Drawing::Size(wDos, hDos);
}
System::Void Proyecto_DCL::NivelUno::picHab1_Click(System::Object^  sender, System::EventArgs^  e) {
	gcnew PrincipalUno(this, manejadorBD);
}
System::Void Proyecto_DCL::NivelUno::picHab2_Click(System::Object^  sender, System::EventArgs^  e) {
	gcnew PrincipalDos(this, manejadorBD);
}
System::Void Proyecto_DCL::NivelUno::btnVolver_Click(System::Object^  sender, System::EventArgs^  e) {
	//gcnew Niveles(this, manejadorBD);
}
System::Void Proyecto_DCL::NivelUno::btnVolver_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnVolver->Size = System::Drawing::Size(wVolver + 10, hVolver + 10);
}
System::Void Proyecto_DCL::NivelUno::btnVolver_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnVolver->Size = System::Drawing::Size(wVolver, hVolver);
}
System::Void Proyecto_DCL::NivelUno::timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	this->Opacity += .1;
	//Detener el timer
	if (this->Opacity == 1) {
		this->timer1->Stop();
		this->form->Close();
	}
}
System::Void Proyecto_DCL::NivelUno::picCerrar_Click(System::Object^  sender, System::EventArgs^  e) {
	Application::Exit();
}
System::Void Proyecto_DCL::NivelUno::picMinimizar_Click(System::Object^  sender, System::EventArgs^  e) {
	this->WindowState = FormWindowState::Minimized;
}
System::Void Proyecto_DCL::NivelUno::NivelUno_Load(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
}
System::Void Proyecto_DCL::NivelUno::NivelUno_Activated(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
}
System::Void Proyecto_DCL::NivelUno::NivelUno_Deactivate(System::Object^  sender, System::EventArgs^  e) {
	if (this->WindowState == FormWindowState::Minimized) {
		this->Opacity = 0;
	}
}