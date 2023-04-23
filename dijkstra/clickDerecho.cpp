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
            finX = YF / 10;
            finY = XF / 10;
            cout << "presionasteF en (" << XF / 10 << "," << YF / 10 << ")" << endl;

            celdaColor[finX][finY] = 2;

            break;


        case 'I':
            celdaColor[inicioX][inicioY] = 0;

            XI = Mouse::getPosition(window).x;
            YI = Mouse::getPosition(window).y;
            inicioX = YI / 10;
            inicioY = XI / 10;
            cout << "presionasteI en (" << XI / 10 << "," << YI / 10 << ")" << endl;

            celdaColor[inicioX][inicioY] = 1;

            break;
        }
       // presionarTecla = 0; // Se restablece la variable de la tecla presionada
    
}
