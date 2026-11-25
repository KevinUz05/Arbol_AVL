#include "AVLArbol.h"
#include <iostream>
#include <queue>
#include <stdexcept>




AVLArbol::AVLArbol() : raiz(nullptr), tamano(0) {}

AVLArbol::~AVLArbol()
{
    limpiar();
}


//las rotaciones

AVLNodo* AVLArbol::rotarDerecha(AVLNodo* y)
{
    AVLNodo* x = y->izquierda;
    AVLNodo* T2 = x->derecha;


    x->derecha = y;
    y->izquierda = T2;

    y->actualizarAltura();
    x->actualizarAltura();

    return x;

}

AVLNodo* AVLArbol::rotarIzquierda(AVLNodo* x)
{
    AVLNodo* y = x->derecha;
    AVLNodo* T2 = y->izquierda;

    y->izquierda = x;
    x->derecha = T2;

    x->actualizarAltura();
    y->actualizarAltura();

    return y;

}
    AVLNodo* AVLArbol::rotarIzquierdaDerecha(AVLNodo* nodo)
    {
        nodo->izquierda = rotarIzquierda(nodo->izquierda);
        return rotarDerecha(nodo);

    }

    AVLNodo* AVLArbol::rotarDerechaIzquierda(AVLNodo* nodo)
    {
        nodo->derecha = rotarDerecha(nodo->derecha);
        return rotarIzquierda(nodo);

    }

//balanceo


AVLNodo* AVLArbol::balance(AVLNodo* nodo)
{
    if (nodo == nullptr)
    {
        return nullptr;
    }

    nodo->actualizarAltura();
    int bf = nodo->obtenerFactorBalance();

    if (bf > 1)
    {
        if (nodo->izquierda->obtenerFactorBalance() >= 0)
        {
            return rotarDerecha(nodo);
        }
        return rotarIzquierdaDerecha(nodo);

    }

    if (bf < -1)
    {
        if (nodo->derecha->obtenerFactorBalance() <= 0)
        {
            return rotarIzquierda(nodo);

        }
        return rotarDerechaIzquierda(nodo);

    }

    return nodo;

}

 void AVLArbol::insertar(int valor)
{
    bool insertado = false;
    raiz = insertarNodo(raiz, valor, insertado);

    if (insertado)
    {
        tamano++;

    }
}

AVLNodo* AVLArbol::insertarNodo(AVLNodo* nodo, int valor, bool& insertado)
{
    if (nodo== nullptr)
    {
        insertado = true;
        return new AVLNodo(valor);

    }

    if (valor <nodo->dato)
    {
        nodo->izquierda = insertarNodo(nodo->izquierda, valor, insertado);

    } else if (valor > nodo->dato)
    {
        nodo->derecha = insertarNodo(nodo->derecha, valor, insertado);

    } else
    {
        insertado = false;
        return nodo;

    }

    return balance(nodo);

}

void AVLArbol::remover(int valor)
{
    bool removido = false;
    raiz = removerNodo(raiz, valor, removido);
    if (removido)
    {
        tamano--;

    }
}

AVLNodo* AVLArbol::removerNodo(AVLNodo* nodo, int valor, bool& removido)
{
    if (nodo == nullptr)
    {
        removido = false;
        return nullptr;
    }
    if (valor < nodo->dato)
    {
        nodo->izquierda = removerNodo(nodo->izquierda, valor, removido);
    } else if (valor > nodo->dato)
    {
        nodo->derecha = removerNodo(nodo->derecha, valor, removido);
    } else
    {
        removido = true;

        if (nodo->izquierda == nullptr || nodo->derecha == nullptr)
        {
            AVLNodo* temporal = (nodo->izquierda != nullptr) ? nodo->izquierda : nodo->derecha;
            delete nodo;
            return temporal;
        }
        AVLNodo* sucesor = encontrarMinimoNodo(nodo->derecha);
        nodo->dato =sucesor->dato;
        bool dummy = false;
        nodo->derecha = removerNodo(nodo->derecha, sucesor->dato, dummy);
    }
    return balance(nodo);
}

//busqueda

bool AVLArbol::buscar(int valor) const
{
    return buscarNodo(raiz, valor);
}
bool AVLArbol::buscarNodo(AVLNodo* nodo, int valor) const
{
    if (nodo == nullptr)
    {
        return false;
    }
    if (valor == nodo->dato)
    {
        return true;
    }
    if (valor < nodo->dato)
    {
        return buscarNodo(nodo->izquierda, valor);
    }
    return buscarNodo(nodo->derecha, valor);
}

