#include <iostream>

using namespace std;

int main(){
	char mayus, minus, i_ascii=32; //indice entero para pasar de mayuscula a minuscula en ascii
	
	cout << "\nIntroduce un caracter: ";
	cin >> mayus;
	
	minus = mayus + i_ascii;
	
	cout << "\nSu caracter en minuscula: " << minus << endl;
	
	return 0;
}
