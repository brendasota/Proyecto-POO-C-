#include "Restaurante.h"

TipoString Restaurante::getComida()
{
	return comida;
}

TipoString Restaurante::getEspecialidad()
{
	return especialidad;
}

string Restaurante::getTexturefile()
{
	return "img/img3.png";
}

void Restaurante::mostrarInformacion()
{
	cout << "  Restaurante \"" << nombre << "\"" << endl;
	cout << "  Ubicacion : X = " << posX << " Y = " << posY << endl;
	cout << "  Calificacion : " << calificacion << " de 10" << endl;
	cout << "  Tipo de comida : " << comida << endl;
	cout << "  Especialidad del dia : " << especialidad << endl;
}

void Restaurante::actualizarInformacion()
{
	cout << "Ingrese especialidad del dia : ";
	cin >> especialidad;
}