AVLNodo* AVLArbol::encontrarMinimoNodo(AVLNodo* nodo) const
{
    AVLNodo* actual = nodo;
    while (actual != nullptr && actual->izquierda != nullptr)
    {
        actual = actual->izquierda;
    }
    return actual;
}

AVLNodo* AVLArbol::encontrarMaximoNodo(AVLNodo* nodo) const
{
    AVLNodo* actual = nodo;
    while (actual!= nullptr && actual->derecha != nullptr)
    {
        actual = actual->derecha;
    }
    return actual;
}

int AVLArbol::encontrarMinimo() const
{
    if (raiz == nullptr)
    {
        throw std::runtime_error("Eroor, el arbol esta vacio");
    }
    return encontrarMinimoNodo(raiz)->dato;
}

int AVLArbol::encontrarMaximo() const
{
    if (raiz == nullptr)
    {
        throw std::runtime_error("Eroor, el arbol esta vacio");
    }
    return encontrarMaximoNodo(raiz)->dato;

}

int AVLArbol::obtenerAltura() const
{
    return (raiz != nullptr) ? raiz->altura : 0;

}

int AVLArbol::obtenerTamano() const
{
    return tamano;
}

void AVLArbol::limpiar()
{
    limpiarNodos(raiz);
    raiz = nullptr;
    tamano = 0;

}

void AVLArbol::limpiarNodos(AVLNodo* nodo)
{
    if (nodo == nullptr)
    {
        return;
    }
    limpiarNodos(nodo->izquierda);
    limpiarNodos(nodo->derecha);
    delete nodo;

}

//recorridos


void AVLArbol::enOrden() const
{
    enOrdenApoyo(raiz);
    std::cout << "\n";

}

void AVLArbol::enOrdenApoyo(AVLNodo* nodo) const
{
    if (nodo == nullptr)
    {
        return;
    }

    enOrdenApoyo(nodo->izquierda);
    std::cout << nodo->dato << " ";
    enOrdenApoyo(nodo->derecha);

}

void AVLArbol::preOrden() const
{
    preOrdenApoyo(raiz);
    std::cout << "\n";

}


void AVLArbol::preOrdenApoyo(AVLNodo* nodo) const
{
    if (nodo == nullptr)
    {
        return;
    }

    std::cout << nodo-> dato << " ";
    preOrdenApoyo(nodo->izquierda);
    preOrdenApoyo(nodo->derecha);

}

void AVLArbol::posOrden() const
{
    posOrdenApoyo(raiz);
    std::cout << "\n";

}

void AVLArbol::posOrdenApoyo(AVLNodo* nodo) const
{
    if (nodo == nullptr)
    {
        return;
    }

    posOrdenApoyo(nodo->izquierda);
    posOrdenApoyo(nodo->derecha);
    std::cout << nodo->dato << " ";

}

void AVLArbol::nivelOrden() const
{
    if (raiz == nullptr)
    {
        std::cout << "\n";
        return;

    }

    std::queue<AVLNodo*> q;
    q.push(raiz);

    while (!q.empty())
    {
        AVLNodo* actual = q.front();
        q.pop();

        std::cout << actual->dato << " ";

        if (actual->izquierda != nullptr)
        {
            q.push(actual->izquierda);

        }
        if (actual->derecha != nullptr)
        {
            q.push(actual->derecha);

        }
    }

    std::cout << "\n";

}

void AVLArbol::imprimirArbol() const
{
    if (raiz == nullptr)
    {
        std::cout << "(Arbol vacio)\n";
        return;

    }

    imprimirArbolApoyo(raiz, 0);
    std::cout << "\n";

}

void AVLArbol::imprimirArbolApoyo(AVLNodo* nodo, int espacio) const
{
    if (nodo == nullptr)
    {
        return;
    }

    espacio += 8;

    imprimirArbolApoyo(nodo->derecha, espacio);

    std::cout << "\n";
    for (int i = 8; i < espacio; i++)
    {
        std::cout << " ";

    }
    std::cout << nodo->dato << " (FB:" << nodo->obtenerFactorBalance() << ")\n";

    imprimirArbolApoyo(nodo->izquierda, espacio);

}
