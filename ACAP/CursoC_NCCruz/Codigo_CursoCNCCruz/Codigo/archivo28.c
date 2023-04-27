#include <stdio.h>

void mostrarValores(int a, int b){
	printf("Muestro: %d y %d\n", a, b);
}

void mostrarSuma(int a, int b){
	printf("Sumo: %d + %d = %d\n", a, b, a+b);
}

void mostrarResta(int a, int b){
	printf("Resto: %d - %d = %d\n", a, b, a-b);
}

typedef void (*MyFunc2INT) (int, int);

void Aplicar(void (*)(int, int), int, int);//Declaramos

void (*dameLaResta(void))(int, int){
	return mostrarResta;
}

int main(){
	int a = 6, b = 9;
	void (*funcSet[3])(int, int);//MyFunc2INT funcSet[3];
	funcSet[0] = mostrarValores;
	funcSet[1] = mostrarSuma;
	funcSet[2] = dameLaResta();//Llamamos
	Aplicar(funcSet[0], a, b);//Mostramos
	(funcSet[1])(a, b);//Sumamos
	(dameLaResta())(a, b);//No usamos funcSet, re-pedimos direccion
	return 0;
}

void Aplicar(void (*func)(int, int), int a, int b){
	func(a, b);
}
