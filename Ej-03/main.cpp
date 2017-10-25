#include "Dijkstra.h"

int main() {
    GrafoEnlazado<char> gr;

    gr.nodo_agregar(0, 'a');
    gr.nodo_agregar(1, 'b');
    gr.nodo_agregar(2, 'c');
    gr.nodo_agregar(3, 'd');
    gr.nodo_agregar(4, 'e');
    gr.nodo_agregar(5, 'f');
    gr.nodo_agregar(6, 'g');
    gr.nodo_agregar(7, 'h');
    gr.nodo_agregar(8, 'i');
    gr.nodo_agregar(9, 'j');
    gr.nodo_agregar(10, 'k');
    gr.nodo_agregar(11, 'l');
    gr.nodo_agregar(12, 'm');
    gr.nodo_agregar(13, 'n');
    gr.nodo_agregar(14, 'o');
    gr.nodo_agregar(15, 'p');
    gr.nodo_agregar(16, 'q');
    gr.nodo_agregar(17, 'r');
    gr.nodo_agregar(18, 's');
    gr.nodo_agregar(19, 't');
    gr.nodo_agregar(20, 'u');
    gr.nodo_agregar(21, 'v');
    gr.nodo_agregar(22, 'w');
    gr.nodo_agregar(23, 'x');
    gr.nodo_agregar(24, 'y');
    gr.nodo_agregar(25, 'z');
    gr.arco_agregar(0, 3, 19);
    gr.arco_agregar(0, 2, 9);
    gr.arco_agregar(0, 22, 7);
    gr.arco_agregar(1, 0, 16);
    gr.arco_agregar(2, v, 2);
    gr.arco_agregar(3, 1, 0);
    gr.arco_agregar(3, 7, 4);
    gr.arco_agregar(3, 5, 4);
    gr.arco_agregar(4, 4, 1);
    gr.arco_agregar(5, i, 2);
    gr.arco_agregar(5, 6, 0);
    gr.arco_agregar(6, 1, 6);
    gr.arco_agregar(6, 3, 1);
    gr.arco_agregar(6, p, 18);
    gr.arco_agregar(7, k, 7);
    gr.arco_agregar(8, l, 9);
    gr.arco_agregar(9, 6, 1);
    gr.arco_agregar(9, 5, 3);
    gr.arco_agregar(9, i, 17);
    gr.arco_agregar(10, t, 7);
    gr.arco_agregar(10, z, 6);
    gr.arco_agregar(11, r, 6);
    gr.arco_agregar(11, 24, 1);
    gr.arco_agregar(12, r, 1);
    gr.arco_agregar(13, n, 1);
    gr.arco_agregar(14, 7, 8);
    gr.arco_agregar(14, i, 5);
    gr.arco_agregar(14, o, 4);
    gr.arco_agregar(14, q, 0);
    gr.arco_agregar(15, o, 2);
    gr.arco_agregar(16, 24, 15);
    gr.arco_agregar(17, z, 5);
    gr.arco_agregar(18, l, 4);
    gr.arco_agregar(19, j, 3);
    gr.arco_agregar(19, u, 2);
    gr.arco_agregar(20, j, 1);
    gr.arco_agregar(21, v, 1);
    gr.arco_agregar(21, 2, 1);
    gr.arco_agregar(22, 0, 3);******
    gr.arco_agregar(23, v, 1);
    gr.arco_agregar(24, q, 9);
    gr.arco_agregar(24, r, 1);
    gr.arco_agregar(25, r, 1);
    gr.arco_agregar(25, z, 0);

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 26; ++j) {
            try {
                cout << endl << "Desde el nodo " << i << " hasta el nodo " << j << " hay conexion con un peso de "
                     << gr.arco_get_val(i, j) << endl;
            } catch (int n) {
                cout << endl << "No hay conexion desde el nodo " << i << " hasta el nodo " << j << endl;
            }
        }
    }
    for (int i = 0; i < 26; ++i)
        Dijkstra(gr, 26, i);
}