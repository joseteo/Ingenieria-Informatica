#include <iostream>
#include <iomanip>
#include <random>
#include <thread>
#include "HoareMonitor.h"


using namespace std;
using namespace HM;

//compilar g++ -std=c++11 -pthread -o fumadores_monitores fumadores_monitores.cpp HoareMonitor.cpp Semaphore.cpp
/* función generadora de números aleatorios */
template< int min, int max > int aleatorio(){

  static default_random_engine generador( (random_device())() );
  static uniform_int_distribution<int> distribucion_uniforme( min, max );

  return distribucion_uniforme( generador );
}

void Fumar( int num_fumador ){
// calcular milisegundos aleatorios de duración de la acción de fumar)
  chrono::milliseconds duracion_fumar( aleatorio<20,200>() );
// informa de que comienza a fumar
  cout << "Fumador " << num_fumador << " :" << " empieza a fumar (" <<
  duracion_fumar.count() << " milisegundos)" << endl;
// espera bloqueada un tiempo igual a ''duracion_fumar' milisegundos
  this_thread::sleep_for( duracion_fumar );
// informa de que ha terminado de fumar
  cout << "Fumador " << num_fumador << " : termina de fumar, comienza espera de ingrediente." << endl;
}

int ProducirIngrediente(){

  chrono::milliseconds tiempo( aleatorio<20,200>() );
  this_thread::sleep_for(tiempo);

  return aleatorio<0,2>();
}

/***************************************************************/

class EstancoSU : public HoareMonitor{

  private:
      //mostrador donde se coloca el ingrediente i, si tiene valor -1 está vacío
      int mostrador;
      CondVar estanquero, fumador[3];
      // colas de espera y señal

  public:
      EstancoSU();
      void ObtenerIngrediente(int i);
      void PonerIngrediente(int j);
      void EsperarRecogida();
};

// constructor
EstancoSU::EstancoSU(){

    mostrador = -1;
    estanquero = newCondVar();

    for(int i = 0; i < 3; i++)
      fumador[i] = newCondVar();
}


// en este procedimiento el fumador espera bloqueado a su ingrediente, lo retira del
//mostrador y avisa al estanquero
void EstancoSU::ObtenerIngrediente(int i){
    // si en el mostrador no está el ingrediente i que necesita
    if( mostrador != i)
    // el fumador espera a que esté
      fumador[i].wait();

    // el fumador recoge el ingrediente, quedando vacío el mostrador (-1)
    mostrador = -1;

    cout << "Ingrediente " << i << " recogido." << endl;

    estanquero.signal(); // se avisa al estanquero que el mostrador está vacío
}


// este procedimiento pone el ingrediente en el mostrador y avisa al fumador que necesita el ingrediente i

void EstancoSU::PonerIngrediente(int i){

    // se pone el ingrediente en el mostrador
    mostrador = i;

    cout << "Ingrediente " << i << " puesto en el mostrador." << endl;

    fumador[i].signal(); // se avisa al fumador i que su ingrediente está disponible
}


// en este procedimiento el estanquero espera a que algún fumador retire el ingrediente del mostrador
void EstancoSU::EsperarRecogida(){

    if(mostrador != -1) // si el mostrador no está vacío (!= -1)
      estanquero.wait(); // el estanquero espera hasta que lo esté
}


/**************************************************************/

void funcion_estanquera(MRef<EstancoSU> monitor){

  int ingr;

  while(true){
      // el estanquero produce un ingrediente
      ingr = ProducirIngrediente();

      // lo coloca en el mostrador
      monitor->PonerIngrediente(ingr);

      // espera a que sea recogido
      monitor->EsperarRecogida();
  }
}


void funcion_fumadora(MRef<EstancoSU> monitor, int i){

    while(true){

      // el fumador i coge el ingrediente del mostrador
      monitor->ObtenerIngrediente(i);
      Fumar(i);
    }
}




/***************************************************************/


int main(){

    // creo el monitor de tipo EstancoSU
    MRef<EstancoSU> monitor = Create<EstancoSU>();

    // creo hebra_estanquero y la lanzo
    thread hebra_estanquero(funcion_estanquera, monitor);

    // creo las hebra_fumadores y las lanzo
    thread hebra_fumadores[3];
    for(int i = 0; i < 3; i++){
        hebra_fumadores[i]= thread(funcion_fumadora, monitor, i);
    }

    // esperar a que termine la hebra, se pone después de fumador, ya que un signal()
    //no funciona si no hay un wait() antes
    hebra_estanquero.join();

    // esperar a que terminen las hebras
    for(int i = 0; i < 3; i++){
        hebra_fumadores[i].join();
    }
}
