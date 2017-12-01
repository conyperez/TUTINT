#include "Mensaje.h"
#include <windows.h>
#include <MMSystem.h>

System::Void Proyecto_DCL::Mensaje::SonidoUno() {
	PlaySound(TEXT("Audios/Oceano/Nemo-Papa.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::Mensaje::SonidoDos() {
	PlaySound(TEXT("Audios/Playa/Bob-Esponja-Final.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::Mensaje::SonidoTres() {
	PlaySound(TEXT("Audios/Parque/Judy-Final.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::Mensaje::SonidoCuatro() {
	PlaySound(TEXT("Audios/Zoologico/Marty-Final.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::Mensaje::SonidoCinco() {
	PlaySound(TEXT("Audios/Espacio/Gru-Final.wav"), NULL, SND_ASYNC);
}
System::Void Proyecto_DCL::Mensaje::iniciarPic() {
	this->picUno->Visible = false;
	this->picDos->Visible = false;
	this->picTres->Visible = false;
	this->picCuatro->Visible = false;
	this->picCinco->Visible = false;
	this->pictureBox1->Visible = false;
	this->pictureBox2->Visible = true;
}
System::Void Proyecto_DCL::Mensaje::inicializar() {
	iniciarPic();
	if (habilidad == 1) {
		this->pictureBox2->Visible = true;
		this->picUno->Visible = true;
		SonidoUno();
	}
	else if (habilidad == 2) {
		this->pictureBox2->Visible = true;
		this->picDos->Visible = true;
		SonidoDos();
	}
	else if (habilidad == 3) {
		this->pictureBox2->Visible = true;
		this->picTres->Visible = true;
		SonidoTres();
	}
	else if (habilidad == 4) {
		this->pictureBox2->Visible = true;
		this->picCuatro->Visible = true;
		SonidoCuatro();
	}
	else if (habilidad == 5) {
		this->pictureBox1->Visible = true;
		this->picCinco->Visible = true;
		SonidoCinco();
	}
}
System::Void Proyecto_DCL::Mensaje::button1_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Close();
}
System::Void Proyecto_DCL::Mensaje::timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	this->Opacity += .1;
	//Detener el timer
	if (this->Opacity == 1) {
		this->timer1->Stop();
	}
}
System::Void Proyecto_DCL::Mensaje::Mensaje_Load(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
}
