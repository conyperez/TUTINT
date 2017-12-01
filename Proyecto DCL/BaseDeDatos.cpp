#include "BaseDeDatos.h"
#include <msclr\marshal_cppstd.h>
#include <string>
#include <list>

BaseDeDatos::BaseDeDatos()
{
	MySqlConnectionStringBuilder^ builder = gcnew MySqlConnectionStringBuilder();
	builder->Server = "localhost";
	builder->UserID = "root";
	builder->Password = "1234";
	builder->Database = "bd_tutin1.2";
	conn = gcnew MySqlConnection(builder->ToString());
}

BaseDeDatos::~BaseDeDatos() {}

void BaseDeDatos::estadoBD(int estado)
{
	if (estado == 0) {
		conn->Open();
	}
	if (estado == 1) {
		conn->Close();
	}
}

bool BaseDeDatos::ingresarDatosRegistro(System::String^ nombre)
{
	//Inicio la base de datos
	estadoBD(0);
	//Datos de la tabla jugador

	connCmd = gcnew MySqlCommand("INSERT INTO `bd_tutin1.2`.jugador(nom_jugador,total_estrellas) VALUES ('" + nombre + "',0);", conn);
	try {
		dataReader = connCmd->ExecuteReader();
		estadoBD(1); //Cierro la base de datos
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show(ex->Message);
		return false;
	}

	//Datos de la tabla niveles
	//Nivel 1
	estadoBD(0);
	setNombreNivel("Playa");
	connCmd = gcnew MySqlCommand("INSERT INTO `bd_tutin1.2`.nivel(nom_nivel,IdJugador_nivel,cant_estrellas,permiso) VALUES('Playa','" + nombre + "', 0,'Desbloqueado');", conn);
	try {
		dataReader = connCmd->ExecuteReader();
		estadoBD(1); //Cierro la base de datos
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show(ex->Message);
		return false;
	}
	//Nivel 2
	estadoBD(0);
	connCmd = gcnew MySqlCommand("INSERT INTO `bd_tutin1.2`.nivel(nom_nivel,IdJugador_nivel,cant_estrellas,permiso) VALUES('Parque','" + nombre + "',0,'Bloqueado');", conn);
	try {
		dataReader = connCmd->ExecuteReader();
		estadoBD(1); //Cierro la base de datos
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show(ex->Message);
		return false;
	}
	//Nivel 3
	estadoBD(0);
	connCmd = gcnew MySqlCommand("INSERT INTO `bd_tutin1.2`.nivel(nom_nivel,IdJugador_nivel,cant_estrellas,permiso) VALUES('Espacio','" + nombre + "',0,'Bloqueado');", conn);
	try {
		dataReader = connCmd->ExecuteReader();
		estadoBD(1); //Cierro la base de datos
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show(ex->Message);
		return false;
	}
	//Datos de la tabla habilidad
	//Conciencia_fonologica
	estadoBD(0);
	connCmd = gcnew MySqlCommand("INSERT INTO `bd_tutin1.2`.habilidad(nombre_hab,IdJugador_hab,nom_niv,niv_logro_hab,cant_estrellas,permiso) VALUES ('Conciencia_fonologica','" + nombre + "','Playa','NN',0,'Desbloqueado');", conn);
	try {
		dataReader = connCmd->ExecuteReader();
		estadoBD(1); //Cierro la base de datos
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show(ex->Message);
		return false;
	}
	//Conciencia_alfabetica
	estadoBD(0);
	connCmd = gcnew MySqlCommand("INSERT INTO `bd_tutin1.2`.habilidad(nombre_hab,IdJugador_hab,nom_niv,niv_logro_hab,cant_estrellas,permiso) VALUES ('Conciencia_alfabetica','" + nombre + "','Playa','NN',0,'Bloqueado');", conn);
	try {
		dataReader = connCmd->ExecuteReader();
		estadoBD(1); //Cierro la base de datos
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show(ex->Message);
		return false;
	}
	//Vocabulario
	estadoBD(0);
	connCmd = gcnew MySqlCommand("INSERT INTO `bd_tutin1.2`.habilidad(nombre_hab,IdJugador_hab,nom_niv,niv_logro_hab,cant_estrellas,permiso) VALUES ('Vocabulario','" + nombre + "','Parque','NN',0,'Bloqueado');", conn);
	try {
		dataReader = connCmd->ExecuteReader();
		estadoBD(1); //Cierro la base de datos
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show(ex->Message);
		return false;
	}
	//Comprension_literal
	estadoBD(0);
	connCmd = gcnew MySqlCommand("INSERT INTO `bd_tutin1.2`.habilidad(nombre_hab,IdJugador_hab,nom_niv,niv_logro_hab,cant_estrellas,permiso) VALUES ('Comprension_literal','" + nombre + "','Parque','NN',0,'Bloqueado');", conn);
	try {
		dataReader = connCmd->ExecuteReader();
		estadoBD(1); //Cierro la base de datos
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show(ex->Message);
		return false;
	}
	//Comprension_inferencial
	estadoBD(0);
	connCmd = gcnew MySqlCommand("INSERT INTO `bd_tutin1.2`.habilidad(nombre_hab,IdJugador_hab,nom_niv,niv_logro_hab,cant_estrellas,permiso) VALUES ('Comprension_inferencial','" + nombre + "','Espacio','NN',0,'Bloqueado');", conn);
	try {
		dataReader = connCmd->ExecuteReader();
		estadoBD(1); //Cierro la base de datos
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show(ex->Message);
		return false;
	}

	// Datos de la tabla objetivo
	/*
	estadoBD(0);
	connCmd = gcnew MySqlCommand("INSERT INTO `bd_tutin1.2`.objetivos(habilidad, dificultad, complejidad, num_actividad, objetivo) VALUES('Comprension_inferencial', 'Basica', 'Basica', '1', 'Reconocer inferencias'); ", conn);
	try {
		dataReader = connCmd->ExecuteReader();
		estadoBD(1); //Cierro la base de datos
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show(ex->Message);
		return false;
	}*/

	return true;
}

