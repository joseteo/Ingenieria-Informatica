#include <iostream>
#include <cmath>

using namespace std;

int main(){
   double interes;
   double capital;
   double capital_final;
   double anios;

   cout << "Interés bancario\n\nIntroduzca capital inicial --> ";
   cin >> capital;
   cout << "Introduzca interés --> ";
   cin >> interes;
   cout << "Introduzca los anios -->";
   cin >> anios;

	for(int i=1; i<=anios; i++){
   	capital_final = capital * pow((1 + interes/100.0), i);
	
   	cout << "\nCapital obtenido transcurrido el ano numero " << i << " = " << capital_final;
   }

}
