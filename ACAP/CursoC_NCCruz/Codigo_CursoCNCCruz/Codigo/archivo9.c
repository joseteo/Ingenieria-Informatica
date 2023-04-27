#include <limits.h>
#include <stdio.h>

int main(void){
	unsigned int enteroMaximo = UINT_MAX;
	printf("El int más grande aquí es: %u\n", enteroMaximo);
	printf("(Y son %lu bytes)\n", sizeof(unsigned int));
	return 0;
}
