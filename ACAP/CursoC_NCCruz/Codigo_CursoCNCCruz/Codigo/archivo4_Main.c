#include <stdio.h>

int valorGlobal = 6;

void Saludar(void);//Presentamos esta funcion
				   //pero su codigo solo se
				   //encontrara enlazando

int main(void){
	Saludar();
	printf("Valor Global: %d\n", valorGlobal);
	return 0;
}
