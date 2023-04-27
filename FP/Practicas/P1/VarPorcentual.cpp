#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double vp=0, v_i=0, v_f=0;
	
	cout << "Introduce el valor inicial: " << endl;
	cin >> v_i;
	
	cout << "Introduce el valor final: " << endl;
	cin >> v_f;
	
	vp = abs( 100 * ( (v_f - v_i) / v_i ) );
	
	cout << "Variacion porcentual: " << vp << "%" << endl;
	
	return 0;
}
