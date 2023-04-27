// -----------------------------------------------------------------------------
//
// Sistemas concurrentes y Distribuidos.
// Práctica 4. Implementación de sistemas de tiempo real.
//
// Archivo: ejecutivo1.cpp
// Implementación del primer ejemplo de ejecutivo cíclico:
//
//   Datos de las tareas:
//   ------------
//   Ta.  T    C
//   ------------
//   A  500  100
//   B  500  150
//   C  1000 200
//   D  2000 240
//
//  -------------
//
//  Planificación (con Ts == 500 ms)
//  *---------*----------*---------*--------*
//  | A B C | A B C | A B D | A B D |
//  *---------*----------*---------*--------*
//
//1.-¿cual es el minimo tiempo de espera que queda al final de las iteraciones del ciclo secundario con tu solucion?
//    El tiempo minimo de espera que queda es de 10 ms, entre la tercera iteracion y la cuarta, y a su vez entre la cuarta iteracion y la siguiente.
//
//2.¿seria planificable si la tarea D tuviese un tiempo computo de 250 ms?
//    Si, seria planificable, ya que el Ts es de 500 ms y la suma de A + B + D siendo 100 + 150 + *250* seria igual a 500 ms,
//    como no lo supera se podria planificar incluso de la forma anterior, "tabla de planificacion de las lineas 20-23",
//    pero debido a que se ajusta tanto el consumo de tiempo se producirian retrasos de cerca de un milisegundo.
//
// Historial:
// Creado en Diciembre de 2017
// -----------------------------------------------------------------------------

#include <string>
#include <iostream> // cout, cerr
#include <thread>
#include <chrono>   // utilidades de tiempo
#include <ratio>    // std::ratio_divide

using namespace std ;
using namespace std::chrono ;
using namespace std::this_thread ;

// tipo para duraciones en segundos y milisegundos, en coma flotante:
typedef duration<float,ratio<1,1>>    seconds_f ;
typedef duration<float,ratio<1,1000>> milliseconds_f ;

// -----------------------------------------------------------------------------
// tarea genérica: duerme durante un intervalo de tiempo (de determinada duración)

void Tarea( const std::string & nombre, milliseconds tcomputo )
{
   cout << "   Comienza tarea " << nombre << " (C == " << tcomputo.count() << " ms.) ... " ;
   sleep_for( tcomputo );
   cout << "fin." << endl ;
}

// -----------------------------------------------------------------------------
// tareas concretas del problema:

void TareaA() { Tarea( "A", milliseconds(100) );  }
void TareaB() { Tarea( "B", milliseconds(150) );  }
void TareaC() { Tarea( "C", milliseconds(200) );  }
void TareaD() { Tarea( "D", milliseconds(250) );  }
//void TareaE() { Tarea( "E", milliseconds( 20) );  }

// -----------------------------------------------------------------------------
// implementación del ejecutivo cíclico:

int main( int argc, char *argv[] )
{
   // Ts = duración del ciclo secundario
   const milliseconds Ts( 500 );

   // ini_sec = instante de inicio de la iteración actual del ciclo secundario
   time_point<steady_clock> ini_sec = steady_clock::now();


   while( true ) // ciclo principal
   {
      cout << endl
           << "---------------------------------------" << endl
           << "Comienza iteración del ciclo principal." << endl ;

      for( int i = 1 ; i <= 4 ; i++ ) // ciclo secundario (4 iteraciones)
      {

         cout << endl << "Comienza iteración " << i << " del ciclo secundario." << endl ;

         switch( i )
         {
            case 1 : TareaA(); TareaB(); TareaC();           break ;
            case 2 : TareaA(); TareaB(); TareaC();           break ;
            case 3 : TareaA(); TareaB(); TareaD();           break ;
            case 4 : TareaA(); TareaB(); TareaD();           break ;
         }


         // calcular el siguiente instante de inicio del ciclo secundario
         ini_sec += Ts ;


         // esperar hasta el inicio de la siguiente iteración del ciclo secundario
         sleep_until( ini_sec );

         time_point<steady_clock> aux = steady_clock::now();
         steady_clock::duration duracion = aux - ini_sec;

        cout <<"\nDuracion == " << seconds_f(duracion).count() << " segundos."<< endl;

        if (duracion > milliseconds(50))
          exit(-1);
      }
   }
}
