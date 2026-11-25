#ifndef PROYECTO_AVL_AVLARBOL_H
#define PROYECTO_AVL_AVLARBOL_H

#include "AVLNodo.h"

class AVLArbol
{
private:
    AVLNodo* raiz;
    int tamano;

    AVLNodo* rotarDerecha(AVLNodo* y);
    AVLNodo* rotarIzquierda(AVLNodo* x);
    AVLNodo* rotarIzquierdaDerecha(AVLNodo* nodo);
    AVLNodo* rotarDerechaIzquierda(AVLNodo* nodo);

    AVLNodo* balance(AVLNodo* nodo);
    AVLNodo* insertarNodo(AVLNodo* nodo, int valor, bool& insertado);
    AVLNodo* removerNodo(AVLNodo* nodo, int valor, bool& removido);
    AVLNodo* encontrarMinimoNodo(AVLNodo* nodo) const;
    AVLNodo* encontrarMaximoNodo(AVLNodo* nodo) const;
    bool buscarNodo(AVLNodo* nodo, int valor) const;
    void limpiarNodos(AVLNodo* nodo);

    void imprimirArbolApoyo(AVLNodo* nodo, int espacio) const;

    void enOrdenApoyo(AVLNodo* nodo) const;
    void preOrdenApoyo(AVLNodo* nodo) const;
    void posOrdenApoyo(AVLNodo* nodo) const;

public:
    AVLArbol();

    ~AVLArbol();

    AVLArbol(const AVLArbol&) = delete;
    AVLArbol& operator=(const AVLArbol&) = delete;

    void insertar(int valor);

    void remover(int valor);

    bool buscar(int valor) const;

    int encontrarMinimo() const;

    int encontrarMaximo() const;

    int obtenerAltura() const;

    int obtenerTamano() const;

    void limpiar();

    void enOrden() const;
    void preOrden() const;
    void posOrden() const;
    void nivelOrden() const;

    void imprimirArbol() const;

};

#endif //PROYECTO_AVL_AVLARBOL_H
