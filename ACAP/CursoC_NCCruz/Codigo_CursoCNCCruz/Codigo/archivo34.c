#include <stdio.h>

int main(){
	for(int i = 0; i<3; i++){
		printf("El valor de i es: %d\n", i);
	}
	//Y no se suele hacer... pero podemos ser muy creativos:
	for(int i = 0, j = 1; i<6 && j<7; i=i+2, j=j+2){
		printf("I vale: %d y J vale: %d\n", i, j);
	}
	return 0;
}
