#include <iostream>

using namespace std;

int main(){
	int min, max, k;
	
	cout << "\nIntroduzca el minimo: ";
	cin >> min;
	
	cout << "\nIntrocuzca el maximo: ";
	cin >> max;
	while(max < min){
		cout << "\nIntroduza un maximo mayor al minimo introducido: " << min << endl;
		cin >> max;
	}
	cout << "\nIntrocuzca el valor de k: ";
	cin >> k;
	while(k < 1){
		cout << "\nIntroduza k siendo mayor o igual a 1: ";
		cin >> k;
	}
	
	int cont;
	for(int i=min; i<=max; i++){
		cont=0;
		for (int j=2; j<i ; j++){
			if (i%j==0){
				cont++;
			}
		}
		if (cont >= k)
			cout << i << " ";
	}
	
	return 0;
}
