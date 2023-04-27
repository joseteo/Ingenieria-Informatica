#include <iostream>

using namespace std;

bool numGuay(int eg){
	bool esguay=false;
	int top=eg/2 + 1, sum, aux, i=1;
	
	while( (esguay==false) && (i<top) ){
		sum=i;
		aux=i+1;
		while(sum < eg){
			sum += aux;
			aux++;
		}
		if(sum == eg)
			esguay=true;
		
		i++;
	}
	
	return esguay;
}

int main(){
	int eg=0;
	bool esguay=false;
	
	cout << "\nIntroduce un numero entero positivo: ";
	cin >> eg;
	
	esguay = numGuay(eg);
	
	if( esguay )
		cout << "\nEl numero " << eg << " es guay";
	else
		cout << "\nEl numero " << eg << " no es guay";
	
}
