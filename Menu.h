//
#ifndef MENU
#define MENU

#include <limits>

#include "Tierra.h"
#include "Tipos.h"
#include "Hotel.h"
#include "Museo.h"
#include "Restaurante.h"

using namespace std;

template <typename T>
T input(const string& label) {
	T value;
	cout << label;
	cin >> value;
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return value;
}

class Menu {
	TipoEntero opcion;
	Tierra tierra;
	void mostrarMenu();
	void seleccionarOpcion();
	void agregarObjeto();
	void dibujarMapa();
	void actualizarObjeto();
public:
	Menu(int ancho, int altura);
	void ejecutar();
};


#endif;
    void dibujarMapa();
public:
    Controlador(): opcion{} {}
    void ejecutar();
};


#endif //GAME_CONTROLADOR_H

