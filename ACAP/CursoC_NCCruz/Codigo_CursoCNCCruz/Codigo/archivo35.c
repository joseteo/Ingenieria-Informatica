#include <stdio.h>

int main(){
	int matriz[2][2] = {{1, 2}, {3, 4}};
	for(int i = 0; i<2; i++){
		for(int j = 0; j<2; j++){
			goto super_salida;
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
	super_salida: printf("Salimos de un bucle doble de golpe!\n");
	return 0;
}
