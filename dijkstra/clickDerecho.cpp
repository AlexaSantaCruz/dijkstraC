#include "clickDerecho.h"

void clickDerecho(sf::RenderWindow& window, char& presionarTecla) {
        int XF;
        int YF;
        int XI;
        int YI;
        switch (presionarTecla)
        {
        case 'F':
            // Actualizar las coordenadas y el área visual para el punto final
            celdaColor[finX][finY]=0;
            XF = Mouse::getPosition(window).x;
            YF = Mouse::getPosition(window).y;
           
            if (inicioX == YF / 10 && inicioY == XF / 10) {
                cout << "El inicio y el fin no pueden ser el mismo, no es por filosofo, así son las reglas"<<endl;
            }
            else {
                finX = YF / 10;
                finY = XF / 10;
                celdaColor[finX][finY] = 2;

            }


            break;


        case 'I':
            celdaColor[inicioX][inicioY] = 0;

            XI = Mouse::getPosition(window).x;
            YI = Mouse::getPosition(window).y;

            if (YI / 10 == finX &&  XI / 10== finY) {
                cout << "El inicio y el fin no pueden ser el mismo, no es por filosofo, así son las reglas"<<endl;

            }
            else {
                inicioX = YI / 10;
                inicioY = XI / 10;
                celdaColor[inicioX][inicioY] = 1;

            }



            break;
        }
       // presionarTecla = 0; // Se restablece la variable de la tecla presionada
    
}
