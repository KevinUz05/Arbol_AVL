# Proyecto Final - Árbol AVL en C++

Implementación de un Árbol Binario de Búsqueda Auto-Balanceado

**Alumno:** Kevin Uziel García Márquez

## Estructura del proyecto

```text
Proyecto_AVL/
├── include/
│   ├── AVLNodo.h
│   └── AVLArbol.h
├── src/
│   ├── AVLNodo.cpp
│   ├── AVLArbol.cpp
│   └── main.cpp
├── CMakeLists.txt
└── README.md
```

## Funciones implementadas

* **Operaciones básicas:** `insertar`, `remover`, `buscar`, `encontrarMinimo`, `encontrarMaximo`, `obtenerAltura`, `obtenerTamano`, `limpiar`.
* **Rotaciones (privadas):** `rotarDerecha`, `rotarIzquierda`, `rotarIzquierdaDerecha`, `rotarDerechaIzquierda`.
* **Recorridos y visualización:** `enOrden`, `preOrden`, `posOrden`, `nivelOrden` e `imprimirArbol` 

## Cómo compilar y ejecutar

### En CLion
1. Abrir la carpeta `Proyecto_AVL` desde CLion 
2. Esperar a que CLion cargue el archivo `CMakeLists.txt` 
3. Seleccionar el objetivo `Proyecto_AVL` arriba a la derecha y presionar el botón **Run**

