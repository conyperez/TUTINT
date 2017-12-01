#ifndef AGENTECONTROLADOR_H
#define AGENTECONTROLADOR_H
#include "AgenteAprendizaje.h"
#include "LeerArchivo.h"
#include "Percepciones.h"
#include "Evaluador.h"
#include "Recuperacion.h"
#include <string>


public class AgenteControlador {

public:
	AgenteControlador(string habilidad, Recuperacion *_recuperacion);
	//constructor temporal para evitar errores en las actividades
	AgenteControlador(string habilidad);
	~AgenteControlador();
	vector<string> determinarActividad();
	Percepciones* getPercepciones();
	int getRespuestasBuenas();
	int getRespuestasMalas();
	void obtenerNivelLogro();
	vector<Regla*> determinarNivelActuacion();
	void setPercepcionesActividad(vector<string> resp, int ayuda, vector<TiempoMI*> timeItems, TiempoMI* timeAct, string nivLogro);
	vector<string> calcularActividad(string nivel);
	void setNumSesion(int _numSesion);


private:
	LeerArchivo *archivo;
	Conector *conector;
	Percepciones *percepciones;
	MotorDeInferencia* motorInferencia;
	Recuperacion *recuperacion;
	AgenteAprendizaje* agenteAprende;
	int numSesion;
	int contBuenas = 0;
	int contMalas = 0;

};
#endif // AGENTECONTROLADOR_H