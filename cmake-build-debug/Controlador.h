//
// Created by utec on 21/06/19.
//

#ifndef GAME_CONTROLADOR_H
#define GAME_CONTROLADOR_H


#include "Tierra.h"
#include "Tipos.h"

template <typename T>
T input(string label) {
 T value;
 cout << label;
 cin >> value;
 cin.clear();
 cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
 return value;
}

/*
//--- Esta seria la funcion para leer un string,
//--- esta función si se quiere generalizar para colocar un label
//--- y leer cualquier tipo de dato se tendría que convertir al template anterior

string&& input(string label) {
 string value;
 cout << label;
 cin >> value;
 return move(value);
}
*/
class Controlador {
TipoEntero opcion;
   Tierra tierra;
   void imprimirMenu();
   void seleccionarOpcion();
   void agregarObjeto();
   void removerObjeto();
   void dibujarMapa();
public:
   Menu(): opcion{} {}
   void ejecutar();
};
#endif
};


#endif //GAME_CONTROLADOR_H
