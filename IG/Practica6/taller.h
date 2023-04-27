#ifndef _TALLER_H
#define _TALLER_H

#include "objrevolucion.h"
#include "objply.h"
#include "malla.h"
#include "cilindro.h"
#include "cubo.h"

using namespace std;

class Taller{
    
private:
    ObjPLY * objply_letra_T= nullptr;
    ObjPLY * objply_letra_A= nullptr;
    ObjPLY * objply_letra_L= nullptr;
    ObjPLY * objply_letra_E= nullptr;
    ObjPLY * objply_letra_R= nullptr;
    Cubo * pared_taller=nullptr;
    Cilindro * floor=nullptr;
    
    Textura * suelo= new Textura("cemento.jpg");

public:
    Taller();
    void dibujar(int dib, int modo_actual);
    
};

#endif
