#include "aux.h"
#include "malla.h"
#include "tetraedro.h"

Tetraedro::Tetraedro()
{
    color_s.resize(4);
    color_l.resize(4);
    color_p.resize(4);

    Tupla3f v0 = {0,85,0};
    Tupla3f v1 = {100,-60,0};
    Tupla3f v2 = {-50,-60,87};
    Tupla3f v3 = {-50,-60,-87};

    v.push_back(v0);
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    
    Tupla3i c0 = {2,1,0};
    Tupla3i c1 = {3,2,0};
    Tupla3i c2 = {1,3,0};
    Tupla3i c3 = {2,3,1};
    
    f.push_back(c0);
    f.push_back(c1);
    f.push_back(c2);
    f.push_back(c3);

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
