#include "RangosTiempo.h"
#include "Argumento.h"

RangosTiempo::RangosTiempo(int act, TiempoMI* tiempo, std::string hab, std::string dif, std::string compl) {
	actividad = act;
	tiempoAct = tiempo;
	habilidad = hab;
	dificultad = dif;
	complejidad = compl;
}

RangosTiempo::RangosTiempo(int act, std::string hab, std::string dif, std::string compl) {
	actividad = act;
	habilidad = hab;
	dificultad = dif;
	complejidad = compl;
}

RangosTiempo::~RangosTiempo() { }

Hecho* RangosTiempo::determinarTiempoItem() {
	Hecho *hecho;
	if (habilidad == "Conciencia_fonologica") {
		if (dificultad == "Basica") {
			if (complejidad == "B�sica") {
				hecho = rangosItemHabilidadUnoBB();
			}
			else if (complejidad == "Intermedia") {
				hecho = rangosItemHabilidadUnoBI();
			}
			else {
				hecho = rangosItemHabilidadUnoBD();
			}
		}
		else if (dificultad == "Intermedia") {
			if (complejidad == "B�sica") {
				hecho = rangosItemHabilidadUnoIB();
			}
			else if (complejidad == "Intermedia") {
				hecho = rangosItemHabilidadUnoII();
			}
			else {
				hecho = rangosItemHabilidadUnoID();
			}
		}
		else {
			if (complejidad == "B�sica") {
				hecho = rangosItemHabilidadUnoDB();
			}
			else if (complejidad == "Intermedia") {
				hecho = rangosItemHabilidadUnoDI();
			}
			else {
				hecho = rangosItemHabilidadUnoDD();
			}
		}
	}
	else if (habilidad == "Conciencia_alfabetica") {
		if (dificultad == "Basica") {
			if (complejidad == "B�sica") {
				hecho = rangosItemHabilidadDosBB();
			}
			else if (complejidad == "Intermedia") {
				hecho = rangosItemHabilidadDosBI();
			}
			else {
				hecho = rangosItemHabilidadDosBD();
			}
		}
		else if (dificultad == "Intermedia") {
			if (complejidad == "B�sica") {
				hecho = rangosItemHabilidadDosIB();
			}
			else if (complejidad == "Intermedia") {
				hecho = rangosItemHabilidadDosII();
			}
			else {
				hecho = rangosItemHabilidadDosID();
			}
		}
		else {
			if (complejidad == "B�sica") {
				hecho = rangosItemHabilidadDosDB();
			}
			else if (complejidad == "Intermedia") {
				hecho = rangosItemHabilidadDosDI();
			}
			else {
				hecho = rangosItemHabilidadDosDD();
			}
		}
	}
	return nullptr;
}

Hecho* RangosTiempo::determinarTiempoAct() {
	Hecho *hecho;
	if (habilidad == "Conciencia_fonologica") {
		if (dificultad == "Basica") {
			if (complejidad == "B�sica") {
				hecho = rangosActHabilidadUnoBB();
			}
			else if (complejidad == "Intermedia") {
				hecho = rangosActHabilidadUnoBI();
			}
			else {
				hecho = rangosActHabilidadUnoBD();
			}
		}
		else if (dificultad == "Intermedia") {
			if (complejidad == "B�sica") {
				hecho = rangosActHabilidadUnoIB();
			}
			else if (complejidad == "Intermedia") {
				hecho = rangosActHabilidadUnoII();
			}
			else {
				hecho = rangosActHabilidadUnoID();
			}
		}
		else {
			if (complejidad == "B�sica") {
				hecho = rangosActHabilidadUnoDB();
			}
			else if (complejidad == "Intermedia") {
				hecho = rangosActHabilidadUnoDI();
			}
			else {
				hecho = rangosActHabilidadUnoDD();
			}
		}
	}
	else if (habilidad == "Conciencia_alfabetica") {
		if (dificultad == "Basica") {
			if (complejidad == "B�sica") {
				hecho = rangosActHabilidadDosBB();
			}
			else if (complejidad == "Intermedia") {
				hecho = rangosActHabilidadDosBI();
			}
			else {
				hecho = rangosActHabilidadDosBD();
			}
		}
		else if (dificultad == "Intermedia") {
			if (complejidad == "B�sica") {
				hecho = rangosActHabilidadDosIB();
			}
			else if (complejidad == "Intermedia") {
				hecho = rangosActHabilidadDosII();
			}
			else {
				hecho = rangosActHabilidadDosID();
			}
		}
		else {
			if (complejidad == "B�sica") {
				hecho = rangosActHabilidadDosDB();
			}
			else if (complejidad == "Intermedia") {
				hecho = rangosActHabilidadDosDI();
			}
			else {
				hecho = rangosActHabilidadDosDD();
			}
		}
	}
	//Es por mientras
	return hecho;
}

