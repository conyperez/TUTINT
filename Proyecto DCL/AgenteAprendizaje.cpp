#include "AgenteAprendizaje.h"

AgenteAprendizaje::AgenteAprendizaje(Percepciones *p, Recuperacion *_recuperacion) {
	percepciones = p;
	conector = Conector::obtenerConector();
	recuperacion = _recuperacion;
}

AgenteAprendizaje::AgenteAprendizaje(Percepciones * p)
{
	percepciones = p;
	conector = Conector::obtenerConector();
}

AgenteAprendizaje::~AgenteAprendizaje() { }

int AgenteAprendizaje::obtenerCritica() {		// 1: hay critica, 2: no hay cricia, 0: no hay critica por ser la primera act.
	nivelAutonomia = getNivelAutonomia();
	nivelEficacia = getNivelEficacia();
	nivelMotivacion = getNivelMotivacion();
	nivelLogro = getNivelLogro();

	double porcentajeActuacion;
	// Determinar porcentaje de cada nivel

	// Autonomia
	conector->agregarHecho(new Hecho("rangoAyuda", Argumento(nivelAutonomia), VERDADERO));
	motorInferencia = new MotorDeInferencia(conector->obtenerBaseDeHechos(), conector->obtenerBaseDeConocimiento());
	Hecho *resultadoAutonomia = nullptr;
	string valorAutonomia;
	resultadoAutonomia = motorInferencia->ejecutar("valorAutonomia", ENCADENAMIENTO_ADELANTE);
	if (motorInferencia->getTerminoInferencia()) {
		valorAutonomia = resultadoAutonomia->getArgumento()[0].ToString();
		conector->borrarHechos();
	}
	delete motorInferencia;

	// Eficacia
	conector->agregarHecho(new Hecho("rangoTiempoItem", Argumento(nivelEficacia), VERDADERO));
	motorInferencia = new MotorDeInferencia(conector->obtenerBaseDeHechos(), conector->obtenerBaseDeConocimiento());
	Hecho *resultadoEficacia = nullptr;
	string valorEficacia;
	resultadoEficacia = motorInferencia->ejecutar("valorEficacia", ENCADENAMIENTO_ADELANTE);
	if (motorInferencia->getTerminoInferencia()) {
		valorEficacia = resultadoEficacia->getArgumento()[0].ToString();
		conector->borrarHechos();
	}
	delete motorInferencia;

	//Motivacion
	conector->agregarHecho(new Hecho("rangoTiempoAct", Argumento(nivelMotivacion), VERDADERO));
	motorInferencia = new MotorDeInferencia(conector->obtenerBaseDeHechos(), conector->obtenerBaseDeConocimiento());
	Hecho *resultadoMotivacion = nullptr;
	string valorMotivacion;
	resultadoMotivacion = motorInferencia->ejecutar("valorMotivacion", ENCADENAMIENTO_ADELANTE);
	if (motorInferencia->getTerminoInferencia()) {
		valorMotivacion = resultadoMotivacion->getArgumento()[0].ToString();
		conector->borrarHechos();
	}
	delete motorInferencia;

	//Nivel de Logro
	motorInferencia = new MotorDeInferencia(conector->obtenerBaseDeHechos(), conector->obtenerBaseDeConocimiento());
	conector->agregarHecho(new Hecho("nivelLogroAct", Argumento(nivelLogro), VERDADERO));
	Hecho *resultadoNivLogro = nullptr;
	string valorLogro;
	resultadoNivLogro = motorInferencia->ejecutar("valorLogro", ENCADENAMIENTO_ADELANTE);
	if (motorInferencia->getTerminoInferencia()) {
		valorLogro = resultadoNivLogro->getArgumento()[0].ToString();
		conector->borrarHechos();
	}
	delete motorInferencia;

	double porcentAutonomia = atof(valorAutonomia.c_str());		// Convertir a double
	double porcentEficacia = atof(valorEficacia.c_str());
	double porcentMotivacion = atof(valorMotivacion.c_str());
	double porcentLogro = atof(valorLogro.c_str());

	porcentajeActuacion = (porcentAutonomia * 0.25) + (porcentEficacia * 0.25) + (porcentMotivacion * 0.25) + (porcentLogro * 0.25);
	percepciones->setNivelActuacion(porcentajeActuacion);

	// Obtener nivel de actuacion de la actividad
	conector->agregarHecho(new Hecho("porcentajeActuacion", Argumento(to_string(porcentajeActuacion)), VERDADERO));
	motorInferencia = new MotorDeInferencia(conector->obtenerBaseDeHechos(), conector->obtenerBaseDeConocimiento());
	Hecho *resultadoNvActuacion = nullptr;
	string rangoActuacion = nullptr;
	resultadoNvActuacion = motorInferencia->ejecutar("nivelActuacion", ENCADENAMIENTO_ATRAS);
	if (motorInferencia->getTerminoInferencia()) {
		nivelActuacion = conector->obtenerBaseDeConocimiento()->obtenerRegla(resultadoNvActuacion);
		rangoActuacion = resultadoNvActuacion->getArgumento()[0].ToString();
		conector->borrarHechos();
	}
	delete motorInferencia;

	// Establecer si hay critica
	vector<string> historialNiveles = recuperacion->getHistorialNivelActuacion();
	if (historialNiveles.size() == 0) {			// No ha hecho ninguna actividad, aparte de la que se esta evaluando
		// Se guarda este nivel de actuacion como total_actuacion en la BD
		totalActuacion = rangoActuacion;
		recuperacion->setDatosActuacion(rangoActuacion, totalActuacion, porcentajeActuacion);
		return 0;
	}
	else if (historialNiveles.size() >= 1) {		// Ha hecho una actividad o más actividades
		int total = historialNiveles.size();
		// Establece si hay progreso
		conector->agregarHecho(new Hecho("nivelActual", Argumento(rangoActuacion), VERDADERO));
		conector->agregarHecho(new Hecho("nivelAnterior", Argumento(historialNiveles[total]), VERDADERO));
		motorInferencia = new MotorDeInferencia(conector->obtenerBaseDeHechos(), conector->obtenerBaseDeConocimiento());
		Hecho *resultadoProgreso = nullptr;
		string progreso = nullptr;
		resultadoProgreso = motorInferencia->ejecutar("progreso", ENCADENAMIENTO_ATRAS);
		if (motorInferencia->getTerminoInferencia()) {
			progreso = resultadoProgreso->getArgumento()[0].ToString();
			progresoActual = conector->obtenerBaseDeConocimiento()->obtenerRegla(resultadoProgreso);
			conector->borrarHechos();
		}
		delete motorInferencia;

		// Segun resultado de progreso, establece si hay critica
		conector->agregarHecho(new Hecho("progreso", Argumento(progreso), VERDADERO));
		motorInferencia = new MotorDeInferencia(conector->obtenerBaseDeHechos(), conector->obtenerBaseDeConocimiento());
		Hecho *resultadoCritica = nullptr;
		string argCritica = nullptr;
		resultadoCritica = motorInferencia->ejecutar("generarCritica", ENCADENAMIENTO_ATRAS);
		if (motorInferencia->getTerminoInferencia()) {
			argCritica = resultadoCritica->getArgumento()[0].ToString();
			conector->borrarHechos();
		}
		delete motorInferencia;

		if (progreso == "True") {
			totalActuacion = "Alto";
		}
		else if (progreso == "False") {
			totalActuacion = "Bajo";
		}
		else {
			totalActuacion = "Medio";
		}

		if (argCritica == "True") {		// True = Progreso o retroceso, hay critica
			critica = progreso;
			recuperacion->setDatosActuacion(rangoActuacion, totalActuacion, porcentajeActuacion);
			return 1;
		}
		else {
			recuperacion->setDatosActuacion(rangoActuacion, totalActuacion, porcentajeActuacion);
			return 2;
		}
		return 2;
	}
}

