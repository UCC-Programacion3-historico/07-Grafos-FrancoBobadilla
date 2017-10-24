#ifndef GRAFOENLAZADO_H
#define GRAFOENLAZADO_H

template<class T>
class Arco {
private:
    int peso;
    Arco *next;
    NodoGrafo *nodo_apuntado;
public:
    Arco() {
        nodo_apuntado = nullptr;
        next = nullptr;
    }

    Arco(int p, NodoGrafo *d, Arco *n) {
        peso = p;
        nodo_apuntado = d;
        next = n;
    }

    void setPeso(int p) { peso = p; }

    void setNodoApuntado(NodoGrafo *d) { nodo_apuntado = d; }

    void setNext(Arco *n) { next = n; }

    int getPeso() { return peso; }

    NodoGrafo *getNodoApuntado() { return nodo_apuntado; }

    Arco *getNext() { return next; }
};

template<class T>
class NodoGrafo {
private:
    T dato;
    NodoGrafo *next;
    Arco *arco_apuntado;
public:
    NodoGrafo() {
        next = nullptr;
        arco_apuntado = nullptr;
    }

    NodoGrafo(T d, NodoGrafo *n, Arco *a) {
        dato = d;
        next = n;
        arco_apuntado = a;
    }

    void setDato(int d) { dato = d; }

    void setNext(NodoGrafo *n) { next = n; }

    void setArcos(Arco *a) { arco_apuntado = a; }

    T getDato() { return dato; }

    NodoGrafo *getNext() { return next; }

    Arco *getArcoApuntado() { return arco_apuntado; }
};

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
        NodoGrafo<T> *nn = new NodoGrafo<T>(val, inicio, nullptr);
        inicio = nn;
        return;
    }
    int cont = 0;
    NodoGrafo<T> *aux = inicio;

    while (aux != NULL && cont < n - 1) {
        cont++;
        aux = aux->getNext();
    }
    if (aux == NULL) throw 1;

    NodoGrafo<T> *nn = new NodoGrafo<T>(val, aux->getNext(), nullptr);
    aux->setNext(nn);
}

template<class T>
void GrafoEnlazado<T>::nodo_remover(int n) {
    if (n == 0) {
        inicio = NULL;
        return;
    }

    int cont = 0;
    NodoGrafo<T> *aux = inicio;
    NodoGrafo<T> *tmp;

    while (aux != NULL && cont < n - 1) {
        cont++;
        aux = aux->getNext();
    }

    if (aux == NULL) throw 1;

    tmp = aux->getNext();
    aux->setNext(tmp->getNext());
    delete tmp;
}

template<class T>
void GrafoEnlazado<T>::nodo_set_val(int n, T val) {
    NodoGrafo<T> *aux = inicio;
    int cont = 0;
    while (cont < n && aux != NULL) {
        cont++;
        aux = aux->getNext();
    }
    if (aux == NULL)throw 1;
    aux->setDato(val);
}

template<class T>
T GrafoEnlazado<T>::nodo_get_val(int n) {
    NodoGrafo<T> *aux = inicio;
    int cont = 0;
    while (cont < n && aux != NULL) {
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
    while (cont < n1 && aux1 != NULL) {
        cont++;
        aux1 = aux1->getNext();
    }
    if (n1 != cont) throw 1;
    cont = 0;
    while (cont < n2 && aux2 != NULL) {
        cont++;
        aux2 = aux2->getNext();
    }
    if (n2 != cont) throw 1;
    Arco<T> *tmp = aux1->getArcoApuntado();
    while (tmp != NULL) {
        if (tmp->getNodoApuntado() == aux2)
            throw 1;
        tmp = tmp->getNext();
    }
    Arco<T> *na = new Arco<T>(val, aux2, aux1->getArcoApuntado());
    aux1->setArcos(na);
}

template<class T>
void GrafoEnlazado<T>::arco_remover(int n1, int n2) {

}

template<class T>
void GrafoEnlazado<T>::arco_set_val(int n1, int n2, int val) {

}

template<class T>
int GrafoEnlazado<T>::arco_get_val(int n1, int n2) {
    return 0;
}

template<class T>
int GrafoEnlazado<T>::adyacentes(int n1, int n2) {
    return 0;
}

template<class T>
int *GrafoEnlazado<T>::vecinos(int n) {
    return nullptr;
}

template<class T>
bool GrafoEnlazado<T>::esVacio() {
    return false;
}


#endif //GRAFOENLAZADO_H
