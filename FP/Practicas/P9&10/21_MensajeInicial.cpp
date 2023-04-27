#include <iostream>
#include <string>
using namespace std;


string LeeString(char terminador){
   string cadena;
   char caracter;
   
   caracter = cin.get();
   
   while (caracter != terminador){
      cadena.push_back(caracter);
      caracter = cin.get();
   }
   
   return cadena;
}

string EliminaUltimos(string cadena, char a_borrar){
   // Debe compilar con la opci�n ISO C++11 tal y como se indica al inicio del gui�n de pr�cticas 
   
   // MUY IMPORTANTE: Las modificaciones que hagamos sobre cadena NO afectan
   // al par�metro actual.
   
   while (! cadena.empty() && cadena.back() == a_borrar)
      cadena.pop_back();

   /*    
   Otra forma:
   
      int ultimo = cadena.size() - 1;
   
      while (ultimo >= 0 && cadena[ultimo] == a_borrar){
         cadena.erase(ultimo);
         ultimo--;
      }
   */         
   
   return cadena;
}

int main(){
   char car_marco, car; 
   const char TERMINADOR = '@';
   string msj;
    
   cout << "Enmarca\n" << "Introduzca un car�cter para enmarcar"
        << "y a continuaci�n los caracteres del mensaje usando como terminador el car�cter "
        << TERMINADOR <<  "\n";
   
   
   // Almacene en msj el resultado de llamar a la funci�n LeeString
   
   // Enmarcar el mensaje con las funciones apropiadas
}
