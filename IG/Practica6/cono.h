#ifndef CONO_H_INCLUDED
#define CONO_H_INCLUDED

#include "aux.h"

class Cono : public ObjRevolucion
{
   public:
    Cono(const int num_vert_perfil=15, const int num_instancias_perf=50, const float altura=30.0, const float radio=10);
    
} ;

#endif
