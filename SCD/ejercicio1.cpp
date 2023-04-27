#include <iostream>
#include <cassert>
#include <thread>
#include <mutex>
#include <random> // dispositivos, generadores y distribuciones aleatorias
#include <chrono> // duraciones (duration), unidades de tiempo
#include "Semaphore.h"

using namespace std ;
using namespace SEM ;

// COMPILAR CON g++ -std=c++11 -pthread -I. -o ejercicio1 ejercicio1.cpp Semaphore.cpp




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

mutex mutex_cout;
int mostrador = 0;
Semaphore puedo_poner = 1;
Semaphore aviso[3] = {0,0,0};
Semaphore ya_fumado = 1;
Semaphore lote = 2;
Semaphore consumir_lote = 0;
/*
int fin=0;
int fin2=0;*/
bool finish=false;
//----------------------------------------------------------------------
// función que ejecuta la hebra del estanquero

void funcion_hebra_estanquero(){

  while(true){
    sem_wait(lote);
    sem_wait(puedo_poner);
    mostrador = aleatorio<0,2>();

    sem_wait(ya_fumado);
    mutex_cout.lock();
    cout<<"Ingrediente " << mostrador<< " puesto en el mostrador."<<endl;
    mutex_cout.unlock();

    sem_signal(aviso[mostrador]);
    sem_signal(consumir_lote);
		//fin++;
  }
}

//-------------------------------------------------------------------------
// Función que simula la acción de fumar, como un retardo aleatoria de la hebra

void fumar( int num_fumador ){

   // calcular milisegundos aleatorios de duración de la acción de fumar)
   chrono::milliseconds duracion_fumar( aleatorio<20,200>() );

   // informa de que comienza a fumar
   mutex_cout.lock();
   cout << "Fumador " << num_fumador << "  :"<< " empieza a fumar (" <<
   duracion_fumar.count() << " milisegundos)" << endl;
   mutex_cout.unlock();

   // espera bloqueada un tiempo igual a ''duracion_fumar' milisegundos
   this_thread::sleep_for( duracion_fumar );

   // informa de que ha terminado de fumar
   mutex_cout.lock();
   cout << "Fumador " << num_fumador << "  : termina de fumar, comienza espera de ingrediente." << endl;
   mutex_cout.unlock();
	/*if (final>=49){
		exit(0);
	}*/

}


void  funcion_hebra_fumador( int num_fumador ){
	//fin2=0;
   while( true ){
     sem_wait(aviso[num_fumador]);

     mutex_cout.lock();
     cout <<"Ingrediente "<<num_fumador<<" retirado"<<endl;
     mutex_cout.unlock();

     sem_signal(puedo_poner);
     fumar(num_fumador);

     sem_signal(ya_fumado);
/*
			if (fin2>=49){
				exit(0);
			}
		 fin2++;*/
   }
}


void funcion_hebra_proveedora(){

  while(true){
    sem_wait(consumir_lote);
    sem_wait(consumir_lote);

    mutex_cout.lock();
    cout << "Un nuevo lote ha llegado."<< endl;
    mutex_cout.unlock();

    sem_signal(lote);
    sem_signal(lote);
  }
}

//----------------------------------------------------------------------

int main(){

  cout << "--------------------------------------------------------" << endl
  << "Problema de los fumadores." <<
  endl<< "--------------------------------------------------------" << endl<<flush ;

  thread hebra_estanquera ( funcion_hebra_estanquero ), hebras[3];
  thread hebra_proveedora( funcion_hebra_proveedora );

  for(int i = 0; i < 3; i++){
		/*if (fin2>=49){
			finish=true;
			exit(0);
		}*/
    hebras[i] = thread ( funcion_hebra_fumador, i);
  }

  hebra_estanquera.join();
  hebra_proveedora.join();

  for(int j = 0; j < 3; j++){
		/*if (finish==true){
			exit(0);
		}*/
    hebras[j].join();
  }

}
