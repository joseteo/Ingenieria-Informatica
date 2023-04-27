#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double pi=0, g_1=0, g_2=0, r_1=0, r_2=0, pi_180=0;
	
	pi = 6 * asin(0.5);
	pi_180 = pi / 180;
	
	cout << "\n Introduzca los dos grados: " << endl;
	cin >> g_1 >> g_2;
	
	r_1 = g_1 * pi_180;
	r_2 = g_2 * pi_180;
	
	cout << "\n " << r_1 << "\t" << r_2 << endl;
	
	return 0;
}
