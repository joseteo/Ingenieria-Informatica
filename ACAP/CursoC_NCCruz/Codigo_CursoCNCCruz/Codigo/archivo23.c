#include <stdio.h>

void func(int* par){
	printf("func: Recibo esta direccion: %p\n", par);
	int leo = (*par);//Leo el puntero y me copio el valor
	leo = leo + 1;//Incremento mi copia
	(*par) = leo;//Actualizo lo que leo
	//Todo esto equivale a: (*par)++
}

int main(){
	int valor = 5;
	int * ptr_Valor = &valor;
	printf("Valor: %d (estoy en: %p)\n", valor, &valor);
	func(ptr_Valor);//Voy a modificar el valor!
	printf("Valor: %d (sigo en: %p)\n", valor, ptr_Valor);
	printf("Y yo, puntero, tambien tengo direccion: %p\n", &ptr_Valor);
	printf("En este PC x64 un puntero a entero ocupa: %lu bytes\n", 
		sizeof(int*));
	printf("\t y uno a double: %lu bytes, y uno a puntero entero: %lu bytes...\n", 
		sizeof(double), sizeof(int**));
	return 0;
}
