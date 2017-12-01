#ifndef AGENTEAPRENDIZAJE_H
#define AGENTEAPRENDIZAJE_H

#include "MotorDeInferencia.h"
#include "RangosTiempo.h"
#include "BaseDeDatos.h"
#include "Percepciones.h"
#include "Recuperacion.h"
#include "Conector.h"
#include "Regla.h"
#include <vector>
#include <string>

using namespace std;

public class AgenteAprendizaje {

private:
	MotorDeInferencia *motorInferencia;
	Percepciones *percepciones;
	Recuperacion *recuperacion;
	Conector *conector;
	string nivelAutonomia;
	string nivelEficacia;
	string nivelMotivacion;
	string nivelLogro;
	string critica;
	string totalActuacion;
	Regla *nivelActuacion;	
	Regla *progresoActual;

public:
	AgenteAprendizaje(Percepciones *p, Recuperacion *_recuperacion);
	AgenteAprendizaje(Percepciones *p);
	~AgenteAprendizaje();
	int obtenerCritica();
	Regla* generarProblema();												
	void realimentarElementoAprendizaje(/*critica tipo string?*/);
	vector<Regla*> determinarElementoActuacion();
	string getNivelAutonomia();												// Cantidad ayuda
	string getNivelEficacia();												// Tiempo respuestas
	string getNivelMotivacion();												// Tiempo actividad
	string getNivelLogro();													// Nivel de logro actividad
};
#endif // AGENTEAPRENDIZAJE_H