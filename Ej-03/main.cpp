#include <iostream>
#include "../Ej-02/GrafoEnlazado.h"
#include "Cola.h"

using namespace std;
typedef struct {
    int hasta;
    int peso;
    int camino[4];
} entrada;

int main() {
    GrafoEnlazado<char> gr;
    gr.nodo_agregar(0, 'a');
    gr.nodo_agregar(1, 'b');
    gr.nodo_agregar(2, 'c');
    gr.nodo_agregar(3, 'd');
    gr.arco_agregar(0, 1, 9);
    gr.arco_agregar(0, 2, 2);
    gr.arco_agregar(1, 0, 2);
    gr.arco_agregar(1, 1, 0);
    gr.arco_agregar(2, 1, 3);
    gr.arco_agregar(1, 3, 1);
    gr.arco_agregar(3, 2, 1);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            try {
                cout << endl << "Entre el nodo " << i << " y el nodo " << j << " hay un peso de "
                     << gr.arco_get_val(i, j) << endl;
            } catch (int n) {
                cout << endl << "No hay conexion desde el nodo " << i << " y el nodo " << j << endl;
            }
        }
    }
    int n;
    entrada tabla[4];
    Cola<int> cola;
    for (int i = 0; i < 4; ++i) {
        tabla[i].hasta = i;
        for (int j = 0; j < 4; ++j) {
            tabla[i].camino[j] = -1;
        }
    }
    cout << endl << "Ingrese nodo al que calcular todos sus caminos:" << endl;
    cin >> n;

    for (int i = 0; i < 4; ++i) {
        if (i == n)
            tabla[i].peso = 0;
        else
            tabla[i].peso = 1000000000; //infinito
    }

    cola.encolar(n);
    while (!cola.esVacia()) {
        n = cola.desencolar();
        for (int i = 0; i < 4; ++i) {
            if (gr.adyacentes(n, i) && gr.arco_get_val(n, i) + tabla[n].peso < tabla[i].peso) {
                tabla[i].peso = gr.arco_get_val(n, i) + tabla[n].peso;
                cola.encolar(i);
                for (int j = 0; j < 4; ++j) {
                    if (tabla[n].camino[j] == -1) {
                        tabla[i].camino[j] = tabla[i].hasta;
                        j = 4;
                    } else {
                        tabla[i].camino[j] = tabla[n].camino[j];
                    }
                }
            }
        }
        cout << endl;
        for (int i = 0; i < 4; ++i) {
            cout<<tabla[i].peso<<"; ";
            for (int j = 0; j < 4; ++j) {
                cout << tabla[i].camino[j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}