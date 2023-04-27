#include <iostream>

using namespace std;

bool primo(int n){
	bool esprimo=true;
	
	if (n == 0 || n == 1 || n == 4)
		esprimo = false;
	for (int i = 2; i < n / 2; i++){
		if (n % i == 0)
			esprimo = false;
	}
	
	return esprimo;
}

int main(){
	bool esprimo=false;
	int n;
	
	cout << "\nIntroduce un numero natural: ";
	cin >> n;
	
	esprimo = primo(n);
	
	if( esprimo)
		cout << "\nEl numero " << n << " es primo";
	else
		cout << "\nEl numero " << n << " no es primo";
	
	
}
