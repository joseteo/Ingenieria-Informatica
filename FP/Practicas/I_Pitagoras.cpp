////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computaci�n e Inteligencia Artificial
// Autor: Juan Carlos Cubero
////////////////////////////////////////////////////////////////////////////

/*
   Programa simple para el c�lculo de la hipotenusa
   de un tri�ngulo rect�ngulo, aplicando el teorema de Pit�goras
*/

#include <iostream>   // Inclusi�n de recursos de E/S
#include <cmath>      // Inclusi�n de recursos matem�ticos
using namespace std;

int main(){               // Programa Principal
   double lado1;          // Declara variables para guardar
   double lado2;          // los dos lados y la hipotenusa
   double hipotenusa;

   cout << "Introduzca la longitud del primer cateto: ";
   cin >> lado1;
   cout << "Introduzca la longitud del segundo cateto: ";
   cin >> lado2;

   hipotenusa = sqrt(lado1*lado1 + lado2*lado2);
   
   cout << "\nLa hipotenusa vale " << hipotenusa;
   cin.get();
}
