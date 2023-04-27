#include <stdio.h>

typedef enum BOOL{
	FALSO,
	CIERTO
} bool;

int main(){
	typedef enum Finde{
		Sabado = 6,
		Domingo
	} Finde;
	enum BOOL miVar = CIERTO;
	bool otra = FALSO;
	Finde mio = Domingo;
	Finde otro = mio;
	otro = Sabado;
	printf("Cierto: %d, Falso: %d\n", miVar, otra);
	printf("Finde: Sabado = %d, Domingo = %d\n", otro, mio);
	return 0;
}
