#include <stdio.h>

int main(void){
	int arrayA[] = {1, 2, 3};
	int* ptr_ini = &(arrayA[0]);//o &array al apuntar al comienzo
	int* ptr_fin = &(arrayA[2]);
	printf("Primer y último valor de A: %d y %d\n", *ptr_ini, *ptr_fin);
	int arrayB [] = {4, 5, 6};
	int* matriz[2];//Array de punteros a entero
	matriz[0] = arrayA;
	matriz[1] = arrayB;
	//Vamos a mostrar los 6 valores de esta matriz:
	printf("Primera fila: [%d %d %d]\n", matriz[0][0], matriz[0][1], matriz[0][2]);
	printf("Segunda fila: [%d %d %d]\n", matriz[1][0], matriz[1][1], matriz[1][2]);
	//Vamos a apuntar a la misma matriz de otra forma:
	int** misma = matriz;// o &(matriz[0])
	printf("Primera fila: [%d %d %d]\n", misma[0][0], misma[0][1], misma[0][2]);
	printf("Segunda fila: [%d %d %d]\n", misma[1][0], misma[1][1], misma[1][2]);
	return 0;
}
