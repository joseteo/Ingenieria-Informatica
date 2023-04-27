/**
 * @file pila_lista.h
 * @brief Fichero cabecera del TDA Pila_lista
 *
 * Gestiona una secuencia de elementos con facilidades para la inserción y
 * borrado de elementos en un extremo
 *
 */

#ifndef PILA_LISTA_H
#define PILA_LISTA_H

#include <iostream>
#include <list>

using namespace std;

/**
 *  @brief T.D.A. Pila
 *
 * Una instancia @e v del tipo de datos abstracto Pila sobre el tipo @c T es
 * una lista de elementos del mismo con un funcionamiento @e LIFO (Last In,
 * First Out). En una pila, las operaciones de inserción y borrado de elementos
 * tienen lugar en uno de los extremos denominado @e Tope. Una pila de longitud
 * @e n la denotamos

 * - [a1,a2,a3,..,an>

 * donde @e ai es el elemento de la posición i-ésima.

 * En esta pila, tendremos acceso únicamente al elemento del @e Tope, es decir,
 * a @e an. El borrado o consulta de un elemento será sobre  @e an, y la
 * inserción de un nuevo elemento se hará sobre éste. Quedando el elemento
 * insertado como @e Tope de la pila.

 * Si @e n=0 diremos que la pila está vacía.

 * El espacio requerido para el almacenamiento es O(n). Donde n es el número de
 * elementos de la Pila.
 *
 * Para la implementación de la Pila, se ha usado una estructura Lista de la STL,
 * situando el @e tope de la Pila en la última posición ocupada de la lista.
 *
 */

//Para que funcionen la sobrecarga de las funciones friend << y >>
template <class T> class Pila;
template <class T> ostream& operator<<(ostream& flujo, Pila<T>& p);

template <class T>
class Pila{
    private:
    list<T> lista;

    public:
    /**
     * @brief Constructor por defecto de la clase. Crea un vector vacío
    */
    Pila();

    /**
     * @brief Constructor de copias
     * @param otra La pila de la que se hará la copia.
    */
    Pila(const Pila& otra);

    /**
     * @brief Sobrecarga del operador de asignación
     * @param otra La pila de la que se hará copia.
    */
    Pila& operator= (const Pila& otra);

    /**
     * @brief Comprueba si la pila está vacia
    */
    bool esta_vacia() const;

    /**
     * @brief Devuelve el elemento del tope de la pila
    */
    T& tope();

    /**
     * @brief Devuelve el elemento del tope de una pila constante
    */
    const T& tope() const;

    /**
     * @brief Añade un elemento "encima" del tope de la pila
     * @param n Elemento que se va a añadir.
    */  
    void poner(const T &n);

    /**
     * @brief Quita el elemento del tope de la pila
    */
    void quitar();

    /**
     * @brief Devuelve el numero de elementos
    */
    int tamanio() const;

    /**
     * @brief Salida de una pila
     * @param flujo stream de salida
     * @param e Pila a escribir
     * @post Se muestra el contenido de la pila
    */
    friend ostream& operator << <>(ostream& flujo, Pila& p);

};

#include "../src/pila_lista.cpp"

#endif
