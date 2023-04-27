#include <iostream>

using namespace std;

int main(){
	double km=0.0, t_base=150.0, t_final=0, tarifa=0.1;
	
	cout << "Introduce los kilometros al destino: ";
	cin >> km;
	
	t_final = t_base;
	
	if( km > 300)
		t_final += ( (km-300) * tarifa);
	
	cout << "\nPrecio final: " << t_final << endl;
	
	return 0;
}
