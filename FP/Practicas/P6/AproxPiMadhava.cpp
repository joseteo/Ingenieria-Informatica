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
	
	double num=1;
	double num1=1;
	double num2=1/sqrt(3);
	double den=1;
	num=num1*num2;
	for(int i=0; i<tope; i++){
		pi += ( num*6 / den );
		num1 *= -1;
		num2 *= 1/sqrt(3) * 1/sqrt(3);
		num = num1*num2;
		den = den + 2;
	}
	
	cout << "\n" << pi << endl;
	
	return 0;
}
