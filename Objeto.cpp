#include "Objeto.h"
#include "Tierra.h"

Objeto::Objeto() : posX{}, posY{}, calificacion{}  {}

Objeto::Objeto(const TipoString& nombre, TipoEntero posX, TipoEntero posY, TipoEntero calificacion) : nombre{ nombre }, posX{ posX }, posY{ posY }, calificacion{ calificacion } {}

Objeto::~Objeto() {}

TipoString   Objeto::getNombre() { return nombre; }
TipoEntero   Objeto::getPosX() { return posX; }
TipoEntero   Objeto::getPosY() { return posY; }
TipoEntero   Objeto::getCalificacion() { return calificacion; }
