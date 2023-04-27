#ifndef Pila_max_H
#define Pila_max_H
#include <iostream>
#include "VDG.h"

using namespace std;

typedef struct{
  int ele;
  int maximo;
}elemento;

 

class PilaMAX{

	private:

		VectorDinamico<elemento> datos;

	public:
		PilaMAX(): datos(10){}

		PilaMAX(const PilaMAX & otra):datos(otra.datos){}
		
		~PilaMAX(){}

		void poner(int  elem);

		int componente();

		void quitar();

		int num_elementos() const;

		bool vacia() const;

		elemento tope();

		const elemento tope() const;

};

ostream& operator<<(ostream & os,const elemento & a);

#endif
