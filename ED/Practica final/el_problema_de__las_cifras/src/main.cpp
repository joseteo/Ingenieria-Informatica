#include <iostream>
#include "algorithm.h"
#include <vector>
#include <string>
#include <stdexcept>
#include <ctime>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]){

	if (argc != 2){
		cout << "Expresion para ejecutar el problema= ./bin/el_problema_de_las_cifras datos" << endl;
		exit(-1);
	}

	vector <int> elementos_init;
	int objetivo, valor, num_elementos_init;
	string lectura;
	string nombre_archivo = argv[1];

  ifstream datos(nombre_archivo.c_str());
  if (!datos){
    throw runtime_error("No existe el archivo= " + (string) argv[1]);
  }

  do{
    datos >> lectura;
  }while(lectura != "numerodatos=");

  datos >> num_elementos_init;

	do{
    datos >> lectura;
  }while(lectura != "Datos=");

	for (int i = 0; i < num_elementos_init; i++){
		datos >> valor;
		elementos_init.push_back(valor);
	}

	do{
    datos >> lectura;
  }while(lectura != "Valorrequerido=");

	datos >> objetivo;

	algorithm resol(elementos_init, objetivo);

	clock_t start;
  double duracion;
	start = clock();

	resol.resolver();

	duracion = ( clock() - start ) / (double) CLOCKS_PER_SEC;
	cout << "Tiempo de calculos= " << duracion << " segundos" << endl;

	resol.mostrar_resultado();
	cout << " = " << objetivo;
	cout << endl;

	return 0;
}
