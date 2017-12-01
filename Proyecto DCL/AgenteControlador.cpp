#include "AgenteControlador.h"


AgenteControlador::AgenteControlador(string habilidad, Recuperacion *_recuperacion)
{
	archivo = new LeerArchivo();
	recuperacion = _recuperacion;
	string nombreArchivo = "BaseDeConocimiento/baseConocimiento" + recuperacion->getNombreJugador() + ".txt";
	if (recuperacion->getNumUltimaActividad() == 0) {
		// Si es primera vez que entra, se crea la base de conocimiento para ese usuario
		archivo->copiarArchivo(nombreArchivo);
	}
	archivo->lectura(nombreArchivo);
	conector = Conector::obtenerConector();
}

AgenteControlador::AgenteControlador(string habilidad)
{
	archivo = new LeerArchivo();
	archivo->lectura("BaseDeConocimiento/baseDeConocimiento.txt");
	conector = Conector::obtenerConector();
}

AgenteControlador::~AgenteControlador() {}

vector<string> AgenteControlador::determinarActividad()
{
	//debo determinar la actividad que debe realizar el agente controlador para ello debe seguir los siguientes criterios:
	/*
	Criterio 1: El usuario es nuevo y nunca ha iniciado sesion
	a.-Si es usuario es nuevo entonces la recuperacion sera nula ya que no tiene ninguna actividad hecha
	b.-se retornara un vector que diga la actividad que debe realizar por defecto.
	c.-falta algo.. (analizar si debe almacenar el nivel de actuacion a partir de recuperacion.)
	Criterio 2: Si el usuario esta en la misma sesion realizando actividades.
	a.-Obtener los datos de la ultima actividad que realizo.
	b.-Obtengo las percepciones de la ultima actividad que realizo (el nivel de logro se calcula en el form estrella.)
	c.-Le mando las percepciones y la recuperacion al agente que aprende. (Todo eso en la funcion determinarNivelActuacion).
	Retorna un vector<Regla*>
	d.-A partir de ese vector regla se debe entregar al motor de inferencia para decidir que accion tomar.
	e.- falta algo.
	*/
	//determinarActividad debe retornar un arreglo de string que indique la el numero de la actividad, la dificultad y la complejidad(en base a la habildiad en que se encuentra).

	vector<string> actividad;
	obtenerNivelLogro();
	//Caso para un usuario nuevo
	if (recuperacion->getNumUltimaActividad() == 0)
	{
		actividad.push_back("Basico"); //dificultad
		actividad.push_back("Intermedia"); //complejidad
		actividad.push_back("1"); //numero de la actividad
		return actividad;
	}
	//Si esta en la misma sesion
	else if (recuperacion->getNumSesion() == this->numSesion) {
		vector<Regla*> elementoActuacion;
		agenteAprende = new AgenteAprendizaje(percepciones, recuperacion);
		elementoActuacion = agenteAprende->determinarElementoActuacion();
		Hecho *resultado = nullptr;
		if (elementoActuacion.size() == 1) //solo nivel de actuacion por lo que no existe critica
		{
			Regla *problema = agenteAprende->generarProblema();
			Hecho *resultado = nullptr;
			motorInferencia = new MotorDeInferencia(conector->obtenerBaseDeHechos(), conector->obtenerBaseDeConocimiento());
			conector->agregarHecho(new Hecho("complejidad", Argumento(problema->getCuerpo[0]), VERDADERO));
			conector->agregarHecho(new Hecho("dificultad", Argumento(problema->getCuerpo[1]), VERDADERO));
			resultado = motorInferencia->ejecutar("estado", ENCADENAMIENTO_ADELANTE);
			if (motorInferencia->getTerminoInferencia())
			{
				string nivel = resultado->getArgumento()[0].ToString();
				actividad = calcularActividad(nivel);
				return actividad;
			}
			conector->borrarHechos();

		}
		else //se genera una critica
		{
			//muestra solo el generado de problemas sin el nivel de actuacion.

		}

		//comparar historial de niveles de actuacion con el nivel de actuacion que obtuvo en la actividad que acaba de realizar
		//luego de obtener la comparacion (ifs) se genera una accion a partir del if que se obtuvo
	}
	//Si ingresa en otra sesion
	else if (recuperacion->getNumSesion() != this->numSesion)
	{
		//genero inferencia para determinar la dificultad y complejidad de la actividad que debe realizar
		if (this->numSesion == recuperacion->getNumSesion()) //si esta realizando actividades en la misma sesion
		{
			Hecho *resultado = nullptr;
			motorInferencia = new MotorDeInferencia(conector->obtenerBaseDeHechos(), conector->obtenerBaseDeConocimiento());
			conector->agregarHecho(new Hecho("complejidad", Argumento(recuperacion->getComplejidadActividad()), VERDADERO));
			conector->agregarHecho(new Hecho("dificultad", Argumento(recuperacion->getDificultadActividad()), VERDADERO));
			resultado = motorInferencia->ejecutar("estado", ENCADENAMIENTO_ADELANTE);
			if (motorInferencia->getTerminoInferencia())
			{
				string nivel = resultado->getArgumento()[0].ToString();
				actividad = calcularActividad(nivel);
				return actividad;
			}
			conector->borrarHechos();
		}
	}
}

