#include "objrevolucion.h"
#include "objply.h"
#include "mecanico.h"

Mecanico::Mecanico()
{
    brazo = new Cubo(5.1);
    brazo->asignarCarasAjedrez();
    brazo->establecer_color_s(0.2431,0.3725,0.5412);
    pierna = new Cubo(5.1);
    pierna->asignarCarasAjedrez();
    pierna->establecer_color_s(0.2431,0.3725,0.5412);
    torso = new Cubo(8.5);
    torso->asignarCarasAjedrez();
    torso->establecer_color_s(0.2431,0.3725,0.5412);
    cabeza = new Cubo(8.5);
    cabeza->asignarCarasAjedrez();
    cabeza->establecer_color_s(0.9922,0.8667,0.7922);
    
}

void Mecanico::dibujar(int dib, int modo_actual)
{
glPushMatrix();    
    glTranslatef(-110.0,5.0,0.0);
    glScalef(0.55f,0.55f,0.55f);

    glPushMatrix();
        //glRotatef(90,0,0,1);
        glTranslatef( 21.0, 15.0, 0.0);
        
        //brazo derecho
        glPushMatrix();
            glTranslatef( -angulo/11, 33+angulo/6, 0.0);
            glRotatef(angulo,1,0,0);
            glRotatef(angulo,0,0,1);
            glTranslatef( 0.0, -32.5, 0.0);
            glRotatef(angulo,1,0,0);
            glScalef(0.9f,2.4f,1.0f);
            brazo->draw(dib, modo_actual);
        glPopMatrix();
        
        glPushMatrix();
            glTranslatef( 0.0, 33, 0.0);
            glRotatef(angulo,0,0,1);
            glTranslatef( 0.0, -7, 0.0);
            glScalef(0.9f,2.4f,1.0f);
            brazo->draw(dib, modo_actual);
        glPopMatrix();
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef( -21.0, 15.0, 0.0);
        //brazo izquierdo
        glPushMatrix();
            glTranslatef( 0.0, 33-angulo2/6, -angulo2/3);
            glRotatef(-angulo2,1,0,0);
            glTranslatef( 0.0, -32.5, 0.0);
            glRotatef(angulo2+angulo2/2,1,0,0);
            glScalef(0.9f,2.4f,1.0f);
            brazo->draw(dib, modo_actual);
        glPopMatrix();
        
        glPushMatrix();
            glTranslatef( 0.0, 31, 0.0);
            glRotatef(-angulo2,1,0,0);
            glTranslatef( 0.0, -5.0, 0.0);
            glScalef(0.9f,2.4f,1.0f);
            brazo->draw(dib, modo_actual);
        glPopMatrix();
    glPopMatrix();
    

    //torso
    glPushMatrix();
        glTranslatef( 0.0, 27.2, 0.0);
        glScalef(1.75f,3.0f,1.0f);
        torso->draw(dib, modo_actual);
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef( 9.5, -36.8, 0.0);
        //pierna derecha
        glPushMatrix();
            glScalef(1.0f,2.4f,1.0f);
            pierna->draw(dib, modo_actual);
        glPopMatrix();
        
        glPushMatrix();
            glTranslatef( 0.0, 25.5, 0.0);
            glScalef(1.0f,2.4f,1.0f);
            pierna->draw(dib, modo_actual);
        glPopMatrix();
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef( -9.5, -36.8, 0.0);
        //pierna izquierda
        glPushMatrix();
            glScalef(1.0f,2.4f,1.0f);
            pierna->draw(dib, modo_actual);
        glPopMatrix();
        
        glPushMatrix();
            glTranslatef( 0.0, 25.5, 0.0);
            glScalef(1.0f,2.4f,1.0f);
            pierna->draw(dib, modo_actual);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef( 0.0, 62.5, 0.0);
        cabeza->draw(dib, modo_actual);
    glPopMatrix();
glPopMatrix();
}


void Mecanico::moverBrazoDer(float incremento)
{
    if(angulo<=0){
        topeBrazoDer=true;
    }
    else if(angulo>=90){
        topeBrazoDer=false;
    }
    if(topeBrazoDer==false){
        if(angulo-incremento>=0)
            angulo-=incremento;
    }
    if(topeBrazoDer==true){
        if(angulo+incremento<=90)
            angulo+=incremento;
    }
}

void Mecanico::moverBrazoIzq(float incremento)
{
    if(angulo2<=0){
        topeBrazoIzq=true;
    }
    else if(angulo2>=45){
        topeBrazoIzq=false;
    }
    if(topeBrazoIzq==false){
            angulo2-=incremento;
    }
    if(topeBrazoIzq==true){
            angulo2+=incremento;
    }
}