void BaseDeDatos::ingresarActualizacionDatosActividad(int buenas, int malas, System::String^ niv_logro, int estrellas, System::String^ permiso, int intento)
{
	estadoBD(0);
	connCmd = gcnew MySqlCommand("UPDATE `bd_tutin1.1`.actividad SET buenas = " + buenas + ",malas = " + malas + ", niv_logro_acti= '" + niv_logro + "', cant_estrellas = " + estrellas + ", permiso ='" + permiso + "',intentos = " + intento + " WHERE num_actividad = " + this->numActividad + " AND IdJugador_act = '" + this->nombreJugador + "' AND nombre_hab = '" + this->habilidad + "'; ", conn);
	try {
		connCmd->ExecuteNonQuery();
		estadoBD(1); //Cierro la base de datos
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show(ex->Message);
	}

}

void BaseDeDatos::ingresarActualizacionDatosHabilidad(System::String ^ nivLogro_hab, int cantEstrellas, System::String ^ permiso)
{
	estadoBD(0);
	connCmd = gcnew MySqlCommand("UPDATE `bd_tutin1.1`.habilidad SET niv_logro_hab = '" + nivLogro_hab + "', cant_estrellas = " + cantEstrellas + ", permiso = '" + permiso + "' WHERE nombre_hab = '" + habilidad + "' AND IdJugador_hab = '" + nombreJugador + "';", conn);
	try {
		dataReader = connCmd->ExecuteReader();
		estadoBD(1); //Cierro la base de datos
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show(ex->Message);
	}
}

void BaseDeDatos::ingresarActualizacionDatosNivel(int cantEstrellas, System::String ^ permiso)
{
	estadoBD(0);
	connCmd = gcnew MySqlCommand("UPDATE `bd_tutin1.1`.nivel SET cant_estrellas = " + cantEstrellas + ", permiso = '" + permiso + "' WHERE nom_nivel = '" + nivel + "' AND IdJugador_nivel = '" + nombreJugador + "';", conn);
	try {
		dataReader = connCmd->ExecuteReader();
		estadoBD(1); //Cierro la base de datos
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show(ex->Message);
	}
}

