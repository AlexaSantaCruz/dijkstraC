#include "variablesGlobal.h"

using namespace std;
int celdaColor[tamanio][tamanio];
bool celdasExploradas[tamanio][tamanio] = { false }; //Inicializar todas las celdas en falso
int inicioX = 2, inicioY = 2, finX = 50, finY = 56;      //inicio(2,3)->fin(50,56)
int finTempX=50, finTempY=56;
vector<pair<int, int>> caminoDijkstra;        //usar para el camino mas corto
vector<pair<int, int>> anteriorPasos;

