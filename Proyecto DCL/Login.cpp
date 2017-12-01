#include "Login.h"
#include "Niveles.h"
#include "Registro.h"

System::Void Proyecto_DCL::Login::inicializarTam() {
	wPic2 = this->pictureBox1->Size.Width;
	hPic2 = this->pictureBox1->Size.Height;
}
System::Void Proyecto_DCL::Login::pictureBox1_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->pictureBox1->Size = System::Drawing::Size(wPic2 + 10, hPic2 + 10);
}
System::Void Proyecto_DCL::Login::pictureBox1_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->pictureBox1->Size = System::Drawing::Size(wPic2, hPic2);
}
System::Void Proyecto_DCL::Login::pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
	Registro^ registro = gcnew Registro(this->dgv1, manejadorBD);
	registro->ShowDialog();
}
System::Void Proyecto_DCL::Login::timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	this->Opacity += .1;
	//Detener el timer
	if (this->Opacity == 1) {
		this->timer1->Stop();
		this->form->Hide();
	}
}
System::Void Proyecto_DCL::Login::Login_Load(System::Object^  sender, System::EventArgs^  e) {
	this->dgv1->DataSource = manejadorBD->seleccionarListaUsuariosRegistrados();
	this->dgv1->DataMember = "Jugador";
	timer1->Start();
}
System::Void Proyecto_DCL::Login::picCerrar_Click(System::Object^  sender, System::EventArgs^  e) {
	Application::Exit();
}
System::Void Proyecto_DCL::Login::picMinimizar_Click(System::Object^  sender, System::EventArgs^  e) {
	this->WindowState = FormWindowState::Minimized;
}
System::Void Proyecto_DCL::Login::Login_Activated(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
}
System::Void Proyecto_DCL::Login::Login_Deactivate(System::Object^  sender, System::EventArgs^  e) {
	if (this->WindowState == FormWindowState::Minimized) {
		this->Opacity = 0;
	}
}
System::Void Proyecto_DCL::Login::dgv1_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
	String^ nombre = this->dgv1->CurrentRow->Cells[0]->Value->ToString();
	if (nombre == nullptr) {
		System::Windows::Forms::MessageBox::Show("No existe una cuenta en esta seccion");
	}
	else {
		manejadorBD->setNombreJugador(nombre);
		int num_sesion = manejadorBD->seleccionarNumeroSesion();
		manejadorBD->setNumSesion(num_sesion++);
		gcnew Niveles(this, manejadorBD);
	}
}
