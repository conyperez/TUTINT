#include "NivelDos.h"
#include "PrincipalTres.h"
#include "PrincipalCuatro.h"
#include "Niveles.h"
#include <list>
#include <string>

System::Void Proyecto_DCL::NivelDos::inicializarTam() {
	wTres = this->picHab3->Size.Width;
	hTres = this->picHab3->Size.Height;
	wCuatro = this->picHab4->Size.Width;
	hCuatro = this->picHab4->Size.Height;
	wVolver = this->btnVolver->Size.Width;
	hVolver = this->btnVolver->Size.Height;
}
System::Void Proyecto_DCL::NivelDos::inicializarComponentesBD() {
	manejadorBD->setNombreNivel("Parque");
	int totalEstr = manejadorBD->seleccionarCantEstrellasNivel();
	std::list<std::string> lista = manejadorBD->seleccionarHabilidadActual();
	// Se carga los componentes del nivel dos
	std::list<std::string>::iterator i;
	for (i = lista.begin(); i != lista.end(); i++) {
		if (*i == "Vocabulario") {
			this->picHab3->Visible = true;
		}
		else if (*i == "Comprension_literal") {
			this->picHab4->Visible = true;
			this->picHab4E->Visible = false;
		}
	}
	this->lblEstrellas->Text = System::Convert::ToString(totalEstr);
}
System::Void Proyecto_DCL::NivelDos::picHab3_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->picHab3->Size = System::Drawing::Size(wTres + 10, hTres + 10);
}
System::Void Proyecto_DCL::NivelDos::picHab3_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->picHab3->Size = System::Drawing::Size(wTres, hTres);
}
System::Void Proyecto_DCL::NivelDos::picHab4_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->picHab4->Size = System::Drawing::Size(wCuatro + 10, hCuatro + 10);
}
System::Void Proyecto_DCL::NivelDos::picHab4_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->picHab4->Size = System::Drawing::Size(wCuatro, hCuatro);
}
System::Void Proyecto_DCL::NivelDos::btnVolver_Click(System::Object^  sender, System::EventArgs^  e) {
	//gcnew Niveles(this, manejadorBD);
}
System::Void Proyecto_DCL::NivelDos::btnVolver_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnVolver->Size = System::Drawing::Size(wVolver + 10, hVolver + 10);
}
System::Void Proyecto_DCL::NivelDos::btnVolver_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnVolver->Size = System::Drawing::Size(wVolver, hVolver);
}
System::Void Proyecto_DCL::NivelDos::picHab3_Click(System::Object^  sender, System::EventArgs^  e) {
	gcnew PrincipalTres(this, manejadorBD);
}
System::Void Proyecto_DCL::NivelDos::picHab4_Click(System::Object^  sender, System::EventArgs^  e) {
	gcnew PrincipalCuatro(this, manejadorBD);
}
System::Void Proyecto_DCL::NivelDos::timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	this->Opacity += .1;
	//Detener el timer
	if (this->Opacity == 1) {
		this->timer1->Stop();
		this->form->Close();
	}
}
System::Void Proyecto_DCL::NivelDos::NivelDos_Load(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
}
System::Void Proyecto_DCL::NivelDos::picCerrar_Click(System::Object^  sender, System::EventArgs^  e) {
	Application::Exit();
}
System::Void Proyecto_DCL::NivelDos::picMinimizar_Click(System::Object^  sender, System::EventArgs^  e) {
	this->WindowState = FormWindowState::Minimized;
}
System::Void Proyecto_DCL::NivelDos::NivelDos_Activated(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
}
System::Void Proyecto_DCL::NivelDos::NivelDos_Deactivate(System::Object^  sender, System::EventArgs^  e) {
	if (this->WindowState == FormWindowState::Minimized) {
		this->Opacity = 0;
	}
}