#ifndef RESTAURANTE
#define RESTAURANTE

#include "Objeto.h"

class Restaurante :public Objeto
{
	TipoString comida;
	TipoString especialidad;
public:
	Restaurante() {};
	Restaurante(const TipoString& nombre, TipoEntero posX, TipoEntero posY, TipoEntero calificacion, TipoString _comida, TipoString _especialidad) :Objeto(nombre, posX, posY, calificacion),comida(_comida),especialidad(_especialidad) {};
	virtual ~Restaurante() {};
	TipoString getComida();
	TipoString getEspecialidad();
	string getTexturefile() override;
	void mostrarInformacion() override;
	void actualizarInformacion() override;
};

#endif // !RESTAURANTE
