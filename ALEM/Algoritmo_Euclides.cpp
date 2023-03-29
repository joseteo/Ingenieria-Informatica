#include <iostream>
#include <cmath>

using namespace std;

int mcd(int a, int b){
	int aux_b = b; 
	while (b!=0){
		b = a%b;
		a = aux_b;
		aux_b = b;
	}
	return a;
}

int main(){
	long int n=0, a=0, b=0, d=0;
	
	cout << "\n Introduce una opcion: ";
	cout << "\n	1. Calcular el maximo comun divisor de dos numeros.";
	cout << "\n 	2. Salir.\n";
	
	cin >> n;
	if( n == 1){
		cout << "\n Calculo del maximo comun divisor de a y b ";
		cout << "\nIntroduce el numero a: ";
		cin >> a;
		cout << "Introduce el numero b: ";
		cin >> b;
		d=mcd(a,b);
		cout << "mcd(" << a << "," << b << ")=" << d;
		main();
	}else if(n == 2)
		cout << "FIN";
	else{
		cout << "Has introducido una opciona no valida.";
		main();
	}
		
	return 0;
}
