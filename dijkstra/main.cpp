#include "clickDerecho.h"
#include "dijkstra.h"


int main() {



    bool mousePresionado = false; // variable para registrar si el botón del mouse está presionado
    char presionarTecla = 0;

    int mapa[60][60];       //mapa con obstaculos
    for (int i = 0; i < 60; i++)
        for (int j = 0; j < 60; j++) {
            if (i == 0 || i == 59 || j == 0 || j == 59)        //Paderedes de la orilla
                mapa[i][j] = 0;
            else
                mapa[i][j] = 1;
        }
    for (int i = 0; i < tamanio; i++)
        for (int j = 0; j < tamanio; j++) {
            celdasExploradas[i][j] = false;     //dijkstra no explorado
            celdaColor[i][j] = 0;     //sin colores
        }

    Thread hiloD(bind(&dijkstra, mapa));
    RenderWindow window(VideoMode(800, 600), "Dijkstra");

    sf::Font font;
    font.loadFromFile("rsc/arial.ttf");
    sf::Text textoBoton("INICIAR", font, 15);
    sf::Text DistanciaTot(" ", font, 24);

    RectangleShape btnInicio(Vector2f(75, 25));       //button Inicio
    btnInicio.setFillColor(Color::Green);

    RectangleShape rectangle(Vector2f(10, 10));      //Fondo del tablero blanco
    rectangle.setFillColor(Color::White);
    RectangleShape celdasNegras(Vector2f(10, 10));     //fondo negro
    celdasNegras.setFillColor(Color::Black);
    RectangleShape celdasExp(Vector2f(10, 10));     //celdas Exploradas
    celdasExp.setFillColor(Color::Blue);
    celdasExp.setOutlineThickness(2);
    celdasExp.setOutlineColor(Color::Yellow);

    RectangleShape celdaInicio(Vector2f(10, 10));
    celdaInicio.setFillColor(Color::Green);
    celdaInicio.setOutlineThickness(2);
    celdaInicio.setOutlineColor(Color::Black);
    RectangleShape celdaFin(Vector2f(10, 10));
    celdaFin.setFillColor(Color::Red);
    celdaFin.setOutlineThickness(2);
    celdaFin.setOutlineColor(Color::Black);
    RectangleShape celdasExpl(Vector2f(10, 10));
    celdasExpl.setFillColor(Color::Yellow);
    // Display

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {

            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                mousePresionado = true; // se registra que el botón del mouse está presionado

            }
            if (Keyboard::isKeyPressed(Keyboard::F)) {
                presionarTecla = 'F';
            }
            if (Keyboard::isKeyPressed(Keyboard::I)) {
                presionarTecla = 'I';
            }
            if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Right) {
                clickDerecho(window, presionarTecla);

            }

            if (Keyboard::isKeyPressed(Keyboard::Z)) {
                if (caminoDijkstra.empty()) {
                    cout << "todavia no has presionado iniciar para ver tu mapa"<<endl;
                    cout << "Si estas viendo este error es pq me quisiste quebrar el codigo, no sean así >:,(";
                    sleep(milliseconds(500));
                }
                else {
                celdaColor[caminoDijkstra[caminoDijkstra.size()-1].first][caminoDijkstra[caminoDijkstra.size()-1].second] = 0;
                pasoAnterior();
                }
                
                
                   
            
            }
            if (Keyboard::isKeyPressed(Keyboard::Y)) {
                if (caminoDijkstra.empty()) {
                    cout << "todavia no has presionado iniciar para ver tu mapa" << endl;
                    sleep(milliseconds(500));

                }
                else {
                pasoSiguiente();

                }

            }

            if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left) {
                mousePresionado = false;

            }
            if (Keyboard::isKeyPressed(Keyboard::R)) {
                for (int i = 0; i < 60; i++) {
                    for (int j = 0; j < 60; j++) {
                        if (i == 0 || i == 59 || j == 0 || j == 59) {
                            mapa[i][j] = 0; // paredes de la orilla
                        }
                        else {
                            mapa[i][j] = 1; // celdas normales
                        }
                    }
                }

                // reiniciar celdas exploradas y colores
                for (int i = 0; i < tamanio; i++) {
                    for (int j = 0; j < tamanio; j++) {
                        celdasExploradas[i][j] = false;
                        celdaColor[i][j] = 0;
                    }
                }

                inicioX = 2;
                inicioY = 2;
                finX = 50;
                finY = 56;

                caminoDijkstra.clear();

                window.clear();
            }
        }
        // se verifica si el botón del mouse está presionado
        if (mousePresionado) {
            int X = Mouse::getPosition(window).x;
            int Y = Mouse::getPosition(window).y;
            int fila = Y / 10;
            int columna = X / 10;
            if (!((fila == inicioX && columna == inicioY) || (fila == finX && columna == finY))) {
                if (mapa[fila][columna] == 0 && fila < 60 && columna < 60)
                    mapa[fila][columna] = 1;
                else if (fila < 60 && columna < 60)
                    mapa[fila][columna] = 0;
            }
           
            sleep(milliseconds(100));
            for (int i = 0; i < 60; i++) {
                for (int j = 0; j < 60; j++) {
                    if (i == 0 || i == 59 || j == 0 || j == 59) {
                        mapa[i][j] = 0; // paredes de la orilla
                    }
                }
            }
            if (X > 600 && X < 675 && Y>0 && Y < 25) {
                finTempX = finX;
                finTempY = finY;
                sleep(seconds(2));
                hiloD.launch();


            }


        }
        // se dibuja el resto de la ventana como antes
        window.clear();
        btnInicio.setPosition(600, 0);
        window.draw(btnInicio);      //Dijkstra mostrarlo
        textoBoton.setPosition(610, 0);       //Texto que dice dijkstra
        DistanciaTot.setPosition(725, 0);     //muestra fondo para el total del dijsktra

        window.draw(textoBoton);

        window.draw(DistanciaTot);


        celdaInicio.setPosition(inicioY * 10, inicioX * 10);
        window.draw(celdaInicio);     //INICIO

       
        celdaColor[inicioX][inicioY] = 1;
        celdaColor[finX][finY] = 1;

        celdaFin.setPosition(finY * 10, finX * 10);
        window.draw(celdaFin);        //FIN
    

        if (!caminoDijkstra.empty()) {
            for (int i = 0; i < caminoDijkstra.size(); i++) {
                celdasExp.setPosition(caminoDijkstra[i].second * 10, caminoDijkstra[i].first * 10);     //se da la posicion de la celda explorada
                window.draw(celdasExp);        //final pathD
                celdaColor[caminoDijkstra[i].first][caminoDijkstra[i].second] = 1;

            }
    
        }

        for (int i = 0; i <= 590; i += 10)
            for (int j = 0; j <= 590; j += 10) {
                if (mapa[i / 10][j / 10] == 0) {
                    celdasNegras.setOutlineThickness(2);
                    celdasNegras.setOutlineColor(Color::Black);
                    celdasNegras.setPosition(j, i);
                    window.draw(celdasNegras);        //Paredes del usuario
                }
                if (celdasExploradas[i / 10][j / 10] == true && celdaColor[i / 10][j / 10] == 0) {
                    celdasExpl.setOutlineThickness(2);
                    celdasExpl.setOutlineColor(Color::Red);
                    celdasExpl.setPosition(j, i);
                    window.draw(celdasExpl);        // celdas exploradas por Dijkstra
                }
              
                if (mapa[i / 10][j / 10] == 1 && celdasExploradas[i / 10][j / 10] == false && celdaColor[i / 10][j / 10] == 0) {
                    rectangle.setOutlineThickness(2);
                    rectangle.setOutlineColor(Color::Black);
                    rectangle.setPosition(j, i);
                    window.draw(rectangle);     //celdas en blanco por default
                }
            }

        window.display();
    }
    return 0;
}