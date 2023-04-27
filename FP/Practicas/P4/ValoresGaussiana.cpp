#include <iostream>
#include <cmath>
using namespace std;

int main(){   
   const double PI = 6 * asin(0.5);   

   double esperanza=0, desviacion=-1, x;         // Entrada.
   double y;                                // Salida
   double tipificado, exponente;
   double minimo, maximo, incremento;
   
   cout << "Gaussiana\n\nIntroduzca el valor del parámetro 'esperanza' : ";
   cin >> esperanza;
   while(desviacion < 0){
   	cout << "Introduzca el valor del parámetro 'desviacion' (>= 0) : ";
   	cin >> desviacion;
	}
   cout << "Introduzca el valor del parametro 'minimo' :";
   cin >> minimo;
   while(maximo < minimo){
   	cout << "Introduce el valor del parametro 'maximo' :";
   	cin >> maximo;
	}
   cout << "Introduzca el valor del incremento : ";
   cin >> incremento;
   
   for (double i = minimo; i <= maximo; i = i + incremento){
	   tipificado = (i - esperanza) / desviacion;
	   exponente = -0.5 * tipificado * tipificado;
	
	   y = exp(exponente) / ( desviacion * sqrt(2*PI) );  
	   
	   cout << "\n" << y;
	}
   
   
}
