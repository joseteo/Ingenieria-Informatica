#include <random>   // para la generación de números pseudoaleatorios
#include <chrono>   // high_resolution_clock (para la semilla)
#include <cstdlib>  // srand (para la semilla)
#include <iostream>
using namespace std;


class GeneradorAleatorioEnteros{
private:
   mt19937 generador_mersenne;   // Mersenne twister
   uniform_int_distribution<int>  distribucion_uniforme;

   unsigned long long Nanosec(){
      auto t = chrono::high_resolution_clock::now().time_since_epoch();
      unsigned long long nanosec = t.count();
      
      return nanosec;
   }
   
public:
   GeneradorAleatorioEnteros()
      :GeneradorAleatorioEnteros(0, 1){
   }
   
   GeneradorAleatorioEnteros(int min, int max){
      const int A_DESCARTAR = 70000; // Panneton et al. ACM TOMS Volume 32 Issue 1, March 2006
      static bool primera_vez = true;
      
      // El siguiente condicional es necesario si se van a crear varios objetos
      // generadores durante la ejecución del programa:
      
      if (primera_vez){
         auto semilla_inicial = Nanosec();
         srand(semilla_inicial);   // casting a unsigned int
         primera_vez = false;
      }
      
      auto semilla = rand();
      generador_mersenne.seed(semilla);
      generador_mersenne.discard(A_DESCARTAR);
      distribucion_uniforme = uniform_int_distribution<int> (min, max);
   }

   int Siguiente(){
      return distribucion_uniforme(generador_mersenne);
   }
};



int main(){  
   ......

   for (int i = 0; i < 4; i++){
      ......
   }

}
