#include "Hotel.h"

TipoEntero Hotel::getEstrellas()
{
	return estrellas;
}

TipoCaracter Hotel::getDisponibilidad()
{
	return disponibilidad;
}

string Hotel::getTexturefile()
{
	return "img/img1.png";
}

void Hotel::mostrarInformacion()
{
	cout << "  Hotel \"" << nombre << "\"" << endl;
	cout << "  Ubicacion : X = " << posX << " Y = " << posY << endl;
	cout << "  Calificacion : " << calificacion << " de 10" << endl;
	cout << "  Estrellas : " << estrellas << " de 5"<<endl;
	if (toupper(disponibilidad) == 'D')
		cout << "  Estado : Disponible" << endl;
	else
		cout << "  Estado : No Disponible" << endl;
}

void Hotel::actualizarInformacion()
{
	cout << "Ingresar disponibilidad : \n  [D] Disponible\n  [N] No Disponible\n";
	cin >> disponibilidad;
}
