#include <stdlib.h>
#include <stdio.h>

#ifdef _OPENMP
  #include <omp.h>
#else
  #define omp_get_thread_num() 0
#endif

int main(int argc, char **argv){
  double tiempo_inicial,tiempo_final, tiempo_total;

  if(argc<2){
    printf("Faltan n compoentes del vector\n");
    exit(-1);
  }

  unsigned int N=atoi(argv[1]);   //El maximo de N es 2^32 -1 =4294967295 sizeof(unsigned int)=4 B
  int i,j,suma;
  int *v,*mv,**m;

  v=(int*) malloc(N*sizeof(int));
  mv=(int*) malloc(N*sizeof(int));
  m=(int**) malloc(N*sizeof(int *));

  if(v==NULL || mv==NULL || m==NULL){
    printf("Fallo en la reserva de espacio para la amtriz y el vector\n");
    exit(-2);
  }

  for(i=0;i<N;i++){
    m[i]=(int *) malloc(N*sizeof(int));
    if(m[i]==NULL){
      printf("Fallo en la reserva de espacio para la amtriz y el vector\n");
      exit(-3);
    }
  }

  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      if(i<=j)
        m[i][j]=9;
      else
        m[i][j]=0;
    }
    v[i]=2;
    mv[i]=0;
  }

  #pragma omp parallel private(j)
  {
    tiempo_inicial= omp_get_wtime();

    #pragma omp for firstprivate(suma) schedule(runtime)
    for(i=0;i<N;i++){
      suma=0;
      for(j=0;j<N;j++){
        suma+=m[i][j]*v[i];
      }
      #pragma single
        mv[i]=suma;
    }

    tiempo_final=omp_get_wtime();
  }

  tiempo_total= tiempo_final-tiempo_inicial;
  printf("Tamaño de la matriz y vector= %d\t / Tiempo(seg.) %11.9f\n",N,tiempo_total);

  printf("matriz_x_vector[%d]= %d\n",0,mv[0]);
  printf("matriz_x_vector[%d]= %d\n",N-1,mv[N-1]);

  //liberamos los valores de la matriz y liberamos los espacios de la matriz y los vectores
  for(i=0;i<N;i++)
    free(m[i]);
  free(m);
  free(v);
  free(mv);
  return 0;
}
