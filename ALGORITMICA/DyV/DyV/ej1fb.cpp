#include <cstdlib> // Para usar srand y rand
#include <chrono>
#include <iostream>
#include <fstream> // Para usar ficheros
#include <math.h> // Para usar floor

using namespace std;

int ejercicio1basico(int x, int y){
  int aux=0;
  for(int i=0; i<y; i++)
    aux+=x;
  return aux;
}

int main(int argc, char *argv[]){
	int x=0, y=0, result=0;
  chrono::time_point<std::chrono::high_resolution_clock> t0, tf; // Para medir el tiempo de ejecución
	long double tejecucion; // tiempo de ejecucion del algoritmo en ms
	ofstream fsalida;

  if (argc != 2) {
		cerr<<"\nError: El programa se debe ejecutar de la siguiente forma.\n\n";
		cerr<<argv[0]<<" NombreFicheroSalida\n\n";
		return 0;
	}

	// Abrimos fichero de salida
	fsalida.open(argv[1]);
	if (!fsalida.is_open()) {
		cerr<<"Error: No se pudo abrir fichero para escritura "<<argv[1]<<"\n\n";
		return 0;
	}


	// Inicializamos generador de no. aleatorios
  srand(time(NULL));
  x = rand();
  y = rand();

	cerr << "Ejecutando operacion de la ALU para valores x: " << x << " y: " << y << endl;

	t0= std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que comienza la ejecuciÛn del algoritmo
  result = ejercicio1basico(x,y);
	tf= std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que finaliza la ejecuciÛn del algoritmo

	tejecucion= std::chrono::duration_cast<std::chrono::microseconds>(tf - t0).count();
  tejecucion = tejecucion/(1000000);

	cerr << "\tResultado x*y: " << result << "\nTiempo de ejec. (s): " << tejecucion <<endl;

	// Guardamos t_ejecucion a fichero de salida
	fsalida<<tejecucion<<"\n";

	// Cerramos fichero de salida
	fsalida.close();

  return 0;
}
