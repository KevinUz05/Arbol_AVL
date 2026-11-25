#ifndef PROYECTO_AVL_AVLNODO_H
#define PROYECTO_AVL_AVLNODO_H

class AVLNodo
{
public:
    int dato;
    AVLNodo* izquierda;
    AVLNodo* derecha;
    int altura;

    explicit AVLNodo(int valor);

    void actualizarAltura();

    int obtenerFactorBalance() const;

};

#endif
