#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double tope=0;
	double pi=2;
	
	cout <<"\nIntroduce el valor de tope: ";
	while((tope < 1) || (tope > 100000) )
		cin >> tope;
	
	cout.precision(15);

	/*
	//b
	int expo=1;
	for(double i=0; i<=tope; i++){
		pi +=  ( expo * 4 / (2 * i + 1) );
		
		expo *= -1;
	}
	*/
	//c
	double num=2;
	double den=1;
	bool inter=true;
	/*
	//metodo 1 sin bool
	for(int i=0; i<tope; i++){
		pi *= ( num / den );
		if(i%2==0)
			den+=2;
		else
			num+=2;
	}
	
	//metodo 1 con bool
	for(int i=0; i<tope; i++){
		pi *= ( num / den );
		if(inter)
			den+=2;
		else
			num+=2;
		inter = !inter;
	}
	*/
	/*
	metodo 2*/
	int aux=0;
	for(int i=0; i<tope; i++){
		pi *= ( num / den );
		aux = num;
		num = den + 1;
		den = aux + 1;
	}
	
	cout << "\n" << pi << endl;
	
	return 0;
}
