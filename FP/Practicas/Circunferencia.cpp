//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computaci�n e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
//////////////////////////////////////////////////////////////////////////

// Circunferencia

/*
Cree un programa que nos pida la longitud del radio y calcule el �rea
del c�rculo y la longitud de la circunferencia correspondientes. Finalmente, el programa
mostrar� en pantalla los resultados. Recuerde que:
�rea circulo = pi * r * r
longitud circunferencia = 2 * pi * r
Se proponen las siguientes alternativas.
a) Pedir al usuario que introduzca el valor de pi
b) Usar el literal 3.1416 donde sea necesario.
c) Usar un dato llamado pi, asignarle el literal 3.1416 y usarlo donde sea necesario.
�Cu�l elegir�a y por qu�?
*/


#include <iostream>
using namespace std;

int main(){
   /*
   �Le pedimos al usuario que introduzca el valor de pi?
   La respuesta es que no.
   
   Un principio b�sico en programaci�n:
      No se le pedir� al usuario que introduzca cualquier dato
      que pueda calcularse dentro del programa.
   
   Este mismo principio lo extenderemos cuando veamos las funciones 
   y las clases.
   */
   
   /*   
   Si no le pedimos al usuario que introduzca el valor de pi,
   �usamos entonces el literal 3.1416 donde sea necesario?
   
   double radio;            // Dato de entrada
   double area, longitud;   // Datos de salida

   cout << "Introduzca el valor del radio: ";
   cin >> radio;

   area     = 3.1416 * radio * radio;   // :-(
   longitud = 2 * 3.1416  * radio;      // :-(

   cout << "\n\nEl �rea del c�rculo vale " << area;
   cout << "\n\nLa longitud de la circunferencia vale " << longitud;
   cout << "\n\n";
   */

   /*
   Esta soluci�n no es aceptable ya que si, por ejemplo, queremos darle
   mayor precisi�n a Pi y utilizar el valor 3.1415927
   tenemos que hacer un cambio del valor tantas veces como aparezca,
   lo cual es muy propenso a errores.

   Un principio b�sico en programaci�n:
     No debemos repetir c�digo

   A lo largo del curso detallaremos lo que pretendemos decir con esta frase.
   Por ahora, no debemos repetir la aparici�n del literal 3.1416

   Soluci�n:
      Usamos un dato, le asignamos un valor y usamos dicho dato
      en expresiones posteriores.
      Por ahora, le asignamos 3.1416. 
	  Posteriormente, le asignaremos una expresi�n con m�s precisi�n 
	  y finalmente lo mejoraremos usando constantes
   */

   double PI;      
   double radio;            // Dato de entrada
   double area, longitud;   // Datos de salida

   cout << "Longitud de circunferencia y �rea de c�rculo"
        << "\nIntroduzca el valor del radio: ";
   cin >> radio;
   
   PI = 3.1416;  
   area     = PI * radio * radio;      // :-)
   longitud = 2 * PI  * radio;         // :-)

   cout << "\n\nEl �rea del c�rculo vale " << area;
   cout << "\n\nLa longitud de la circunferencia vale " << longitud;
}
