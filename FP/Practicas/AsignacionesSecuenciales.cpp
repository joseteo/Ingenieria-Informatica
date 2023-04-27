//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computaci�n e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
//////////////////////////////////////////////////////////////////////////

/*
Indique cu�l ser�a el resultado de las siguientes operaciones:
 
int salario_base;
int salario_final;
int incremento;

salario_base = 1000;
salario_final = salario_base;

incremento = 200;
salario_final = salario_final + incremento;

salario_base = 3500;

cout << "\nSalario base: " << salario_base;
cout << "\nSalario final: " << salario_final;

Responda razonadamente a la siguiente pregunta: �El hecho de realizar la
asignaci�n salario_final = salario_base; hace que ambas variables est�n
ligadas durante todo el programa y que cualquier modificaci�n posterior de
salario_base afecte a salario_final ?
*/

#include <iostream>
using namespace std;

int main(){
   int salario_base;
   int salario_final;
   int incremento;

   salario_base  = 1000;
   salario_final = salario_base;

   incremento = 200;
   salario_final = salario_final + incremento;

   salario_base = 3500;
   
   cout << "\nSalario base:  " << salario_base;
   cout << "\nSalario final: " << salario_final;
   
   /*
   La respuesta a la pregunta es que NO.
   salario_final y salario_base son variables totalmente distintas.
   Cuando se realiza la asignaci�n
      salario_final = salario_base;
   la variable salario_final recibe una copia del valor que en ese momento
   tenga la variable salario_base.
   Pero posteriormente, cualquier modificaci�n que hagamos de
   salario_base NO afecta en ning�n momento a la variable salario_final
   (a no ser, claro est�, que volvamos e ejecutar la sentencia de asignaci�n anterior)
   */
}
