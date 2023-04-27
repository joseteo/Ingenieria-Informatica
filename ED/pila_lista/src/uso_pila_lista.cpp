#include <iostream>
#include "../include/pila_lista.h"

using namespace std;

int main(int argc, char const *argv[]){

    Pila<int> p;
    Pila<char> p1;
    Pila<int> p2;

    p2.poner(96);
    p2.poner(34);
    p2.poner(45);

    p1.poner('a');
    p1.poner('z');

    cout << p1 << endl;

    p.poner(6);
    p.poner(9);
    p.poner(3);
    p.poner(2);

    cout << p2 << endl;

    cout << p;

    return 0;
}
