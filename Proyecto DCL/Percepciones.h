#ifndef PERCEPCIONES_H
#define PERCEPCIONES_H

#include "TiempoMI.h"
#include<vector>
#include<string>

using namespace System;

public class Percepciones {

private:
	// Percepciones	
	std::vector<std::string> respuestas;		// Respuesta de la actividad realizada
	std::vector<TiempoMI*> tiempoItems;		// Eficacia
	std::string nivelLogro;					// Desempeño
	TiempoMI* tiempoAct;						// Motivacion
	int cantAyuda;							// Autonomía
	int actividad;
	std::string habilidad;
	std::string complejidad;					// Nivel de Complejidad
	std::string dificultad;					// Nivel de Dificultad
	std::string objetivo;					// Objetivo a lograr
	double nivelActuacion;					// Nivel obtenido del usuario

public:
	Percepciones();
	Percepciones(int act, std::string hab, std::string compl, std::string dific, std::string obj);
	Percepciones(std::string nivLogro, int ayuda, std::vector<TiempoMI*> timeItems, TiempoMI* timeAct, std::string obj);
	~Percepciones();
	std::vector<std::string> getRespuestas();
	void setRespuestas(std::vector<std::string> resp);
	std::string getNivelLogro();
	void setNivelLogro(std::string nivLogro);
	int getCantAyuda();
	void setCantAyuda(int ayuda);
	std::vector<TiempoMI*> getTiempoItems();
	void setTiempoItems(std::vector<TiempoMI*> timeItems);
	TiempoMI* getTiempoAct();
	void setTiempoAct(TiempoMI* timeAct);
	int getActividad();
	void setActividad(int act);
	std::string getHabilidad();
	void setHabilidad(std::string hab);
	std::string getComplejidad();
	void setComplejidad(std::string compl);
	std::string getDificultad();
	void setDificultad(std::string dific);
	std::string getObjetivo();
	void setObjetivo(std::string obj);
	double getNivelActuacion();
	void setNivelActuacion(double nivActuacion);
};
#endif // PERCEPCIONES_H
