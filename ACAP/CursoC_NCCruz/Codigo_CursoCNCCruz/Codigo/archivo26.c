#include <stdio.h>

const int constante = 9;

int main(){
	const int* ptrAConst = &constante;
	int array3D[2][2][2] = {{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}};
	printf("Primera rodaja:\n");
	printf("%d %d\n", array3D[0][0][0], array3D[0][0][1]);
	printf("%d %d\n", array3D[0][1][0], array3D[0][1][1]);
	printf("Segunda rodaja:\n");
	printf("%d %d\n", array3D[1][0][0], array3D[1][0][1]);
	printf("%d %d\n", array3D[1][1][0], array3D[1][1][1]);
	printf("O en crudo...:\n");
	int* ptr = &(array3D[0][0][0]);//Vamos a ver que esta todo contiguo:
	printf("%d, %d, %d, %d, ", *ptr, *(ptr+1), *(ptr+2), *(ptr+3));
	printf("%d, %d, %d, %d\n", ptr[4], ptr[5], ptr[6], ptr[7]);
	int (*otro)[2][2] = array3D;// ESTO ES UN PUNTERO A ARRAY
	printf("%d\n", otro[0][1][1]);
	printf("%d\n", (*(otro + 1))[1][1]);
	return 0;
}
