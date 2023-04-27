#ifndef RESULTADO_H
#define RESULTADO_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Resultado{

	private:

		int clase;

		int resultado;

		const Resultado *dad1, *dad2;

		int operacion;

	public:

		Resultado(int resultado, int clase, Resultado *dad1, Resultado *dad2, int operacion);

		void mostrar_camino() const;

		inline int get_resultado() const{
			return resultado;
		}

		inline bool operator<(const Resultado &otra) const{
			return (this->resultado < otra.resultado);
		}

		inline bool operator>(const Resultado &otra) const{
			return (this->resultado > otra.resultado);
		}

		inline bool operator<=(const Resultado &otra) const{
			return (this->resultado <= otra.resultado);
		}

		inline bool operator>=(const Resultado &otra) const{
			return (this->resultado >= otra.resultado);
		}

		inline bool operator==(const Resultado &otra) const{
			return (this->resultado == otra.resultado);
		}

};


# endif

