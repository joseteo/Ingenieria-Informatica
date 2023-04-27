// -----------------------------------------------------------------------------
//
// Sistemas concurrentes y Distribuidos.
// Práctica 3. Implementación de algoritmos distribuidos con MPI
//
// Archivo: filosofos-plantilla.cpp
// Implementación del problema de los filósofos (sin camarero).
// Plantilla para completar.
//
// Historial:
// Actualizado a C++11 en Septiembre de 2017
// -----------------------------------------------------------------------------


#include <mpi.h>
#include <thread> // this_thread::sleep_for
#include <random> // dispositivos, generadores y distribuciones aleatorias
#include <chrono> // duraciones (duration), unidades de tiempo
#include <iostream>
#include <cassert>
#include <mutex>

using namespace std;
using namespace std::this_thread ;
using namespace std::chrono ;

const int
   num_filosofos = 5 ,
   num_procesos  = 2*num_filosofos + 1 ,
   id_camarero = 10,
   etiq_coger = 0,
   etiq_soltar = 1,
   etiq_sentarse = 2,
   etiq_levantarse = 3;

mutex mutex_cout;

//****************************************************************************//
//***                           COMPILAR                                   ***//
//***      mpicxx -std=c++11 -o filosofos-cam_exe filosofos-cam.cpp        ***//
//***                                                                      ***//
//***              mpirun -np 11 ./filosofos-cam_exe                       ***//
//****************************************************************************//

//**********************************************************************
// plantilla de función para generar un entero aleatorio uniformemente
// distribuido entre dos valores enteros, ambos incluidos
// (ambos tienen que ser dos constantes, conocidas en tiempo de compilación)
//----------------------------------------------------------------------

template< int min, int max > int aleatorio()
{
  static default_random_engine generador( (random_device())() );
  static uniform_int_distribution<int> distribucion_uniforme( min, max ) ;
  return distribucion_uniforme( generador );
}

// ---------------------------------------------------------------------

void funcion_filosofos( int id )
{
  int id_ten_izq = (id + 1) % (num_procesos-1), //id. tenedor izq.
      id_ten_der = (id + (num_procesos-1) - 1) % (num_procesos-1), //id. tenedor der.
      valor;

  MPI_Status estado;

  while ( true )
  {
    mutex_cout.lock();
    cout <<"Filósofo " <<id << " solicita sentarse." <<endl <<flush;
    mutex_cout.unlock();
    MPI_Ssend(&valor, 1, MPI_INT, id_camarero, etiq_sentarse, MPI_COMM_WORLD);

    mutex_cout.lock();
    cout <<"Filósofo " <<id << " SE HA SENTADO." <<endl<< flush;
    mutex_cout.unlock();

    mutex_cout.lock();
    cout <<"Filósofo " <<id << " solicita ten. izq." <<id_ten_izq <<endl<<flush;
    mutex_cout.unlock();
    // ... solicitar tenedor izquierdo (completar)
    MPI_Ssend(&valor, 1, MPI_INT, id_ten_izq, etiq_coger, MPI_COMM_WORLD);

    mutex_cout.lock();
    cout <<"Filósofo " <<id <<" solicita ten. der." <<id_ten_der <<endl<<flush;
    mutex_cout.unlock();
    // ... solicitar tenedor derecho (completar)
    MPI_Ssend(&valor, 1, MPI_INT, id_ten_der, etiq_coger, MPI_COMM_WORLD);

    mutex_cout.lock();
    cout <<"Filósofo " <<id <<" comienza a comer" <<endl<<flush;
    mutex_cout.unlock();
    sleep_for(seconds( aleatorio<5,10>() ) );

    mutex_cout.lock();
    cout <<"Filósofo " <<id <<" suelta ten. izq. " <<id_ten_izq <<endl<<flush;
    mutex_cout.unlock();
    // ... soltar el tenedor izquierdo (completar)
    MPI_Ssend(&valor, 1, MPI_INT, id_ten_izq, etiq_soltar, MPI_COMM_WORLD);

    mutex_cout.lock();
    cout<< "Filósofo " <<id <<" suelta ten. der. " <<id_ten_der <<endl<<flush;
    mutex_cout.unlock();
    // ... soltar el tenedor derecho (completar)
    MPI_Ssend(&valor, 1, MPI_INT, id_ten_der, etiq_soltar, MPI_COMM_WORLD);

    mutex_cout.lock();
    cout <<"Filósofo " <<id << " solicita levantarse." <<endl<<flush;
    mutex_cout.unlock();
    MPI_Ssend(&valor, 1, MPI_INT, id_camarero, etiq_levantarse,MPI_COMM_WORLD);
    mutex_cout.lock();
    cout <<"Filósofo " <<id << " SE HA LEVANTADO." <<endl<<flush;
    mutex_cout.unlock();

    mutex_cout.lock();
    cout << "Filosofo " << id << " comienza a pensar" << endl<<flush;
    mutex_cout.unlock();
    sleep_for(seconds( aleatorio<5,10>() ) );
    mutex_cout.lock();
    cout << "Filosofo " << id << " termina de pensar" << endl<<flush;
    mutex_cout.unlock();
 }
}
// ---------------------------------------------------------------------

