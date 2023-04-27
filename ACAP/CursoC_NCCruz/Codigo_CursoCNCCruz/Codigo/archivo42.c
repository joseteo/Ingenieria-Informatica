#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#include "archivo42_Matrices.h"

double get_wall_time(){//Para medir tiempo real 
    struct timeval time;
    if (gettimeofday(&time,NULL)){
        printf("Error de medición de tiempo\n");
        return 0;
    }
    return (double) time.tv_sec + (double) time.tv_usec * 0.000001;
}

int Sumar(int a, int b){
	return a+b;
}

int Restar(int a, int b){
	return a-b;
}

int (*elegirFuncion(int tipo))(int, int){//Esto es una funcion que devuelve punteros a funcion
	switch(tipo){
		case 0:
			return Sumar;
		case 1:
			return Restar;
		default:
			printf("Modo desconocido. Usando 'Sumar'\n");
			return Sumar;
	}
}

void operar(int tam, int** matrizA, int (*operador)(int, int), int** matrizB, int mostrar){
	int** matrizC = reservarMatriz(tam);
	if(matrizC){
		double TA = get_wall_time();
		aplicarOperaction(tam, matrizA, operador,matrizB, matrizC);
		double TB = get_wall_time();
		printf("Hecho! Tiempo invertido: %.3lf\n", TB-TA);
		if(mostrar){
			printf("A:\n");
			mostrarMatriz(tam, matrizA);
			printf("--------------\n");
			printf("B:\n");
			mostrarMatriz(tam, matrizB);
			printf("--------------\nC:\n");
			mostrarMatriz(tam, matrizC);
		}
		liberarMatriz(matrizC);
	}else{
		printf("Error. No se ha podido reservar espacio para el resultado");
	}
}

int crearNuevosDatos(int tam, int*** matrizA, int*** matrizB){
	*matrizA = reservarMatriz(tam);
	*matrizB = reservarMatriz(tam);
	if(!(*matrizA) || !(*matrizB)){
		printf("Error. No se han podido reservar las matrices A y B\n");
		return 0;
	}else{
		llenarMatrizAleatoria(tam, *matrizA, 0, 10);
		llenarMatrizAleatoria(tam, *matrizB, 0, 10);
		if(!volcarMatriz("archivo42_MatrizA.txt", tam, *matrizA) ||
						!volcarMatriz("archivo42_MatrizB.txt", tam, *matrizB)){
			printf("Error al volcar las nuevas matrices a disco.\n");
			return 0;
		}
		return 1;
	}
}

int cargarDatosPrevios(int* tam, int*** matrizA, int*** matrizB){
	int tamA = 0, tamB = 0;
	if(cargarMatriz("archivo42_MatrizA.txt", &tamA, matrizA) &&
						cargarMatriz("archivo42_MatrizB.txt", &tamB, matrizB)){
		if(tamA == tamB){
			*tam = tamA;
			return 1;
		}else{
			printf("Error. Las matrices leídas no son compatibles.\n");
			return 0;	
		}
	}else{
		printf("Error. No se han podido cargar las matrices desde archivo.\n");
		return 0;
	}
}

int main(int argc, char* argv[]){
	if(argc!=3 && argc!=5){
		printf("Ejecuta el modo 1 para hacer un cálculo y guardar los datos.\n");
		printf("Ejecuta el modo 2 para hacer una operación con datos guardados.\n");
		printf("[1]: ./prog semilla tam operacion[0/1] mostrar\n");
		printf("[2]: ./prog operacion[0/1] mostrar\n");
	}else{
		int** matrizA = 0;
		int** matrizB = 0;
		int (*operador)(int, int) = elegirFuncion(atoi(argv[argc-2]));
		int mostrar = atoi(argv[argc-1]);
		int tam = 0, ok = 1;
		if(argc==5){
			srand(atoi(argv[1]));
			tam = atoi(argv[2]);
			ok = crearNuevosDatos(tam, &matrizA, &matrizB);
		}else{
			ok = cargarDatosPrevios(&tam, &matrizA, &matrizB);
		}
		if(ok){
			operar(tam, matrizA, operador, matrizB, mostrar);
		}
		liberarMatriz(matrizA);
		liberarMatriz(matrizB);
	}
	return 0;
}
