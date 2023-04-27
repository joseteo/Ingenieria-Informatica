#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv){
	srand(time(0));//Si me comentas, veras siempre las mismas salidas
	int valRand = rand(); 
	printf("Entero aleatorio entre 0 y RAND_MAX: %d\n", valRand);
	valRand = rand() % 6;
	printf("Entero aleatorio entre 0 y 5: %d\n", valRand);
	valRand = (rand()%(10-3+1)) + 3;
	printf("Entero aleatorio entre 3 y 10: %d\n", valRand);
	printf("Y ahora reales...");
	double realRand = ((double) rand() / RAND_MAX);
	printf("Real aleatorio entre 0 y 1: %.3lf\n", realRand);
	realRand = ((double) rand() / RAND_MAX)*30.0;
	printf("Real aleatorio entre 0 y 30: %.3lf\n", realRand);
	realRand = ((double) rand() / RAND_MAX)*(40.-10.)+10.0;
	printf("Real aleatorio entre 10 y 40: %.3lf\n", realRand);
	return 0;
}
