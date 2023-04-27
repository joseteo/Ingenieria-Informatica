#include <stdio.h>

int main(void){
	int a = 0, b = 1;
	printf("%d && %d = %d\n", a, b, a && b);
	printf("%d || %d = %d\n", a, b, a || b);
	printf("!%d = %d ; !%d = %d\n", a, !a, b, !b);
	printf("%d && %d = %d\n", 7, 1, 7 && 1);
	printf("!%d = %d; !%d = %d; !%d = %d\n", 7, !7, -3, !-3, 0, !0);
	return 0;
}
