#include <cassert>
#include "Pila_max_VD.h"


using namespace std;



void PilaMAX::poner(int elem){

  elemento e={elem,elem};

  if (datos.dimension() > 0 && datos.componente(0).maximo > elem){
    e.maximo=datos.componente(0).maximo;
  }

  datos.asignar_componente(0, e);
};

int PilaMAX::componente(){
  return datos.dimension();
}

void PilaMAX::quitar(){

  assert(datos.dimension()>0);

  datos.quitar();
};


int PilaMAX::num_elementos() const{

  return datos.dimension();
};


bool PilaMAX::vacia() const{

  return (datos.dimension()==0);
};


elemento PilaMAX::tope(){

  assert(datos.dimension()>0);

  return datos.componente(0);
};


const elemento PilaMAX::tope() const{

  assert(datos.dimension()>0);

  return datos.componente(0);
};


std::ostream& operator<<(std::ostream& os,const elemento & a){

  os<<a.ele<< " Maximo: "<<a.maximo<<endl;

  return os;
}
