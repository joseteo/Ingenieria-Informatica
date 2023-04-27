#include <stdio.h>

int main(void){
	#ifdef DEMO
	printf("Cómprame\n");
	#else
	printf("¡Hola Mundo!\n");
	#endif
	return 0;
}
