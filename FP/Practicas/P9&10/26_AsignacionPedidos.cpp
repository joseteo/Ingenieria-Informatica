// Asignación de pedidos a técnicos

#include <iostream>
using namespace std;

int main(){
   const int MAX_ASIGNAC = 20;
   int num_asignac;
   const int MAX_COSTE = 100;
   
   int tarifas[MAX_ASIGNAC][MAX_ASIGNAC];  
   bool asignac[MAX_ASIGNAC][MAX_ASIGNAC];
   bool pedido_ya_asignado[MAX_ASIGNAC];
   
   int pos_min, min, costo;
   
   cout << "\nAsignaciones de técnicos a pedidos. Introduzca número de "
        << "técnicos.\nDebe ser igual al número de pedidos y menor o igual que "
        << MAX_ASIGNAC << "\n"
        << "A continuación introduzca la matriz de tarifas\n";
   cin >> num_asignac;
   cout << "\n";
   
   for (int i = 0; i < num_asignac; i++)
      for (int j = 0; j < num_asignac; j++)
         cin >> tarifas[i][j];

   for (int i = 0; i < num_asignac; i++)
      pedido_ya_asignado[i] = false;

   for (int i = 0; i < num_asignac; i++)
      for (int j = 0; j < num_asignac; j++)
         asignac[i][j] = false;

   costo = 0;
   
   for (int i = 0; i < num_asignac; i++){
   	min = 3e6;
   	for (int j = 0; j < num_asignac; j++)
   		if(!pedido_ya_asignado[j])
   			if(tarifas[i][j] < min){
   				min = tarifas[i][j];
   				pos_min = j;
				}

		asignac[i][pos_min] = true;
		pedido_ya_asignado[pos_min] = true;
		costo += tarifas[i][pos_min];
	}
   /*
   Calcular la matriz asignac y el costo total
   */
   
   cout << "\n\nMatriz de asignac:\n";
   
   for(int i = 0; i < num_asignac; i++){   	
   	for(int j = 0; j < num_asignac; j++)
   	  cout << asignac[i][j] << "\t";
   	
   	cout << "\n";
   }

   cout << "\nCoste total: " << costo;


   // Ejemplo de entrada:
   // 3    21 12 31     16 14 25     12 18 20
   
   // Salida:
   /*
      0 1 0
      1 0 0
      0 0 1
      48
   */
   
}
