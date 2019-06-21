#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int matriz[3][3];
    for(int x=0;x<3;x++){
        for(int y=0;y<3;y++){
            cout<<"Digita un numero ["<<x<<"]["<<y<<"]: ";
            cin>>matriz[x][y];
        }
    }
    cout<<"\nLa diagonal de los numeros ingresados es: "<<endl;
    cout<<matriz[0][0]<<endl;
    cout<<"  "<<matriz[1][1]<<endl;
    cout<<"    "<<matriz[2][2]<<endl;

    return 0;

}


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
