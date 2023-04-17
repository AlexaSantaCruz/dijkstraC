#include <SFML/Graphics.hpp>
#include <chrono>

#include "global.h"

using namespace std;

int main()
{
    chrono::microseconds lag(0);
    chrono::steady_clock::time_point tiempoAnterior;



    sf::Event event;
    sf::RenderWindow window(sf::VideoMode(global::pantalla::resize * global::pantalla::ancho, global::pantalla::resize * global::pantalla::alto), "Dijkstra", sf::Style::Close);
    window.setView(sf::View(sf::FloatRect(0, 0, global::pantalla::ancho, global::pantalla::alto)));


    sf::Sprite mapaSprite;
    sf::Texture mapaTextura;
    

    sf::Texture fuenteTextura;

    fuenteTextura.loadFromFile("rsc/imagenes/Font.png");

    mapaTextura.loadFromFile("rsc/imagenes/Map.png");
    
    mapaSprite.setTexture(mapaTextura);

    //global::map<>mapa = {};

    while (window.isOpen())
    {

        chrono::microseconds deltaT = chrono::duration_cast<std::chrono::microseconds>(chrono::steady_clock::now() - tiempoAnterior);

         lag += deltaT;
         tiempoAnterior += deltaT;
 
         while (global::pantalla::FRAME_DURATION <= lag){
            lag -= global::pantalla::FRAME_DURATION;


            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            if (global::pantalla::FRAME_DURATION > lag) {
                window.clear();

                for (int i = 0; i < global::mapa::columnas; i++) {
                    for (int j = 0; j < global::mapa::columnas; j++) {

                        mapaSprite.setPosition(global::mapa::x + i * global::mapa::tamanioCelda, global::mapa::y + j * global::mapa::tamanioCelda);
                        window.draw(mapaSprite);
                    }
                }
                window.display();
            }
            

        }
    }
}