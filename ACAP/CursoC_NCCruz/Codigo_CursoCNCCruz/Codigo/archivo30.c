#include <stdlib.h>
#include <stdio.h>

int main(){
	int* array = malloc(sizeof(int)*2);
	array[0] = 8;
	array[1] = 8;
	array = realloc(array, sizeof(int)*4);
	printf("[%d, %d, %d, %d]\n", array[0], array[1], array[2], array[3]);
	free(array);
	//Vamos a hacernos una matriz 2x3
	int** matriz = malloc(sizeof(int*)*2);//Vamos a crear un bloque para
										//guardar el apuntador a cada fila
	matriz[0] = malloc(sizeof(int)*3);//Reservamos la primera fila guardando su int*
	matriz[1] = malloc(sizeof(int)*3);//Reservamos la primera fila guardando su int*
	matriz[0][0] = 1;//Accedemos primero a la fila [0] y ya vamos a la columna [0]: Izq a Der
	matriz[0][1] = 2;
	matriz[0][2] = 3;
	matriz[1][0] = 4;
	matriz[1][1] = 5;
	matriz[1][2] = 6;
	printf("[%d, %d, %d;\n", matriz[0][0], matriz[0][1], matriz[0][2]);
	printf("%d, %d, %d]\n", matriz[1][0], matriz[1][1], matriz[1][2]);
	//Ahora liberamos, primero cada fila para no "olvidar" su direccion
	free(matriz[0]);
	free(matriz[1]);
	free(matriz);//Finalmente liberamos el bloque que tenia el apuntador a cada inicio de fila
	return 0;// Y NO, ESTA MATRIZ NO ESTA CONTIGUA EN MEMORIA... VEREMOS OTROS METODOS MEJORES
}
