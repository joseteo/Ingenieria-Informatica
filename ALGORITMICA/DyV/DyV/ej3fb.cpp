#include <cstdlib> // Para usar srand y rand
#include <chrono>
#include <iostream>
#include <fstream> // Para usar ficheros
#include <math.h> // Para usar floor

using namespace std;

int ejercicio3basico(int n){
  int y=0, aux=0;
  for(int i=1; i < n/2; i++){
    aux = i * (i+1) * (i+2);
    if(aux == n)
      y=i;
  }
  return y;
}

int main(int argc, char *argv[]){
	int n=0, y=0;
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

  cout << "Introduce numero: " << endl;
  cin >> n;

	cerr << "Ejecutando algoritmo para n: " << n << endl;

	t0= std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que comienza la ejecuciÛn del algoritmo
  y = ejercicio3basico(n);
	tf= std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que finaliza la ejecuciÛn del algoritmo

	tejecucion= std::chrono::duration_cast<std::chrono::microseconds>(tf - t0).count();
  tejecucion = tejecucion/(1000000);

  if(y!=0)
	cerr << "\tResultado y: " << y << "\n\t" << y << "*" << y+1 << "*" << y+2 << "=" << n << "\nTiempo de ejec. (s): " << tejecucion <<endl;
  else
  cerr << "\tNo existe numero natural tal que cumpla la condicion" << endl;

	// Guardamos t_ejecucion a fichero de salida
	fsalida<<tejecucion<<"\n";

	// Cerramos fichero de salida
	fsalida.close();

  return 0;
}
