#include "AVLNodo.h"
#include <algorithm>

AVLNodo::AVLNodo(int valor)
    : dato(valor), izquierda(nullptr), derecha(nullptr), altura(1) {}

void AVLNodo::actualizarAltura()
{
    int alturaIzquierda = (izquierda != nullptr) ? izquierda->altura : 0;
    int alturaDerecha = (derecha != nullptr) ? derecha->altura : 0;
    altura = 1 + std::max(alturaIzquierda, alturaDerecha);

}

int AVLNodo::obtenerFactorBalance() const
{
    int alturaIzquierda = (izquierda != nullptr) ? izquierda->altura : 0;
    int alturaDerecha = (derecha != nullptr) ? derecha->altura : 0;
    return alturaIzquierda - alturaDerecha;

}