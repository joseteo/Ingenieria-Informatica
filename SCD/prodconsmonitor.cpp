#include <iostream>
#include <thread> // this_thread::sleep_for
#include <random> // dispositivos, generadores y distribuciones aleatorias
#include <chrono> // duraciones (duration), unidades de tiempo
#include <mpi.h>  // includes de MPI

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

/*				IMPORTANTE

	COMPILAR= mpic++ -o prodconsMonitor prodconsmonitor.cpp Semaphore.cpp

	EJECUTAR= mpirun -np 3 ./prodconsMonitor
*/

const int
	id_productor          = 0 , // identificador del proceso productor
	id_buffer             = 1 , // identificador del proceso buffer
	id_consumidor         = 2 , // identificador del proceso consumidor
	num_procesos_esperado = 3 , // numero total de procesos esperado
	num_items             = 20 ; // numero de items producidos o consumidos

template< int min, int max > int aleatorio(){
	static default_random_engine generador((random_device())());
	static uniform_int_distribution<int> distribucion_uniforme(min, max);
	return distribucion_uniforme(generador);
}

int producir(){
	static int contador = 0 ;
	sleep_for(milliseconds(aleatorio<10,200>()));
	contador++;
	cout<<"Productor ha producido valor "<<contador<<endl<<flush;
	return contador;
}

void funcion_productor(){
	for(unsigned int i=0; i<num_items; i++){
		// producir valor
		int valor_prod = producir();
		// enviar valor
		cout<<"Productor va a enviar valor "<<valor_prod<<endl<<flush;
		MPI_Ssend(&valor_prod, 1, MPI_INT, id_buffer, 0, MPI_COMM_WORLD);
	}
}

void consumir(int valor_cons){
	// espera bloqueada
	sleep_for(milliseconds(aleatorio<10,200>()));
	cout<<"Consumidor ha consumido valor "<<valor_cons<<endl<<flush;
}

void funcion_consumidor(){
	int peticion, valor_rec = 1;
	MPI_Status estado;

	for(unsigned int i=0; i < num_items; i++){
		MPI_Ssend(&peticion, 1, MPI_INT, id_buffer, 0, MPI_COMM_WORLD);
		MPI_Recv(&valor_rec, 1, MPI_INT, id_buffer, 0, MPI_COMM_WORLD, &estado);
		cout<<"Consumidor ha recibido valor "<<valor_rec<<endl<<flush;
		consumir(valor_rec);
	}
}

void funcion_buffer(){
	int valor, peticion;
	MPI_Status  estado;

	for(unsigned int i = 0; i<num_items; i++){
		MPI_Recv(&valor, 1, MPI_INT, id_productor,  0, MPI_COMM_WORLD, &estado);
		cout<<"Buffer ha recibido valor "<<valor<<endl;

		MPI_Recv(&peticion, 1, MPI_INT, id_consumidor, 0, MPI_COMM_WORLD, &estado);

		cout<<"Buffer va a enviar valor "<<valor<<endl;
		MPI_Ssend(&valor, 1, MPI_INT, id_consumidor, 0, MPI_COMM_WORLD);
	}
}

int main(int argc, char *argv[]){
	int id_propio, num_procesos_actual; // ident. propio, num. de procesos

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &id_propio);
	MPI_Comm_size(MPI_COMM_WORLD, &num_procesos_actual);
	if(num_procesos_esperado == num_procesos_actual){
		if(id_propio == id_productor)  // si mi ident. es el del productor
			funcion_productor();   // ejecutar funcion del productor
		else if(id_propio == id_buffer)// si mi ident. es el del buffer
			funcion_buffer();      // ejecutar funcion buffer
		else                           // en otro caso, mi ident es consumidor
			funcion_consumidor();  // ejecutar funcion consumidor
	}else if(id_propio == 0)  	       // si hay error, el proceso 0 informa
		cerr<<"error: numero de procesos distinto del esperado."<<endl;

	MPI_Finalize();
	return 0;
}
