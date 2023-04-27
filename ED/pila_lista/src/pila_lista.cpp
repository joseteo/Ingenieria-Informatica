#include <iostream>
#include <list>
#include "../include/pila_lista.h"

using namespace std;

template <class T>
Pila<T>::Pila(): lista(){}

template <class T>
Pila<T>::Pila(const Pila& otra): lista(otra.lista){}

template <class T>
Pila<T>& Pila<T>::operator=(const Pila& otra){
    if(this != &otra){
        lista = otra.lista;
    }
    return *this;
}

template <class T>
bool Pila<T>::esta_vacia() const{
    return lista.empty();
}

template <class T>
T& Pila<T>::tope(){
    return lista.back();
}

template <class T>
const T& Pila<T>::tope() const{
    return lista.back();
}

template <class T>
void Pila<T>::poner(const T &n){
    lista.push_back(n);
}

template <class T>
void Pila<T>::quitar(){
    lista.pop_back();
}

template <class T>
int Pila<T>::tamanio() const{
    return lista.size();
}

template <class T>
ostream& operator <<(ostream& flujo, Pila<T>& p){
    flujo << "TAMAÑO: " << p.tamanio() << endl;
    while(!p.esta_vacia()){
        flujo << "| " << p.tope() << " |" << endl;
        p.quitar(); //Necesito no hacer Pila constante ya que si no no puedo quitar elementos
    }
    return flujo;
}
