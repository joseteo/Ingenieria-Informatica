#include <iostream>

using namespace std;

int main(){
	double d_puntos=0.04, d_t_largo=0.02, precio=0.0,
	p_puntos=0.0, p_largo=0.0;
	
	cout << "Introduce el precio del billete: ";
	cin >> precio;
	
	p_puntos = precio - ( precio * d_puntos);
	p_largo = precio - ( precio * d_t_largo);
	
	cout << "\nPrecio descuento puntos cliente: " << p_puntos 
	<< "\nPrecio descuento trayecto largo: " << p_largo << endl;
	
	return 0;
}
