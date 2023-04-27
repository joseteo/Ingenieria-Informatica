#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <chrono>
#include <fstream>
#include <utility>

using namespace std;
using namespace std;

int maximo, minimo;

int max(int max1, int max2){
  int aux=0;

  if(max1>max2)
    aux=max1;
  else
    aux=max2;
  return aux;
}

int min(int min1, int min2){
  int aux=0;

  if(min1<min2)
    aux=min1;
  else
    aux=min2;
  return aux;
}

int* MaximoMinimoDyV(int *A, int Cini, int Cfin){

    int *v1,*v2, *vf;
    v1=new int[2];  // v1[max1,min1]
    v2=new int[2];  // v2[max2,min2]
    vf=new int[2];  // vf[maximo, minimo]

    if (Cini<Cfin-1){
        int mitad = (Cini-Cfin)/2;
        v1=MaximoMinimoDyV(A,Cini,mitad);
        v2=MaximoMinimoDyV(A,mitad+1,Cfin-1);
        maximo=max(v1[0],v2[0]); //devuelve max de los 2
        minimo=min(v1[1],v2[1]); //devuelve min de los 2
    }else if (Cini==Cfin){
        maximo = minimo = A[Cini];
    }else{
        maximo=max(A[Cini],A[Cfin]);
        minimo=min(A[Cini],A[Cfin]);
    }
    vf[0]=maximo;
    vf[1]=minimo;

    return vf;
}

int main(int argc, char *argv[]) {

  int *v;
	int n, i, argumento;
  chrono::time_point<std::chrono::high_resolution_clock> t0, tf; // Para medir el tiempo de ejecución
	double tejecucion; // tiempo de ejecucion del algoritmo en ms
	unsigned long int semilla;
	ofstream fsalida;

	if (argc <= 3) {
		cerr<<"\nError: El programa se debe ejecutar de la siguiente forma.\n\n";
		cerr<<argv[0]<<" NombreFicheroSalida Semilla tamCaso1 tamCaso2 ... tamCasoN\n\n";
		return 0;
	}

	// Abrimos fichero de salida
	fsalida.open(argv[1]);
	if (!fsalida.is_open()) {
		cerr<<"Error: No se pudo abrir fichero para escritura "<<argv[1]<<"\n\n";
		return 0;
	}

	// Inicializamos generador de no. aleatorios
	semilla= atoi(argv[2]);
	srand(semilla);

	// Pasamos por cada tamaÒo de caso
	for (argumento= 3; argumento<argc; argumento++) {

		// Cogemos el tamanio del caso
		n= atoi(argv[argumento]);

		v= new int[n];
		// Reservamos memoria para el vector


		// Generamos vector aleatorio de prueba, con componentes entre 0 y n-1
		for (i= 0; i<n; i++)
			v[i]= rand()%n;

		cerr << "Ejecutando MaximoMinimoDyV para tam. caso: " << n << endl;

		t0= std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que comienza la ejecuciÛn del algoritmo
		MaximoMinimoDyV(v, 0, n); // Ejecutamos el algoritmo para tamaÒo de caso n
		tf= std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que finaliza la ejecuciÛn del algoritmo

		unsigned long tejecucion= std::chrono::duration_cast<std::chrono::microseconds>(tf - t0).count();

		cerr << "\tTiempo de ejec. (us): " << tejecucion << " para tam. caso "<< n << " max= "<<maximo<<" min= "<< minimo<<endl;

		// Guardamos tam. de caso y t_ejecucion a fichero de salida
		fsalida<<n<<" "<<tejecucion<<"\n";


		// Liberamos memoria del vector
		delete [] v;
	}

	// Cerramos fichero de salida
	fsalida.close();

	return 0;
}
