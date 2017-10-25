#ifndef INC_07_GRAFOS_DIJKSTRA_H
#define INC_07_GRAFOS_DIJKSTRA_H

#include <iostream>
#include "../Ej-02/GrafoEnlazado.h"
#include "Cola.h"

using namespace std;

void Dijkstra(GrafoEnlazado<char> gr, int tamanio, int origen) {
    cout << endl << endl << "Caminos mas cortos posibles desde el nodo '" << gr.nodo_get_val(origen)
         << "' hasta los demas:" << endl
         << endl << "Hasta|Peso|Camino" << endl;
    int peso[tamanio];
    int camino[tamanio][tamanio];
    Cola<int> cola;
    for (int i = 0; i < tamanio; ++i) {
        peso[i] = 2147483647; //infinito
        for (int j = 0; j < tamanio; ++j)
            camino[i][j] = -1;
    }
    peso[origen] = 0;
    cola.encolar(origen);
    while (!cola.esVacia()) {
        origen = cola.desencolar();
        for (int i = 0; i < tamanio; ++i) {
            if ((gr.adyacentes(origen, i) != 0) && gr.arco_get_val(origen, i) + peso[origen] < peso[i]) {
                peso[i] = gr.arco_get_val(origen, i) + peso[origen];
                cola.encolar(i);
                for (int j = 0; j < tamanio; ++j) {
                    if (camino[origen][j] == -1) {
                        camino[i][j] = i;
                        j = tamanio;
                    } else {
                        camino[i][j] = camino[origen][j];
                    }
                }
            }
        }
    }
    for (int i = 0; i < tamanio; ++i) {
        if (camino[i][0] != -1 && peso[i] != 2147483647) {
            if (peso[i] <= 9)
                cout << gr.nodo_get_val(i) << "    |" << peso[i] << "   |";
            else
                cout << gr.nodo_get_val(i) << "    |" << peso[i] << "  |";
            for (int j = 0; j < tamanio; ++j) {
                if (camino[i][j] != -1)
                    cout << gr.nodo_get_val(camino[i][j]) << " ";
            }
            cout << endl;
        }
    }
    cout << endl;
}

#endif //INC_07_GRAFOS_DIJKSTRA_H
