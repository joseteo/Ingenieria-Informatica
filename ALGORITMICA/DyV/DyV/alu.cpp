#include <cstdlib> // Para usar srand y rand
#include <chrono>
#include <iostream>
#include <fstream> // Para usar ficheros
#include <math.h> // Para usar floor

using namespace std;

int OpMult(int x, int y){
  int aux;
  if(y <= 1){ // Caso base
		if(y == 1)
      aux=x;
    if(y == 0)
      aux=0;
  }else{ // Caso general
    int s1 = OpMult(x, floor(y/2)); // floor redondea al entero
	  if(y%2==0)
		  aux=s1+s1;
	  if(y%2!=0)
		  aux=s1+s1+x;
  }

  return aux;
}

int main(int argc, char *argv[]){
	int x=0, y=0, result=0;
  chrono::time_point<std::chrono::high_resolution_clock> t0, tf; // Para medir el tiempo de ejecución
	unsigned long tejecucion; // tiempo de ejecucion del algoritmo en ms
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
	result = OpMult(x, y); // Ejecutamos el algoritmo
	tf= std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que finaliza la ejecuciÛn del algoritmo

	tejecucion= std::chrono::duration_cast<std::chrono::microseconds>(tf - t0).count();

	cerr << "\tResultado x*y: " << result << "\nTiempo de ejec. (us): " << tejecucion <<endl;

	// Guardamos t_ejecucion a fichero de salida
	fsalida<<tejecucion<<"\n";

	// Cerramos fichero de salida
	fsalida.close();

  return 0;
}
