#include <float.h>
#include <stdio.h>

int main(void){
	float a = 1.0;
	printf("Un float tiene %lu bytes, y abarca [%e, %e]\n", sizeof(a), FLT_MIN, FLT_MAX);
	double b = 2.0;
	printf("Un double tiene %lu bytes, y abarca [%le, %le]\n", sizeof(b), DBL_MIN, DBL_MAX);
	long double c = 3.0;
	printf("Un long double tiene %lu bytes, y abarca [%Le, %Le]\n", sizeof(c), LDBL_MIN, LDBL_MAX);
	return 0;
}
