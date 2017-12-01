#pragma once
#ifndef MANEJADOR_BASE_DE_DATOS
#define MANEJADOR_BASE_DE_DATOS
#include "BaseDeDatos.h"

public ref class ManejadorBD {

public:
	ManejadorBD();
	~ManejadorBD();
	bool ingresarDatosRegistro(System::String^);
	void ingresarDesbloqueoSiguienteActividad();
	void ingresarDesbloqueoSiguienteHabilidad(System::String^ hab_sgte);
	void ingresarDesbloqueoSiguienteNivel(System::String^ nom_sgt_niv);
	void ingresarActualizacionDatosActividad(int buenas, int malas, System::String^ niv_logro, int estrellas, System::String^ permiso, int intentos);
	void ingresarActualizacionDatosHabilidad(System::String^ nivLogro_hab, int cantEstrellas, System::String^ permiso);
	void ingresarActualizacionDatosNivel(int cantEstrellas, System::String^ permiso);
	void ingresarActualizarDatosEstrellasTotales(int totalEstrellas);
	void ingresarActualizarDatosEstrellasNivel(int estrellas);
	void ingresarActualizarDatosEstrellasHabilidad(int estrellas);
	void ingresarDatosActividadActual(int numAct, int buenas, int malas, System::String^ niv_logro, int estrellas, System::String^ permiso, int intento);
	System::Data::DataSet^ seleccionarListaUsuariosRegistrados();
	list<string> seleccionarNivelActual();
	string seleccionarHabilidadActual();
	int seleccionarActividadActual();
	int seleccionarNumSesion();
	string seleccionarNivLogroActividadActual();
	string seleccionarDificultadActividadActual();
	string seleccionarComplejidadActividadActual();
	string seleccionarObjetivoActividadActual();
	int seleccionarCantEstrellasNivel();
	int seleccionarCantEstrellasHabilidad();
	int seleccionarTotalEstrellas();
	int seleccionarIntentosActividad();
	int seleccionarEstrellasActividadActual();
	void setNombreJugador(System::String^);
	void setNombreHabilidad(System::String^ nomhabilidad);
	void setNombreNivel(System::String^ nomNivel);
	void setNumeroActividad(int numeroActividad);
	void setObjetivoAct(System::String^ objetivo);
	string getNombreJugador();

private:
	BaseDeDatos^ bd;
};

#endif // !MANEJADOR_BASE_DE_DATOS