Regla* AgenteAprendizaje::generarProblema() {
	conector->agregarHecho(new Hecho("dificultad", Argumento(percepciones->getDificultad()), VERDADERO));
	conector->agregarHecho(new Hecho("complejidad", Argumento(percepciones->getComplejidad()), VERDADERO));
	conector->agregarHecho(new Hecho("totalActuacion", Argumento(totalActuacion), VERDADERO));
	motorInferencia = new MotorDeInferencia(conector->obtenerBaseDeHechos(), conector->obtenerBaseDeConocimiento());
	Hecho *resultadoProblema = nullptr;
	Regla *problema = nullptr;
	resultadoProblema = motorInferencia->ejecutar("generarProblema", ENCADENAMIENTO_ATRAS);
	if (motorInferencia->getTerminoInferencia()) {
		problema = conector->obtenerBaseDeConocimiento()->obtenerRegla(resultadoProblema);
		conector->borrarHechos();
	}
	delete motorInferencia;
	return problema;
}

void AgenteAprendizaje::realimentarElementoAprendizaje() {
	string tmpRegla = recuperacion->getProblemaGenerado();
	Regla* problemaGenerado = conector->transformarStringRegla(tmpRegla);
	
	// Cuanto aprendizaje (valor) hubo según el proceso o retroceso
	conector->agregarHecho(new Hecho(problemaGenerado->getCabeza()->getRelacion(), problemaGenerado->getCabeza()->getArgumento(), VERDADERO));
	conector->agregarHecho(new Hecho(problemaGenerado->getCuerpo()[0]->getRelacion(), problemaGenerado->getCuerpo()[0]->getArgumento(), VERDADERO));
	conector->agregarHecho(new Hecho(problemaGenerado->getCuerpo()[1]->getRelacion(), problemaGenerado->getCuerpo()[1]->getArgumento(), VERDADERO));
	motorInferencia = new MotorDeInferencia(conector->obtenerBaseDeHechos(), conector->obtenerBaseDeConocimiento());
	Hecho *resultadoAprendizaje = nullptr;
	string aprendizaje = nullptr;
	resultadoAprendizaje = motorInferencia->ejecutar("aprendizaje", ENCADENAMIENTO_ATRAS);
	if (motorInferencia->getTerminoInferencia()) {
		aprendizaje = resultadoAprendizaje->getArgumento()[0].ToString();
		conector->borrarHechos();
	}
	delete motorInferencia;

	// Cambiar el peso que tiene la regla que se disparo para el problema
	int valorAprendizaje = atoi(aprendizaje.c_str());
	int pesoActual = conector->obtenerBaseDeConocimiento()->obtenerRegla(problemaGenerado->getCabeza())->getPeso();
	int total = pesoActual + valorAprendizaje;
	conector->obtenerBaseDeConocimiento()->obtenerRegla(problemaGenerado->getCabeza())->setPeso(total);
}

