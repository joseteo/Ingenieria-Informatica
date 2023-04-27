#include <iostream>

using namespace std;

int main(){
	double salario_base=0,
	incremento = 1.02;
	
	cout << "\n Introduzca el salario_base: " << endl;
	cin >> salario_base;
	
	//alternativa A
	cout << "\n Alternativa A" << endl;
	cout << "\n Salario Final: " << salario_base * incremento << endl;
	
	//alternativa B
	double salario_final=0;
	salario_final = salario_base * incremento;
	cout << "\n Alternativa B" << endl;
	cout << "\n Salario Final: " << salario_final << endl;
	
	//alternativa C
	salario_base*=incremento;
	cout << "\nAlternativa C" << endl;
	cout << "\n Salario Final: " << salario_base << endl;
	
	return 0;
}
