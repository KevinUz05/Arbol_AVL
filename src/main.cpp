//correr programa principal con pruebas :)


#include "AVLArbol.h"
#include <cassert>
#include <iostream>

int main()
{
    AVLArbol arbol;

    std::cout << "probar rotaciones  \n";


    std::cout << "\n=== ESTRUCTURA VISUAL DEL ARBOL ===\n";
    arbol.imprimirArbol();

    arbol.insertar(10);
    std::cout << "\n=== ESTRUCTURA VISUAL DEL ARBOL ===\n";
    arbol.imprimirArbol();

    arbol.insertar(20);
    std::cout << "\n=== ESTRUCTURA VISUAL DEL ARBOL ===\n";
    arbol.imprimirArbol();

    arbol.insertar(30);
    std::cout << "\n=== ESTRUCTURA VISUAL DEL ARBOL ===\n";
    arbol.imprimirArbol();

    assert(arbol.obtenerAltura() == 2);


    arbol.insertar(5);
    std::cout << "\n=== ESTRUCTURA VISUAL DEL ARBOL ===\n";
    arbol.imprimirArbol();

    arbol.insertar(3);
    std::cout << "\n=== ESTRUCTURA VISUAL DEL ARBOL ===\n";
    arbol.imprimirArbol();


    arbol.insertar(4);
    std::cout << "\n=== ESTRUCTURA VISUAL DEL ARBOL ===\n";
    arbol.imprimirArbol();


    arbol.insertar(40);
    std::cout << "\n=== ESTRUCTURA VISUAL DEL ARBOL ===\n";
    arbol.imprimirArbol();

    arbol.insertar(35);
    std::cout << "\n=== ESTRUCTURA VISUAL DEL ARBOL ===\n";
    arbol.imprimirArbol();



    std::cout << "tamano: " << arbol.obtenerAltura() << "\n";
    std::cout << "altura: " << arbol.obtenerAltura() << "\n";

    std::cout << "probar recorridos \n";
    std::cout << "en orden: ";
    arbol.enOrden();

    std::cout << "preorden: ";
    arbol.preOrden();

    std::cout << "pos orden: ";
    arbol.posOrden();

    std::cout << "nivel orden: ";
    arbol.nivelOrden();

    std::cout << "busqueda del minimo y maximo: ";
    assert(arbol.buscar(35) == true);
    assert(arbol.buscar(99) == false);
    assert(arbol.encontrarMinimo() == 3);
    assert(arbol.encontrarMaximo() == 40);

    std::cout << "minimo: " << arbol.encontrarMinimo() << "  Maximo: " << arbol.encontrarMaximo() << "\n";
    std::cout << "buscar el 35: " << (arbol.buscar(35) ? "encontrado" : "no encontrado") << "\n";


    std::cout << "eliminacion con auto balanceo  \n" ;
    arbol.remover(3);
    std::cout << "\n=== ESTRUCTURA VISUAL DEL ARBOL ===\n";
    arbol.imprimirArbol();

    arbol.remover(40);
    std::cout << "\n=== ESTRUCTURA VISUAL DEL ARBOL ===\n";
    arbol.imprimirArbol();

    arbol.remover(20);
    std::cout << "\n=== ESTRUCTURA VISUAL DEL ARBOL ===\n";
    arbol.imprimirArbol();

    assert(arbol.buscar(20) == false);
    assert(arbol.obtenerAltura() == 3);

    std::cout << " en orden despues de eliminar \n";
    arbol.enOrden();
    std::cout << "nueva altura: " << arbol.obtenerAltura() << "\n";


    std::cout << "limpiar memoria";
    arbol.limpiar();
    assert(arbol.obtenerTamano() == 0);
    assert(arbol.obtenerAltura() == 0);
    std::cout << "arbol limpiado, tamano: " << arbol.obtenerTamano() << "\n";

    std::cout << "\n=== ESTRUCTURA VISUAL DEL ARBOL ===\n";
    arbol.imprimirArbol();

    return 0;


}


