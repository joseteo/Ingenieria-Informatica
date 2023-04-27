#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <curand_kernel.h>
#include <ctime>

__global__ void encontrar_maximo(double* numeros, double* max, int* mutex, int n) {
  int i = threadIdx.x + blockIdx.x * blockDim.x;
  int stride = gridDim.x * blockDim.x;    //estos dos permiten hacer que si el tamaño de bloque es 100 y el de hilos es 10,
  int offset = 0;   // con estos el primer thread se encargará de la primera entrada del vector global de la 101 de la 201 en adelante,
                    //lo que lo hace mas flexible y escalable

  __shared__ double cache[512];

  double temp = -1;
  while(i + offset < n){
    temp = fmax(temp, numeros[i + offset]);
    offset += stride;
  }

  cache[threadIdx.x] = temp;

  __syncthreads();

  //reduccion del vector, y al finalizar el mayor valor de entre los 512 se encontrara en la primera posicion de cache
  int j = blockDim.x/2;
  while(j != 0){
    if(threadIdx.x < j){
      cache[threadIdx.x] = fmax(cache[threadIdx.x], cache[threadIdx.x + j]);
    }

    __syncthreads();
    j /= 2;
  }

  if(threadIdx.x == 0){
    while(atomicCAS(mutex, 0, 1) != 0)  // bloquea el mutex //sentencia atomica entre distintas hebras, el mutex se usa para la exclusion,
      *max = fmax(*max, cache[0]);      //y sirve como llave para usar la variable global sin riesgo

      //printf("MAXIMO= %lf\n", *max);
    atomicExch(mutex, 0); //libera el mutex
  }
}
/*
__global__ void cudaRand(double* numeros){
  int i = threadIdx.x + blockIdx.x * blockDim.x;

  curandState state;
  curand_init((unsigned long long)clock(), 0, 0, &state);

  printf("numero[%d] = %lf\n", i, numeros[i]);
  numeros[i] = curand_uniform_double(&state);
}*/

int main(void)
{
  int N = 1024*1024;
  double *x, *d_x, *x_max, *d_x_max;
  int* mutex;

  //alojar memoria
  x = (double*)malloc(N*sizeof(double));
  x_max = (double*)malloc(sizeof(double));
  cudaMalloc((void**)&d_x, N * sizeof(double));
  cudaMalloc((void**)&d_x_max, sizeof(double));
  cudaMalloc((void**)&mutex, sizeof(int));
  cudaMemset(mutex, 0, sizeof(double));
  cudaMemset(d_x_max, 0, sizeof(double)); //inicializar el maximo a 0 para evitar basura inicial

  cudaEvent_t start, stop;
  cudaEventCreate(&start);
  cudaEventCreate(&stop);


  //cudaRand <<< 1, N >>> (d_x); //genera numeros random
  for(int i=0; i<N; i++)
    x[i] = N*double(rand()) / RAND_MAX;

  cudaEventRecord(start);

  cudaMemcpy(d_x, x, N*sizeof(double), cudaMemcpyHostToDevice);

  for(int i=0; i<1000; i++)
  encontrar_maximo <<< 512, 512 >>> (d_x, d_x_max, mutex, N); //512 es gridSize, y 512 es blockSize

  cudaMemcpy(x_max, d_x_max, sizeof(double), cudaMemcpyDeviceToHost);

  cudaEventRecord(stop);

  cudaEventSynchronize(stop);
  float milliseconds = 0;
  cudaEventElapsedTime(&milliseconds, start, stop);


  /*for (int i = 0; i < N; i++) {
    printf("Elementos Aleatorios Del Vector: %lf\n", x[i]);
  }*/

  printf("Maximo elemento GPU: %lf\n", *x_max);
  printf("Tiempo GPU: %fms\n", milliseconds);

  cudaEventRecord(start);

  for(int i=0; i<1000; i++){
    *x_max = -1.0;
    for(int i=0; i<N; i++){
      if(x[i] > *x_max){
        *x_max = x[i];
      }
    }
  }

  cudaEventRecord(stop);

  cudaEventSynchronize(stop);
  milliseconds = 0;
  cudaEventElapsedTime(&milliseconds, start, stop);

  printf("Maximo elemento CPU: %lf\n", *x_max);
  printf("Tiempo CPU: %fms\n", milliseconds);

  //liberar memoria
  free(x);
  free(x_max);
  cudaFree(d_x);
  cudaFree(d_x_max);
  cudaFree(mutex);
}
