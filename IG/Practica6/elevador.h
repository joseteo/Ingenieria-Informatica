#ifndef _ELEVADOR_H
#define _ELEVADOR_H

#include "objrevolucion.h"
#include "objply.h"
#include "malla.h"
#include "cilindro.h"
#include "cono.h"
#include "cubo.h"

using namespace std;

class Elevador{
    
private:
    Cubo * ventanas=nullptr;
   Cilindro * carlift=nullptr;
   Cubo * soporte=nullptr;
   Cubo * bases_brazos=nullptr;
   Cono * bases_carlift=nullptr;
   Cubo * brazo=nullptr;
   Cilindro * base_car=nullptr;
   ObjPLY * coche= nullptr;
   bool topeElevador= false;
   Textura * text_coche= new Textura("rojo-1.jpg");
    
public:
    float elevar_y= 0.0;
    Elevador();
    void dibujar(int dib, int modo_actual);
    void moverElevador(float incremento);
};

#endif
