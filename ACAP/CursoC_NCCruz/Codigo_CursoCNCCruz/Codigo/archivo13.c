#include <stdio.h>

int main(){
	int a = 1, b = 3;
	printf("%d + %d = %d\n", a, b, a + b);
	printf("%d - %d = %d\n", a, b, a - b);
	printf("%d * %d = %d\n", a, b, a * b);
	printf("%d / %d = %d\n", a, b, a / b);
	printf("%d %% %d = %d\n", a, b, a % b);
	printf("-%d = %d; - %d = %d\n", a, -a, b, -b);
	printf("-%d + %d = %d\n", a, b, -a + b);
	printf("-(%d + %d) = %d\n", a, b, -(a + b));
	return 0;
}
