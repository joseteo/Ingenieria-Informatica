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
#include <omp.h>

#define M 4
#define N 5

struct {
  int a[N];
  int b[N];
} s;

int main(int argc, char** argv){

  struct timespec cgt1,cgt2; double ncgt; //para tiempo de ejecución

  int ii,i,x1,x2;
  int R[M];

  srand(time(NULL));
  for(ii=0; ii<N; ii++){
    s.a[ii]= rand() % 10;
  }
  for(ii=0; ii<N; ii++){
    s.b[ii]= rand() % 10;
  }

  clock_gettime(CLOCK_REALTIME,&cgt1);

  for(ii=0; ii<M; ii++){
    x1=0;
    x2=0;
    for(i=0; i<N; i++)
      x1+=((s.a[i])<<1)+ii;
    for(i=0; i<N; i++)
      x2+=((s.b[i]<<1)+s.b[ii])-ii;

    if(x1<x2)
      R[ii]=x1;
    else
      R[ii]=x2;
  }

  clock_gettime(CLOCK_REALTIME,&cgt2);
  ncgt=(double) (cgt2.tv_sec-cgt1.tv_sec)+
       (double) ((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));

  printf("Tiempo (seg.): %11.9f\n",ncgt);

  return 0;
}