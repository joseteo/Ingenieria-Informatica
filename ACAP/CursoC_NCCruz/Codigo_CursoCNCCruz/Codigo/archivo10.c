#include <stdio.h>

int main(void){
	char a = 'a';
	printf("El caracter es: %c (o %d)\n", a, a);
	printf("Tiene un tamaño de %lu byte\n", sizeof(a));
	return 0;
}
