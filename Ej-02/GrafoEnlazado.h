#ifndef GRAFOENLAZADO_H
#define GRAFOENLAZADO_H
#include "NodoGrafo.h"
#include "Arco.h"
template<class T>
class GrafoEnlazado {
private:
    NodoGrafo<T> *inicio;
public:
    GrafoEnlazado();

    void nodo_agregar(int n, T val);

    void nodo_remover(int n);

    void nodo_set_val(int n, T val);

    T nodo_get_val(int n);

    void arco_agregar(int n1, int n2, int val);

    void arco_remover(int n1, int n2);

    void arco_set_val(int n1, int n2, int val);

    int arco_get_val(int n1, int n2);

    int adyacentes(int n1, int n2);

    int *vecinos(int n);

    bool esVacio();
};

template<class T>
GrafoEnlazado<T>::GrafoEnlazado() {
    inicio = nullptr;
}

template<class T>
void GrafoEnlazado<T>::nodo_agregar(int n, T val) {
    if (n == 0) {
        NodoGrafo<T> *nn = new NodoGrafo<T>(val, inicio, nullptr, 0);
        inicio = nn;
        return;
    }
    int cont = 0;
    NodoGrafo<T> *aux = inicio;

    while (aux != nullptr && cont < n - 1) {
        cont++;
        aux = aux->getNext();
    }
    if (aux == nullptr) throw 1;

    NodoGrafo<T> *nn = new NodoGrafo<T>(val, aux->getNext(), nullptr, n);
    aux->setNext(nn);
}

template<class T>
void GrafoEnlazado<T>::nodo_remover(int n) {
    if (n == 0) {
        inicio = nullptr;
        return;
    }

    int cont = 0;
    NodoGrafo<T> *aux = inicio;
    NodoGrafo<T> *tmp;

    while (aux != nullptr && cont < n - 1) {
        cont++;
        aux = aux->getNext();
    }

    if (aux == nullptr) throw 1;

    tmp = aux->getNext();
    aux->setNext(tmp->getNext());
    delete tmp;
}

template<class T>
void GrafoEnlazado<T>::nodo_set_val(int n, T val) {
    NodoGrafo<T> *aux = inicio;
    int cont = 0;
    while (cont < n && aux != nullptr) {
        cont++;
        aux = aux->getNext();
    }
    if (aux == nullptr)throw 1;
    aux->setDato(val);
}

template<class T>
T GrafoEnlazado<T>::nodo_get_val(int n) {
    NodoGrafo<T> *aux = inicio;
    int cont = 0;
    while (cont < n && aux != nullptr) {
        cont++;
        aux = aux->getNext();
    }
    if (n != cont) throw 1;
    return aux->getDato();
}

template<class T>
void GrafoEnlazado<T>::arco_agregar(int n1, int n2, int val) {

    NodoGrafo<T> *aux1 = inicio;
    NodoGrafo<T> *aux2 = inicio;
    int cont = 0;
    while (cont < n1 && aux1 != nullptr) {
        cont++;
        aux1 = aux1->getNext();
    }
    if (n1 != cont) throw 1;
    cont = 0;
    while (cont < n2 && aux2 != nullptr) {
        cont++;
        aux2 = aux2->getNext();
    }
    if (n2 != cont) throw 1;
    Arco<T> *tmp = aux1->getArcoApuntado();
    while (tmp != nullptr) {
        if (tmp->getNodoApuntado() == aux2) throw 1;
        tmp = tmp->getNext();
    }
    Arco<T> *na = new Arco<T>(val, aux2, aux1->getArcoApuntado());
    aux1->setArcos(na);
}

