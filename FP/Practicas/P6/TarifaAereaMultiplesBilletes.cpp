#include <iostream>
#include <cctype>
using namespace std;

int main(){   
   const int    LIMITE_KMS_RECARGO = 300;
   const double RECARGO_KM = 0.1;
   const double MIN_KMS_DSCTO = 700.0;
   const int    MIN_PTOS_DSCTO_BAJO = 100;
   const int    MIN_PTOS_DSCTO_ALTO = 200;
   const int    DSCTO_POR_KMS = 2;
   const int    DSCTO_BAJO_POR_PTOS = 3;
   const int    DSCTO_ALTO_POR_PTOS = 4;
   const double TARIFA_BASE = 150.0;
   const int    MAX_PTOS = 400;
   
   const char TERMINADOR = '#';
   const char NUEVO = 'N';
   bool billete_nuevo, car_ok, fin_input;
   char car;
   
   double dscto;
   double tarifa;
   int distancia;
   int ptos_fidel;   

   cout << "Tarifa aérea."
        << "\nIntroduzca los datos de todos los billetes introduciendo, "
        << "previamente, el carácter N (Nuevo) Introduzca # para terminar."
        << "\nIntroduzca la distancia del recorrido del viaje (> 0) y el "
        << "número de puntos de la tarjeta de fidelización (entre 0 y "
        << MAX_PTOS << ":\n";
   
   do{
      do{
         cin >> car;
         car = toupper(car);
         billete_nuevo = car == NUEVO;
         fin_input = car == TERMINADOR;
         car_ok = billete_nuevo || fin_input;
      }while (!car_ok);
   
      if (!fin_input){
         do{
            cin >> distancia;         
         }while (distancia <= 0);
         
         do{
            cin >> ptos_fidel;   
         }while (ptos_fidel < 0 || ptos_fidel > MAX_PTOS);

         tarifa = TARIFA_BASE;
      
         if (distancia > LIMITE_KMS_RECARGO)
            tarifa = tarifa + RECARGO_KM * (distancia - LIMITE_KMS_RECARGO) ;
              
         if (distancia > MIN_KMS_DSCTO)
            dscto = DSCTO_POR_KMS;   
         else
            dscto = 0;   
               
         if (ptos_fidel > MIN_PTOS_DSCTO_ALTO)   
            dscto = dscto + DSCTO_ALTO_POR_PTOS;
         else if (ptos_fidel > MIN_PTOS_DSCTO_BAJO)   
            dscto = dscto + DSCTO_BAJO_POR_PTOS;
               
         tarifa = tarifa * (1 - dscto / 100.0);
      
         cout << "\n\nTarifa final aplicando los descuentos: ";
         cout << tarifa;
      }
   }while (!fin_input);
}
