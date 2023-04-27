#include <iostream>
#include <stdio.h>

using namespace std;

void factoresPrimos(int numero){
	int factores[numero/2];
	int i_factores=0;
	int i=2;
	while(i<=numero){
   	if((numero%i)==0){
			factores[i_factores]=i;
			numero=numero/i;
			i_factores++;
   	}
   	if((numero%i)!=0)
			i++;
	}
  	
	i=0;   
	cout << "1 "; 
	while(i<i_factores){
		cout << " " << factores[i] << " ";
		i++;
	}
}

int main(){
	int n=0;
	
	cout << "\nIntroduce un numero entero: ";
	cin >> n;
	
	factoresPrimos(n);
       
	return 0;
}
