#include "aux.h"
#include "malla.h"
#include "cubo.h"

Cubo::Cubo(float lado)
{
    color_s.resize(8);
    color_l.resize(8);
    color_p.resize(8);

    Tupla3f v0 = {-lado,lado,-lado};
    Tupla3f v1 = {-lado,-lado,-lado};
    Tupla3f v2 = {lado,lado,-lado};
    Tupla3f v3 = {lado,-lado,-lado};
    Tupla3f v4 = {lado,lado,lado};
    Tupla3f v5 = {lado,-lado,lado};
    Tupla3f v6 = {-lado,lado,lado};
    Tupla3f v7 = {-lado,-lado,lado};
        
    
    v.push_back(v0);
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    v.push_back(v5);
    v.push_back(v6);
    v.push_back(v7);

   
    Tupla3i c0 = {2,1,0};
    Tupla3i c1 = {3,1,2};
    Tupla3i c2 = {4,3,2};
    Tupla3i c3 = {5,3,4};
    Tupla3i c4 = {6,5,4};
    Tupla3i c5 = {7,5,6};
    Tupla3i c6 = {0,7,6};
    Tupla3i c7 = {1,7,0};
    Tupla3i c8 = {4,0,6};
    Tupla3i c9 = {2,0,4};
    Tupla3i c10 = {3,7,1};
    Tupla3i c11 = {5,7,3};
    

    f.push_back(c0);
    f.push_back(c1);
    f.push_back(c2);
    f.push_back(c3);
    f.push_back(c4);
    f.push_back(c5);
    f.push_back(c6);
    f.push_back(c7);
    f.push_back(c8);
    f.push_back(c9);
    f.push_back(c10);
    f.push_back(c11);

    
    establecer_color_s(0.0, 0.0, 100.0);
    establecer_color_l(100.0, 0.0, 0.0);
    establecer_color_p(0.0, 100.0, 0.0);
    calcular_normales();
    
    
}
