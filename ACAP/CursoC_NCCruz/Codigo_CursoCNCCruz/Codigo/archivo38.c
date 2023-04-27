#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
	printf("Esto siempre: %s\n", argv[0]);//Voy a la primera fila
	if(argc<3){//Si no controlamos esto, casi siempre se rompera el programa
		printf("Error, se esperaba un entero y un double\n");
		printf("./prog <entero> <double>\n");
	}else{
		int par1 = atoi(argv[1]);
		double par2 = atof(argv[2]);
		printf("Recibo: %d, %.3lf\n", par1, par2);
	}
	return 0;
}