void BaseDeDatos::ingresarActualizarDatosEstrellasTotales(int estrellas)
{
	estadoBD(0);
	connCmd = gcnew MySqlCommand("UPDATE `bd_tutin1.1`.jugador SET total_estrellas = " + estrellas + " WHERE nom_jugador = '" + nombreJugador + "';", conn);
	try {
		connCmd->ExecuteNonQuery();
		estadoBD(1); //Cierro la base de datos
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show(ex->Message);
	}
}

void BaseDeDatos::ingresarActualizarDatosEstrellasNivel(int estrellas)
{
	estadoBD(0);
	connCmd = gcnew MySqlCommand("UPDATE `bd_tutin1.1`.nivel SET cant_estrellas = " + estrellas + " WHERE IdJugador_nivel = '" + this->nombreJugador + "' AND nom_nivel = '" + this->nivel + "';", conn);
	try {
		connCmd->ExecuteNonQuery();
		estadoBD(1); //Cierro la base de datos
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show(ex->Message);
	}
}

void BaseDeDatos::ingresarActualizarDatosEstrellasHabilidad(int estrellas)
{
	estadoBD(0);
	connCmd = gcnew MySqlCommand("UPDATE `bd_tutin1.1`.habilidad SET cant_estrellas = " + estrellas + " WHERE IdJugador_hab = '" + nombreJugador + "' AND nombre_hab = '" + habilidad + "';", conn);
	try {
		connCmd->ExecuteNonQuery();

		estadoBD(1); //Cierro la base de datos
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show(ex->Message);
	}
}

void BaseDeDatos::ingresarDatosActividadActual(int numAct, int buenas, int malas, System::String ^ niv_logro, int estrellas, System::String ^ permiso, int intento)
{
	conn->Open();
	connCmd = gcnew MySqlCommand("INSERT INTO `bd_tutin1.1`.actividad(num_actividad,IdJugador_act,nombre_hab,objetivo,buenas,malas,niv_logro_acti,cant_estrellas,permiso,intentos) VALUES(" + numAct + ",'" + nombreJugador + "','" + habilidad + "','" + objetivo + "'," + buenas + "," + malas + ",'" + niv_logro + "'," + estrellas + ",'" + permiso + "'," + intento + ");", conn);
	try {
		connCmd->ExecuteNonQuery();
		conn->Close();
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show(ex->Message);
	}
}



void BaseDeDatos::ingresarDesbloqueoSiguienteActividad()
{
	int numero = this->numActividad + 1;
	if ((this->nivel == "Playa" && this->numActividad < 5) || (this->nivel == "Parque" && this->numActividad < 6) || (this->nivel == "Espacio" && this->numActividad < 7)) {
		//Inicio la base de datos
		estadoBD(0);
		//Datos de la tabla jugador
		connCmd = gcnew MySqlCommand("UPDATE `bd_tutin1.1`.actividad SET permiso = 'Desbloqueado' WHERE num_actividad = " + numero + " AND IdJugador_act = '" + nombreJugador + "';", conn);
		try {
			connCmd->ExecuteNonQuery();
			estadoBD(1); //Cierro la base de datos
		}
		catch (System::Exception^ ex) {
			System::Windows::Forms::MessageBox::Show(ex->Message);
		}
	}
}

void BaseDeDatos::ingresarDesbloqueoSiguienteHabilidad(System::String^ hab_sgte)
{
	estadoBD(0);
	connCmd = gcnew MySqlCommand("UPDATE `bd_tutin1.1`.habilidad SET permiso = 'Desbloqueado' WHERE nombre_hab = '" + hab_sgte + "' AND IdJugador_hab = '" + nombreJugador + "';", conn);
	try {
		connCmd->ExecuteNonQuery();
		estadoBD(1); //Cierro la base de datos
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show(ex->Message);
	}
}

