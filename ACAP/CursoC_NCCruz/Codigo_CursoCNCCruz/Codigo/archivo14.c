#include <stdio.h>

int main(void){
	int a = 6, b = 9;
	printf("%d < %d: %d\n", a, b, a<b);
	printf("%d > %d: %d\n", a, b, a>b);
	printf("%d <= %d: %d\n", a, b, a<=b);
	printf("%d >= %d: %d\n", a, b, a>=b);
	printf("%d == %d: %d\n", a, b, a==b);
	printf("%d != %d: %d\n", a, b, a!=b);
	return 0;
}