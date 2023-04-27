#include <iostream>
using namespace std;


int main(){
   double cota_izda, cota_dcha, valor_real;
   char car_izda, car_dcha, car_coma; // ascii [=91 y ]=93
   
   cout << "\nIntervalo." << "\nIntroduzca el intervalo: ";
        
   cin >> car_izda; 
   cin >> cota_izda;
   cin >> car_coma; 
   cin >> cota_dcha;
   cin >> car_dcha; 
   
   cin >> valor_real;
   
	if( car_izda == 91 && cota_izda <= valor_real){
		if( car_dcha == 93 && valor_real <= cota_dcha)
			cout << "\nEl valor " << valor_real << " está dentro del intervalo "  << car_izda << " " << cota_izda << " " 
	        << car_coma << " " << cota_dcha << " " << car_dcha;
	   else if( valor_real < cota_dcha)
	   	cout << "\nEl valor " << valor_real << " está dentro del intervalo "  << car_izda << " " << cota_izda << " " 
	        << car_coma << " " << cota_dcha << " " << car_dcha;
	   else
	   	cout << "\nEl valor " << valor_real << " no está dentro del intervalo "  << car_izda << " " << cota_izda << " " 
	        << car_coma << " " << cota_dcha << " " << car_dcha;
	}else if( cota_izda < valor_real){
		if( car_dcha == 93 && valor_real <= cota_dcha)
			cout << "\nEl valor " << valor_real << " está dentro del intervalo "  << car_izda << " " << cota_izda << " " 
	        << car_coma << " " << cota_dcha << " " << car_dcha;
	   else if( valor_real < cota_dcha)
	   	cout << "\nEl valor " << valor_real << " está dentro del intervalo "  << car_izda << " " << cota_izda << " " 
	        << car_coma << " " << cota_dcha << " " << car_dcha;
	   else
	   	cout << "\nEl valor " << valor_real << " no está dentro del intervalo "  << car_izda << " " << cota_izda << " " 
	        << car_coma << " " << cota_dcha << " " << car_dcha;
	}else
		cout << "\nEl valor " << valor_real << " no está dentro del intervalo "  << car_izda << " " << cota_izda << " " 
	        << car_coma << " " << cota_dcha << " " << car_dcha;
	
}


