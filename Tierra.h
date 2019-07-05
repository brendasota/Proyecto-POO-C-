#ifndef TIERRA
#define TIERRA

#include <iostream>
#include <vector>
#include "Tipos.h"
#include "Objeto.h"
#include "Hotel.h"
#include "Museo.h"
#include "Restaurante.h"
#include <SFML/Graphics.hpp>

using namespace std;

class Tierra {
private:
	int altura;
	int ancho;
	sf::RenderWindow* plano;
	vector<Objeto*> objetos;
	vector<Objeto*> mejoresobjetos;
	vector<Objeto*> mejoresobjetostipo;
	vector<Objeto*> objetosdisponibles;
	vector<Objeto*> objetoslujosos;
	vector<Objeto*>* vector = nullptr;
	void actualizarTierra();
	void capturarEventos();
public:
	Tierra();
	Tierra(TipoEntero ancho, TipoEntero altura);
	virtual ~Tierra();
	void adicionarObjeto(Objeto* objeto);
	void imprimirObjetos();
	void dibujarTierra();
	void hallarMejores();
	void hallarMejoresTipo();
	void hallarDisponibles();
	void hallarLujosos();
	void actualizarVector(int operacion);
	bool buscarObjeto(string nombre);
	TipoEntero getAltura();
	TipoEntero getAncho();
	TipoEntero getCantidadObjectos();
};

#endif



