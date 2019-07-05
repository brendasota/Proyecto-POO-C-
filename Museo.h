#ifndef MUSEO
#define MUSEO

#include "Objeto.h"

class Museo :public Objeto
{
	TipoString exposicion;
public:
	Museo() {};
	Museo(const TipoString& nombre, TipoEntero posX, TipoEntero posY, TipoEntero calificacion, TipoString _exposicion) :Objeto(nombre, posX, posY, calificacion), exposicion(_exposicion) {};
	virtual ~Museo() {};
	TipoString getExposicion();
	string getTexturefile() override;
	void mostrarInformacion() override;
	void actualizarInformacion() override;
};

#endif // !MUSEO
