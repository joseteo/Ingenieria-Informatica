#include <stdio.h>
#include <stdlib.h>

#ifdef _OPENMP
  #include <omp.h>
#else
  #define omp_get_thread_num() 0
#endif
#include <time.h>

extern double *x,*y,a;
extern unsigned int N;

unsigned int N=0;
double a=0.0;
double *x;
double *y;

int main(int argc, char **argv){

  struct timespec cgt1,cgt2; double ncgt; //para tiempo de ejecución

  if(argc<3){
    fprintf(stderr,"Faltan recibir por parametro el tamaño y un numero \n");
    exit(-1);
  }

  N=(unsigned int)atoi(argv[1]);
  a=atof(argv[2]);

  x=(double*)malloc(N*sizeof(double));
  y=(double*)malloc(N*sizeof(double));

  for(int i=0; i<N; i++){
    x[i]=i+1;
    y[i]=i+2;
  }

  clock_gettime(CLOCK_REALTIME,&cgt1);

  for(int i=0; i<N; i++)
    y[i]=a*x[i]+y[i];

  clock_gettime(CLOCK_REALTIME,&cgt2);
  ncgt=(double) (cgt2.tv_sec-cgt1.tv_sec)+
       (double) ((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));

  printf("Tiempo (seg.): %11.9f\n",ncgt);

  return 0;
}
