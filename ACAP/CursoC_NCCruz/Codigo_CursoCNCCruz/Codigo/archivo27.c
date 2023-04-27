#include <stdio.h>

void mostrarValores(int a, int b){
	printf("Muestro: %d y %d\n", a, b);
}

typedef void (*MyFunc2INT) (int, int);

int main(){
	int a = 6, b = 9;
	void (*ptrMostrador)(int, int) = mostrarValores;
	MyFunc2INT otroPtrMostrador = &mostrarValores;
	ptrMostrador(a, b);
	(*ptrMostrador)(a, b);
	otroPtrMostrador(a, b);
	(*otroPtrMostrador)(a, b);
	return 0;
}
