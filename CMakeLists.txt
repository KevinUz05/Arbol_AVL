cmake_minimum_required(VERSION 3.16)
project(Proyecto_AVL)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wall -Wextra -Wpedantic -Werror -g)

add_executable(Proyecto_AVL
        src/AVLNodo.cpp
        src/AVLArbol.cpp
        src/main.cpp
)

target_include_directories(Proyecto_AVL PRIVATE include)