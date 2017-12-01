#include "Evaluador.h"
#include "Hecho.h"
#include "Argumento.h"

using namespace std;

Evaluador::Evaluador(std::string hab, int act, std::vector<std::string> resp) {
	habilidad = hab;
	actividad = act;
	respuestas = resp;
	contBuenas = 0;
	contMalas = 0;
	lecturaArchivo = new LeerArchivo();
	lecturaArchivo->lecturaEvaluador();
	conector = Conector::obtenerConector();
}

Evaluador::~Evaluador() { }

string Evaluador::revisarActividad() {
	for (unsigned int i = 0; i < respuestas.size(); i++) {
		conector->agregarHecho(new Hecho("habilidad", Argumento(habilidad), VERDADERO));
		conector->agregarHecho(new Hecho("actividad", Argumento(to_string(actividad)), VERDADERO));
		conector->agregarHecho(new Hecho("itemAct", Argumento(to_string(i + 1)), VERDADERO));
		conector->agregarHecho(new Hecho("respuesta", Argumento(respuestas[i]), VERDADERO));
		obtenerEstadoRespuesta();
		conector->borrarHechos();
	}
	conector->borrarHechos();
	nivelLogroAct = determinarNivelLogroActividad();
	return nivelLogroAct;
}

void Evaluador::obtenerEstadoRespuesta() {
	motorInferencia = new MotorDeInferencia(conector->obtenerBaseDeHechos(), conector->obtenerBaseDeConocimiento());
	Hecho *resultado = nullptr;
	resultado = motorInferencia->ejecutar("calificacion", ENCADENAMIENTO_ADELANTE);
	if (motorInferencia->getTerminoInferencia()) {
		if (motorInferencia->getTerminoInferencia()) {
			if (resultado->getEstado() == VERDADERO) {
				if (motorInferencia != nullptr)
				{
					motorInferencia->setDetenerInferencia(true);
				}
				contBuenas++;
			}
			else {
				if (motorInferencia != nullptr)
				{
					motorInferencia->setDetenerInferencia(true);
				}
				contMalas++;
			}
		}
	}
}

string Evaluador::determinarNivelLogroActividad() {
	int porcentaje = ((getContBuenas() * 100) / (getContBuenas() + getContMalas()));
	conector->agregarHecho(new Hecho("porcentaje", Argumento(to_string(porcentaje)), VERDADERO));
	
	motorInferencia = new MotorDeInferencia(conector->obtenerBaseDeHechos(), conector->obtenerBaseDeConocimiento());
	Hecho *resultado = nullptr;
	resultado = motorInferencia->ejecutar("nivelLogroAct", ENCADENAMIENTO_ADELANTE);
	if (motorInferencia->getTerminoInferencia()) {
		string res = resultado->getArgumento()[0].ToString();
		return res;
	}
	return nullptr;
}

int Evaluador::getContBuenas() {
	return contBuenas;
}

int Evaluador::getContMalas() {
	return contMalas;
}

string Evaluador::getNivelLogroAct() {
	return nivelLogroAct;
}