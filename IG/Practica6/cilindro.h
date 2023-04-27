#ifndef CILINDRO_H_INCLUDED
#define CILINDRO_H_INCLUDED

#include "aux.h"

class Cilindro : public ObjRevolucion
{
   public:
    Cilindro(const int num_vert_perfil=10, const int num_instancias_perf=30, const float altura=30.0, const float radio=10, const bool t_s=true, const bool t_i=true, bool calcCT=false);
    
} ;

#endif