void BaseDeDatos::ingresarDesbloqueoSiguienteNivel(System::String^ nom_sgt_niv)
{
	estadoBD(0);
	connCmd = gcnew MySqlCommand("UPDATE `bd_tutin1.1`.nivel SET permiso = 'Desbloqueado' WHERE nom_nivel = '" + nom_sgt_niv + "' AND IdJugador_nivel = '" + nombreJugador + "';", conn);
	try {
		connCmd->ExecuteNonQuery();
		estadoBD(1); //Cierro la base de datos
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show(ex->Message);
	}
}

System::Data::DataSet^ BaseDeDatos::seleccionarListaUsuariosRegistrados()
{
	estadoBD(0);
	MySqlDataAdapter^ daJugador = gcnew MySqlDataAdapter("SELECT * FROM `bd_tutin1.1`.jugador", conn);
	System::Data::DataSet^ dsJugador = gcnew System::Data::DataSet();
	daJugador->Fill(dsJugador, "Jugador");
	estadoBD(1); //Cierro la base de datos
	return dsJugador;
}

list<string> BaseDeDatos::seleccionarNivelActual()
{
	list<string> listnomNivel;

	estadoBD(0);
	connCmd = gcnew MySqlCommand("SELECT nom_nivel FROM `bd_tutin1.1`.nivel WHERE IdJugador_nivel = '" + nombreJugador + "' AND permiso = 'Desbloqueado';", conn);
	MySqlDataReader^ query = connCmd->ExecuteReader();

	while (query->Read()) {
		listnomNivel.push_back(context.marshal_as<string>(query[0]->ToString()));
	}
	estadoBD(1);

	return listnomNivel;
}

string  BaseDeDatos::seleccionarHabilidadActual()
{
	string habActual;

	estadoBD(0);
	connCmd = gcnew MySqlCommand("SELECT nombre_hab FROM  `bd_tutin1.1`.habilidad WHERE IdJugador_hab = '" + nombreJugador + "' AND permiso = 'Desbloqueado';", conn);
	MySqlDataReader^ query = connCmd->ExecuteReader();

	while (query->Read()) {
		habActual = context.marshal_as<string>(query[0]->ToString());
	}
	estadoBD(1);
	return habActual;
}

vector<string> BaseDeDatos::seleccionarTotalActuacion()
{
	vector<string> total_actuacion;
	estadoBD(0);
	connCmd = gcnew MySqlCommand("SELECT total_actuacion FROM percepciones,actividad WHERE actividad.num_actividad = percepciones.num_actividad AND nombre_hab = '" + habilidad + "' AND dificultad = '" + dificultad + "';", conn);
	MySqlDataReader^ query = connCmd->ExecuteReader();
	while (query->Read())
	{
		total_actuacion.push_back(context.marshal_as<string>(query[0]->ToString()));
	}
	estadoBD(1);
	return total_actuacion;
}

string BaseDeDatos::seleccionarDificultadActividadActual()
{
	string dificultad;
	estadoBD(0);
	connCmd = gcnew MySqlCommand("SELECT dificultad FROM `bd_tutin1.2`.actividad WHERE IdJugador_act = '" + nombreJugador + "' AND nombre_hab = '" + habilidad + "';", conn);
	MySqlDataReader^ query = connCmd->ExecuteReader();

	while (query->Read())
	{
		dificultad = context.marshal_as<string>(query[0]->ToString());
	}
	estadoBD(1);
	return dificultad;
}

string BaseDeDatos::seleccionarComplejidadActividadActual()
{
	string complejidad;
	estadoBD(0);
	connCmd = gcnew MySqlCommand("SELECT complejidad FROM `bd_tutin1.2`.actividad WHERE IdJugador_act = '" + nombreJugador + "' AND nombre_hab = '" + habilidad + "' AND dificultad = '" + dificultad + "';", conn);
	MySqlDataReader^ query = connCmd->ExecuteReader();

	while (query->Read())
	{
		complejidad = context.marshal_as<string>(query[0]->ToString());
	}
	estadoBD(1);
	return complejidad;
}



