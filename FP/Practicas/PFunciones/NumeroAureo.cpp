#include <iostream>

using namespace std;

double fibonacci(double n){
	if((n==0) || (n==1))
		return 1;
	else
		return (fibonacci(n-1)+fibonacci(n-2));
}

int main(){
	double n;
	double aureo;
	
	cout << "\nIntroduce el enésimo término para el calculo de fibonacci: ";
	cin >> n;
	
	aureo = fibonacci(n+1) / fibonacci(n);
	
	cout.precision(15);
	cout << "\nNumero aureo: " << aureo << endl;
	
	return 0;
}
