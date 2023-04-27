#include "objrevolucion.h"
#include "objply.h"
#include "taller.h"

Taller::Taller()
{
    pared_taller = new Cubo(500);
    pared_taller->asignarCarasAjedrez();
    //pared_taller->establecer_color_s(0.6255, 0.5863, 0.4765);
    pared_taller->set_textura(suelo);
    objply_letra_T = new ObjPLY("T.ply");
    objply_letra_T->asignarCarasAjedrez();
    objply_letra_T->establecer_color_s(1.0,0.0,0.0);
    objply_letra_A = new ObjPLY("A.ply");
    objply_letra_A->asignarCarasAjedrez();
    objply_letra_A->establecer_color_s(1.0,0.0,0.0);
    objply_letra_L = new ObjPLY("L.ply");
    objply_letra_L->asignarCarasAjedrez();
    objply_letra_L->establecer_color_s(1.0,0.0,0.0);
    objply_letra_E = new ObjPLY("E.ply");
    objply_letra_E->asignarCarasAjedrez();
    objply_letra_E->establecer_color_s(1.0,0.0,0.0);
    objply_letra_R = new ObjPLY("R.ply");
    objply_letra_R->asignarCarasAjedrez();
    objply_letra_R->establecer_color_s(1.0,0.0,0.0);
    floor = new Cilindro(2,2,1400,300,true,true,true);
    floor->asignarCarasAjedrez();
    floor->set_textura(suelo);
    
}

void Taller::dibujar(int dib, int modo_actual)
{
    
        glPushMatrix();
            glTranslatef( 0.0 , -22.0 , 0.0 );
            glRotatef(90, 1, 0, 0);
            glTranslatef( 0.0 , -350.0 , 0.0 );
            floor->draw(dib, modo_actual);
        glPopMatrix();
        /*
        //pared_taller
        glPushMatrix();
            glTranslatef( 0.0 , -26.0 , 0.0 );
            glScalef(1.0f, 0.01f, 1.0f);
            pared_taller->draw(dib, modo_actual);
        glPopMatrix();
        */
        
        //letras
        //T
        glPushMatrix();
            glTranslatef( -150.0 , 150.0 , -350.0 );
            glScalef(15.0f,15.0f,15.0f);
            objply_letra_T->draw(dib, modo_actual);
        glPopMatrix();
        
        //A
        glPushMatrix();
            glTranslatef( -90.0 , 150.0 , -350.0 );
            glScalef(15.0f,15.0f,15.0f);
            objply_letra_A->draw(dib, modo_actual);
        glPopMatrix();
        
        //L1
        glPushMatrix();
            glTranslatef( -30.0 , 150.0 , -350.0 );
            glScalef(15.0f,15.0f,15.0f);
            objply_letra_L->draw(dib, modo_actual);
        glPopMatrix();
        
        //L2
        glPushMatrix();
            glTranslatef( 30.0 , 150.0 , -350.0 );
            glScalef(15.0f,15.0f,15.0f);
            objply_letra_L->draw(dib, modo_actual);
        glPopMatrix();
        
        //E
        glPushMatrix();
            glTranslatef( 90.0 , 150.0 , -350.0 );
            glScalef(15.0f,15.0f,15.0f);
            objply_letra_E->draw(dib, modo_actual);
        glPopMatrix();
        
        //R
        glPushMatrix();
            glTranslatef( 150.0 , 150.0 , -350.0 );
            glScalef(15.0f,15.0f,15.0f);
            objply_letra_R->draw(dib, modo_actual);
        glPopMatrix();
        
}
