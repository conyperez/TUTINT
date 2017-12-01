#include "Registro.h"

System::Void Proyecto_DCL::Registro::pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ id = this->textBox1->Text;
	bool aceptado = manejadorBD->ingresarDatosRegistro(id);
	if (aceptado) {
		this->Close();
		// Se carga la tabla
		this->tabla->DataSource = manejadorBD->seleccionarListaUsuariosRegistrados();
		this->tabla->DataMember = "Jugador";
	}
}
System::Void Proyecto_DCL::Registro::picCerrar_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Close();
}
System::Void Proyecto_DCL::Registro::timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	this->Opacity += .1;
	//Detener el timer
	if (this->Opacity == 1) {
		this->timer1->Stop();
	}
}
System::Void Proyecto_DCL::Registro::Registro_Load(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
}
