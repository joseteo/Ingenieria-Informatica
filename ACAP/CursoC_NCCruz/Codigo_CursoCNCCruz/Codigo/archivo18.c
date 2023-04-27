#include <stdio.h>

int main(){
	int array1D[3];//No inicializo
	printf("A1D=[%d, %d, %d]\n", array1D[0], array1D[1], array1D[2]);
	printf("El tamaño de A1D es de %lu bytes: 3x%lu\n", sizeof(array1D), sizeof(int));
	
	int array1D_B[3] = {0};//Inicializo todo a 0
	printf("A1D_B=[%d, %d, %d]\n", array1D_B[0], array1D_B[1], array1D_B[2]);
	int array1D_C[3] = {0, 1};//Inicializo solo los 2 primeros
	printf("A1D_C=[%d, %d, %d]\n", array1D_C[0], array1D_C[1], array1D_C[2]);
	//array1D = array1D_B;//PROHIBIDO

	int array2D[ ][2] = {{1, 2}, {3, 4}};

	printf("A2D=\t[%d, %d,\n\t %d %d]\n", array2D[0][0], array2D[0][1], 
									array2D[1][0], array2D[1][1]);

	int array3D[2][2][2] = {{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}};

	printf("A3D[0]=\t[%d, %d,\n\t %d %d]\n", array3D[0][0][0], array3D[0][0][1], 
									array3D[0][1][0], array3D[0][1][1]);
	printf("A3D[1]=\t[%d, %d,\n\t %d %d]\n", array3D[1][0][0], array3D[1][0][1], 
									array3D[1][1][0], array3D[1][1][1]);
	return 0;
}
