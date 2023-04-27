#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double pi=0; //uso double en lugar de int, para así poder mostrar los decimales de pi
	
	pi = 6 * asin(0.5);
	
	cout << "\n Valor de Pi: " << pi << endl;
	
	return 0;
}
