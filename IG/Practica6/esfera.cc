#include "aux.h"
#include "objrevolucion.h"
#include "esfera.h"
#include "malla.h"


Esfera::Esfera(const int num_vert_perfil, const int num_instancias_perf, const float radio, bool calcCT){
    
    float angulo = M_PI/(num_vert_perfil-1);
    
    v.clear();
    
    for(int i=(-(num_vert_perfil-1)/2); i<= (num_vert_perfil-1)/2; i++){
        Tupla3f v0 = {cos(i*angulo)*radio,sin(i*angulo)*radio,0};
        v.push_back(v0);
    }
    
    
    crearMalla(v, num_instancias_perf, true, true, calcCT);
    
    color_s.resize((num_vert_perfil+1)*(num_instancias_perf+1));
    color_l.resize((num_vert_perfil+1)*(num_instancias_perf+1));
    color_p.resize((num_vert_perfil+1)*(num_instancias_perf+1));
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
