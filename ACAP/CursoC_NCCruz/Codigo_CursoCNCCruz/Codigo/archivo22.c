#include <stdio.h>

void Saludar(int);

int sumar(int a, int b){
	return a+b;
}

int main(){
	int miA = 6;
	Saludar(miA);
	Saludar(miA);
	Saludar(miA);
	printf("%d + 3 = %d\n", miA, sumar(miA, 3));
	return 0;
}

void Saludar(int a){
	a++;
	int b = 5;
	static int val = 0;
	printf("Hola %d; A++ = %d; B = %d\n", val, a, b);
	val++;
	b++;
}
