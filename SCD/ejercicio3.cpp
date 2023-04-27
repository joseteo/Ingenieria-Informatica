#include <iostream>
#include <iomanip>
#include <cassert>
#include <random>
#include <thread>
#include "HoareMonitor.h"

using namespace std ;
using namespace HM ;

// numero de fumadores
const int num_fumadores = 2 ;

// mutex de escritura en pantalla
mutex mtx ;


template< int min, int max > int aleatorio()
{
  static default_random_engine generador( (random_device())() );
  static uniform_int_distribution<int> distribucion_uniforme( min, max ) ;
  return distribucion_uniforme( generador );
}

//**********************************************************************

int ProducirIngrediente(  )
{
   mtx.lock();
   cout << "Estanquero: comienza a producir" << endl ;
   mtx.unlock();

   this_thread::sleep_for( chrono::milliseconds( aleatorio<20,30>() ));
   const int ingre = aleatorio<0,num_fumadores-1>() ;

   mtx.lock();
   cout << "Estanquero: finaliza producción de ingrediente " << ingre << endl ;
   mtx.unlock();

   return ingre ;
}
//----------------------------------------------------------------------

void Fumar( int num_fumador )
{
   mtx.lock();
   cout << "              Fumador " << num_fumador << ": comienza a fumar" << endl ;
   mtx.unlock();

   this_thread::sleep_for( chrono::milliseconds( aleatorio<20,40>() ));

   mtx.lock();
   cout << "              Fumador " << num_fumador << ": termina de fumar" << endl ;
   mtx.unlock();
}
//----------------------------------------------------------------------


// *****************************************************************************
// clase para monitor Estanco

class Estanco : public HoareMonitor
{
 private:
  int num_ingr_mostr ; // ingre. en mostr (-1 == ninguno)

 CondVar                    // colas condicion:
   ingre_mostr[num_fumadores], //  colas de fumadores (ingrediente en mostrad.)
   mostrador_libre ;           //  cola del estanquero ()

 public:          // constructor y métodos públicos
   Estanco() ;    // constructor
   void obtenerIngrediente( int ingre );
   void ponerIngrediente( int ingre );
   void esperarRecodigaIngrediente() ;
   void esperar_mi_ingrediente(int num_fumador);
} ;
// -----------------------------------------------------------------------------

Estanco::Estanco(  )
{
   mostrador_libre = newCondVar();
   for( int i = 0 ; i < num_fumadores ; i++ )
      ingre_mostr[i] = newCondVar() ;
   num_ingr_mostr = -1 ;
}
// -----------------------------------------------------------------------------
// función llamada por el consumidor para extraer un dato

void Estanco::obtenerIngrediente( int ingre )
{

   num_ingr_mostr = -1 ;
   mostrador_libre.signal();
}
// -----------------------------------------------------------------------------

void Estanco::ponerIngrediente( int ingre )
{
   assert( num_ingr_mostr == -1 );
   num_ingr_mostr = ingre ;
   ingre_mostr[ingre].signal();
}
// *****************************************************************************
// funciones de hebras

void Estanco::esperarRecodigaIngrediente()
{
  if ( num_ingr_mostr != -1 )
     mostrador_libre.wait();

      assert( num_ingr_mostr == -1 );
}

void Estanco::esperar_mi_ingrediente(int num_fumador)
{
    obtenerIngrediente();
    if ( num_ingr_mostr != num_fumador )
       ingre_mostr[num_fumador].wait();


}


// *****************************************************************************
// clase para monitor buffer

class Buffer : public HoareMonitor
{
 private:
  int buf; //
  bool buffer_lleno; //buffer lleno-->true

 CondVar  // colas condicion:
     puedeProducir,//  cola del productor
     puedeConsumir;//  cola del consumidor

 public:          // constructor y métodos públicos
   Buffer() ;    // constructor
   void escribir( int valor );
   int leer();
} ;
// -----------------------------------------------------------------------------

Buffer::Buffer(  )
{
   puedeProducir = newCondVar();
   puedeConsumir = newCondVar();
   buffer_lleno = false ;
}


// -----------------------------------------------------------------------------
// función llamada por el consumidor para extraer un dato

int Buffer::leer(){
   if (!buffer_lleno) // Si pasa esto ESPERAMOS
      puedeConsumir.wait();

   const int valor =buf ;

   // señalar al productor que hay un hueco libre, por si está esperando
   puedeProducir.signal();

   // devolver valor
   return valor ;
}
// -----------------------------------------------------------------------------
// función llamada por el productor para escribir un dato
void Buffer::escribir(int valor){
   if ( buffer_lleno) //Si pasa esto ESPERAMOS
      puedeProducir.wait();
   buf = valor ;
    // señalar al consumidor que ya hay una celda ocupada (por si esta esperando)
   puedeConsumir.signal();
}





// -----------------------------------------------------------------------------

void funcion_hebras_fumadores( MRef<Estanco> monitor, int num_fumador, MRef<Buffer> monitor_buffer )
{
   while( true )
   {
      monitor->obtenerIngrediente( num_fumador );
      Fumar( num_fumador );
      monitor_buffer->escribir(num_fumador);
   }
}

// -----------------------------------------------------------------------------

void funcion_hebra_estanquero( MRef<Estanco> monitor )
{
   while( true )
   {
      const int ingre = ProducirIngrediente();
      monitor->esperar_mi_ingrediente(num_fumadores);
      monitor->ponerIngrediente( ingre );
      monitor->esperarRecodigaIngrediente();
   }
}


int main()
{
   cout << "-----------------------------------------------------------" << endl
        << "Problema de los fumadores con hebra contadora." << endl
        << "-----------------------------------------------------------" << endl
        << flush ;


   // crear monitor estanco
   MRef<Estanco> monitor= Create<Estanco>();

   // crear monitor buffer
   MRef<Buffer> monitor_buffer = Create<Buffer>();

   // crear y lanzar las hebras
   thread hebras_fumadores[num_fumadores],
          hebra_estanquero;

   for( unsigned i = 0 ; i < num_fumadores ; i++ )
      hebras_fumadores[i] = thread( funcion_hebras_fumadores, monitor, i, monitor_buffer );
   hebra_estanquero = thread( funcion_hebra_estanquero, monitor );

   // esperar a que terminen las hebras
   for( unsigned i = 0 ; i < num_fumadores ; i++ )
      hebras_fumadores[i].join();
   hebra_estanquero.join();
}
