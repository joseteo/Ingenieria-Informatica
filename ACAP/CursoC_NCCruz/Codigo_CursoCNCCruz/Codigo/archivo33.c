#include <stdio.h>

int main(){
	int val = 0;
	while(val<2){
		printf("Hola\n");
		val++;//Modifico o no saldre nunca...
		if(val==3){//Esto sobra, pero nos enseña
			break;//que con un break podriamos salir
			//tanto de un while como de un do-while
			//obviando la condicion
		}
	}
	do{
		//continue;//Si no lo quitamos pasariamos
		//directamente a evaluar y no hariamos nada
		printf("Esto solo lo repito una vez\n");
		val++;//aunque la condicion no se cumpla
		//    Como garantiza un do-while
	}while(val<2);
	return 0;
}
