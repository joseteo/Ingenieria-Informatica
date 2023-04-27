#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <curand_kernel.h>
#include <ctime>
#include <vector>

__global__ void producto_matrices(double* m_a, double* m_b, double* m_r, int n) {
  int fila = threadIdx.y + blockIdx.y * blockDim.y;
  int col = threadIdx.x + blockIdx.x * blockDim.x;

  double temp = 0;

  if(fila < n && col < n){
    for(int i=0; i < n; i++){
      temp += m_a[fila * n + i] * m_b[i * n + col];
    }
  }

  m_r[fila * n + col] = temp;
}

int main(void)
{
  printf("Introduce las dimensiones de las matrices (recuerda si las dimensiones son matriz1 AxB y matriz2 CxD, la B y la C han de ser iguales)\n");
  int A=0, B=0, C=0, D=0;

  printf("\nA=");
  A = scanf("%d", &A);
  printf("\nB=");
  B = scanf("%d", &B);
  printf("\nC=");
  C = scanf("%d", &C);
  printf("\nD=");
  D = scanf("%d", &D);

  if(B!=C){
    printf("Introduce las dimensiones de las matrices (recuerda si las dimensiones son matriz1 AxB y matriz2 CxD, la B y la C han de ser iguales)\n");
    printf("\nA=");
    A = scanf("%d", &A);
    printf("\nB=");
    B = scanf("%d", &B);
    printf("\nC=");
    C = scanf("%d", &C);
    printf("\nD=");
    D = scanf("%d", &D);
  }
  int N = (A > B) ? ((A > D) ? A : D) : (B > D) ? B : D; //si el maximo es A si el maximo es B o es D
  int size = N*N;
  double *m_a, *d_m_a, *m_b, *d_m_b, *m_r, *d_m_r;

  //alojar memoria
  m_r = (double*)malloc(sizeof(double));
  m_a = (double*)malloc(A*B * sizeof(double));
  m_b = (double*)malloc(C*D * sizeof(double));
  cudaMalloc((void**)&d_m_r, sizeof(double));
  cudaMalloc((void**)&d_m_a, A*B * sizeof(double));
  cudaMalloc((void**)&d_m_b, C*D * sizeof(double));
  cudaMemset(d_m_r, 0, sizeof(double));

  cudaEvent_t start, stop;
  cudaEventCreate(&start);
  cudaEventCreate(&stop);

  for(int i=0; i < A*B; i++)
    m_a[i] = double(rand()%(A*B)) / (A*B);

  for(int i=0; i < C*D; i++)
    m_b[i] = double(rand()%(C*D)) / (C*D);


  cudaEventRecord(start);

  cudaMemcpy(d_m_a, m_a, N*sizeof(double), cudaMemcpyHostToDevice);
  cudaMemcpy(d_m_b, m_b, N*sizeof(double), cudaMemcpyHostToDevice);

  dim3 threadsPerBlock(N, N);
  dim3 blocksPerGrid(1, 1);
    if (N*N > 512){
      threadsPerBlock.x = 512;
      threadsPerBlock.y = 512;
      blocksPerGrid.x = ceil(double(N)/double(threadsPerBlock.x));
      blocksPerGrid.y = ceil(double(N)/double(threadsPerBlock.y));
    }

  producto_matrices <<< blocksPerGrid, threadsPerBlock >>> (d_m_a, d_m_b, d_m_r, N); //512 es gridSize, y 512 es blockSize

  cudaMemcpy(m_r, d_m_r, size*sizeof(double), cudaMemcpyDeviceToHost);

  cudaEventRecord(stop);

  cudaEventSynchronize(stop);
  float milliseconds = 0;
  cudaEventElapsedTime(&milliseconds, start, stop);

  for (int i=0; i < A*D; i++)
      printf("%lf\n", *m_r);

  printf("Tiempo GPU: %fms\n", milliseconds);

  cudaEventRecord(start);

  double *cpu_m_r;
  cpu_m_r = (double*)malloc(sizeof(double));
  double sum;
  for (int i=0; i<A*D; i++){
    sum += m_a[i]*m_b[i];
    cpu_m_r[i] = sum;
  }

  cudaEventRecord(stop);

  cudaEventSynchronize(stop);
  milliseconds = 0;
  cudaEventElapsedTime(&milliseconds, start, stop);

  for (int i=0; i < size; i++)
    printf("%lf\n", *cpu_m_r);

  printf("Tiempo CPU: %fms\n", milliseconds);

  //liberar memoria
  free(m_r);
  free(d_m_r);
  free(cpu_m_r);
  cudaFree(m_a);
  cudaFree(d_m_a);
  cudaFree(m_b);
  cudaFree(d_m_b);
}
