#include <iostream>
#include "Menu.h"

int main() {
	Menu ctrl(600, 400);
	ctrl.ejecutar();
	return 0;
}

//const map<char, sf::Color> listaColores = {
//        {'R', sf::Color::Red },
//        {'G', sf::Color::Green},
//        {'B', sf::Color::Blue}};



//int main()
//{
//    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
//    sf::CircleShape shape(100.f);
//    shape.setFillColor(sf::Color::Green);
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        window.clear();
//        window.draw(shape);
//        window.display();
//    }
//
//    return 0;
//}
