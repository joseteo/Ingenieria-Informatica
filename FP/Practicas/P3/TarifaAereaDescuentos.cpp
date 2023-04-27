#include <iostream>

using namespace std;

int main(){
	double km=0.0, t_base=150.0, t_final=0, tarifa=0.1,
	puntos=0.0, desc100=0.03, desc200=0.04, desc700km=0.02;
	
	cout << "Introduce los kilometros al destino y los puntos de la tarjeta de fidelizacion: ";
	cin >> km >> puntos;
	
	t_final = t_base;
	
	if( km > 300)
		t_final += ( (km-300) * tarifa);
	
	if(km > 700)
		t_final -= t_final * desc700km;
	if(puntos >= 100 && puntos < 200)
		t_final -= t_final * desc100;
	else if(puntos >= 200)
		t_final -= t_final * desc200;
		
	
	
	
	cout << "\nPrecio final: " << t_final << endl;
	
	return 0;
}