// Funcion llamada desde el Agente Controlador
vector<Regla*> AgenteAprendizaje::determinarElementoActuacion() {
	vector<Regla*> elemento;
	int presentaCritica = obtenerCritica();
	if (presentaCritica == 1) {					// Hay critica
		realimentarElementoAprendizaje();
		elemento.push_back(nivelActuacion);
		return elemento;
	} 
	else if (presentaCritica == 2) {				// No hay critica
		generarProblema();
		elemento.push_back(nivelActuacion);
		Regla *problema = generarProblema();
		elemento.push_back(problema);
		return elemento;
	}
	else if (presentaCritica == 0) {				// No hay critica por ser la primera actividad
		elemento.push_back(nivelActuacion);
		return elemento;
	}
}

string AgenteAprendizaje::getNivelAutonomia() {
	if (percepciones->getCantAyuda() >= 10) {
		if (percepciones->getComplejidad() == "Basico") {
			conector->agregarHecho(new Hecho("cantAyuda", Argumento("7-10"), VERDADERO));
		}
		else if (percepciones->getComplejidad() == "Intermedia") {
			conector->agregarHecho(new Hecho("cantAyuda", Argumento("8-10"), VERDADERO));
		}
		else if (percepciones->getComplejidad() == "Dificil") {
			conector->agregarHecho(new Hecho("cantAyuda", Argumento("9-10"), VERDADERO));
		}
	}
	else {
		conector->agregarHecho(new Hecho("total", Argumento(to_string(percepciones->getCantAyuda())), VERDADERO));
	}
	conector->agregarHecho(new Hecho("complejidad", Argumento(percepciones->getComplejidad()), VERDADERO));
	motorInferencia = new MotorDeInferencia(conector->obtenerBaseDeHechos(), conector->obtenerBaseDeConocimiento());
	Hecho *resultado = nullptr;
	resultado = motorInferencia->ejecutar("rangoAyuda", ENCADENAMIENTO_ADELANTE);
	if (motorInferencia->getTerminoInferencia()) {
		string nivel = resultado->getArgumento()[0].ToString();
		conector->borrarHechos();
		return nivel;
	}
	delete motorInferencia;

	return nullptr;
}

string AgenteAprendizaje::getNivelEficacia() {
	RangosTiempo *rango = new RangosTiempo(percepciones->getActividad(), percepciones->getHabilidad(), percepciones->getDificultad(), percepciones->getComplejidad());
	vector<string> niveles;
	for (unsigned int i = 0; i < percepciones->getTiempoItems().size(); i++) {
		rango->setTiempo(percepciones->getTiempoItems()[i]);
		Hecho *rangoItem = rango->determinarTiempoItem();
		string argumento = rangoItem->getArgumento()[i].getValor();
		niveles.push_back(argumento);
	}
	int contBueno = 0, contRegular = 0, contMalo = 0;
	for (unsigned int i = 0; i < niveles.size(); i++) {
		if (niveles[i] == "Bueno") {
			contBueno++;
		}
		else if (niveles[i] == "Regular") {
			contRegular++;
		}
		else {
			contMalo++;
		}
	}
	string nivelEficacia;
	if (contBueno > contMalo && contBueno > contRegular) {
		nivelEficacia = "Bueno";
	}
	else if (contRegular > contBueno && contRegular > contBueno) {
		nivelEficacia = "Regular";
	}
	else if (contMalo > contRegular && contMalo > contBueno) {
		nivelEficacia = "Malo";
	}
	else if (contBueno == contRegular) {
		nivelEficacia = "Regular";
	}
	else if (contBueno == contMalo) {
		nivelEficacia = "Regular";
	}
	else if (contRegular == contMalo) {
		nivelEficacia = "Malo";
	}
	return nivelEficacia;
}


string AgenteAprendizaje::getNivelMotivacion() {
	RangosTiempo *rango = new RangosTiempo(percepciones->getActividad(), percepciones->getTiempoAct(), percepciones->getHabilidad(), percepciones->getDificultad(), percepciones->getComplejidad());
	Hecho *rangoAct = rango->determinarTiempoAct();
	string nivel = rangoAct->getArgumento()[0].getValor();
	return nivel;
}

string AgenteAprendizaje::getNivelLogro() {
	return percepciones->getNivelLogro();
}