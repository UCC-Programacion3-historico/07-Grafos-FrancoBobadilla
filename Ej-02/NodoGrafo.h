#ifndef INC_07_GRAFOS_NODOGRAFO_H
#define INC_07_GRAFOS_NODOGRAFO_H
#include "Arco.h"
template<class T>
class Arco;

template<class T>
class NodoGrafo {
private:
    T dato;
    NodoGrafo *next;
    Arco<T> *arco_apuntado;
    int posicion;
public:
    NodoGrafo() {
        next = nullptr;
        arco_apuntado = nullptr;
    }

    NodoGrafo(T d, NodoGrafo *n, Arco<T> *a, int p) {
        dato = d;
        next = n;
        arco_apuntado = a;
        posicion = p;
    }

    void setDato(int d) { dato = d; }

    void setNext(NodoGrafo *n) { next = n; }

    void setArcos(Arco<T> *a) { arco_apuntado = a; }

    T getDato() { return dato; }

    NodoGrafo *getNext() { return next; }

    Arco<T> *getArcoApuntado() { return arco_apuntado; }

    int getPosicion() { return posicion; }
};

#endif //INC_07_GRAFOS_NODOGRAFO_H