Hecho* RangosTiempo::rangosItemHabilidadUnoBB() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1) {
		if (tiempoTotal <= 33) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 33 && tiempoTotal <= 136) {	// 2:16
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 137) {	// 2:17
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Malo"), VERDADERO);
		}
	}
	else if (actividad == 2) {
		if (tiempoTotal <= 45) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 45 && tiempoTotal <= 74) {	// 1:14
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 75) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosItemHabilidadUnoBI() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1) {
		if (tiempoTotal <= 40) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 40 && tiempoTotal <= 99) {	// 1:39
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 100) {	
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Malo"), VERDADERO);
		}
	}
	else if (actividad == 2) {
		if (tiempoTotal <= 29) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 29 && tiempoTotal <= 80) {	// 1:20
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 81) {	
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosItemHabilidadUnoBD() { 
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1) {
		if (tiempoTotal <= 25) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 25 && tiempoTotal <= 89) {	// 1:09
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 90) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Malo"), VERDADERO);
		}
	}
	else if (actividad == 2) {
		if (tiempoTotal <= 30) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 30 && tiempoTotal <= 84) {	// 1:04
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 85) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosItemHabilidadUnoIB() { 
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1) {
		if (tiempoTotal <= 35) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 35 && tiempoTotal <= 84) {	// 1:04
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 85) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Malo"), VERDADERO);
		}
	}
	else if (actividad == 2) {
		if (tiempoTotal <= 31) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 30 && tiempoTotal <= 89) {	// 1:09
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 89) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosItemHabilidadUnoII() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1) {
		if (tiempoTotal <= 36) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 36 && tiempoTotal <= 101) {	// 1:41
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 102) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Malo"), VERDADERO);
		}
	}
	else if (actividad == 2) {
		if (tiempoTotal <= 67) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 67 && tiempoTotal <= 139) {	// 2:19
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 140) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosItemHabilidadUnoID() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1 || actividad == 2) {
		if (tiempoTotal <= 30) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 30 && tiempoTotal <= 79) {	// 1:19
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 80) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosItemHabilidadUnoDB() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1) {
		if (tiempoTotal <= 87) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 87 && tiempoTotal <= 242) {	// 4:02
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 243) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Malo"), VERDADERO);
		}
	}
	else if (actividad == 2) {
		if (tiempoTotal <= 20) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 20 && tiempoTotal <= 55) {	// 0:55
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 56) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosItemHabilidadUnoDI() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1) {
		if (tiempoTotal <= 40) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 40 && tiempoTotal <= 114) {	// 1:54
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 115) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Malo"), VERDADERO);
		}
	}
	else if (actividad == 2) {
		if (tiempoTotal <= 80) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 80 && tiempoTotal <= 149) {	// 2:29
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 150) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosItemHabilidadUnoDD() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1) {
		if (tiempoTotal <= 80) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 80 && tiempoTotal <= 149) {	// 2:29
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 115) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Malo"), VERDADERO);
		}
	}
	else if (actividad == 2) {
		if (tiempoTotal <= 76) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 76 && tiempoTotal <= 179) {	// 2:59
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 180) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosItemHabilidadDosBB() { return nullptr; }

Hecho* RangosTiempo::rangosItemHabilidadDosBI() { return nullptr; }

Hecho* RangosTiempo::rangosItemHabilidadDosBD() { return nullptr; }

Hecho* RangosTiempo::rangosItemHabilidadDosIB() { return nullptr; }

Hecho* RangosTiempo::rangosItemHabilidadDosII() { return nullptr; }

Hecho* RangosTiempo::rangosItemHabilidadDosID() { return nullptr; }

Hecho* RangosTiempo::rangosItemHabilidadDosDB() { return nullptr; }

Hecho* RangosTiempo::rangosItemHabilidadDosDI() { return nullptr; }

Hecho* RangosTiempo::rangosItemHabilidadDosDD() { return nullptr; }

