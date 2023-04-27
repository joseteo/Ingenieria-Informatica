#include <iostream>
#include <cmath>
using namespace std;

int main(){
   double interes;
   double capital;
   double capital_final;
   int i=1;

   cout << "Interés bancario\n\nIntroduzca capital inicial --> ";
   cin >> capital;
   cout << "Introduzca interés --> ";
   cin >> interes;

	while(capital_final < capital*2){
		capital_final = capital * pow((1 + interes/100.0), i);
		i++;
	}

   cout << "\nPara doblar la cantidad inicial han de pasar " << 
	i-1 << " años\nAl finalizar, se obtendrá un total de " << capital_final << " euros";
   cout << "\n\n";

}
