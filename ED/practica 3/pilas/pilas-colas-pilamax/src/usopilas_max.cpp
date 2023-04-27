#include <iostream>
#include "Pila_max_VD.h"
#include "VDG.h"

using namespace std;

int main(){

  PilaMAX p;

  int i;

  elemento aux;

  for (i=10; i >=0 ; i--){

    p.poner(i);
    cout << p.tope()<< endl;
  }

  p.quitar();

  cout << p.tope() <<endl;

  return 0;
}
