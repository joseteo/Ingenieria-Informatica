#include <iostream>

using namespace std;

int main(){
   const char TERMINADOR = '#';
   const int MAX_NUM_CARACT = 3e6;
   char v[MAX_NUM_CARACT];
   char a_borrar;
   char car;
   int i, util;

   cout << "\nAQUIIIIIIIII\n";
   car = cin.get();
   i = 0;
   
   while (car != TERMINADOR){
      v[i] = car;
      car = cin.get();
      i++;
   }
   
   util = i;
   
   a_borrar = cin.get();
   
   int escr, lect;

   escr = 0;

   for (lect = 0; lect < util; lect++){
      if (v[lect] != a_borrar){
         v[escr] = v[lect];
         escr++;
      }
   }

   util = escr;

   for (int i = 0; i < util; i++)
      cout << v[i] ;   
		
	cin.get();   
}

