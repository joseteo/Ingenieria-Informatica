/* SumaVectoresC.c
 Suma de dos vectores: v3 = v1 + v2

 Para compilar usar (-lrt: real time library, no todas las versiones de gcc necesitan que se incluya -lrt):
       gcc  -O2 SumaVectores.c -o SumaVectores –lrt
       gcc  -O2 –S SumaVectores.c –lrt   //para generar el código ensamblador

 Para ejecutar use: SumaVectoresC longitud
*/

#include <stdlib.h> // biblioteca con funciones atoi(), rand(), srand(), malloc() y free()
#include <stdio.h> // biblioteca donde se encuentra la función printf()
#include <time.h>     // biblioteca donde se encuentra la función clock_gettime()

//Sólo puede estar definida una de las tres constantes VECTOR_ (sólo uno de los ...
//tres defines siguientes puede estar descomentado):
#define VECTOR_LOCAL    // descomentar para que los vectores sean variables ...
                   // locales (si se supera el tamaño de la pila se ...
                   // generará el error "Violación de Segmento")
//#define VECTOR_GLOBAL// descomentar para que los vectores sean variables ...
                   // globales (su longitud no estará limitada por el ...
                   // tamaño de la pila del programa)
//#define VECTOR_DYNAMIC    // descomentar para que los vectores sean variables ...
                   // dinámicas (memoria reutilizable durante la ejecución)
#ifdef VECTOR_GLOBAL
#define MAX 33554432         //=2^25
double v1[MAX], v2[MAX], v3[MAX];
#endif

int main(int argc, char** argv){

  struct timespec cgt1,cgt2; double ncgt; //para tiempo de ejecución

  //Leer argumento de entrada (nº de componentes del vector)
  if (argc<2){
    printf("Faltan nº componentes del vector\n");
    exit(-1);
  }

  unsigned int N = atoi(argv[1]); // Máximo N =2^32-1=4294967295 (sizeof(unsigned int) = 4 B)

  int **v1, **v2, **v3;
  v1 = (int**) malloc(N*sizeof(int*));// malloc necesita el tamaño en bytes
  v2 = (int**) malloc(N*sizeof(int*)); //si no hay espacio suficiente malloc devuelve NULL
  v3 = (int**) malloc(N*sizeof(int*));

  if ( (v1==NULL) || (v2==NULL) || (v3==NULL) ){
    printf("No hay suficiente espacio para los vectores o matriz \n");
    exit(-2);
  }

  for (int i = 0; i < N; i++)
  {
    v3[i] = (int*) malloc(N*sizeof(int));
    v1[i] = (int*) malloc(N*sizeof(int));
    v2[i] = (int*) malloc(N*sizeof(int));

    if ( (v1==NULL) || (v2==NULL) || (v3==NULL) ){
      printf("No hay suficiente espacio para la matriz \n");
      exit(-2);
    }
  }

  srand(time(NULL));
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      v2[i][j] = j + 1;
      v1[i][j] = j + 2;
      v3[i][j] = 0;
    }
  }


  clock_gettime(CLOCK_REALTIME,&cgt1);
  //Calcular suma de vectores
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)
      for(int k=0; k<N; k++)
        v3[i][j] += v1[i][k] * v2[k][j];

  clock_gettime(CLOCK_REALTIME,&cgt2);
  ncgt=(double) (cgt2.tv_sec-cgt1.tv_sec)+
       (double) ((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));

  //Imprimir resultado de la suma y el tiempo de ejecución

  printf("Tiempo (seg.): %11.9f\n",ncgt);
  printf("v3[%d] =  %d\n",0,v3[0][0]);
  printf("v3[%d] =  %d\n",N-1,v3[0][N-1]);

  return 0;
}
