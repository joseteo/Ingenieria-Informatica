#ifndef _BOTON_H
#define _BOTON_H

#include "objrevolucion.h"
#include "objply.h"
#include "cilindro.h"
#include "cubo.h"

using namespace std;

class Boton{
    
private:
    
    Cubo * caja=nullptr;
    Cilindro * boton=nullptr;
    
public:
    float cantidad = 0.0;
    Boton();
    void dibujar(int dub, int modo_actual);
    void moverBoton(float incremento);
};

#endif
