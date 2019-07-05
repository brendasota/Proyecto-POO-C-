#ifndef HOTEL
#define HOTEL

#include "Objeto.h"

class Hotel :public Objeto
{
	TipoEntero estrellas;
	TipoCaracter disponibilidad;
public:
	Hotel() {};
	Hotel(const TipoString& nombre, TipoEntero posX, TipoEntero posY, TipoEntero calificacion, TipoEntero _estrellas, TipoCaracter _disponibilidad) :Objeto(nombre, posX, posY, calificacion), estrellas(_estrellas), disponibilidad(_disponibilidad) {};
	virtual ~Hotel() {};
	TipoEntero getEstrellas();
	TipoCaracter getDisponibilidad();
	string getTexturefile() override;
	void mostrarInformacion() override;
	void actualizarInformacion() override;
};

#endif // !HOTEL
