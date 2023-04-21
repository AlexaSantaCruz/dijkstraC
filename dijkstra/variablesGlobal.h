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


using namespace std;
using namespace sf;


#define tamanio 60      //celdas
//vector<pair<int, int>> pathD;        //usar para el camino mas corto
extern bool celdasExploradas[tamanio][tamanio];//explored cells
extern int celdaColor[tamanio][tamanio]; //celda esta pintada
extern int inicioX, inicioY, finX , finY;      //origen(2,3)->fin(50,56)


#endif // VARIABLES_GLOBAL_H
