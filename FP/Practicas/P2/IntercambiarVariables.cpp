#include <iostream>

using namespace std;

int main(){
	int caja_izda=0, caja_dcha=0, aux=0;
	
	cout << "\nIntroduce la cantidad de dinero de la caja izquierda: ";
	cin >> caja_izda;
	cout << "\nIntroduce la cantidad de dinero de la caja derecha: ";
	cin >> caja_dcha;
	
	aux = caja_dcha;
	caja_dcha = caja_izda;
	caja_izda = aux;
	
	cout << "\nLa caja izquierda vale: " << caja_izda;
	cout << "\nLa caja derecha vale: " << caja_dcha << endl;
	
	return 0;
}
