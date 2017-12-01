#ifndef LEERARCHIVO_H
#define LEERARCHIVO_H
#include "Conector.h"

class LeerArchivo {

public:
	LeerArchivo();
	~LeerArchivo();
	void copiarArchivo(string nombreArchivo);
	void lecturaEvaluador();
	void lectura(string nombreArchivo);			// nombreArchivo = baseConocimiento[NombreUsuario].txt

private:
	Conector *conector;
};

#endif // LEERARCHIVO_H