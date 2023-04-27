#include <stdio.h>

int main(){
	int a = -2;
	signed short int b = 3;
	int c = a + b;
	printf("%d + %hi = %d\n", a, b, c);
	//------------------------
	float valor = a/b;
	printf("%d/%hi = %f :-/\n", a, b, valor);
	valor = (float) (a / b);
	printf("%d/%hi = %f :-/\n", a, b, valor);
	valor = ((float) a) / b;
	printf("%d/%hi = %f :-)\n", a, b, valor);
	valor = (float) a / (float) b;
	printf("%d/%hi = %f :-)\n", a, b, valor);
	return 0;
}
