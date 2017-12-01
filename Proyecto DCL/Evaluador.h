#ifndef EVALUADOR_H
#define EVALUADOR_H

#include "Conector.h"
#include "LeerArchivo.h"
#include "MotorDeInferencia.h"
#include <vector>
#include <string>

public class Evaluador {

private:
	Conector* conector;
	MotorDeInferencia* motorInferencia;
	LeerArchivo* lecturaArchivo;
	std::vector<std::string> respuestas;
	std::string habilidad;
	int actividad;
	int contBuenas;
	int contMalas;
	std::string nivelLogroAct;

public:
	Evaluador(std::string hab, int act, std::vector<std::string> resp);
	~Evaluador();
	std::string revisarActividad();					// Retorna nivel de logro act
	void obtenerEstadoRespuesta();					// Buena o Mala
	std::string determinarNivelLogroActividad();
	int getContBuenas();
	int getContMalas();
	std::string getNivelLogroAct();
};
#endif // EVALUADOR_H