#include <stdio.h>

int main(void){
	int miEntero = 1000000; // Esto es mas que 32 767
	printf("Mi entero: %d\n", miEntero);
	printf("Bytes de un SIGNED INT: %lu\n", sizeof(int));
	return 0;
}
