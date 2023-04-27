#include <iostream>

using namespace std;

class Dinero{
private:
   long long eur_enteros  = 0;  // Tiene sentido un valor por defecto
   long long cent_enteros = 0;

   bool EsCorrecta(int cantidad){
      return cantidad >= 0;
   }
public:      
   long long Euros(){
      return eur_enteros;      
   }
   
   long long Centimos(){
      return cent_enteros;      
   }
   
   void SetEurCent(long long euros, long long centimos){
      if (EsCorrecta(euros) && EsCorrecta(centimos)){
         cent_enteros = centimos % 100;
         eur_enteros  = euros + centimos / 100;
      }
   }
};

int main(){
   long long  euros, centimos, suma_euros, suma_centimos;
   Dinero dinero1, dinero2;  // un_dinero est� en un estado v�lido -> 0 euros
   Dinero dinero_suma;
   
   cout << "Dinero\n\nIntroduzca euros y c�ntimos de dos cantidades.\n\n";
   
   cin >> euros >> centimos;
   
   dinero1.SetEurCent(euros, centimos);

   cin >> euros >> centimos;

   dinero2.SetEurCent(euros, centimos);
   
   suma_euros = dinero1.Euros() + dinero2.Euros();
   suma_centimos = dinero1.Centimos() + dinero2.Centimos();
   
   dinero_suma.SetEurCent(suma_euros, suma_centimos);
   
   cout << "\nEuros enteros: " << dinero_suma.Euros()
        << "\nC�ntimos     : " << dinero_suma.Centimos();
}
