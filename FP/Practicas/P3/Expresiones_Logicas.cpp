#include <iostream>

using namespace std;

int main(){
	char letra, vocal;
	int edad, adivine, anio, velocidad;
	bool b_l,b_e,b_a,b_an,b_v,b_vo;
	b_l=b_e=b_a=b_an=b_v=b_vo=false;
	
	cin >> letra >> edad >> adivine >> anio >> velocidad >> vocal;
	
	if((letra >= 97) && (letra <= 122)){
		b_l = true;
	}
	
	if((edad < 18) || (edad > 65)){
		b_e = true;
	}
	
	if((adivine >= 1) && (adivine <= 100)){
		b_a = true;
	}
	
	if( anio%400 == 0){
		b_an = true;
	}
	
	if( velocidad >= 100){
		b_v = true;
	}
	
	if(vocal == 'a' || vocal == 'e' || 
		vocal == 'i' || vocal == 'o' || vocal == 'u'){
		b_vo = true;
	}
   
	cout << "\n" << b_l << " " << b_e << " " << b_a
	<< " " << b_an << " " << b_v << " " << b_vo << endl;
	
	return 0;
}