string BaseDeDatos::seleccionarObjetivoActividadActual()
{
	string objetivo;
	estadoBD(0);
	connCmd = gcnew MySqlCommand("SELECT obetivo FROM `bd_tutin1.2`.objetivos WHERE habilidad = '" + habilidad + "' AND dificultad = '" + dificultad + "' AND complejidad = '" + complejidad + "' AND num_actividad = '" + numActividad + "';", conn);
	MySqlDataReader^ query = connCmd->ExecuteReader();

	while (query->Read())
	{
		objetivo = context.marshal_as<string>(query[0]->ToString());
	}
	estadoBD(1);
	return objetivo;
}

int BaseDeDatos::seleccionarNumeroSesion()
{
	string actActual;

	estadoBD(0);
	connCmd = gcnew MySqlCommand("SELECT num_sesion FROM `bd_tutin1.2`.actividad, `bd_tutin1.2`.jugador WHERE IdJugador_act = '" + nombreJugador + "';", conn);
	try {
		dataReader = connCmd->ExecuteReader();
		while (dataReader->Read()) {
			actActual = context.marshal_as<string>(dataReader->GetString(0));
		}
		estadoBD(1); //Cierro la base de datos
		return atoi(actActual.c_str());
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show(ex->Message);
	}
	return atoi(actActual.c_str());
}

int BaseDeDatos::seleccionarActividadActual()
{
	string actActual;

	estadoBD(0);
	connCmd = gcnew MySqlCommand("SELECT num_actividad FROM `bd_tutin1.1`.actividad WHERE IdJugador_act = '" + nombreJugador + "' AND permiso = 'Desbloqueado' AND nombre_hab = '" + habilidad + "' ORDER BY num_actividad ASC;", conn);
	try {
		dataReader = connCmd->ExecuteReader();
		while (dataReader->Read()) {
			actActual = context.marshal_as<string>(dataReader->GetString(0));
		}
		estadoBD(1); //Cierro la base de datos
		return atoi(actActual.c_str());
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show(ex->Message);
	}
	return atoi(actActual.c_str());
}

string BaseDeDatos::seleccionarNivLogroActividadActual()
{
	estadoBD(0);
	string nivLogro;

	connCmd = gcnew MySqlCommand("SELECT niv_logro_acti FROM `bd_tutin1.1`.actividad WHERE num_actividad = " + numActividad + " AND IdJugador_act = '" + nombreJugador + "';", conn);
	try {
		dataReader = connCmd->ExecuteReader();
		while (dataReader->Read()) {
			nivLogro = context.marshal_as<string>(dataReader->GetString(0));
		}
		estadoBD(1); //Cierro la base de datos
		return nivLogro;
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show(ex->Message);
	}
	return nivLogro;
}

string BaseDeDatos::seleccionarUltimoProblemaGenerado() {
	estadoBD(0);
	string reglaProblema;

	connCmd = gcnew MySqlCommand("SELECT problema FROM `bd_tutin1.2`.actividad WHERE IdJugador_act = '" + nombreJugador + "' ORDER BY `codigo_act` DESC LIMIT 1;", conn);
	try {
		dataReader = connCmd->ExecuteReader();
		while (dataReader->Read()) {
			reglaProblema = context.marshal_as<string>(dataReader->GetString(0));
		}
		estadoBD(1); //Cierro la base de datos
		return reglaProblema;
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show(ex->Message);
	}
	return reglaProblema;
}

int BaseDeDatos::seleccionarCantEstrellasNivel()
{
	estadoBD(0);
	string estrellas;
	connCmd = gcnew MySqlCommand("SELECT cant_estrellas FROM `bd_tutin1.1`.nivel WHERE IdJugador_nivel = '" + nombreJugador + "' AND nom_nivel = '" + nivel + "';", conn);
	try {
		dataReader = connCmd->ExecuteReader();
		while (dataReader->Read()) {
			estrellas = context.marshal_as<string>(dataReader->GetString(0));
		}
		estadoBD(1); //Cierro la base de datos
		return atoi(estrellas.c_str());
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show(ex->Message);
	}
	return atoi(estrellas.c_str());
}

