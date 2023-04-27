#include <iostream>
#include <cassert>
#include <thread>
#include <mutex>
#include <random> // dispositivos, generadores y distribuciones aleatorias
#include <chrono> // duraciones (duration), unidades de tiempo
#include "Semaphore.h"

using namespace std ;
using namespace SEM ;

// COMPILAR CON g++ -std=c++11 -pthread -I. -o fumadorescopia fumadorescopia.cpp Semaphore.cpp




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
Semaphore puede_contar = 0;
Semaphore conto = 0;
int fin=0;
int fin2=0;
bool finish=false;
int variable_fumador;
//----------------------------------------------------------------------
// función que ejecuta la hebra del estanquero

void funcion_hebra_estanquero(){

  while(fin<50){
    sem_wait(puedo_poner);
    mostrador = aleatorio<0,2>();
    
    mutex_cout.lock();
    cout<<"Ingrediente " << mostrador<< " puesto en el mostrador."<<endl;
    mutex_cout.unlock();

    sem_signal(aviso[mostrador]);
		fin++;
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
	fin2=0;
   while( fin2<50 ){
     sem_wait(aviso[num_fumador]);

     mutex_cout.lock();
     cout <<"Ingrediente "<<num_fumador<<" retirado"<<endl;
     mutex_cout.unlock();

     sem_signal(puedo_poner);
     fumar(num_fumador);

     sem_signal(puede_contar);
     variable_fumador=num_fumador;
     sem_wait(conto);

			if (fin2>=49){
				exit(0);
			}
		 fin2++;
   }
}


void funcion_hebra_contador_cigarrillos(){
  int contador[3]= {0,0,0};
  int id_fumador;
  int aux=0;

  while(true){
    sem_wait(puede_contar);
    id_fumador=variable_fumador;
    sem_signal(conto);

    mutex_cout.lock();
    cout << ".........Contabilizado Fumador " << id_fumador << "  " << endl;
    mutex_cout.unlock();
    contador[id_fumador]++;

    if(aux==4){
      mutex_cout.lock();
      for (int i = 0; i < 3; i++) {
        cout <<"\tfumador "<<i<<" lleva "<<contador[i]<<" cigarros fumados."<<endl;
      }
      mutex_cout.unlock();
      aux=0;
    }
    else aux++;

  }
}

//----------------------------------------------------------------------

int main(){

  cout << "--------------------------------------------------------" << endl
  << "Problema de los fumadores." <<
  endl<< "--------------------------------------------------------" << endl<<flush ;

  thread hebra_estanquera ( funcion_hebra_estanquero ), hebras[3], hebra_contador_cigarrillos( funcion_hebra_contador_cigarrillos );

  for(int i = 0; i < 3; i++){
		if (fin2>=49){
			finish=true;
			exit(0);
		}
    hebras[i] = thread ( funcion_hebra_fumador, i);
  }

  hebra_estanquera.join();
  hebra_contador_cigarrillos.join();

  for(int j = 0; j < 3; j++){
		if (finish==true){
			exit(0);
		}
    hebras[j].join();
  }

}
