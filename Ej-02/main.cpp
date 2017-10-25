#include <iostream>
#include "GrafoEnlazado.h"

using namespace std;

int main() {
    GrafoEnlazado<string> gr;
    gr.nodo_agregar(0, "Hola");
    gr.nodo_agregar(1, "Como");
    gr.nodo_agregar(2, "Chau");
    gr.nodo_agregar(3, "Si");
    gr.arco_agregar(0, 2, 3);
    gr.arco_agregar(0, 1, 2);
    gr.arco_agregar(1, 0, 3);
    gr.arco_agregar(2, 1, 5);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            try {
                cout << endl << "Entre el nodo " << i << " y el nodo " << j << " hay un peso de "
                     << gr.arco_get_val(i, j) << endl;
            } catch (int n) {
                cout << endl << "No hay conexion desde el nodo " << i << " y el nodo " << j << endl;
            }
            try {
                cout << endl << "Entre el nodo " << j << " y el nodo " << i << " hay un peso de "
                     << gr.arco_get_val(j, i) << endl;
            } catch (int n) {
                cout << endl << "No hay conexion desde el nodo " << j << " y el nodo " << j << endl;
            }
        }
    }
    return 0;
}