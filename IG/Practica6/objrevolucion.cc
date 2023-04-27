#include "aux.h"
#include "malla.h"
#include "ply_reader.h"
#include "objrevolucion.h"
#include "math.h"




// *****************************************************************************
//
// Clase ObjRevolucion (práctica 2)
//
// *****************************************************************************


// *****************************************************************************
// objeto de revolución obtenido a partir de un perfil (en un PLY)

ObjRevolucion::ObjRevolucion() {}


ObjRevolucion::ObjRevolucion(const std::string & archivo, int num_instancias, bool tapa_sup, bool tapa_inf, bool calcCT) {

    ply::read_vertices( archivo, this->v);
    crearMalla( v, num_instancias,tapa_sup,tapa_inf,calcCT);
    
    color_s.resize(num_instancias*v.size());
    color_l.resize(num_instancias*v.size());
    color_p.resize(num_instancias*v.size());
    
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

// *****************************************************************************
// objeto de revolución obtenido a partir de un perfil (en un vector de puntos)

 
ObjRevolucion::ObjRevolucion(std::vector<Tupla3f> archivo, int num_instancias, bool tapa_sup, bool tapa_inf, bool calcCT) {
    crearMalla(archivo, num_instancias, tapa_sup, tapa_inf, calcCT);
    calcular_normales();
}


void ObjRevolucion::crearMalla( const std::vector<Tupla3f> & perfil_original, const int num_instancias_perf, const bool tapa_sup, const bool tapa_inf, bool calcCT){
    N=num_instancias_perf;
    M=perfil_original.size();
    
    const float PI = 3.1415926f;
    double angulo_vector = 2* PI /num_instancias_perf;
    
    std::vector<Tupla3f> v_aux= perfil_original;
    std::vector<Tupla3i> f_aux= f;
    bool tapa_sur=tapa_inf, 
         tapa_norte=tapa_sup;
    
    v.clear();
    f.clear();
    
    if (v_aux.at(0)[1]>v_aux.at(v_aux.size()-1)[1]){
        for(int i = 0; i<v_aux.size()/2 ; i++ ){
            std::swap(v_aux[i], v_aux[v_aux.size()-1-i]);
        }
    }
    
    
    if(v_aux.at(0)[0]==0){
        tapa_sur=false;
    }else if(v_aux.at(v_aux.size()-1)[0]==0){
        tapa_norte=false;
    }
    

    
    for(int i=0; i <= num_instancias_perf-1; i++){
        for(int j=0; j <= v_aux.size()-1; j++){            
            Tupla3f v0 = { v_aux.at(j)[0]*cos(i*angulo_vector) , v_aux.at(j)[1] , v_aux.at(j)[0]*sin(i*angulo_vector) };
            v.push_back(v0);
        }
    }
    if(calcCT){
        for(int j=0; j <= v_aux.size()-1; j++){
            v.push_back({v_aux.at(j)[0],v_aux.at(j)[1],v_aux.at(j)[2]});
        }
        for(int i=0; i <= num_instancias_perf; i++){
            for(int j=0; j <= v_aux.size()-2; j++){
                int a=v_aux.size()*i+j;
                int b=(v_aux.size()*((i+1)%num_instancias_perf))+j;
                Tupla3i f0 = {b+1,b,a};
                f.push_back(f0);
                Tupla3i f1 = {a+1,b+1,a};
                f.push_back(f1);
            }
        }
        
    }else{
        for(int i=0; i <= num_instancias_perf-1; i++){
            for(int j=0; j <= v_aux.size()-2; j++){
                int a=v_aux.size()*i+j;
                int b=(v_aux.size()*((i+1)%num_instancias_perf))+j;
                Tupla3i f0 = {b+1,b,a};
                f.push_back(f0);
                Tupla3i f1 = {a+1,b+1,a};
                f.push_back(f1);
            }
        }
    }
    
    if(tapa_sur==true){
        Tupla3f v0= { 0 , v_aux.at(0)[1] , 0 };
        v.push_back(v0);
        for(int i=0; i < num_instancias_perf-1; i++){
            Tupla3i f0 = {v.size()-1,v_aux.size()*i,v_aux.size()*(i+1)};
            f.push_back(f0);
        }
        Tupla3i f1 = { v_aux.size()*(num_instancias_perf-1) , v_aux.size()*0 , v.size()-1 };
        f.push_back(f1);
    }
    
    if(tapa_norte==true){
        int pos = v_aux.size()-1;
        Tupla3f v0= { 0 , v_aux.at(pos)[1] , 0 };
        v.push_back(v0);
        for(int i=0; i < num_instancias_perf-1; i++){
            Tupla3i f0 = {v_aux.size()*(i+2)-1,v_aux.size()*(i+1)-1,v.size()-1};
            f.push_back(f0);
        }
        Tupla3i f1 = {v.size()-1,v_aux.size()-1, v_aux.size()*(num_instancias_perf)-1};
        f.push_back(f1);
    }

    if(calcCT){
        d.clear();
        d.push_back(0);
        
        for(int j=0; j < v_aux.size()-1; j++){
            d.push_back( (d.at(j) + fabsf(v_aux.at(j+1)[1] - v_aux.at(j)[1]) ) );
        }
        
        calcularCoordTextura();
    }
}

void ObjRevolucion::calcularCoordTextura()
{
    N+=1;
    
    for(int i=0; i < N; i++){
        for(int j=0; j < M; j++){
            
            float s = (float)i/(N-1);
            float t = (d[j]/d[M-1]);

            ct.push_back({s,t});
        }
    }
    
    ct.push_back({0,1});
    ct.push_back({1,0});
}







