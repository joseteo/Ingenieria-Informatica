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
   // Debe compilar con la opción ISO C++11 tal y como se indica al inicio del guión de prácticas 
   
   // MUY IMPORTANTE: Las modificaciones que hagamos sobre cadena NO afectan
   // al parámetro actual.
   
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
    
   cout << "Enmarca\n" << "Introduzca un carácter para enmarcar"
        << "y a continuación los caracteres del mensaje usando como terminador el carácter "
        << TERMINADOR <<  "\n";
   
   
   // Almacene en msj el resultado de llamar a la función LeeString
   
   // Enmarcar el mensaje con las funciones apropiadas
}
