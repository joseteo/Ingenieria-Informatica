#include "objrevolucion.h"
#include "objply.h"
#include "elevador.h"

FILE * file;

Elevador::Elevador()
{
    ventanas = new Cubo(1);
    ventanas->asignarCarasAjedrez();
    ventanas->establecer_color_s(0.6,0.6,0.6);
    carlift = new Cilindro(6, 4, 160, 12);
    carlift->asignarCarasAjedrez();
    carlift->establecer_color_s(0.0,0.0,1.0);
    
    
    bases_carlift = new Cono(2, 4, 18, 17);
    bases_carlift->asignarCarasAjedrez();
    bases_carlift->establecer_color_s(0.0,0.0,0.0);
    
    
    soporte = new Cubo(12);
    soporte->asignarCarasAjedrez();
    soporte->establecer_color_s(1.0,1.0,0.0);
    bases_brazos = new Cubo(4);
    bases_brazos->asignarCarasAjedrez();
    bases_brazos->establecer_color_s(0.5,0.5,0.5);
    brazo = new Cubo(4);
    brazo->asignarCarasAjedrez();
    brazo->establecer_color_s(1.0,1.0,0.0);
    base_car = new Cilindro(3,50,5,8);
    base_car->asignarCarasAjedrez();
    base_car->establecer_color_s(0.3,0.3,0.3);
    coche = new ObjPLY("big_dodge.ply");
    coche->asignarCarasAjedrez();
    coche->establecer_color_s(0.8,0.0,0.0);
    //coche->set_textura(text_coche);
}

void Elevador::dibujar(int dib, int modo_actual)
{
        glPushMatrix();
            glTranslatef( 0.0 , 23.5+elevar_y , 2.0 );
            glScalef(14.0f,14.0f,14.0f);
            glRotatef(-90,0,1,0);
            coche->draw(dib, modo_actual);
        glPopMatrix();
    
        glPushMatrix();
            glTranslatef( 0.0 , 42.0+elevar_y , 20.5 );
            glRotatef(-9,1,0,0);
            glScalef(28.0f,8.0f,0.5f);
            ventanas->draw(dib, modo_actual);
        glPopMatrix();
        
        glPushMatrix();
            glTranslatef( -30.2 , 41.0+elevar_y , 2.1 );
            glRotatef(9,0,1,0);
            glScalef(0.5f,9.0f,15.0f);
            ventanas->draw(dib, modo_actual);
        glPopMatrix();
        
        glPushMatrix();
            glTranslatef( 30.2 , 41.0+elevar_y , 2.1 );
            glRotatef(-9,0,1,0);
            glScalef(0.5f,9.0f,15.0f);
            ventanas->draw(dib, modo_actual);
        glPopMatrix();
        
        glPushMatrix();
            glTranslatef( -32.5 , 41.0+elevar_y , -32.0 );
            glScalef(0.5f,9.0f,16.5f);
            ventanas->draw(dib, modo_actual);
        glPopMatrix();
        
        glPushMatrix();
            glTranslatef( 32.5 , 41.0+elevar_y , -32.0 );
            glScalef(0.5f,9.0f,16.5f);
            ventanas->draw(dib, modo_actual);
        glPopMatrix();
        
        glPushMatrix();
            glTranslatef( -32.5 , 41.0+elevar_y , -60.0 );
            glScalef(0.5f,9.0f,10.5f);
            ventanas->draw(dib, modo_actual);
        glPopMatrix();
        
        glPushMatrix();
            glTranslatef( 32.5 , 41.0+elevar_y , -60.0 );
            glScalef(0.5f,9.0f,10.5f);
            ventanas->draw(dib, modo_actual);
        glPopMatrix();
        
        glPushMatrix();
            glTranslatef( 0.0 , 43.0+elevar_y , -83.58 );
            glScalef(16.0f,5.9f,0.5f);
            ventanas->draw(dib, modo_actual);
        glPopMatrix();
        
        
    //carlift
        glPushMatrix();
            glRotatef(45,0,1,0);
            glTranslatef( -50 , -20 , -50 );
            carlift->draw(dib, modo_actual);
        glPopMatrix();
        
        glPushMatrix();
            glRotatef(45,0,1,0);
            glTranslatef( 50 , -20 , 50 );
            carlift->draw(dib, modo_actual);
        glPopMatrix();
        
        glPushMatrix();
            glRotatef(45,0,1,0);
            glTranslatef( -50 , -22 , -50 );
            bases_carlift->draw(dib, modo_actual);
        glPopMatrix();
        
        /*glPushMatrix();
            glRotatef(45,0,1,0);
            glTranslatef( 50 , -22 , 50 );
            bases_carlift->draw(dib, modo_actual);
        glPopMatrix();*/
        
        glPushMatrix();
            glTranslatef( 67  , 7+elevar_y , 0 );
            glScalef(1.0f,2.0f,0.6f);
            soporte->draw(dib, modo_actual);
        glPopMatrix();
        
        glPushMatrix();
            glTranslatef( -67  , 7+elevar_y , 0 );
            glScalef(1.0f,2.0f,0.6f);
            soporte->draw(dib, modo_actual);
        glPopMatrix();
        
        glPushMatrix();
            glTranslatef( 57.9  , -13+elevar_y , 0 );
            glScalef(1.0f,1.0f,7.0f);
            bases_brazos->draw(dib, modo_actual);
        glPopMatrix();
        
        glPushMatrix();
            glTranslatef( -57.9  , -13+elevar_y , 0 );
            glScalef(1.0f,1.0f,7.0f);
            bases_brazos->draw(dib, modo_actual);
        glPopMatrix();
        
        glPushMatrix();
            glTranslatef( 41.5  , -13+elevar_y , -24 );
            glScalef(5.0f,0.9f,0.9f);
            brazo->draw(dib, modo_actual);
        glPopMatrix();
        
        glPushMatrix();
            glTranslatef( 41.5  , -13+elevar_y , 24 );
            glScalef(5.0f,0.9f,0.9f);
            brazo->draw(dib, modo_actual);
        glPopMatrix();
        
        glPushMatrix();
            glTranslatef( -41.5  , -13+elevar_y , -24 );
            glScalef(5.0f,0.9f,0.9f);
            brazo->draw(dib, modo_actual);
        glPopMatrix();
        
        glPushMatrix();
            glTranslatef( -41.5  , -13+elevar_y , 24 );
            glScalef(5.0f,0.9f,0.9f);
            brazo->draw(dib, modo_actual);
        glPopMatrix();
        
        glPushMatrix();
            glTranslatef( -25  , -10+elevar_y , 24 );
            base_car->draw(dib, modo_actual);
        glPopMatrix();
        
        glPushMatrix();
            glTranslatef( -25  , -10+elevar_y , -24 );
            base_car->draw(dib, modo_actual);
        glPopMatrix();
        
        glPushMatrix();
            glTranslatef( 25  , -10+elevar_y , 24 );
            base_car->draw(dib, modo_actual);
        glPopMatrix();
        
        glPushMatrix();
            glTranslatef( 25  , -10+elevar_y , -24 );
            base_car->draw(dib, modo_actual);
        glPopMatrix();
}

void Elevador::moverElevador(float incremento)
{
    if(elevar_y<=0){
        topeElevador=true;
    }
    else if(elevar_y>=75){
        topeElevador=false;
    }
    if(topeElevador==false){
        if(elevar_y-incremento>=0)
            elevar_y-=incremento;
    }
    if(topeElevador==true){
        if(elevar_y+incremento<=75)
            elevar_y+=incremento;
    }
}