void funcion_tenedores( int id )
{
  int valor, id_filosofo ;  // valor recibido, identificador del filósofo
  MPI_Status estado ;       // metadatos de las dos recepciones

  while ( true )
  {
    MPI_Recv( &valor, 1, MPI_INT, MPI_ANY_SOURCE, etiq_coger, MPI_COMM_WORLD, &estado);

    id_filosofo = estado.MPI_SOURCE;
    mutex_cout.lock();
    cout <<"Ten. " <<id <<" ha sido cogido por filo. " <<id_filosofo <<endl<<flush;
    mutex_cout.unlock();

    MPI_Recv ( &valor, 1, MPI_INT, id_filosofo, etiq_soltar, MPI_COMM_WORLD,&estado );

    mutex_cout.lock();
    cout <<"Ten. "<< id<< " ha sido liberado por filo. " <<id_filosofo <<endl<<flush;
    mutex_cout.unlock();
  }
}
// ---------------------------------------------------------------------

void funcion_camarero(int id){

  assert(id == 10);
  static int sentados =0;
  int valor;
  MPI_Status estado;

  while(true){

    if(sentados < num_filosofos-1){
      MPI_Recv(&valor, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &estado);

      if(estado.MPI_SOURCE==0){

      if(estado.MPI_TAG == etiq_sentarse){
          mutex_cout.lock();
          cout << "El camarero da un sitio al filosofo " << estado.MPI_SOURCE << endl << endl<< flush;
          mutex_cout.unlock();
          sentados++;
          mutex_cout.lock();
          cout << "HAY " << sentados << " FILOSOFOS SENTADOS" << endl << endl<< flush;
          mutex_cout.unlock();
      }
      else if(estado.MPI_TAG == etiq_levantarse){
          mutex_cout.lock();
          cout << "SE LEVANTA EL FILOSOFO " << estado.MPI_SOURCE << endl << endl<< flush;
          mutex_cout.unlock();
          sentados--;
          mutex_cout.lock();
          cout << "HAY " << sentados << " FILOSOFOS SENTADOS" << endl << endl<< flush;
          mutex_cout.unlock();
      }
      else{
          cout << "El camarero recibe un mensaje incorrecto " << endl<< endl << flush;
          exit(-1);
      }
    }else if(estado.MPI_SOURCE==1){

      if(estado.MPI_TAG == etiq_sentarse){
          mutex_cout.lock();
          cout << "El camarero da un sitio al filosofo " << estado.MPI_SOURCE << endl<< endl << flush;
          mutex_cout.unlock();
          sentados++;
          mutex_cout.lock();
          cout << "HAY " << sentados << " FILOSOFOS SENTADOS" << endl<< endl << flush;
          mutex_cout.unlock();
      }
      else if(estado.MPI_TAG == etiq_levantarse){
          mutex_cout.lock();
          cout << "SE LEVANTA EL FILOSOFO " << estado.MPI_SOURCE << endl << endl<< flush;
          mutex_cout.unlock();
          sentados--;
          mutex_cout.lock();
          cout << "HAY " << sentados << " FILOSOFOS SENTADOS" << endl << endl<< flush;
          mutex_cout.unlock();
      }
      else{
          cout << "El camarero recibe un mensaje incorrecto " << endl << endl<< flush;
          exit(-1);
      }
    }else if(estado.MPI_SOURCE==2){

        if(estado.MPI_TAG == etiq_sentarse){
            mutex_cout.lock();
            cout << "El camarero da un sitio al filosofo " << estado.MPI_SOURCE << endl << endl<< flush;
            mutex_cout.unlock();
            sentados++;
            mutex_cout.lock();
            cout << "HAY " << sentados << " FILOSOFOS SENTADOS" << endl << endl<< flush;
            mutex_cout.unlock();
        }
        else if(estado.MPI_TAG == etiq_levantarse){
            mutex_cout.lock();
            cout << "SE LEVANTA EL FILOSOFO " << estado.MPI_SOURCE << endl << endl<< flush;
            mutex_cout.unlock();
            sentados--;
            mutex_cout.lock();
            cout << "HAY " << sentados << " FILOSOFOS SENTADOS" << endl << endl<< flush;
            mutex_cout.unlock();
        }
        else{
            cout << "El camarero recibe un mensaje incorrecto " << endl<< endl << flush;
            exit(-1);
        }
      }else if(estado.MPI_SOURCE==3){

          if(estado.MPI_TAG == etiq_sentarse){
              mutex_cout.lock();
              cout << "El camarero da un sitio al filosofo " << estado.MPI_SOURCE << endl<< endl << flush;
              mutex_cout.unlock();
              sentados++;
              mutex_cout.lock();
              cout << "HAY " << sentados << " FILOSOFOS SENTADOS" << endl << endl<< flush;
              mutex_cout.unlock();
          }
          else if(estado.MPI_TAG == etiq_levantarse){
              mutex_cout.lock();
              cout << "SE LEVANTA EL FILOSOFO " << estado.MPI_SOURCE << endl << endl<< flush;
              mutex_cout.unlock();
              sentados--;
              mutex_cout.lock();
              cout << "HAY " << sentados << " FILOSOFOS SENTADOS" << endl << endl<< flush;
              mutex_cout.unlock();
          }
          else{
              cout << "El camarero recibe un mensaje incorrecto " << endl<< endl << flush;
              exit(-1);
          }
        }else if(estado.MPI_SOURCE==4){

            if(estado.MPI_TAG == etiq_sentarse){
                mutex_cout.lock();
                cout << "El camarero da un sitio al filosofo " << estado.MPI_SOURCE << endl << endl<< flush;
                mutex_cout.unlock();
                sentados++;
                mutex_cout.lock();
                cout << "HAY " << sentados << " FILOSOFOS SENTADOS" << endl << endl<< flush;
                mutex_cout.unlock();
            }
            else if(estado.MPI_TAG == etiq_levantarse){
                mutex_cout.lock();
                cout << "SE LEVANTA EL FILOSOFO " << estado.MPI_SOURCE << endl << endl<< flush;
                mutex_cout.unlock();
                sentados--;
                mutex_cout.lock();
                cout << "HAY " << sentados << " FILOSOFOS SENTADOS" << endl << endl<< flush;
                mutex_cout.unlock();
            }
            else{
                cout << "El camarero recibe un mensaje incorrecto " << endl << endl<< flush;
                exit(-1);
            }
            }
    }
    else{
      MPI_Recv(&valor, 1, MPI_INT, MPI_ANY_SOURCE, etiq_levantarse, MPI_COMM_WORLD, &estado);
      cout << "Se levanta el filosofo " << estado.MPI_SOURCE << endl << flush;
      sentados--;
    }
  }
}


int main( int argc, char** argv )
{
   int id_propio, num_procesos_actual ;

   MPI_Init( &argc, &argv );
   MPI_Comm_rank( MPI_COMM_WORLD, &id_propio );
   MPI_Comm_size( MPI_COMM_WORLD, &num_procesos_actual );


   if(num_procesos == num_procesos_actual ){

      if((id_propio % 2 == 0) && (id_propio !=10))   // si es par
        funcion_filosofos(id_propio);                // es un filósofo

      if(id_propio % 2 == 1)     // si es impar
        funcion_tenedores(id_propio); // es un tenedor

      if(id_propio == 10)
        funcion_camarero(id_propio);


   }else{

      if(id_propio == 0 ) // solo el primero escribe error, indep. del rol
      {
        cout << "el número de procesos esperados es:    " << num_procesos << endl
             << "el número de procesos en ejecución es: " << num_procesos_actual << endl
             << "(programa abortado)" << endl ;
      }
   }

   MPI_Finalize();
   return 0;
}

// ---------------------------------------------------------------------
