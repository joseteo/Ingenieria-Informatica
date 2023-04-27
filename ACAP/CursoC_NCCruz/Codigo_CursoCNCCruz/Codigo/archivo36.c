#include <stdio.h>

int sumaDos(int base){
	int resultado = base + 2;
	return resultado;
}

int main(){
	int valor = 0;
	for(int i = 0; i<3; i++){
		valor = sumaDos(valor);
	}
	printf("Valor: %d\n", valor);
	return 0;
}
