#include <iostream>

using namespace std;

int main(){
   const int    LIM_KMS_RECARGO = 300;
   const double RECARGO_KM = 0.1;
   const double MIN_KMS_DSCTO = 700.0;
   const int    MIN_PTOS_DSCTO_BAJO = 100;  
   const int    MIN_PTOS_DSCTO_ALTO = 200;
   const int    DSCTO_KMS = 2;
   const int    DSCTO_BAJO_PTOS = 3;
   const int    DSCTO_ALTO_PTOS = 4;
   const double TRF_BASE = 150.0;
   double dscto;
   double trf, recargo_dist;
   int dist=-1;
   int ptos_fidel=-1;   

   cout << "Tarifa a�rea\n\n"
        << "Introduzca la distancia del recorrido del viaje y el "
        << "n�mero de puntos de la tarjeta de fidelizaci�n:\n";
   while(dist < 0)
   	cin >> dist;
   while((ptos_fidel < 0) || (ptos_fidel > 400))
   	cin >> ptos_fidel;   

   trf = TRF_BASE;
   recargo_dist = 0;

   if (dist > LIM_KMS_RECARGO)
      recargo_dist = RECARGO_KM * (dist - LIM_KMS_RECARGO) ;
   
   trf = trf + recargo_dist;
   
   ///////////////////////////////
   dscto = 0;
      
   if (ptos_fidel > MIN_PTOS_DSCTO_ALTO)   
      dscto =  DSCTO_ALTO_PTOS;
   else if (ptos_fidel > MIN_PTOS_DSCTO_BAJO)   
      dscto =  DSCTO_BAJO_PTOS;
   ///////////////////////////////                    
   
   if (dist > MIN_KMS_DSCTO)
      dscto = dscto + DSCTO_KMS;   
   
   trf = trf * (1 - dscto / 100.0);

   cout << "\n\nTarifa final aplicando los descuentos: ";
   cout << trf;
}
