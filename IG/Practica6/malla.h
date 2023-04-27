// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: Malla3D.h
// -- declaraciones de clase Malla3D (mallas indexadas) y derivados
//
// #############################################################################

#ifndef MALLA3D_H_INCLUDED
#define MALLA3D_H_INCLUDED

#include "aux.h"
#include "material.h"
#include "textura.h"
#include "jpg_imagen.hpp"

// *****************************************************************************
//
// clase para objetos 3D (mallas indexadas)
//
// *****************************************************************************
   

class Malla3D
{
    private:
        GLuint idV = 0, idT = 0;
        material * m=nullptr;
        Textura * textura = nullptr;
        
   public:
    
    
    GLuint crearVBO( GLuint tipo_vbo, GLuint tamanio_bytes, GLvoid * puntero_ram );
    
    void asignarCarasAjedrez();
    
   // dibuja el objeto en modo inmediato
   void draw_ModoInmediato( std::vector<Tupla3f> vertices, std::vector<Tupla3i> caras, int modo_v, int modo_d);
   // dibuja el objeto en modo diferido (usando VBOs)
    void draw_ModoDiferido(std::vector< Tupla3f > vertices, std::vector< Tupla3i > caras, int modo_v, int modo_d);

   // función que redibuja el objeto
   // está función llama a 'draw_ModoInmediato' (modo inmediato)
   // o bien a 'draw_ModoDiferido' (modo diferido, VBOs)
   void draw(int dib=0, int tipo=0);
   
   void establecer_color_s(int cr, int cg, int cb);
   void establecer_color_activo(unsigned char modo);
   void establecer_color_p(int  cr, int cg, int cb);
   void establecer_color_l(int cr, int cg, int cb);
   void set_material(material *mat);
   void set_textura(Textura * tex);
   std::vector<Tupla3f> nv;
   std::vector<Tupla2f> ct;

   Tupla3u getColor() const;
   Tupla3f getCentro() const;
   
   protected:

   void calcular_normales() ; // calcula tabla de normales de vértices (práctica 3)
   
   std::vector<Tupla3i> caras_p;
   std::vector<Tupla3i> caras_i;
   std::vector<Tupla3f> v ;   // tabla de coordenadas de vértices (una tupla por vértice, con tres floats)
   std::vector<Tupla3i> f ; // una terna de 3 enteros por cada cara o triángulo
   Tupla3u * activa_color=nullptr;
   std::vector<Tupla3u> color_s; // los colores necesitan ser unicos ,revisar asignacion previa en creacion, meter colorea como unsigned int.
   std::vector<Tupla3u> color_p;
   std::vector<Tupla3u> color_l;

   Tupla3f centro;
   Tupla3f centro_transformado;

   void calcularCentro();
   // completar: tabla de colores, tabla de normales de vértices
} ;


#endif