int BaseDeDatos::seleccionarCantEstrellasHabilidad()
{
	estadoBD(0);
	string estrellas;
	connCmd = gcnew MySqlCommand("SELECT cant_estrellas FROM `bd_tutin1.1`.habilidad WHERE IdJugador_hab = '" + nombreJugador + "' AND nombre_hab = '" + habilidad + "';", conn);
	try {
		dataReader = connCmd->ExecuteReader();
		while (dataReader->Read()) {
			estrellas = context.marshal_as<string>(dataReader->GetString(0));
		}
		estadoBD(1); //Cierro la base de datos
		return atoi(estrellas.c_str());
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show(ex->Message);
	}
	return atoi(estrellas.c_str());
}

int BaseDeDatos::seleccionarTotalEstrellas()
{
	//Inicio la base de datos
	estadoBD(0);
	string estrellas;
	connCmd = gcnew MySqlCommand("SELECT total_estrellas FROM `bd_tutin1.1`.jugador WHERE nom_jugador = '" + nombreJugador + "'; ", conn);
	try {
		dataReader = connCmd->ExecuteReader();
		while (dataReader->Read()) {
			estrellas = context.marshal_as<string>(dataReader->GetString(0));
		}
		estadoBD(1); //Cierro la base de datos
		return atoi(estrellas.c_str());
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show(ex->Message);
	}

	return atoi(estrellas.c_str());
}

int BaseDeDatos::seleccionarIntentosActividad()
{
	list<string> intentos;
	int actividadActual = seleccionarActividadActual();
	estadoBD(0);
	connCmd = gcnew MySqlCommand("SELECT intentos FROM `bd_tutin1.1`.actividad WHERE IdJugador_act = '" + nombreJugador + "' AND num_actividad = " + actividadActual + " AND nombre_hab = '" + this->habilidad + "';", conn);
	MySqlDataReader^ query = connCmd->ExecuteReader();

	while (query->Read()) {
		intentos.push_back(context.marshal_as<string>(query[0]->ToString()));
	}
	estadoBD(1);

	return atoi(intentos.back().c_str());
}

int BaseDeDatos::seleccionarEstrellasActividadActual()
{
	string intento;
	int actividadActual = seleccionarActividadActual();
	estadoBD(0);
	connCmd = gcnew MySqlCommand("SELECT cant_estrellas FROM `bd_tutin1.1`.actividad WHERE IdJugador_act = '" + nombreJugador + "' AND num_actividad = " + actividadActual + " AND nombre_hab = '" + this->habilidad + "'", conn);

	dataReader = connCmd->ExecuteReader();
	while (dataReader->Read()) {
		intento = context.marshal_as<string>(dataReader->GetString(0));
	}
	estadoBD(1); //Cierro la base de datos
	return atoi(intento.c_str());

}

void BaseDeDatos::setNombreJugador(System::String^ jugador)
{
	nombreJugador = jugador;
}

void BaseDeDatos::setNombreHabilidad(System::String ^ nomhabilidad)
{
	habilidad = nomhabilidad;
}

void BaseDeDatos::setNombreNivel(System::String ^ nomNivel)
{
	nivel = nomNivel;
}

void BaseDeDatos::setObjetivoActividad(System::String ^ obj)
{
	objetivo = obj;
}

void BaseDeDatos::setNumeroActividad(int numeroActividad)
{
	numActividad = numeroActividad;
}

void BaseDeDatos::setNumSesion(int numeroSesion) {
	numSesion = numeroSesion;
}

int BaseDeDatos::getNumSesion() {
	return numSesion;
}

string BaseDeDatos::getNombreJugador() {
	return context.marshal_as<string>(nombreJugador->ToString());
}