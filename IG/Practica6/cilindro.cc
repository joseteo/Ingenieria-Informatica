#include "aux.h"
#include "objrevolucion.h"
#include "cilindro.h"
#include "malla.h"


Cilindro::Cilindro(const int num_vert_perfil, const int num_instancias_perf, const float altura, const float radio, const bool t_s, const bool t_i, bool calcCT){
    
    float distancia = altura/num_vert_perfil;
    
    v.clear();
    
    for(int i=0; i< num_vert_perfil; i++){
        Tupla3f v0 = {radio,i*distancia,0};
        v.push_back(v0);
    }
    
    crearMalla( v, num_instancias_perf, t_s, t_i, calcCT);
    
    color_s.resize(num_instancias_perf*num_vert_perfil);
    color_l.resize(num_instancias_perf*num_vert_perfil);
    color_p.resize(num_instancias_perf*num_vert_perfil);
    int R, G, B;
    R = rand()%255;
    G = rand()%255;
    B = rand()%255;
    establecer_color_s(R/255.0, G/255.0, B/255.0);
    R = rand()%255;
    G = rand()%255;
    B = rand()%255;
    establecer_color_l(R/255.0, G/255.0, B/255.0);
    R = rand()%255;
    G = rand()%255;
    B = rand()%255;
    establecer_color_p(R/255.0, G/255.0, B/255.0);
    calcular_normales();
}
