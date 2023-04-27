#ifndef _CAJA_H
#define _CAJA_H

#include "objrevolucion.h"
#include "objply.h"
#include "malla.h"
#include "cilindro.h"
#include "cono.h"
#include "cubo.h"
#include "material.h"

using namespace std;

class Caja{
    
private:
    
    Cilindro * caja=nullptr;
    Cilindro * cajon=nullptr;
    Cilindro * rueda=nullptr;
    Cilindro * soporte_rueda=nullptr;
    Cubo * tirador=nullptr;
    bool topeCajon=false;
    //material * cromo = new material({0.19225f, 0.19225f, 0.19225f, 1.0f},{0.8624f, 0.0125f, 0.8584f, 1.0f},{0.4f, 0.413f, 0.4f, 1.0},2.0f);
    
public:
    float mover_z = 0.0;
    Caja();
    void dibujar(int dib, int modo_actual);
    void moverCajon(float incremento);
};

#endif
