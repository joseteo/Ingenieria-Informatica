#include <iostream>
#include <cmath>

using namespace std;

int factorial(int n){
	int aux=1;
	
	if(n<1){
		return aux;
	}
	cout << "\n" << n;
	return n*factorial(n-1);
}

double Taylor(double x, double N){
	double taylor=1;
	
	for(int i=1; i <= N; i++){
		taylor += ( pow((0.5 * log(x)),i)/ factorial(i) );
	}
	
	return taylor;
}

int main(){
	double x,N;
	
	cout << "\nIntroduce un numero real X y el numero de sumandos N" << endl;
	cin >> x >> N;
	
	cout << "\nFact: " << factorial(N);
	
	cout << "\nLa raiz cuadrada del desarrollo de Taylos es: " << Taylor(x, N) << endl;
	
}
