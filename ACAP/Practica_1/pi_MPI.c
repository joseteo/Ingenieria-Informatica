// Calculo aproximado de PI mediante la serie de Leibniz e integral del cuarto de circulo
// https://es.wikipedia.org/wiki/Serie_de_Leibniz
// N.C. Cruz, Universidad de Granada, 2022

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <limits.h>
#include <mpi.h>

#define TAG_RECTANGLE 1
#define TAG_LEIBNIZ 2

double get_wall_time(){
    struct timeval time;
    if (gettimeofday(&time,NULL)){
        printf("Error de medición de tiempo\n");
        return 0;
    }
    return (double) time.tv_sec + (double) time.tv_usec * 0.000001;
}

double piLeibniz(int steps){
	double partpi = 0.0;
	double num = 1.0;
	double denom = 1.0;
	for(int i = 0; i<steps; i++){
		partpi += num/denom;
		num = -1.0*num; // Alternamos el signo
		denom += 2.0;
	}
	return 4.0*partpi;
}

double piRectangles(int intervals){
	double width = 1.0/intervals;
	double sum = 0.0, x;
	for(int i = 0; i<intervals; i++){
		x = (i + 0.5)*width;
		sum += 4.0/(1.0 + x*x);
	}
	return sum*width;
}

void calculo_PI(int steps, int rank, int size, double *leib, double *rect){
	double partpi = 0.0;
	double num = 1.0;
	double denom = 1.0 + 2.0*rank*steps/size;

	double width = 1.0/steps;
	double sum = 0.0, x;

	double buffer_l=0;
	double buffer_r=0;
	MPI_Status status;

	double instanteA = get_wall_time();
	for(int i = rank*steps/size; i<(steps/size + rank*steps/size); i++){
		partpi += num/denom;
		num = -1.0*num;
		denom += 2.0;
		x = (i + 0.5)*width;
		sum += 4.0/(1.0 + x*x);
	}

	buffer_l= 4.0*partpi;
	double instanteB = get_wall_time();

	*leib = buffer_l;
	*rect = buffer_l;
	//printf("\nFURULA Y VALE: %f", *leib);
	printf("\nCalculo de PI con %d procesadores [%d intervalos] = %f LEIBNIZ= %lf RECTANGLES= %lf", size, steps, instanteB-instanteA, *leib, *rect);
}

int main(int argc, char* argv[]){
	int steps = INT_MAX;
  MPI_Init(&argc, &argv);
	MPI_Status status;
	int rank, size;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	double *buf_suma_l = 0, *buf_suma_r = 0;
	double buffer_l, buffer_r, *leib, *rect;
	if(rank==0){
		if(argc!=2){	//El primer argumento siempre es el nombre del programa
			printf("Uso: ./prog esfuerzo\n");
		}else{
			steps = atoi(argv[1]);
			double contador;
			if(steps<=0){
				printf("El número de iteraciones debe ser un entero positivo!\n");
			}else{
				buf_suma_l = malloc(sizeof(double)*steps);
				buf_suma_r = malloc(sizeof(double)*steps);
				int workSize = steps/size;
				int offset = steps % size;
				int start, quantity;
				for(int i = 1; i<size; i++){//Reparto desde 1 porque yo tambien voy a trabajar
					start = i*workSize + (i<offset?i:offset);
					quantity = workSize + (i<offset);//printf("[%d, (%d) => %d) \n", start, quantity, start+quantity);
					MPI_Send(&buffer_l, 1, MPI_DOUBLE, 0, TAG_LEIBNIZ, MPI_COMM_WORLD);
					MPI_Send(&buffer_r, 1, MPI_DOUBLE, 0, TAG_RECTANGLE, MPI_COMM_WORLD);
				}

				quantity = workSize + (0<offset);//Soy el 0, asi que se que empiezo en 0
				double instanteA = get_wall_time();
				for (int i = 0; (-1 < i) && (i < INT_MAX); i+=(INT_MAX/10)){
					double tIni3 = get_wall_time();
					//double pi = piLeibniz(i);
					//double pi2 = piRectangles(i);
					calculo_PI(steps, rank, size, &leib, &rect);
					double tEnd3 = get_wall_time();

					double tiempo = tEnd3 - tIni3;
					contador+=tiempo;
				}

				double media = contador/10;
				printf("\nMEDIA= %f\n", media);

				double instanteB = get_wall_time();


				for(int i = 1; i<size; i++){
					MPI_Recv(&buf_suma_l[i], 1, MPI_DOUBLE, MPI_ANY_SOURCE, TAG_LEIBNIZ, MPI_COMM_WORLD, &status);
					MPI_Recv(&buf_suma_r[i], 1, MPI_DOUBLE, MPI_ANY_SOURCE, TAG_RECTANGLE, MPI_COMM_WORLD, &status);
				}

				free(buf_suma_l);
				free(buf_suma_r);

			}
		}
	}else{
		MPI_Send(&buffer_l, 1, MPI_DOUBLE, 0, TAG_LEIBNIZ, MPI_COMM_WORLD);
		MPI_Send(&buffer_r, 1, MPI_DOUBLE, 0, TAG_RECTANGLE, MPI_COMM_WORLD);
	}
	MPI_Finalize();
	return 0;
}
