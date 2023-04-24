#pragma once
#include "variablesGlobal.h"

void dijkstra(int mapa[tamanio][tamanio]);

void encontrarMinimo(float dist[tamanio][tamanio], int &minimoX, int &minimoY);

void encontrarCamino(pair<int, int> anterior[tamanio][tamanio], float distancia[tamanio][tamanio]);

void pasoAnterior();

void pasoSiguiente();