#include <stdlib.h>
#include <stdio.h>

int* dameUnArray(int cuantos){
	//int array[cuantos] = {0};
	//Eso no lo podria devolver porque se perdera
	//el control al salir de la funcion
	return malloc(sizeof(int)*cuantos);//Se pasa a int* solo
}

int* dameUnArrayACero(int cuantos){
	//int array[cuantos] = {0};
	//Eso no lo podria devolver porque se perdera
	//el control al salir de la funcion
	return calloc(cuantos, sizeof(int));//Se pasa a int* solo
}

int main(){
	int* miArrayRND = dameUnArray(2);
	int* miArrayINI = dameUnArrayACero(2);
	//Nos la jugamos y no comprobamos con un if(...)
	miArrayRND[0] = 8;
	miArrayRND[1] = 9;
	printf("ArrayRND: %d, %d\n", *miArrayRND, *(miArrayRND+1));
	printf("ArrayINI: %d, %d\n", *miArrayINI, *(miArrayINI+1));
	free(miArrayRND);
	free(miArrayINI);
	return 0;
}
