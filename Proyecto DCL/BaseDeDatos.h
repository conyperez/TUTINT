#pragma once
#ifndef BASE_DE_DATOS
#define BASE_DE_DATOS
#include <string>
#include <msclr\marshal_cppstd.h>
#include <list>

using System::Collections::Generic::List;
using namespace MySql::Data::MySqlClient;
using namespace std;

public ref class BaseDeDatos {

public:
	BaseDeDatos();
	~BaseDeDatos();
	void estadoBD(int);
	bool ingresarDatosRegistro(System::String^);
	void ingresarDesbloqueoSiguienteActividad();
	void ingresarDesbloqueoSiguienteHabilidad(System::String^ hab_sgte);
	void ingresarDesbloqueoSiguienteNivel(System::String^ nom_sgt_niv);
	void ingresarActualizacionDatosActividad(int buenas, int malas, System::String^ niv_logro, int estrellas, System::String^ permiso, int intento);
	void ingresarActualizacionDatosHabilidad(System::String^ nivLogro_hab, int cantEstrellas, System::String^ permiso);
	void ingresarActualizacionDatosNivel(int cantEstrellas, System::String^ permiso);
	void ingresarActualizarDatosEstrellasTotales(int estrellas);
	void ingresarActualizarDatosEstrellasNivel(int estrellas);
	void ingresarActualizarDatosEstrellasHabilidad(int estrellas);
	void ingresarDatosActividadActual(int numAct, int buenas, int malas, System::String^ niv_logro, int estrellas, System::String^ permiso, int intento); //este metodo sirve solo cuando el usuario realizo la misma actividad mas de una vez.
	System::Data::DataSet^ seleccionarListaUsuariosRegistrados();
	list<string> seleccionarNivelActual();
	string seleccionarHabilidadActual();
	vector<string> seleccionarTotalActuacion();
	string seleccionarDificultadActividadActual();
	string seleccionarComplejidadActividadActual();
	string seleccionarObjetivoActividadActual();
	string seleccionarUltimoProblemaGenerado();
	int seleccionarActividadActual();
	string seleccionarNivLogroActividadActual();
	int seleccionarCantEstrellasNivel();
	int seleccionarCantEstrellasHabilidad();
	int seleccionarTotalEstrellas();
	int seleccionarIntentosActividad();
	int seleccionarEstrellasActividadActual();
	int seleccionarNumeroSesion();
	void setNombreJugador(System::String^);
	void setNombreHabilidad(System::String^ nomhabilidad);
	void setNombreNivel(System::String^ nomNivel);
	void setObjetivoActividad(System::String^ obj);
	void setNumeroActividad(int numeroActividad);
	void setNumSesion(int numeroSesion);
	int getNumSesion();
	string getNombreJugador();
private:
	MySqlConnection^ conn;
	MySqlCommand^ connCmd;
	MySqlDataReader^ dataReader;
	System::String^ nombreJugador;
	System::String^ dificultad;
	System::String^ complejidad;
	System::String^ nivel;
	System::String^ habilidad;
	System::String^ objetivo;
	int numActividad;
	int numSesion;
	msclr::interop::marshal_context context;
};

#endif // !BASE_DE_DATOS
