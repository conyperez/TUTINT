#include "ManejadorBD.h"

ManejadorBD::ManejadorBD() {
	bd = gcnew BaseDeDatos();
}

ManejadorBD::~ManejadorBD() { }

bool ManejadorBD::ingresarDatosRegistro(System::String^ nombre)
{
	bool aceptado = bd->ingresarDatosRegistro(nombre);
	return aceptado;
}

void ManejadorBD::ingresarActualizacionDatosActividad(int buenas, int malas, System::String^ niv_logro, int estrellas, System::String^ permiso, int intentos)
{
	bd->ingresarActualizacionDatosActividad(buenas, malas, niv_logro, estrellas, permiso, intentos);
}

void ManejadorBD::ingresarActualizacionDatosHabilidad(System::String ^ nivLogro_hab, int cantEstrellas, System::String ^ permiso)
{
	bd->ingresarActualizacionDatosHabilidad(nivLogro_hab, cantEstrellas, permiso);
}

void ManejadorBD::ingresarActualizacionDatosNivel(int cantEstrellas, System::String ^ permiso)
{
	bd->ingresarActualizacionDatosNivel(cantEstrellas, permiso);
}

void ManejadorBD::ingresarActualizarDatosEstrellasTotales(int totalEstrellas)
{
	bd->ingresarActualizarDatosEstrellasTotales(totalEstrellas);
}

void ManejadorBD::ingresarActualizarDatosEstrellasNivel(int estrellas)
{
	bd->ingresarActualizarDatosEstrellasNivel(estrellas);
}

void ManejadorBD::ingresarActualizarDatosEstrellasHabilidad(int estrellas)
{
	bd->ingresarActualizarDatosEstrellasHabilidad(estrellas);
}

void ManejadorBD::ingresarDatosActividadActual(int numAct, int buenas, int malas, System::String ^ niv_logro, int estrellas, System::String ^ permiso, int intento)
{
	bd->ingresarDatosActividadActual(numAct, buenas, malas, niv_logro, estrellas, permiso, intento);
}

void ManejadorBD::ingresarDesbloqueoSiguienteActividad()
{
	bd->ingresarDesbloqueoSiguienteActividad();
}

void ManejadorBD::ingresarDesbloqueoSiguienteHabilidad(System::String^ hab_sgte)
{
	bd->ingresarDesbloqueoSiguienteHabilidad(hab_sgte);
}

void ManejadorBD::ingresarDesbloqueoSiguienteNivel(System::String^ nom_sgt_niv)
{
	bd->ingresarDesbloqueoSiguienteNivel(nom_sgt_niv);
}

System::Data::DataSet^ ManejadorBD::seleccionarListaUsuariosRegistrados()
{
	System::Data::DataSet^ data = gcnew System::Data::DataSet();
	return data = bd->seleccionarListaUsuariosRegistrados();
}

list<string> ManejadorBD::seleccionarNivelActual()
{
	list<string> lista = bd->seleccionarNivelActual();
	return lista;
}

string ManejadorBD::seleccionarHabilidadActual()
{
	string lista = bd->seleccionarHabilidadActual();
	return lista;
}

int ManejadorBD::seleccionarActividadActual()
{
	int act = bd->seleccionarActividadActual();
	return act;
}

int ManejadorBD::seleccionarNumSesion()
{
	int numSesion = bd->getNumSesion();
	return numSesion;
}

string ManejadorBD::seleccionarNivLogroActividadActual()
{
	string nivelLogro = bd->seleccionarNivLogroActividadActual();
	return nivelLogro;
}

string ManejadorBD::seleccionarDificultadActividadActual()
{
	string dificultad = bd->seleccionarDificultadActividadActual();
	return dificultad;
}

string ManejadorBD::seleccionarComplejidadActividadActual()
{
	string complejidad = bd->seleccionarComplejidadActividadActual();
	return complejidad;
}

string ManejadorBD::seleccionarObjetivoActividadActual()
{
	string objetivo = bd->seleccionarObjetivoActividadActual();
	return objetivo;
}

int ManejadorBD::seleccionarCantEstrellasNivel()
{
	int cant = bd->seleccionarCantEstrellasNivel();
	return cant;
}

int ManejadorBD::seleccionarCantEstrellasHabilidad()
{
	int cant = bd->seleccionarCantEstrellasHabilidad();
	return cant;
}

int ManejadorBD::seleccionarTotalEstrellas()
{
	int total = bd->seleccionarTotalEstrellas();
	return total;
}

int ManejadorBD::seleccionarIntentosActividad()
{
	int intentos = bd->seleccionarIntentosActividad();
	return intentos;
}

int ManejadorBD::seleccionarEstrellasActividadActual()
{
	int estrellas = bd->seleccionarEstrellasActividadActual();
	return estrellas;
}

void ManejadorBD::setNombreJugador(System::String^ jugador)
{
	bd->setNombreJugador(jugador);
}

void ManejadorBD::setNombreHabilidad(System::String ^ nomhabilidad)
{
	bd->setNombreHabilidad(nomhabilidad);
}

void ManejadorBD::setNombreNivel(System::String ^ nomNivel)
{
	bd->setNombreNivel(nomNivel);
}

void ManejadorBD::setNumeroActividad(int numeroActividad)
{
	bd->setNumeroActividad(numeroActividad);
}

void ManejadorBD::setObjetivoAct(System::String ^ objetivo)
{
	bd->setObjetivoActividad(objetivo);
}

string ManejadorBD::getNombreJugador() {
	string nombre = bd->getNombreJugador();
	return nombre;
}