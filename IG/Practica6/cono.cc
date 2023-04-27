#include "aux.h"
#include "objrevolucion.h"
#include "cono.h"
#include "malla.h"


Cono::Cono(const int num_vert_perfil, const int num_instancias_perf, const float altura, const float radio){
    
    float distancia_y = altura/num_vert_perfil;
    float distancia_x = radio/num_vert_perfil;
    
    v.clear();
    
    for(int i=0; i< num_vert_perfil; i++){
        Tupla3f v0 = {radio-i*distancia_x,i*distancia_y,0};     
        v.push_back(v0);
    }
    
    crearMalla(v, num_instancias_perf, true, true);
    
    color_s.resize(num_vert_perfil*num_instancias_perf);
    color_l.resize(num_vert_perfil*num_instancias_perf);
    color_p.resize(num_vert_perfil*num_instancias_perf);
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


