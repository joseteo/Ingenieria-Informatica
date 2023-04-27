#include <stdio.h>
#include <stdlib.h>

int main(){
	int val;
	printf("Valor sin inicializar: %d\n", val);

	int* vec = malloc(sizeof(int)*2);//VEC[0, 1]
	printf("Valor fuera de rango: %d\n", vec[2]);//Leo sin deber
	vec[2] = 0;//Escribo sin deber... esto puede cerrar todo
	//free(vec);//Y no libero esta memoria... tengo una fuga
	return 0;
}