vector<string> AgenteControlador::calcularActividad(string nivel) {
	vector<string> actividad;
	//Cuando ocurre aumento

	if (nivel == "Complejidad_intermedia_facil")
	{
		actividad.push_back("Basico"); //dificultad
		actividad.push_back("Intermedio"); //Complejidad
		actividad.push_back("1");
		return actividad;
	}
	else if (nivel == "Complejidad_dificil_facil")
	{
		actividad.push_back("Basico"); //dificultad
		actividad.push_back("Dificil"); //Complejidad
		actividad.push_back("1");
		return actividad;
	}
	else if (nivel == "Complejidad_intermedia_intermedia")
	{
		actividad.push_back("Intermedio"); //dificultad
		actividad.push_back("Intermedio"); //Complejidad
		actividad.push_back("1");
		return actividad;
	}
	else if (nivel == "Complejidad_dificil_intermedia")
	{
		actividad.push_back("Intermedio"); //dificultad
		actividad.push_back("Dificil"); //Complejidad
		actividad.push_back("1");
		return actividad;
	}
	else if (nivel == "Complejidad_intermedia_dificil")
	{
		actividad.push_back("Dificil"); //dificultad
		actividad.push_back("Intermedio"); //Complejidad
		actividad.push_back("1");
		return actividad;
	}
	else if (nivel == "Complejidad_dificil_dificil")
	{
		actividad.push_back("Dificil"); //dificultad
		actividad.push_back("Dificil"); //Complejidad
		actividad.push_back("1");
		return actividad;
	}
	else if (nivel == "otro") {
		actividad.push_back("Dificil"); //dificultad
		actividad.push_back("Dificil"); //Complejidad
		actividad.push_back("2");
		return actividad;
	}
	return actividad;
}

void AgenteControlador::setNumSesion(int _numSesion) {
	this->numSesion = _numSesion;
}

Percepciones* AgenteControlador::getPercepciones()
{
	return this->percepciones;
}

int AgenteControlador::getRespuestasBuenas()
{
	return this->contBuenas;
}

int AgenteControlador::getRespuestasMalas()
{
	return this->contMalas;
}

void AgenteControlador::obtenerNivelLogro()
{
	Evaluador *evaluador = new Evaluador(percepciones->getHabilidad(), percepciones->getActividad(), percepciones->getRespuestas());
	percepciones->setNivelLogro(evaluador->revisarActividad());
	contBuenas = evaluador->getContBuenas();
	contMalas = evaluador->getContMalas();
}

vector<Regla*> AgenteControlador::determinarNivelActuacion()
{
	Percepciones *percepcionesAprendizaje = new Percepciones(percepciones->getNivelLogro(), percepciones->getCantAyuda(), percepciones->getTiempoItems(), percepciones->getTiempoAct(), percepciones->getObjetivo());
	//¿El objetivo del agente de aprendizaje deberia ser...? Generar reglas
	AgenteAprendizaje *aprendizaje = new AgenteAprendizaje(percepcionesAprendizaje, recuperacion);
	//Elemento de actuacion: puede ser critica o generar problema
	vector<Regla*> actuacion = aprendizaje->determinarElementoActuacion();
	return actuacion;
	/*if (actuacion.size() == 1) { // Solo devuelve nivel de actuacion

	}
	else// Devuelve nivel de actuacion y problema generado
	{

	}*/
}

void AgenteControlador::setPercepcionesActividad(vector<string> resp, int ayuda, vector<TiempoMI*> timeItems, TiempoMI * timeAct, string nivLogro)
{
	percepciones->setRespuestas(resp);
	percepciones->setCantAyuda(ayuda);
	percepciones->setTiempoItems(timeItems);
	percepciones->setTiempoAct(timeAct);
	percepciones->setNivelLogro(nivLogro);
}