Hecho* RangosTiempo::rangosActHabilidadUnoBB() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1) {
		if (tiempoTotal <= 130) {	// 2:10
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 130 && tiempoTotal <= 316) {	// 5:16
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 317) {	
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Malo"), VERDADERO);
		}
	}
	else if (actividad == 2) {
		if (tiempoTotal <= 225) {	// 3:45
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 225 && tiempoTotal <= 310) {	// 5:10
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 311) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosActHabilidadUnoBI() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1) {
		if (tiempoTotal <= 130) {	// 2:10
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 130 && tiempoTotal <= 300) {	// 5:00
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 301) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Malo"), VERDADERO);
		}
	}
	else if (actividad == 2) {
		if (tiempoTotal <= 120) {	// 2:00
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 120 && tiempoTotal <= 240) {	// 4:00
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 241) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosActHabilidadUnoBD() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1) {
		if (tiempoTotal <= 90) {	// 1:30
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 90 && tiempoTotal <= 190) {	// 3:10
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 191) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Malo"), VERDADERO);
		}
	}
	else if (actividad == 2) {
		if (tiempoTotal <= 120) {	// 2:00
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 120 && tiempoTotal <= 240) {	// 4:00
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 241) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosActHabilidadUnoIB() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1) {
		if (tiempoTotal <= 119) {	// 1:59
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 119 && tiempoTotal <= 239) {	// 3:59
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 240) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Malo"), VERDADERO);
		}
	}
	else if (actividad == 2) {
		if (tiempoTotal <= 147) {	// 2:27
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 120 && tiempoTotal <= 259) {	// 4:19
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 260) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosActHabilidadUnoII() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1) {
		if (tiempoTotal <= 120) {	// 2:00
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 120 && tiempoTotal <= 269) {	// 4:29
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 270) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Malo"), VERDADERO);
		}
	}
	else if (actividad == 2) {
		if (tiempoTotal <= 270) {	// 4:30
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 270 && tiempoTotal <= 389) {	// 6:29
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 390) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosActHabilidadUnoID() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1 || actividad == 2) {
		if (tiempoTotal <= 120) {	// 2:00
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 120 && tiempoTotal <= 249) {	// 4:09
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 250) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosActHabilidadUnoDB() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1) {
		if (tiempoTotal <= 310) {	// 5:10
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 310 && tiempoTotal <= 240) {	// 7:30
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 241) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Malo"), VERDADERO);
		}
	}
	else if (actividad == 2) {
		if (tiempoTotal <= 60) {	// 1:00
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 60 && tiempoTotal <= 140) {	// 2:20
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 140) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosActHabilidadUnoDI() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1) {
		if (tiempoTotal <= 140) {	// 2:20
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 140 && tiempoTotal <= 245) {	// 4:05
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 246) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Malo"), VERDADERO);
		}
	}
	else if (actividad == 2) {
		if (tiempoTotal <= 250) {		// 4:10
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 250 && tiempoTotal <= 400) {	// 6:40
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 401) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosActHabilidadUnoDD() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1) {
		if (tiempoTotal <= 250) {	// 4:10
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 250 && tiempoTotal <= 380) {	// 6:20
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 381) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Malo"), VERDADERO);
		}
	}
	else if (actividad == 2) {
		if (tiempoTotal <= 240) {		// 4:00
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 240 && tiempoTotal <= 360) {	// 6:00
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 361) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosActHabilidadDosBB() { return nullptr; }

Hecho* RangosTiempo::rangosActHabilidadDosBI() { return nullptr; }

Hecho* RangosTiempo::rangosActHabilidadDosBD() { return nullptr; }

Hecho* RangosTiempo::rangosActHabilidadDosIB() { return nullptr; }

Hecho* RangosTiempo::rangosActHabilidadDosII() { return nullptr; }

Hecho* RangosTiempo::rangosActHabilidadDosID() { return nullptr; }

Hecho* RangosTiempo::rangosActHabilidadDosDB() { return nullptr; }

Hecho* RangosTiempo::rangosActHabilidadDosDI() { return nullptr; }

Hecho* RangosTiempo::rangosActHabilidadDosDD() { return nullptr; }

int RangosTiempo::getActividad() { 
	return actividad;
}

void RangosTiempo::setActividad(int act) { 
	actividad = act;
}

void RangosTiempo::setTiempo(TiempoMI* time) {
	tiempoAct = time;
}