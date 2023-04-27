#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double n_real=0, n_d=1, n_red=0, calc_nd=0;
	
	cout << "\n Introduce el numero resl y la cifra decimal: " << endl;
	cin >> n_real >> n_d;
	
	calc_nd = pow(10, n_d);
	
	n_red = round( n_real * calc_nd ) / calc_nd;
	
	cout << "\n Numero redondeado: " << n_red << endl;
	
	return 0;
}
