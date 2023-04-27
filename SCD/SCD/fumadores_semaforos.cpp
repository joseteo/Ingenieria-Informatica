#include <iostream>
#include <cassert>
#include <thread>
#include <mutex>
#include <random> // dispositivos, generadores y distribuciones aleatorias
#include <chrono> // duraciones (duration), unidades de tiempo
#include "Semaphore.h"

using namespace std ;
using namespace SEM ;






//**********************************************************************
// plantilla de función para generar un entero aleatorio uniformemente
// distribuido entre dos valores enteros, ambos incluidos
// (ambos tienen que ser dos constantes, conocidas en tiempo de compilación)
//----------------------------------------------------------------------

template< int min, int max > int aleatorio(){
  static default_random_engine generador( (random_device())() );
  static uniform_int_distribution<int> distribucion_uniforme( min, max ) ;
  return distribucion_uniforme( generador );
}

int mostrador = 0;
Semaphore puedo_poner = 1;
Semaphore aviso[3] = {0,0,0};

//----------------------------------------------------------------------
// función que ejecuta la hebra del estanquero

void funcion_hebra_estanquero(){
  int ingrediente = 0;

  while(true){
    ingrediente = aleatorio<0,2>();
    sem_wait(puedo_poner);
    mostrador = ingrediente;
    cout<<"Ingrediente " << mostrador<< " puesto."<<endl;
    sem_signal(aviso[mostrador]);
  }
}

//-------------------------------------------------------------------------
// Función que simula la acción de fumar, como un retardo aleatoria de la hebra

void fumar( int num_fumador ){

   // calcular milisegundos aleatorios de duración de la acción de fumar)
   chrono::milliseconds duracion_fumar( aleatorio<20,200>() );

   // informa de que comienza a fumar

    cout << "Fumador " << num_fumador << "  :"<< " empieza a fumar (" <<
    duracion_fumar.count() << " milisegundos)" << endl;

   // espera bloqueada un tiempo igual a ''duracion_fumar' milisegundos
   this_thread::sleep_for( duracion_fumar );

   // informa de que ha terminado de fumar

    cout << "Fumador " << num_fumador << "  : termina de fumar, comienza espera de ingrediente." << endl;

}


void  funcion_hebra_fumador( int num_fumador ){
   while( true ){ 
     sem_wait(aviso[num_fumador]);
     cout <<"Ingrediente "<<num_fumador<<"retirado"<<endl;
     sem_signal(puedo_poner);
     fumar(num_fumador);
   }
}

//----------------------------------------------------------------------

int main(){
  
  cout << "--------------------------------------------------------" << endl
  << "Problema de los fumadores." <<
  endl<< "--------------------------------------------------------" << endl<<flush ;

  thread hebra_estanquera ( funcion_hebra_estanquero ), hebras[3];

  for(int i = 0; i < 3; i++){
    hebras[i] = thread ( funcion_hebra_fumador, i);
  }

  hebra_estanquera.join();

  for(int j = 0; j < 3; j++){
    hebras[j].join();
  }
  
}
