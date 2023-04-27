#include <stdio.h>

int main(void){
	int valor = 6;
	{
		int valor = 9;
		printf("Valor: %d\n", valor);
	}
	
	return 0;
}
