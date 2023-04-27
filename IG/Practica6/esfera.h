#ifndef ESFERA_H_INCLUDED
#define ESFERA_H_INCLUDED

#include "aux.h"

class Esfera : public ObjRevolucion
{
   public:
    Esfera(const int num_vert_perfil=100, const int num_instancias_perf=100, const float radio=15.0, bool calcCT=false);
    
} ;

#endif

