/*
SESION 8 EJERCICIO 11
Realizar un programa que inserte un vector
dentro de otro a partir de una posición determinada.
*/

#include <iostream>
using namespace std;

int main(){
	
	int const MAX=1000;
	int inicial[MAX], aux[MAX];
	int util_inicial, valor, util_introducir, util_aux=0, contador=0, pos;
	
	do{
		cout << "\nTamanio vector 1: ";
		cin >> util_inicial;
	}while (util_inicial > MAX);
	
	for(int i=0; i < util_inicial; i++){
		cout << "\nIntroduce numero: ";
		cin >> inicial[i];
	}
	
	do{	
		cout << "\nIntroducir posicion: ";
		cin >> pos;
	}while(pos > util_inicial);
	
	pos--; //El -- es porque los vectores empiezan en 0
	
	for(int i=pos; i <= util_inicial; i++){
		aux[util_aux] = inicial[i];	
	
		util_aux++;	
		util_inicial--;
	}
	
	do{
		cout << "\nTamanio vector 2: ";
		cin >> util_introducir
	}while (util_introducir > MAX);
	
	for(int i=0; i < util_introducir; i++){	
		cout << "\nIntroducir valores nuevo vector: "; 
		cin >> valor;
	
		inicial[util_inicial] = valor;  //Los valores se los introduzco sobreescribiendo en el vector a partir de la posicion
	
		util_inicial++;
	}
	
	for(int i=0; i < util_aux; i++){	
		inicial[util_inicial] = aux[i];
		
		util_inicial++;	
	}
	
	cout << "\nEl vector resultante es: ";
		
	for(int i=0; i < util_inicial; i++){
		cout << " " << inicial[i];	
	}
	
}

