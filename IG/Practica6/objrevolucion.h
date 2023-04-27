// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: Cubo.h

//
// #############################################################################

#ifndef OBJREVOLUCION_H_INCLUDED
#define OBJREVOLUCION_H_INCLUDED

#include "aux.h"
#include "ply_reader.h"
#include "malla.h"

// *****************************************************************************
//
// clases derivadas de Malla3D (definen constructores específicos)
//
// *****************************************************************************

// *****************************************************************************
// Cubo con centro en el origen y lado unidad por defecto
// (tiene 9 vertices y 6 caras)

class ObjRevolucion : public Malla3D
{
    
public:
    ObjRevolucion();

    ObjRevolucion(const std::string & archivo, int num_instancias, bool tapa_sup=true, bool tapa_inf=true, bool calcCT=false) ;
    ObjRevolucion(std::vector<Tupla3f> archivo, int num_instancias, bool tapa_sup=true, bool tapa_inf=true, bool calcCT=false) ;
    void calcularCoordTextura();

protected:
    std::vector<float> d;
    int M=0,N=0;
    void crearMalla( const std::vector<Tupla3f> & perfil_original, const int num_instancias_perf, const bool tapa_sup, const bool tapa_inf, bool calcCT=false);
    
} ;




#endif
