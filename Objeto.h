#ifndef OBJETO
#define OBJETO

#include "Tipos.h"
#include <iostream>
using namespace std;

class Objeto {
protected:
	string        nombre;
	TipoEntero    posX;
	TipoEntero    posY;
	TipoEntero    calificacion;
public:
	Objeto();
	Objeto(const TipoString& nombre, TipoEntero posX, TipoEntero posY, TipoEntero calificacion);
	virtual ~Objeto();
	string     getNombre();
	TipoEntero getPosX();
	TipoEntero getPosY();
	TipoEntero getCalificacion();
	virtual string getTexturefile() = 0;
	virtual void mostrarInformacion() = 0;
	virtual void actualizarInformacion() = 0;
};

#endif
