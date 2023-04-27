#include <iostream>

using namespace std;

/* capacidades maximas de cada tipo:

	- int = rango de -2.147.483.648 a 2.147.483.647
	- long = rango de -2.147.483.648 a 2.147.483.647
	- double = rango de 1.7E - 308 a 1.7E + 308
	- float = rango de 1E - 18 a 1E + 18
*/

int main(){
	
	/*
	a) Problema de desbordamiento de memoria,  resultado: -557712591, real: 1.524.155.677.489
	
	int chico=0, chico1, chico2;
	chico1 = 1234567;
	chico2 = 1234567;
	chico = chico1 * chico2;
	
	cout << "\n" << chico << endl;
	
	
	b) Problema de desbordamiento de memoria,  resultado: -557712591, real: 1.524.155.677.489
	
	long grande=0;
	int chico1, chico2;
	chico1 = 1234567;
	chico2 = 1234567;
	grande = chico1 * chico2;
	
	cout << "\n" << grande << endl;
	
	c) Probloema de precision, resultado: 15289, real: 15289.02
	double resultado, real1, real2;	
	real1 = 123.1;
	real2 = 124.2;
	resultado = real1 * real2;
	
	cout << "\n" << resultado << endl;
	
	d) Problema de precision, resultado: 15241578787227558, real: 15.241.578.787.227.557,72
	double resultado, real1, real2;	
	real1 = 123456789.1;
	real2 = 123456789.2;
	resultado = real1 * real2;
	
	cout << "\n" << resultado << endl;
	
	e) Problema de precision, resultado = 0; real = 0;
	double real, otro_real;
	real = 2e34;
	otro_real = real + 1;
	otro_real =  otro_real - real;
	
	f) Problema de precision, resultado = infinito; real = 1e+500
	double real, otro_real;
	real = 1e+300;
	otro_real = 1e+200;
	otro_real = otro_real - real;
	
	g) Problema de precision, resultado = infinito; real = 
	float chico;
	double grande;
	grande = 2e+150;
	chico = grande;

	*/
	
	float chico;
	double grande;
	grande = 2e+150;
	chico = 	grande;
	
	//cout.precision(10);
	cout << "\n" << chico << endl;
	
	
	return 0;
}


