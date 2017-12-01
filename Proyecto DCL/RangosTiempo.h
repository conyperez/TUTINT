#ifndef RANGOSTIEMPO_H
#define RANGOSTIEMPO_H

#include "Hecho.h"
#include "TiempoMI.h"
#include <string>

public class RangosTiempo {

private:
	int actividad;
	TiempoMI* tiempoAct;
	std::string habilidad;
	std::string dificultad;
	std::string complejidad;

public:
	RangosTiempo(int act, TiempoMI* tiempo, std::string hab, std::string dif, std::string compl);
	RangosTiempo(int act, std::string hab, std::string dif, std::string compl);
	~RangosTiempo();
	Hecho* determinarTiempoItem();
	Hecho* determinarTiempoAct();
	Hecho* rangosItemHabilidadUnoBB();
	Hecho* rangosItemHabilidadUnoBI();
	Hecho* rangosItemHabilidadUnoBD();
	Hecho* rangosItemHabilidadUnoIB();
	Hecho* rangosItemHabilidadUnoII();
	Hecho* rangosItemHabilidadUnoID();
	Hecho* rangosItemHabilidadUnoDB();
	Hecho* rangosItemHabilidadUnoDI();
	Hecho* rangosItemHabilidadUnoDD();
	Hecho* rangosItemHabilidadDosBB();
	Hecho* rangosItemHabilidadDosBI();
	Hecho* rangosItemHabilidadDosBD();
	Hecho* rangosItemHabilidadDosIB();
	Hecho* rangosItemHabilidadDosII();
	Hecho* rangosItemHabilidadDosID();
	Hecho* rangosItemHabilidadDosDB();
	Hecho* rangosItemHabilidadDosDI();
	Hecho* rangosItemHabilidadDosDD();
	Hecho* rangosActHabilidadUnoBB();
	Hecho* rangosActHabilidadUnoBI();
	Hecho* rangosActHabilidadUnoBD();
	Hecho* rangosActHabilidadUnoIB();
	Hecho* rangosActHabilidadUnoII();
	Hecho* rangosActHabilidadUnoID();
	Hecho* rangosActHabilidadUnoDB();
	Hecho* rangosActHabilidadUnoDI();
	Hecho* rangosActHabilidadUnoDD();
	Hecho* rangosActHabilidadDosBB();
	Hecho* rangosActHabilidadDosBI();
	Hecho* rangosActHabilidadDosBD();
	Hecho* rangosActHabilidadDosIB();
	Hecho* rangosActHabilidadDosII();
	Hecho* rangosActHabilidadDosID();
	Hecho* rangosActHabilidadDosDB();
	Hecho* rangosActHabilidadDosDI();
	Hecho* rangosActHabilidadDosDD();
	int getActividad();
	void setActividad(int act);
	void setTiempo(TiempoMI* time);
};
#endif // RANGOSTIEMPO_H

/*
BB = Dificultad b�sica, complejidad b�sica
BI = Dificultad b�sica, complejidad intermedia
BD = Dificultad b�sica, complejidad dif�cil
IB = Dificultad intermedia, complejidad b�sica
II = Dificultad intermedia, complejidad intermedia
ID = Dificultad intermedia, complejidad dif�cil
DB = Dificultad dif�cil, complejidad b�sica
DI = Dificultad dif�cil, complejidad intermedia
DD = Dificultad dif�cil, complejidad dif�cil
*/