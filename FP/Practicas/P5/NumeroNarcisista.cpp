#include <iostream>
#include <cmath>

using namespace std;

int main(){
	bool esNarcisista=false;
	int n=0;
	
	cout << "\nIntroduce un numero entero: ";
	cin >> n;
	
	string num = to_string(n);
	double suma = 0;
	
	for(int i = 0; i < num.size(); i++){
		double digitoA = num[i] - '0';
		double elevado = pow(digitoA, num.size());
		
		suma = suma + elevado;
	}
	
	if(suma == n)
		cout << "\nEl numero es narcisista" << endl;
	else
		cout << "\nEl numero no es narcisista" << endl;
	
	return 0;
}