template<class T>
void GrafoEnlazado<T>::arco_remover(int n1, int n2) {
    NodoGrafo<T> *aux1 = inicio;
    NodoGrafo<T> *aux2 = inicio;
    int cont = 0;
    while (cont < n1 && aux1 != nullptr) {
        cont++;
        aux1 = aux1->getNext();
    }
    if (n1 != cont) throw 1;
    cont = 0;
    while (cont < n2 && aux2 != nullptr) {
        cont++;
        aux2 = aux2->getNext();
    }
    if (n2 != cont) throw 1;
    Arco<T> *tmp = aux1->getArcoApuntado();
    while (tmp != nullptr) {
        if (tmp->getNodoApuntado() == aux2) {
            tmp->setNodoApuntado(nullptr);
            delete tmp;
            return;
        }
        tmp = tmp->getNext();
    }
    throw 1;
}

template<class T>
void GrafoEnlazado<T>::arco_set_val(int n1, int n2, int val) {
    NodoGrafo<T> *aux1 = inicio;
    NodoGrafo<T> *aux2 = inicio;
    int cont = 0;
    while (cont < n1 && aux1 != nullptr) {
        cont++;
        aux1 = aux1->getNext();
    }
    if (n1 != cont) throw 1;
    cont = 0;
    while (cont < n2 && aux2 != nullptr) {
        cont++;
        aux2 = aux2->getNext();
    }
    if (n2 != cont) throw 1;
    Arco<T> *tmp = aux1->getArcoApuntado();
    while (tmp != nullptr) {
        if (tmp->getNodoApuntado() == aux2) {
            tmp->setPeso(val);
            return;
        }
        tmp = tmp->getNext();
    }
    throw 1;
}

template<class T>
int GrafoEnlazado<T>::arco_get_val(int n1, int n2) {
    NodoGrafo<T> *aux1 = inicio;
    NodoGrafo<T> *aux2 = inicio;
    int cont = 0;
    while (cont < n1 && aux1 != nullptr) {
        cont++;
        aux1 = aux1->getNext();
    }
    if (n1 != cont) throw 1;
    cont = 0;
    while (cont < n2 && aux2 != nullptr) {
        cont++;
        aux2 = aux2->getNext();
    }
    if (n2 != cont) throw 1;
    Arco<T> *tmp = aux1->getArcoApuntado();
    while (tmp != nullptr) {
        if (tmp->getNodoApuntado() == aux2)
            return tmp->getPeso();
        tmp = tmp->getNext();
    }
    throw 1;
}

template<class T>
int GrafoEnlazado<T>::adyacentes(int n1, int n2) {
    NodoGrafo<T> *aux1 = inicio;
    NodoGrafo<T> *aux2 = inicio;
    int cont = 0;
    while (cont < n1 && aux1 != nullptr) {
        cont++;
        aux1 = aux1->getNext();
    }
    if (n1 != cont) throw 1;
    cont = 0;
    while (cont < n2 && aux2 != nullptr) {
        cont++;
        aux2 = aux2->getNext();
    }
    if (n2 != cont) throw 1;
    Arco<T> *tmp = aux1->getArcoApuntado();
    while (tmp != nullptr) {
        if (tmp->getNodoApuntado() == aux2)
            return true;
        tmp = tmp->getNext();
    }
    return false;
}

template<class T>
int *GrafoEnlazado<T>::vecinos(int n) {
    NodoGrafo<T> *aux1 = inicio;
    int cont = 0;
    while (cont < n && aux1 != nullptr) {
        cont++;
        aux1 = aux1->getNext();
    }
    if (n != cont) throw 1;
    cont = 0;
    Arco<T> *tmp = aux1->getArcoApuntado();
    while (tmp != nullptr) {
        cont++;
        tmp = tmp->getNext();
    }
    int salida[cont];
    tmp = aux1->getArcoApuntado();
    for (int i = 0; i < cont; ++i) {
        salida[i] = tmp->getNodoApuntado()->getPosicion();
        tmp = tmp->getNext();
    }
    return salida;
}

template<class T>
bool GrafoEnlazado<T>::esVacio() {
    return inicio == nullptr;
}


#endif //GRAFOENLAZADO_H
