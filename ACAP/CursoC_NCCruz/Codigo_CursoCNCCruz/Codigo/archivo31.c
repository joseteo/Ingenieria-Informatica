#include <stdio.h>
#include <stdlib.h>

int main(){
	int* vec = malloc(sizeof(int)*2);
	if(vec){
		vec[0] = 0;
		vec[1] = 1;
		if(!vec[0]){
			printf("VEC[0] es 0\n");
		}else if(vec[1]){
			printf("VEC[0] es <> 0\n");
		}else if (0){
			printf("Y aqui si que no entramos nunca\n");
		}
	}else{
		printf("No se ha podido reservar memoria\n");
	}
	free(vec);
	return 0;
}
