#include <stdio.h>

int main(){
	int a = 1;
	int b = a++;
	int c = ++a;
	printf("A = %d; B = %d; C = %d\n", a, b, c);
	int d;
	d = a+=b;
	printf("A = %d; B = %d; D = %d\n", a, b, d);
	d *= a;
	printf("D = %d\n", d);
	d /= a;
	printf("D = %d\n", d);
	b -= a;
	printf("B = %d\n", b);
	b %= c;
	printf("B = %d\n", b);
	int e = a?16:32;
	printf("Como A=%d, E=%d\n", a, e);
	return 0;
}
