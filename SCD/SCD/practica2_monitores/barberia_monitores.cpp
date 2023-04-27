#include <iostream>
#include <iomanip>
#include <random>
#include <thread>
#include <chrono>
#include "HoareMonitor.h"

using namespace std;
using namespace HM;

//compilar g++ -std=c++11 -pthread -o barberia_monitores barberia_monitores.cpp HoareMonitor.cpp Semaphore.cpp
/* función generadora de números aleatorios */
template< int min, int max > int aleatorio(){

	static default_random_engine generador( (random_device())() );
	static uniform_int_distribution<int> distribucion_uniforme( min, max ) ;

	return distribucion_uniforme( generador );
}


/* función que simula un tiempo aleatorio para cortar el pelo */
void CortarPeloACliente(){

	// cuenta los milisegundos de duración
	chrono::milliseconds corte( aleatorio<20,200>() );

	this_thread::sleep_for( corte ); // espera bloqueado durante "corte" ms
}



/* función que simula el tiempo aleatorio de espera fuera de la barbería*/
void EsperarFueraBarberia(int j){

	// cuenta los milisegundos de duración
	chrono::milliseconds espera( aleatorio<20,200>() );

	cout << "Cliente " << j << " esperando fuera (" << espera.count() <<
	" milisegundos)" << endl;

	this_thread::sleep_for( espera ); // espera bloqueado durante "espera" ms
}


class BarberiaSU : public HoareMonitor{

	private:
		CondVar salaEspera,
		barbero,
		silla;

	public:
		BarberiaSU();
		void CortarPelo(int i);
		void SiguienteCliente();
		void FinCliente();
};

// constructor
BarberiaSU::BarberiaSU(){
	salaEspera = newCondVar();
	barbero = newCondVar();
	silla=newCondVar();
}


// en este procedimiento el cliente consigue el servicio del barbero
void BarberiaSU::CortarPelo(int i){

	if(!silla.empty()){ // si la silla está ocupada
		cout << "Cliente " << i << " esperando en la sala de espera." << endl;
		salaEspera.wait(); // me espero en la sala de espera
	}

	barbero.signal(); // aviso al barbero que estoy en la silla
	cout << "Comienza a pelar al cliente " << i << "." << endl;
	silla.wait(); // espero en la silla a que me peles
}

// este procedimiento hace que el barbero espere un nuevo cliente y servirlo
void BarberiaSU::SiguienteCliente(){

	// si la silla está vacía
	if(silla.empty()){

		// y la sala de espera también
		if(salaEspera.empty()){
			cout << "Barbero duerme." << endl;
			barbero.wait();

		// si la silla está vacía, pero hay clientes en la sala esperando,
		}else{
			cout << "Barbero llama a cliente de la sala de espera." << endl;
			salaEspera.signal(); // el barbero llama a un cliente
		}
	}
}


//Función que avisa de que el barbero ha terminado de pelar
void BarberiaSU::FinCliente(){

	cout << "Barbero termina de pelar." << endl;
	silla.signal();
}


void funcion_cliente(MRef<BarberiaSU> barb, int i){

	while(true){
		barb->CortarPelo(i);
		EsperarFueraBarberia(i);
	}
}

void funcion_barbero(MRef<BarberiaSU> barb){

	while(true){
		barb->SiguienteCliente();
		CortarPeloACliente();
		barb->FinCliente();
	}
}



int main(){
	// creo monitor tipo BarberiaSU
	MRef<BarberiaSU> barberia = Create<BarberiaSU>();

	// creo la hebra barbero y la lanzo
	thread hebra_barbero(funcion_barbero, barberia);

	// creo las hebras clientes y las lanzo
	thread hebra_cliente[10];

	for(int i = 0; i < 10; i++){
		hebra_cliente[i] = thread(funcion_cliente, barberia, i);
	}

	// esperar a que termine la hebra barbero
	hebra_barbero.join();

	// esperar a que terminen las hebras clientes
	for(int j = 0; j < 10; j++){
		hebra_cliente[j].join();
	}
}
