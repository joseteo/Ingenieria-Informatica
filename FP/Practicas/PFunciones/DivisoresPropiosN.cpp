#include <iostream> 
using namespace std;  
   
int main(){    
   int entero, ultimo_dvsor, dvsor, i=0, sum=0;

   cout << "Divisores propios de un entero\n\n";
   
   do{
      cout << "Introduce un numero entero mayor estricto que 0: ";
      cin >> entero;
   }while (entero <= 0);

   dvsor = 1;
   ultimo_dvsor = entero / 2;

	int array[ultimo_dvsor]={};

   while (dvsor <= ultimo_dvsor){
      if (entero % dvsor == 0){
         array[i]= dvsor;
      	i++;
		}
      dvsor++;
   }
   
   for(int j=0; j < i; j++)
   	sum += array[j];

   
   if(sum == entero)
   	cout << "\nEl numero es perfecto";
   else if(sum < entero)
   	cout << "\nEl numero es deficiente";
   else if(sum > entero)
   	cout << "\nEl numero es abundante";
   
   
   
}
