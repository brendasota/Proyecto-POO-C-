#include "Museo.h"

TipoString Museo::getExposicion()
{
	return exposicion;
}

string Museo::getTexturefile()
{
	return "img/img2.png";
}

void Museo::mostrarInformacion()
{
	cout << "  Museo \"" << nombre << "\"" << endl;
	cout << "  Ubicacion : X = " << posX << " Y = " << posY << endl;
	cout << "  Calificacion : " << calificacion << " de 10" << endl;
	cout << "  Exposicion actual : " << exposicion << endl;
}

void Museo::actualizarInformacion()
{
	cout << "Ingresar exposicion actual : ";
	cin >> exposicion;
}
