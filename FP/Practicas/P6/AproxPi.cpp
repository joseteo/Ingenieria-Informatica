// 33
// 30 31 32 40 41 1
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double tope=0;
	double pi=0;
	
	cout <<"\nIntroduce el valor de tope: ";
	while((tope < 1) || (tope > 100000) )
		cin >> tope;
	
	cout.precision(15);
	/*
	//a
	for(double i=0; i<=tope; i++)
		pi += ( pow(-1,i) / (2 * i + 1) );
	*/
	/*
	//b
	int expo=1;
	for(double i=0; i<=tope; i++){
		pi +=  ( expo * 4 / (2 * i + 1) );
		
		expo *= -1;
	}
	*/
	//c
	double expo=0;
	for(int i=0; i<=tope; i++){
		if(i%2==0)
			expo=1;
		else
			expo=-1;
		pi += ( expo * 4 / (2 * i + 1) );
	}
	
	
	
	
	cout << "\n" << pi << endl;
	
	return 0;
}
