#include <iostream> 
using namespace std;  
   
int main(){    
   int entero, ultimo_dvsor, dvsor, i=0;

   cout << "Divisores de un entero\n\n";
   
   do{
      cout << "Introduce un numero entero mayor estricto que 0: ";
      cin >> entero;
   }while (entero <= 0);

   dvsor = 2;
   ultimo_dvsor = entero / 2;

	int array[ultimo_dvsor]={};

   cout << "\n\nDivisores de " << entero << ":\n\n";

   while (dvsor <= ultimo_dvsor){
      if (entero % dvsor == 0){
         array[i]= dvsor;
      	i++;
		}
      dvsor++;
   }
   
   for(int j=0; j < i; j++)
   	cout << array[j] << " ";
}
