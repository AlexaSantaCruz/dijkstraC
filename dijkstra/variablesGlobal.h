#ifndef VARIABLES_GLOBAL_H
#define VARIABLES_GLOBAL_H
#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<iostream>
#include<functional>        //usar funcion bind
#include<float.h>
#include<vector>
#include<set>
#include<string.h>
#include<string>
#include<sstream>
#include<algorithm>


using namespace std;
using namespace sf;


#define tamanio 60      //celdas
extern vector<pair<int, int>> caminoDijkstra;        //usar para el camino mas corto
extern bool celdasExploradas[tamanio][tamanio];//celdas exploradas
extern int celdaColor[tamanio][tamanio]; //celda esta pintada
extern int inicioX, inicioY, finX , finY;      //origen(2,3)->fin(50,56)
extern int finTempX, finTempY;
extern vector<pair<int, int>> anteriorPasos;


#endif // VARIABLES_GLOBAL_H
