#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <iostream>
#include "resultado.h"
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std ;
    
class algorithm{

	private:

		int *code;
		int num_class;
		int num_elementos_init;
		int objetivo;
		set <Resultado> *clase;
		Resultado *mejor_resultado;
		void ordenar_code();
		void generar_resultados(int i, int j);
		void create_class();

	public:

		algorithm(const vector <int> & elementos_init, int objetivo);

		~algorithm();

		void resolver();

		void mostrar_resultado();

};

bool comparar(int j,int t);

int numero_unos(int n);

# endif
