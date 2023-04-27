#ifndef _ESCENA_H
#define _ESCENA_H

#include "ejes.h"
#include "malla.h"
#include "cubo.h"
#include "tetraedro.h"
#include "objply.h"
#include "objrevolucion.h"
#include "cilindro.h"
#include "cono.h"
#include "esfera.h"
#include "luz.h"
#include "luzdireccional.h"
#include "luzposicional.h"
#include "material.h"
#include "taller.h"
#include "elevador.h"
#include "caja.h"
#include "mecanico.h"
#include "boton.h"
#include "camara.h"

typedef enum {NADA, SELOBJETO,SELVISUALIZACION,SELDIBUJADO} menu;
typedef enum {CERO, CUB,TRI,PL,OBJREV,LAMBO} objeto;

class Escena
{

   private:

   GLfloat matrix[16];

 // ** PARÁMETROS DE LA CÁMARA (PROVISIONAL)
       
       // variables que definen la posicion de la camara en coordenadas polares
   GLfloat Observer_distance;
   GLfloat Observer_angle_x;
   GLfloat Observer_angle_y;

   // variables que controlan la ventana y la transformacion de perspectiva
   GLfloat Width, Height, Front_plane, Back_plane;

    // Transformación de cámara
	void change_projection( const float ratio_xy );
	void change_observer();
    
    
   void clear_window();

   menu modoMenu=NADA;
   objeto obj;
   int modo_actual=0;
   int dib=0;
   // Objetos de la escena
   Ejes ejes;
   Cubo * cubo = nullptr ; // es importante inicializarlo a 'nullptr'
   Tetraedro * tetraedro= nullptr ; // es importante inicializarlo a 'nullptr'
   ObjPLY * objply_ant= nullptr;
   ObjPLY * objply_beethoven= nullptr;
   ObjPLY * objply_letra_T= nullptr;
   ObjPLY * objply_letra_A= nullptr;
   ObjPLY * objply_letra_L= nullptr;
   ObjPLY * objply_letra_E= nullptr;
   ObjPLY * objply_letra_R= nullptr;
   Taller * taller=nullptr;
   Elevador * elevador=nullptr;
   Caja * caja=nullptr;
   Mecanico * mecanico=nullptr;
   Boton * boton=nullptr;
   ObjRevolucion * objrev_pcue= nullptr;
   ObjRevolucion * objrev_pinf= nullptr;
   ObjRevolucion * objrev_psup= nullptr;
   ObjRevolucion * peonB=nullptr;
   ObjRevolucion * peonN=nullptr;
   Cilindro * cilindro=nullptr;
   Cilindro * pared_taller=nullptr;
   Cono * cono=nullptr;
   Esfera * esfera=nullptr;
   
   
   //LUCES
   std::vector<bool> interruptorLuz={true, true, true, true, true, true, true, true};
   bool iluminacion = false;
   luzposicional * luzPos1 = nullptr;
   luzposicional * luzPos2 = nullptr;
   luzposicional * luzPos3 = nullptr;
   luzposicional * luzPos4 = nullptr;
   luzposicional * luzPos5 = nullptr;
   luzposicional * luzPos6 = nullptr;
   luzdireccional * luzDir7 = nullptr;
   luzdireccional * luzDir8 = nullptr;
   float variarAnguloAlpha = 0.0, variarAnguloBeta = 0.0;
   bool alpha=false, beta=false;
   bool animarLuzAnimada=false;
   int mod_vis=0;
   
   //Camaras
   int numCamaraActiva=0;
   const static int numCamaras = 5;
   std::vector<bool> camaraActiva={false, false, false, false, false};
   std::vector<Camara> camaras;
   bool activoCamara=false;
   
   Camara * cam0 = nullptr;
   Camara * cam1 = nullptr;
   Camara * cam2 = nullptr;
   Camara * cam3 = nullptr;
   Camara * cam4 = nullptr;
   
   
   bool animacionAuto=false, animacionManual=false;
   float anguloDer = 0.0, anguloIzq = 0.0, moverElevador = 0.0, moverCajon = 0.0, velocidad=0.5;
   std::vector<bool> parteTaller={false, false, false};
   
   material * m1 = new material({0.1f, 0.1f, 0.1f, 1.0f}, {0.1f,0.1f,0.1f,1.0f}, {0.1f,0.1f,0.1f,1.0}, 0.78125f);
   material * m_B = new material({1.0f, 1.0f, 1.0f, 0.0f} , {1.0f, 1.0f, 1.0f, 1.0f} , {1.0f, 1.0f, 1.0f, 0.0} , 0.0f);
   material * m_N = new material({0.0f, 0.0f, 0.0f, 0.0f} , {0.0f, 0.0f, 0.0f, 1.0f} , {0.0f, 0.0f, 0.0f, 1.0} , 0.0f);
   Textura * cocacola= new Textura("text-lata-1.jpg");
   Textura * madera= new Textura("text-madera.jpg");
   
   public:
    
    Escena();
	void inicializar( int UI_window_width, int UI_window_height );
	void redimensionar( int newWidth, int newHeight ) ;

	// Dibujar
	void dibujar() ;
    void variarLuces(float incremento);

	// Interacción con la escena
	bool teclaPulsada( unsigned char Tecla1, int x, int y ) ;
	void teclaEspecial( int Tecla1, int x, int y );
    void mover(int x, int y);
    void ratonMovido(int x, int y);
    void zoom(float factor);
    void dibujaSeleccion();
    void processPick(int x, int y);
    Tupla3f centroCamara(const Tupla3f & centro);
    
    void animarModeloJerarquico();
    void animarMecanico();
    void animarElevador();
    void animarCajon();
    
    bool moverse = false;
    int xant = 0, yant = 0;
    int raton=0;
    

};
#endif
