#include <iostream>
#include <cmath>

using namespace std;

double integral(double L, int N){
	double deltax=L/N;
	double inte=deltax;
	double x=0;
	
	for(int i=1; i<=N; i++){
		x=i*deltax;
		inte += ( (sin(x)*sin(x)*deltax) / (x*x) );
	}	
	
	return inte;
}

int main(){
	int N;
	double L, res=0;
	
	cout << "\nIntroduce el valor del limite superior L y el numero entero N: ";
	cin >> L >> N;
	
	res = integral(L, N);
		
	cout << "\nf(n): " << res;
	
}
