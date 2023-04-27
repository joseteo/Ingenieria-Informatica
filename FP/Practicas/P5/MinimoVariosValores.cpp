#include <iostream>

using namespace std;

int main(){
	int dato=1, cont=0, min=10000000;
	
	cout << "\nIntroduce los numeros: ";
	
	while(dato != 0){
		cin >> dato;
		
		if(dato != 0){
			cont++;
			if(dato < min){
				min = dato;
			}
		}
	}
	
	if(min == 10000000)
		min = 0;
	
	cout << "\nIntroducidos: " << cont << ". Minimo: " << min << endl;
}

/*
Para que el programa cambie a leer valores enteros negativos 
y finalizar con la entrada de cualquier valor positivo.

Habria que cambiar las condiciones del while y el if dentro del mismo, es decir,
...
while(dato < 0){
	...
	if(dato < 0)
	...
}
...
*/

