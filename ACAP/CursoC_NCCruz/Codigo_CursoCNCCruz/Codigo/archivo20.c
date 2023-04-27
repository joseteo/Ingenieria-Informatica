#include <stdio.h>

typedef union LaUnion{
	int campo1;
	int campo2[3];
	union{
		int campoA;
		int campoB;
	} campo3;
} MiUnion;

int main(){
	union LaUnion a = {.campo2={1, 2, 3}}; // C99
	MiUnion b;
	b.campo3.campoA = 7; // A mano
	union LaUnion c = b;
	printf("A: %d, %d, %d\n", a.campo2[0], a.campo2[1],
		a.campo2[2]);
	printf("B: %d\n", b.campo3.campoA);
	printf("C: %d\n", c.campo1);
	c = a;
	printf("C: %d, %d, %d\n", c.campo2[0], c.campo2[1],
		c.campo2[2]);
	return 0;
}
