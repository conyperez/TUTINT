#include "FormEstrella.h"
#include "PrincipalUno.h"
#include "PrincipalDos.h"
#include "PrincipalTres.h"
#include "PrincipalCuatro.h"
#include "PrincipalCinco.h"

System::Void Proyecto_DCL::FormEstrella::button1_Click(System::Object^  sender, System::EventArgs^  e) {
	msclr::interop::marshal_context context;
	int buenas = controlador->getRespuestasBuenas();
	int malas = controlador->getRespuestasMalas();
	int estrellas = numEstrellas;
	String^ nivLogroActividad = gcnew String(controlador->getPercepciones()->getNivelLogro().c_str());
	int intentos = manejadorBD->seleccionarIntentosActividad();
	String^ objetivo = "blblblalblablblaba";						// HAY QUE SACARLOOOOOOOOO!
	manejadorBD->setObjetivoAct(objetivo);

	if (intentos == 0) {
		int intento = intentos + 1;
		//manejadorBD->ingresarDatosActividadActual(numActividad, buenas, malas, nivLogroActividad, estrellas, "Desbloqueado", intento);
		//para el nivel.
		int cantEstrellasNivelActual = manejadorBD->seleccionarCantEstrellasNivel() + estrellas;
		manejadorBD->ingresarActualizarDatosEstrellasNivel(cantEstrellasNivelActual);
		//para la habilidad.
		int cantEstrellasHabActual = manejadorBD->seleccionarCantEstrellasHabilidad() + estrellas;
		manejadorBD->ingresarActualizarDatosEstrellasHabilidad(cantEstrellasHabActual);
		//para las estrellas totales
		int cantEstrellasTotalActual = manejadorBD->seleccionarTotalEstrellas() + estrellas;
		manejadorBD->ingresarActualizarDatosEstrellasTotales(cantEstrellasTotalActual);
	}
	else {
		int intento = intentos + 1;
		int cantEstrellasIntentoAnterior =  manejadorBD->seleccionarEstrellasActividadActual();
		int aumentoEstrellas;
		//comparar la cantidad de estrellas obtenidas en el intento anterior con las estrellas obtenidas actualmente para actualizar el nivel.
		if (cantEstrellasIntentoAnterior < estrellas) {
			aumentoEstrellas = estrellas - cantEstrellasIntentoAnterior;
			//para la actividad
			//manejadorBD->ingresarDatosActividadActual(numActividad, buenas, malas, nivLogroActividad, estrellas, "Desbloqueado", intento);
			//para el nivel.
			int cantEstrellasNivelActual = manejadorBD->seleccionarCantEstrellasNivel() + aumentoEstrellas;
			manejadorBD->ingresarActualizarDatosEstrellasNivel(cantEstrellasNivelActual);
			//para la habilidad.
			int cantEstrellasHabActual = manejadorBD->seleccionarCantEstrellasHabilidad() + aumentoEstrellas;
			manejadorBD->ingresarActualizarDatosEstrellasHabilidad(cantEstrellasHabActual);
			//para las estrellas totales
			int cantEstrellasTotalActual = manejadorBD->seleccionarTotalEstrellas() + aumentoEstrellas;
			manejadorBD->ingresarActualizarDatosEstrellasTotales(cantEstrellasTotalActual);
		}
		else {
			int intento = intentos + 1;
			aumentoEstrellas = cantEstrellasIntentoAnterior - estrellas;
			//para la actividad
			//manejadorBD->ingresarDatosActividadActual(numActividad, buenas, malas, nivLogroActividad, cantEstrellasIntentoAnterior, "Desbloqueado", intento);
		}
	}
	if (estrellas > 1) {
		manejadorBD->ingresarDesbloqueoSiguienteActividad();		// ESTO NO DEBERIA IR
	}
	this->Close();
	determinarFormHabilidad();
}

System::Void Proyecto_DCL::FormEstrella::determinarFormHabilidad() {
	if (habilidad == "Conciencia_fonologica") {
		gcnew PrincipalUno(formActividad, manejadorBD);
	}
	else if (habilidad == "Conciencia_alfabetica") {
		gcnew PrincipalDos(formActividad, manejadorBD);
	}
	else if (habilidad == "Vocabulario") {
		gcnew PrincipalTres(formActividad, manejadorBD);
	}
	else if (habilidad == "Comprension_literal") {
		gcnew PrincipalCuatro(formActividad, manejadorBD);
	}
	else if (habilidad == "Comprension_inferencial") {
		gcnew PrincipalCinco(formActividad, manejadorBD);
	}
}

System::Void Proyecto_DCL::FormEstrella::FormEstrella_Load(System::Object^  sender, System::EventArgs^  e) {
	numEstrellas = obtenerNumeroEstrellas();
	if (numEstrellas == 1)
	{
		mensaje1->Visible = false;
		mensaje2->Visible = false;
		mensaje3->Visible = true;
		estrellaUno->Visible = true;
		estrellaDos->Visible = false;
		estrellaTres->Visible = false;
		estrellaDosE->Visible = true;
		estrellaTresE->Visible = true;
	}
	else if (numEstrellas == 2) {
		mensaje1->Visible = false;
		mensaje2->Visible = true;
		mensaje3->Visible = false;
		estrellaUno->Visible = true;
		estrellaDos->Visible = true;
		estrellaTres->Visible = false;
		estrellaTresE->Visible = true;
	}
	else {
		mensaje1->Visible = true;
		mensaje2->Visible = false;
		mensaje3->Visible = false;
		estrellaUno->Visible = true;
		estrellaDos->Visible = true;
		estrellaTres->Visible = true;
	}
	this->timer1->Start();
}
int Proyecto_DCL::FormEstrella::obtenerNumeroEstrellas() {
	int cantidad = 1;
	if (nivelActuacion >= 80) {
		cantidad = 3;
		return cantidad;
	}
	else if (nivelActuacion >= 50 && nivelActuacion < 80)
	{
		cantidad = 2;
		return cantidad;
	}
	return cantidad;
}
System::Void Proyecto_DCL::FormEstrella::timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	this->Opacity += .1;
	//Detener el timer
	if (this->Opacity == 1) {
		this->timer1->Stop();
	}
}