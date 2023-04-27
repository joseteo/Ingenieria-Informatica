#include <iostream>
#include <cassert>
#include <thread>
#include <mutex>
#include <random>
#include "Semaphore.h"

using namespace std ;
using namespace SEM ;

// COMPILAR CON g++ -std=c++11 -pthread -I. -o ejercicio2 ejercicio2.cpp Semaphore.cpp



const int num_items = 40 ,
	       tam_vec   = 10 ;
unsigned  cont_esc[num_items] = {0},
          cont_lei[num_items] = {0};



int V[tam_vec], primera_libre = 0;
Semaphore libres = tam_vec;
Semaphore ocupadas = 0;
Semaphore control = 1;
int lectoras=2, escritoras=4;

template< int min, int max > int aleatorio()
{
  static default_random_engine generador( (random_device())() );
  static uniform_int_distribution<int> distribucion_uniforme( min, max ) ;
  return distribucion_uniforme( generador );
}


int escribir_dato()
{
   static int contador = 0 ;
   this_thread::sleep_for( chrono::milliseconds( aleatorio<20,100>() ));

   cout << "escrito: " << contador << endl << flush ;

   cont_esc[contador] ++ ;
   return contador++ ;
}
//----------------------------------------------------------------------

void leer_dato( unsigned dato )
{
   assert( dato < num_items );
   cont_lei[dato] ++ ;
   this_thread::sleep_for( chrono::milliseconds( aleatorio<20,100>() ));

   cout << "                  leido: " << dato << endl ;

}


//----------------------------------------------------------------------

void test_contadores()
{
   bool ok = true ;
   cout << "comprobando contadores ...." ;
   for( unsigned i = 0 ; i < num_items ; i++ )
   {  if ( cont_esc[i] != 1 )
      {  cout << "error: valor " << i << " escrito " << cont_esc[i] << " veces." << endl ;
         ok = false ;
      }
      if ( cont_lei[i] != 1 )
      {  cout << "error: valor " << i << " leido " << cont_lei[i] << " veces" << endl ;
         ok = false ;
      }
   }
   if (ok)
      cout << endl << flush << "solución (aparentemente) correcta." << endl << flush ;
}

//----------------------------------------------------------------------

void  funcion_hebra_escritora(  ){
   for( unsigned i = 0 ; i < num_items ; i++ ){
     	int dato = escribir_dato() ;
	sem_wait(libres);
	sem_wait(control);

     	V[primera_libre]=dato;
	primera_libre++;

	sem_signal(control);
	sem_signal(ocupadas);
		escritoras--;
   }
}

//----------------------------------------------------------------------

void funcion_hebra_lectora(  ){
   for( unsigned i = 0 ; i < num_items ; i++ ){
     	int dato;
	sem_wait(ocupadas);
	sem_wait(control);

      	dato=V[primera_libre-1];
	V[primera_libre]=0;
	primera_libre--;

	sem_signal(control);
	sem_signal(libres);
      leer_dato( dato ) ;
			lectoras--;
    }
}
//----------------------------------------------------------------------

int main()
{
   cout << "--------------------------------------------------------" << endl
        << "Problema de los escritores-lectores." << endl
        << "--------------------------------------------------------" << endl
        << flush ;

   thread hebra_escritora ( funcion_hebra_escritora ),
          hebra_lectora( funcion_hebra_lectora );

   hebra_escritora.join() ;
   hebra_lectora.join() ;

   test_contadores();
}
