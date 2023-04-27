#include <stdio.h>

int main(void){
	int val = 7;
	switch(val){
		case 0:
			printf("Entro en 0\n");
			break;
		case 1:
			printf("Entro en 1\n");
			break;
		case 2:
			printf("Entro en 2\n");
			break;
		default:
			printf("Aquí se entra siempre si no hay coincidencia\n");
	}
	return 0;
}
