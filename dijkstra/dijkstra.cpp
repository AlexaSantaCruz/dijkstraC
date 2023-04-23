#pragma once
#include "dijkstra.h"

void dijkstra(int mapa[tamanio][tamanio]) {
    pair<int, int> anterior[tamanio][tamanio];
    float distancia[tamanio][tamanio];
    for (int i = 0; i < tamanio; i++)
        for (int j = 0; j < tamanio; j++)
            distancia[i][j] = FLT_MAX;
    distancia[inicioX][inicioY] = 0.0;
    int encontrado = 0;
    for (int i = 0; i < tamanio && encontrado == 0; i++)
        for (int j = 0; j < tamanio && encontrado == 0; j++) {
            int minimoX = 0, minimoY = 0;
            encontrarMinimo(distancia, minimoX, minimoY);
            celdasExploradas[minimoX][minimoY] = true;
            if (celdasExploradas[finX][finY] == true) {
                encontrado = 1;
                break;
            }
            sf::sleep(milliseconds(1));        //delay para animacion
            //norte
            if (mapa[minimoX - 1][minimoY] == 1 && celdasExploradas[minimoX - 1][minimoY] == false && distancia[minimoX - 1][minimoY] > distancia[minimoX][minimoY] + 1.0) {
                distancia[minimoX - 1][minimoY] = distancia[minimoX][minimoY] + 1.0;
                anterior[minimoX - 1][minimoY] = make_pair(minimoX, minimoY);
            }
            //sur
            if (mapa[minimoX + 1][minimoY] == 1 && celdasExploradas[minimoX + 1][minimoY] == false && distancia[minimoX + 1][minimoY] > distancia[minimoX][minimoY] + 1.0) {
                distancia[minimoX + 1][minimoY] = distancia[minimoX][minimoY] + 1.0;
                anterior[minimoX + 1][minimoY] = make_pair(minimoX, minimoY);
            }
            //oeste
            if (mapa[minimoX][minimoY - 1] == 1 && celdasExploradas[minimoX][minimoY - 1] == false && distancia[minimoX][minimoY - 1] > distancia[minimoX][minimoY] + 1.0) {
                distancia[minimoX][minimoY - 1] = distancia[minimoX][minimoY] + 1.0;
                anterior[minimoX][minimoY - 1] = make_pair(minimoX, minimoY);
            }
            //este
            if (mapa[minimoX][minimoY + 1] == 1 && celdasExploradas[minimoX][minimoY + 1] == false && distancia[minimoX][minimoY + 1] > distancia[minimoX][minimoY] + 1.0) {
                distancia[minimoX][minimoY + 1] = distancia[minimoX][minimoY] + 1.0;
                anterior[minimoX][minimoY + 1] = make_pair(minimoX, minimoY);
            }
            //noroeste
            if (mapa[minimoX - 1][minimoY + 1] == 1 && celdasExploradas[minimoX - 1][minimoY + 1] == false &&
                distancia[minimoX - 1][minimoY + 1] > distancia[minimoX][minimoY] + sqrt(2) && !(mapa[minimoX - 1][minimoY] == 0 && mapa[minimoX][minimoY + 1] == 0)) {
                distancia[minimoX - 1][minimoY + 1] = distancia[minimoX][minimoY] + sqrt(2);
                anterior[minimoX - 1][minimoY + 1] = make_pair(minimoX, minimoY);
            }
            //sureste
            if (mapa[minimoX + 1][minimoY + 1] == 1 && celdasExploradas[minimoX + 1][minimoY + 1] == false &&
                distancia[minimoX + 1][minimoY + 1] > distancia[minimoX][minimoY] + sqrt(2) && !(mapa[minimoX + 1][minimoY] == 0 && mapa[minimoX][minimoY + 1] == 0)) {
                distancia[minimoX + 1][minimoY + 1] = distancia[minimoX][minimoY] + sqrt(2);
                anterior[minimoX + 1][minimoY + 1] = make_pair(minimoX, minimoY);
            }
            //suroeste
            if (mapa[minimoX + 1][minimoY - 1] == 1 && celdasExploradas[minimoX + 1][minimoY - 1] == false &&
                distancia[minimoX + 1][minimoY - 1] > distancia[minimoX][minimoY] + sqrt(2) && !(mapa[minimoX + 1][minimoY] == 0 && mapa[minimoX][minimoY - 1] == 0)) {
                distancia[minimoX + 1][minimoY - 1] = distancia[minimoX][minimoY] + sqrt(2);
                anterior[minimoX + 1][minimoY - 1] = make_pair(minimoX, minimoY);
            }
            //noroeste
            if (mapa[minimoX - 1][minimoY - 1] == 1 && celdasExploradas[minimoX - 1][minimoY - 1] == false &&
                distancia[minimoX - 1][minimoY - 1] > distancia[minimoX][minimoY] + sqrt(2) && !(mapa[minimoX - 1][minimoY] == 0 && mapa[minimoX][minimoY - 1] == 0)) {
                distancia[minimoX - 1][minimoY - 1] = distancia[minimoX][minimoY] + sqrt(2);
                anterior[minimoX - 1][minimoY - 1] = make_pair(minimoX, minimoY);
            }
        }
            encontrarCamino(anterior, distancia);

}


void encontrarMinimo(float distancia[tamanio][tamanio], int &minimoX, int &minimoY) {
	float minimo = FLT_MAX;
	for (int i = 0; i < tamanio;i++) {
		for (int j = 0; j < tamanio;j++) {
			if (celdasExploradas[i][j] == false && distancia[i][j]<minimo) {
				minimo = distancia[i][j];
				minimoX = i;
				minimoY = j;
			}
		}
	}
}

void encontrarCamino(pair<int, int> anterior[tamanio][tamanio], float distancia[tamanio][tamanio]) {
	cout << "\nLength of Dijkstra path is: " << distancia[finX][finY] << endl;
	while (anterior[finX][finY].first != inicioX || anterior[finX][finY].second != inicioX) {        // both simultaneously equal to source coordinates
		sf::sleep(milliseconds(10));        //delay shortest pathD
		cout << "go to ->\n(" << anterior[finX][finY].first << "," << anterior[finX][finY].second << ") ";
		caminoDijkstra.push_back(make_pair(anterior[finX][finY].first, anterior[finX][finY].second));
        int tempX = finX;
        int tempY = finY;
		finX = anterior[tempX][tempY].first;
		finY = anterior[tempX][tempY].second;
	}
}