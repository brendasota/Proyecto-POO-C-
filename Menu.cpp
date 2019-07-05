//
// Created by utec on 21/06/19.
//

#include "Menu.h"
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;
enum class Opciones { Mostrar = 1, Agregar, Actualizar, ubicarMejores, ubicarMejoresTipo, ubicarDisponibles, ubicarLujosos }; // se usa un tipo enumerado para indicar las opciones

/*
 ********************
 *
 * Funciones de Ayuda
 *
 ********************
 */

void limpiar() {
#ifndef WIN32
	cout << "\033[2J\033[0;0H";
#else
	system("cls");
#endif
}

void esperar() {
	char w;
	do {
		w = input<TipoCaracter>("Presione C y Enter para continuar...");
	} while (toupper(w) != 'C');
}

/*
 ******************************
 *
 * Metodos de clase Menu
 *
 ******************************
 */

Menu::Menu(int ancho, int altura) : tierra(ancho, altura), opcion{} {}

void Menu::agregarObjeto() {

	auto establecimiento = input<TipoCaracter>("\nIngrese el tipo de establecimiento : \n  [H] Hotel\n  [R] Restaurante\n  [M] Museo\n");
	while (toupper(establecimiento) != 'H'&& toupper(establecimiento) != 'M'&& toupper(establecimiento) != 'R') {
		cout << "Tipo de establecimiento invalido\n";
		establecimiento = input<TipoCaracter>("Ingrese el tipo de establecimiento : \n  [H] Hotel\n  [R] Restaurante\n  [M] Museo\n");
	}

	auto nombre = input<TipoString>("Ingrese el nombre : ");

	auto calificacion = input<TipoEntero>("Ingrese la calificacion [1 - 10] : ");
	while (calificacion < 1 || calificacion > 10) {
		cout << "Calificacion invalida, por favor ingrese un numero entero del 1 al 10\n";
		calificacion = input<TipoEntero>("Ingrese la calificacion [1 - 10] : ");
	}

	auto x = input<TipoEntero>("Ingrese ubicacion en X : ");
	while (x < 0 || x >= tierra.getAncho()) {
		cout << "Posicion X incorrecta, los limites son: 0, " << tierra.getAncho() - 1 << "\n";
		x = input<TipoEntero>("Ingrese ubicacion en X : ");
	}

	TipoEntero y = input<TipoEntero>("Ingrese ubicacion en Y : ");
	while (y < 0 || y >= tierra.getAltura()) {
		cout << "Posicion Y incorrecta, los limites son: 0, " << tierra.getAltura() - 1 << "\n";
		y = input<TipoEntero>("Ingrese ubicacion en Y : ");
	}

	switch (establecimiento) {
	case 'H': case 'h': 
	{
		auto estrellas = input<TipoEntero>("Ingrese la cantidad de estrellas [1 - 5] : ");
		while (estrellas < 1 || estrellas > 5) {
			cout << "Cantidad de estrellas invalida, por favor ingrese un numero entero del 1 al 5\n";
			estrellas = input<TipoEntero>("Ingrese la cantidad de estrellas [1 - 5] : ");
		}
		auto disponibilidad = input<TipoCaracter>("Ingrese la disponibilidad : \n  [D] Disponible\n  [N] No Disponible\n");
		while (toupper(disponibilidad) != 'N' && toupper(disponibilidad) != 'D') {
			cout << "Disponibilidad invalida\n";
			disponibilidad = input<TipoCaracter>("Ingrese la disponibilidad : \n  [D] Disponible\n  [N] No Disponible\n");
		}
		tierra.adicionarObjeto(new Hotel(nombre, x, y, calificacion, estrellas, disponibilidad));
		break;
	}
	case 'M': case 'm':
	{
		auto exposicion = input<TipoString>("Ingrese el nombre de la exposicion actual : ");
		tierra.adicionarObjeto(new Museo(nombre, x, y, calificacion, exposicion));
		break;
	}
	case 'R': case 'r':
	{
		auto comida = input<TipoString>("Ingrese el tipo de comida que se ofrece : ");
		auto especialidad = input<TipoString>("Ingrese la especialidad del dia : ");
		tierra.adicionarObjeto(new Restaurante(nombre, x, y, calificacion, comida, especialidad));
	}
	}
}

void Menu::actualizarObjeto() {
	auto nombre = input<TipoString>("\nIngrese el nombre del establecimiento : ");
	for (auto& c : nombre) c = toupper(c);
	if (tierra.buscarObjeto(nombre)==true)
		cout << "La informacion se actualizo con exito\n";
	else
		cout << "El establecimiento no existe\n";
	esperar();
}

void Menu::dibujarMapa() {
	limpiar();
	tierra.imprimirObjetos();
	tierra.dibujarTierra();
}

void Menu::mostrarMenu() {
	limpiar();
	cout << "\n  MENU\n";
	cout << string(37, '_') << "\n\n";
	cout << "  [1] Mostrar mapa\n\n";
	cout << "  [2] Agregar nuevo establecimiento\n\n";
	cout << "  [3] Actualizar informacion de establecimiento\n\n";
	cout << "  [4] Ubicar establecimientos mejor calificados\n\n";
	cout << "  [5] Ubicar establecimientos mejor calificados (por tipo)\n\n";
	cout << "  [6] Ubicar hoteles disponibles\n\n";
	cout << "  [7] Ubicar hoteles mas lujosos\n\n";
	cout << "  [0] Salir\n\n  ";
}

void Menu::seleccionarOpcion() {
	limpiar();
	switch (Opciones(opcion)) {
	case Opciones::Mostrar:
		tierra.actualizarVector(1);
		dibujarMapa();
		break;
	case Opciones::Agregar: 
		agregarObjeto();
		break;
	case Opciones::Actualizar:
		tierra.actualizarVector(1);
		actualizarObjeto();
		break;
	case Opciones::ubicarMejores:
		tierra.actualizarVector(2);
		tierra.hallarMejores();
		dibujarMapa();
		break;
	case Opciones::ubicarMejoresTipo:
		tierra.actualizarVector(3);
		tierra.hallarMejoresTipo();
		dibujarMapa();
		break;
	case Opciones::ubicarDisponibles:
		tierra.actualizarVector(4);
		tierra.hallarDisponibles();
		dibujarMapa();
		break;
	case Opciones::ubicarLujosos:
		tierra.actualizarVector(5);
		tierra.hallarLujosos();
		dibujarMapa();
		break;
	}
}

void Menu::ejecutar() {
	do {
		mostrarMenu();
		cin >> opcion;
		seleccionarOpcion();
	} while (opcion != 0);
	cout << "\n  Hasta pronto...\n";
}
