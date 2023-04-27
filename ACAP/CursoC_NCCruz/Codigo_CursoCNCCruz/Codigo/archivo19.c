#include <stdio.h>

typedef struct Estructura{
	int campo1;
	int campo2[3];
} Estructura;

int main(){
	struct interna{//Definicion local
		int campo1;
		Estructura campo2;
	};

	struct interna miA = {0, {1, {2, 3, 4}}};
	struct interna miB = miA;
	miB.campo2.campo2[2] = 66;
	printf("miA: Campo 1: %d; Campo 2: %d, [%d %d %d]\n",
		miA.campo1, miA.campo2.campo1, miA.campo2.campo2[0],
		miA.campo2.campo2[1], miA.campo2.campo2[2]);
	printf("miB: Campo 1: %d; Campo 2: %d, [%d %d %d]\n",
		miB.campo1, miB.campo2.campo1, miB.campo2.campo2[0],
		miB.campo2.campo2[1], miB.campo2.campo2[2]);
	return 0;
}