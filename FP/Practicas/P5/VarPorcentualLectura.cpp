#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double vp[100], v_i=0, v_f=0;
	int i=0;
	
	while( v_i >= 0 ){
		cout << "Introduce el valor inicial y final: " << endl;
		cin >> v_i >> v_f;
		
		vp[i] = abs( 100 * ( (v_f - v_i) / v_i ) );
		
		i++;
	}
	
	cout << "Variacion porcentual: ";
	for(int j=0; j < i-1; j++)
		cout << vp[j] << "% ";
	
	cout << endl;
	
}
