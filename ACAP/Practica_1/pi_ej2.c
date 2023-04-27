// Calculo aproximado de PI mediante la serie de Leibniz e integral del cuarto de circulo
// https://es.wikipedia.org/wiki/Serie_de_Leibniz
// N.C. Cruz, Universidad de Granada, 2022

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <limits.h>

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

double get_wall_time(){
    struct timeval time;
    if (gettimeofday(&time,NULL)){
        printf("Error de medición de tiempo\n");
        return 0;
    }
    return (double) time.tv_sec + (double) time.tv_usec * 0.000001;
}

int main(int argc, char* argv[]){
	if(argc!=2){	//El primer argumento siempre es el nombre del programa
		printf("Uso: ./prog esfuerzo\n");
	}else{
		long int steps = atoi(argv[1]);
		double contador;
		if(steps<=0){
			printf("El número de iteraciones debe ser un entero positivo!\n");
		}else{
			double instanteA = get_wall_time();
			double pi = piLeibniz(steps);
			double instanteB = get_wall_time();
			printf("PI por la serie de G. Leibniz [%ld iteraciones] = %f\t%lf\n", steps, instanteB-instanteA, pi);
			instanteA=instanteB=0;
			instanteA = get_wall_time();
			pi = piRectangles(steps);
			instanteB = get_wall_time();
			printf("PI por integración de círculo [%ld intervalos] = %f \t%lf\n", steps, instanteB-instanteA, pi);

			for (int i = 0; (-1 < i) && (i < INT_MAX); i+=(INT_MAX/10)){
				double tIni3 = get_wall_time();
				double pi = piLeibniz(i);
				double pi2 = piRectangles(i);
				double tEnd3 = get_wall_time();

				printf("El tiempo de la ejecicion %d es: %.3lf (s)\n", i, tEnd3-tIni3);

				double tiempo = tEnd3 - tIni3;
				contador+=tiempo;
			}

			double media = contador/10;
			printf("La media seria: %f (s)\n", media);

		}
	}
	return 0;
}
