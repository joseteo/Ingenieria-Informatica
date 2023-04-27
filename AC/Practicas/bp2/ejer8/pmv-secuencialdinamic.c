#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <malloc.h>

#define DINAMIC

int main(int argc, char const *argv[]){

  if(argc != 2){
    printf("Error introduccion argumentos %s", argv[0]);
    exit(-1);
  }

  struct timespec time1, time2;
  double timeResult;
  int N = atoi(argv[1]);

  #ifdef DINAMIC
    int **matrix;
    int *vector;
    int *vectorResult;
    matrix = (int**) malloc(N * sizeof(int*));
    for(int i=0; i<N; i++)
      matrix[i]=(int*) malloc(N * sizeof(int));

    vector=(int*) malloc(N * sizeof(int));
    vectorResult=(int*) malloc(N * sizeof(int));
    printf(" DINAMIC \n");
  #endif

  for(int i=0; i<N; i++){
    vector[i]=i;
    for(int j=0; j<N;j++)
      matrix[i][j]=i+j;
  }

  //Medicion del tiempo
  clock_gettime(CLOCK_REALTIME, &time1);
  //Calculo del vector resultante
  for(int i=0; i<N; i++){
    int suma=0;
    for(int j=0; j<N; j++){
      suma+=matrix[i][j]*vector[j];
    }

    vectorResult[i]=suma;
  }
  clock_gettime(CLOCK_REALTIME, &time2);
  timeResult= (double) (time2.tv_sec-time1.tv_sec) + (double) (time2.tv_nsec-time1.tv_nsec) / (1.e+9);

  printf("Tiempo: %11.9f\t / Tamanio vectores: %u\n",timeResult,N);
  if(N<15)
    for(int i=0; i<N; i++){
      printf("VECTORRESULT[%d] = %d \n",i,vectorResult[i]);
    }
  else{
    printf("VECTORRESULT[0] = %d ",vectorResult[0]);
    printf("VECTORRESULT[%d] = %d \n",N-1,vectorResult[N-1]);
  }

  #ifdef DINAMIC
    for(int i=0; i<N; i++)
      free(matrix[i]);

    free(matrix);
    free(vector);
    free(vectorResult);
  #endif
}
