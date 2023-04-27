#include <stdio.h>

typedef struct{
	int campoA;
	int campoB;
} Estructura;

union LaUnion{
	int campoA;
	int campoB;
};

void funcionEst(Estructura* ptr){
	int valCampoA = ptr->campoA;
	int valCampoB = (*ptr).campoB;
	printf("Estructura: (%d, %d)\n", valCampoA, valCampoB);
	ptr->campoA+=10;//Modificamos el origen
}

void funcionUnion(union LaUnion* ptr){
	int valor = ptr->campoA;//Es una union... solo hay 1 cosa
	printf("Union: %d\n", valor);
	ptr->campoA+=10;
}

int main(void){
	Estructura miEstructura = {3, 4};
	funcionEst(&miEstructura);
	union LaUnion miUnion;
	miUnion.campoB = 8;
	funcionUnion(&miUnion);
	printf("Queda: Estructura: (%d, %d)\n", miEstructura.campoA,
		miEstructura.campoB);
	printf("\tUnion: %d\n", miUnion.campoA);
	return 0;
}
