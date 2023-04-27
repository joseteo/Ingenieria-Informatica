#include <cstdio>
__global__ void kernel(void){}
int main(){
  kernel<<<1, 1>>>();
  printf("Hola mundo!\n");
  return 0;
}
