#ifndef _MECANICO_H
#define _MECANICO_H

#include "objrevolucion.h"
#include "objply.h"
#include "cubo.h"
#include "malla.h"

using namespace std;

class Mecanico{
    
private:
    
    Cubo * brazo=nullptr;
    Cubo * pierna=nullptr;
    Cubo * torso=nullptr;
    Cubo * cabeza=nullptr;
    bool topeBrazoDer=false, topeBrazoIzq=false;
    
public:
    float angulo2 = 0.0, angulo = 0.0;
    Mecanico();
    void dibujar(int dib, int modo_actual);
    void moverBrazoDer(float incremento);
    void moverBrazoIzq(float incremento);
};

#endif
