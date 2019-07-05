#include "Tierra.h"
#include <string>
#include <iomanip>
#include <map>
#include <iterator> 
#include <algorithm>
#include "Objeto.h"
#include "Tierra.h"

using namespace std;

Tierra::Tierra() : ancho{}, altura{} {
	plano = nullptr;
}

Tierra::Tierra(TipoEntero ancho, TipoEntero altura) : altura{ altura }, ancho{ ancho } {
	plano = new sf::RenderWindow();
}

Tierra::~Tierra() {
	delete plano;
}

void Tierra::adicionarObjeto(Objeto* objeto) {
	objetos.emplace_back(objeto);
}

bool Tierra::buscarObjeto(string nombre) {
	// Buscando objeto
	if (objetos.size() == 0)
		return false;
	string i_nombre;
	for (auto & item : *vector) {
		i_nombre = item->getNombre();
		for (auto& c : i_nombre) c = toupper(c);
		if (i_nombre == nombre) {
			item->actualizarInformacion();
			return true;
		}
	}
	return false;
}

void Tierra::imprimirObjetos() {
	int i = 0;
	for (auto& item : *vector) {
		cout << "  [" << i+1 << "]"<<endl;
		item->mostrarInformacion();
		cout << endl;
		i++;
	}
}

void Tierra::actualizarTierra() {
	plano->clear();

	sf::Texture mapaT;
	if (!mapaT.loadFromFile("img/map.png"))
	{
		cout << "Error al cargar el archivo\n";
		system("pause");
	}
	mapaT.setRepeated(true);
	sf::Sprite mapaS;
	mapaS.setTexture(mapaT);
	mapaS.setTextureRect(sf::IntRect(0, 0, 600, 400));
	plano->draw(mapaS);

	for (auto obj : *vector) {
		sf::Texture puntoT;
		if (!puntoT.loadFromFile(obj->getTexturefile()))
		{
			cout << "Error al cargar el archivo\n";
			system("pause");
		}
		sf::Sprite puntoS;
		puntoS.setTexture(puntoT);
		puntoS.setPosition(static_cast<float>(obj->getPosX()), static_cast<float>(obj->getPosY()));
		plano->draw(puntoS);
	}
	plano->display();
}

void Tierra::dibujarTierra() {

	// Verifica si plano ha sido creado anteriormente
	if (!plano->isOpen())
		plano->create(sf::VideoMode(ancho, altura), "MAPA - Presione [ESC] para salir... ");
	else
		plano->display();

	// Bucle principal
	while (plano->isOpen()) {
		capturarEventos();
		actualizarTierra();
	}
}

void Tierra::hallarMejores()
{
	multimap<int,Objeto*> mejores;
	for (auto& item : objetos) {
		mejores.insert(make_pair(item->getCalificacion(),item));
	}
	int i = 0;
	for (auto itr = rbegin(mejores); itr != rend(mejores) && i < 3; ++itr, ++i) {
		mejoresobjetos.emplace_back(itr->second);
	}
}

void Tierra::hallarMejoresTipo()
{
	multimap<int, Objeto*> mejoresHotel;
	multimap<int, Objeto*> mejoresMuseo;
	multimap<int, Objeto*> mejoresRestaurante;
	for (auto& item : objetos) {
		Hotel* d = dynamic_cast<Hotel*>(item);
		if (d) {
			mejoresHotel.insert(make_pair(item->getCalificacion(), item));
		}
		else {
			Museo* d = dynamic_cast<Museo*>(item);
			if (d) {
				mejoresMuseo.insert(make_pair(item->getCalificacion(), item));
			}
			else {
				Restaurante* d = dynamic_cast<Restaurante*>(item);
				if (d) {
					mejoresRestaurante.insert(make_pair(item->getCalificacion(), item));
				}
			}
		}
	}
	int i = 0;
	if (!mejoresHotel.empty())
		mejoresobjetostipo.emplace_back(rbegin(mejoresHotel)->second);
	if (!mejoresMuseo.empty())
		mejoresobjetostipo.emplace_back(rbegin(mejoresMuseo)->second);
	if (!mejoresRestaurante.empty())
		mejoresobjetostipo.emplace_back(rbegin(mejoresRestaurante)->second);
}

void Tierra::hallarDisponibles()
{
	for (auto& item : objetos) {
		Hotel *d = dynamic_cast<Hotel*>(item);
		if (d) {
			if (toupper(d->getDisponibilidad()) == 'D')
				objetosdisponibles.emplace_back(d);
		}
	}
}

void Tierra::hallarLujosos()
{
	multimap<int, Objeto*> lujosos;
	for (auto& item : objetos) {
		Hotel* d = dynamic_cast<Hotel*>(item);
		if (d) {
			lujosos.insert(make_pair(d->getEstrellas(), item));
		}
	}
	int i = 0;
	for (auto itr = rbegin(lujosos); itr != rend(lujosos) && i < 3; ++itr, ++i) {
		objetoslujosos.emplace_back(itr->second);
	}
}

void Tierra::actualizarVector(int operacion)
{
	switch (operacion) {
	case 1:
		vector = &objetos;
		break;
	case 2:
		vector = &mejoresobjetos;
		break;
	case 3:
		vector = &mejoresobjetostipo;
		break;
	case 4: 
		vector = &objetosdisponibles;
		break;
	case 5:
		vector = &objetoslujosos;
		break;
}
}

TipoEntero Tierra::getAltura() {
	return altura;
}

TipoEntero Tierra::getAncho() {
	return ancho;
}

TipoEntero Tierra::getCantidadObjectos() {
	return objetos.size();
}

void Tierra::capturarEventos() {
	sf::Event event{};

	while (plano->pollEvent(event)) {

		switch (event.type) {
		case sf::Event::Closed:
			plano->close();
			break;
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
				plano->close();
			break;
		}
	}
}
