#ifndef INC_07_GRAFOS_ARCO_H
#define INC_07_GRAFOS_ARCO_H
#include "NodoGrafo.h"
template<class T>
class NodoGrafo;

template<class T>
class Arco {
private:
    int peso;
    Arco *next;
    NodoGrafo<T> *nodo_apuntado;
public:
    Arco() {
        nodo_apuntado = nullptr;
        next = nullptr;
    }

    Arco(int p, NodoGrafo<T> *d, Arco *n) {
        peso = p;
        nodo_apuntado = d;
        next = n;
    }

    void setPeso(int p) { peso = p; }

    void setNodoApuntado(NodoGrafo<T> *d) { nodo_apuntado = d; }

    void setNext(Arco *n) { next = n; }

    int getPeso() { return peso; }

    NodoGrafo<T> *getNodoApuntado() { return nodo_apuntado; }

    Arco *getNext() { return next; }
};
#endif //INC_07_GRAFOS_ARCO_H
