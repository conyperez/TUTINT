#ifndef RECUPERACION_H
#define RECUPERACION_H

#include <vector>
#include <string>

using namespace std;

public class Recuperacion {

private:
	vector<string> historialNivelActuacion;		// Historial de los niveles de actuacion 
	int numAct;
	int numSesion;
	string nombreJugador;
	string dificultad;
	string habilidad;
	string complejidad;
	string objetivo;
	string nivelActuacion;
	string totalActuacion;
	string problemaGenerado;
	double porcentajeActuacion;

public:
	Recuperacion();
	~Recuperacion();
	void setHistorialNivelActuacion(vector<string> historial);
	vector<string> getHistorialNivelActuacion();
	void setProblemaGenerado(string _problemaGenerado);
	void setNombreJugador(string _nombreJugador);
	void setNumUltimaActividad(int _numAct);
	void setDificultadActividad(string _dificultad);
	void setComplejidadActividad(string _complejidad);
	void setObjetivoActividad(string _objetivo);
	void setHabilidadActividad(string _habilidad);
	void setNumSesion(int _numSesion);
	void setDatosActuacion(string _nivelActuacion, string _totalActuacion, double _porcentajeActuacion);
	int getNumUltimaActividad();
	string getProblemaGenerado();
	string getNombreJugador();
	string getDificultadActividad();
	string getComplejidadActividad();
	string getObjetivoActividad();
	string getHabilidadActividad();
	int    getNumSesion();
	string getNivelActuacion();
	string getTotalActuacion();
	double getPorcentajeActuacion();
};

#endif // RECUPERACION_H