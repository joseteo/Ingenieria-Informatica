#include <iostream>

using namespace std;

int main(){
   const int MAX_FIL_IZDA = 10, MAX_COL = 10;
   const int MAX_FIL_DCHA = MAX_COL, MAX_COL_DCHA = 30;
   
   int util_fil_izda, util_col_izda;
   int util_fil_dcha, util_col_dcha;
   int util_fil_prod, util_col_prod;  // util_fil y util_col para cada matriz
   
   int izda[MAX_FIL_IZDA][MAX_COL];
   int dcha[MAX_FIL_DCHA][MAX_COL_DCHA];
   int prod[MAX_FIL_IZDA][MAX_COL_DCHA];

   // No etiquetamos las entradas de datos porque suponemos 
   // que leemos de un fichero
   // Supondremos que util_fil y util_col son > 0

   cin >> util_fil_izda;
   cin >> util_col_izda;

   for (int i = 0; i < util_fil_izda; i++)
      for (int j = 0; j < util_col_izda; j++)
         cin >> izda[i][j];

   util_fil_dcha = util_col_izda;
   cin >> util_col_dcha;

   for (int i = 0; i < util_fil_dcha; i++)
      for (int j = 0; j < util_col_dcha; j++)
         cin >> dcha[i][j];
   
   util_fil_prod = util_fil_izda;
   util_col_prod = util_col_dcha;
   
   for (int i = 0; i < util_fil_prod; i++) 
	  for (int j = 0; j < util_col_prod; j++)
	  	prod[i][j]=0;
   
	for (int i = 0; i < util_fil_prod; i++) {
	  for (int j = 0; j < util_col_prod; j++) {
	      for (int k = 0; k < util_fil_dcha; k++) {
	         prod[i][j] += izda[i][k] * dcha[k][j];
	      }
	  }
	}
   
   cout << "\n\n";
   cout << "Matriz prod:\n";
   
   for (int i=0; i<util_fil_prod; i++){
      cout << "\n";
      
      for (int j=0; j<util_col_prod; j++){
      	cout << prod[i][j] << "\t";
		}
         
   }  
  
   cout << "\n\n";

   // 3 4    9 7 4 5    2 18 2 12    7 9 1 5      2      1 2   3 4   5 6   7 8 
   /*
   Debe salir:
   
   85      110
   150     184
   74      96
   */
}
