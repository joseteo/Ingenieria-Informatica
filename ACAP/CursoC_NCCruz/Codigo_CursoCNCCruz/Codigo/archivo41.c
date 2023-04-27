#include <stdio.h>

typedef struct{
	char nombre[20];
	int lados;
} Poligono;

int escribirPoligono(FILE* archivo, Poligono plg){
	int num_escrito = fprintf(archivo, "###_Nombre: %s\n", plg.nombre);
	if(num_escrito<=0){
		printf("Error al escribir: %s\n", plg.nombre);
		return 0;
	}else{
		num_escrito = fprintf(archivo, "Lados: %d\n", plg.lados);
		if(num_escrito<=0){
			printf("Error al escribir: %d\n", plg.lados);
			return 0;
		}
		return 1;
	}
}

int leerPoligono(FILE* archivo, Poligono* out_plg){
	int check = fscanf(archivo, "###_Nombre: %s\n", out_plg->nombre);
	if(!check){
		printf("Error al leer el nombre del polígono\n");
		return 0;
	}else{
		check = fscanf(archivo, "Lados: %d\n", &(out_plg->lados));
		if(!check){
			printf("Error al leer el número de lados del polígono\n");
		return 0;
		}
		return 1;
	}
}

int main(void){
	Poligono cuadrado = {"Cuadrado", 4};
	Poligono pentagono = cuadrado;
	sprintf(pentagono.nombre, "Pentágono");
	pentagono.lados = 5;
	//Escribimos:
	FILE* salida = fopen("archivo41_Poligonos.txt", "w");
	if(salida){
		if(escribirPoligono(salida, cuadrado)){
			escribirPoligono(salida, pentagono);
		}	
	}
	fclose(salida);
	//Leemos:
	FILE* entrada = fopen("archivo41_Poligonos.txt", "r");
	if(entrada){
		Poligono copias_leidas[2];
		int check = leerPoligono(entrada, &(copias_leidas[0]));
		if(check){
			printf("Leído: Nombre: %s; Lados: %d\n", copias_leidas[0].nombre, 
				copias_leidas[0].lados);
		}
		check = check && leerPoligono(entrada, &(copias_leidas[1]));
		if(check){
			printf("Leído: Nombre: %s; Lados: %d\n", copias_leidas[1].nombre, 
				copias_leidas[1].lados);
		}
	}
	fclose(entrada);
	return 0;
}
