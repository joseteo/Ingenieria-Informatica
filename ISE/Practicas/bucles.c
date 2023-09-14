#include <stdio.h>

float a=0.3; float b=0.8; float c=0.1;

void main(void){
	unsigned long i;
	for (i=0;i<160000000;i++)
		a=a*b/(1+c);
	bucle1(); bucle1(); bucle2();
}

void bucle1(void){
	unsigned long i;
	for (i=0;i<40000000;i++){
		c=(c+c*c)/(1+a*c);c=a*b*c;
	}
	for (i=1;i<=5;i++)
		bucle3();
}

void bucle2(void){
	unsigned long i;
	for (i=0;i<10000000;i++){
		c=(c+c*c+c*c*c)/(1+a*c*c);
		c=a*b*c;
	}
	for (i=1;i<=8;i++)
		bucle3();
}

void bucle3(void){
	unsigned long i;
	for (i=0;i<2000000;i++){
		c=a*b*c;
		c=1/(a+b*c);
	}
	salida();
}

void salida(void){
	printf("A: %f B: %f C: %f\n\n", a, b, c);
}
