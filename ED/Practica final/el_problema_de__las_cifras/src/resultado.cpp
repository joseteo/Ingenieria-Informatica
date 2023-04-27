#include "resultado.h"

Resultado::Resultado(int resultado, int clase, Resultado *dad1, Resultado *dad2, int operacion){
  this->resultado = resultado;
  this->clase = clase;
  this->dad1 = dad1;
  this->dad2 = dad2;
  this->operacion = operacion;
}

void Resultado::mostrar_camino() const{

	if (dad1 != NULL && dad2 != NULL){
		if (dad1->dad1 != NULL && (operacion == 2 || operacion == 4)){
			cout << "( ";
			dad1->mostrar_camino();
			cout << " ) ";
		}else{
			dad1->mostrar_camino();
		}

		if (operacion == 1){
			cout << " + ";
		}else if (operacion == 2){
			cout << " * ";
		}else if (operacion == 3){
			cout << " - ";
		}else if (operacion == 4){
			cout << " / ";
		}

		if (dad2->dad2 != NULL){
			cout << "(";
			dad2->mostrar_camino();
			cout << ")";
		}else{
			dad2->mostrar_camino();
		}

	}else{
		cout << resultado;
	}
}
