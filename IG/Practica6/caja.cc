#include "objrevolucion.h"
#include "objply.h"
#include "caja.h"

Caja::Caja()
{
    caja = new Cilindro(3,4,40,20.23, false);
    caja->asignarCarasAjedrez();
    caja->establecer_color_s(1.0,0.0,0.0);
    cajon = new Cilindro(3,4,8.47,18.71,false);
    cajon->asignarCarasAjedrez();
    cajon->establecer_color_s(0.0,0.0,0.0);
    rueda = new Cilindro(3,50,2.2,2.95);
    rueda->asignarCarasAjedrez();
    rueda->establecer_color_s(0.0,1.0,0.0);
    soporte_rueda = new Cilindro(3,4,2.52,2.55,false,false);
    soporte_rueda->asignarCarasAjedrez();
    soporte_rueda->establecer_color_s(0.0,0.0,0.0);
    tirador = new Cubo(0.75);
    tirador->asignarCarasAjedrez();
    //tirador->set_material(cromo);
    tirador->establecer_color_s(0.6,0.6,0.6);
}

void Caja::dibujar(int dib, int modo_actual)
{
glPushMatrix();
    glTranslatef( -120.0, 0.0, -30.0);
    glScalef(1.1f,1.1f,1.1f);
    
    glPushMatrix();
        glScalef(1.0f,0.9f,1.0f);
        glTranslatef( 0.0, 0.0, -13.75);
        glRotatef(90,1,0,0);
        glRotatef(45,0,1,0);
        caja->draw(dib, modo_actual);
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef( 0.0, 5.0, 0.0+mover_z);
        glRotatef(45,0,1,0);
        cajon->draw(dib, modo_actual);
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef( 0.0, -2.75, 0.0);
        glRotatef(45,0,1,0);
        cajon->draw(dib, modo_actual);
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef( 0.0, -10.0, 0.0);
        glRotatef(45,0,1,0);
        cajon->draw(dib, modo_actual);
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef( -14.0, -17.0, 11.5);
        glRotatef(180,0,1,0);
        glRotatef(90,1,0,0);
        rueda->draw(dib, modo_actual);
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef( -13.0, -15.0, 11.0);
        glRotatef(90,0,0,1);
        glRotatef(45,0,1,0);
        soporte_rueda->draw(dib, modo_actual);
    glPopMatrix();
    
    
    glPushMatrix();
        glTranslatef( -14.0, -17.0, -11.5);
        glRotatef(180,0,1,0);
        glRotatef(90,1,0,0);
        rueda->draw(dib, modo_actual);
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef( -13.0, -15.0, -11.0);
        glRotatef(90,0,0,1);
        glRotatef(45,0,1,0);
        soporte_rueda->draw(dib, modo_actual);
    glPopMatrix();
    
    
    glPushMatrix();
        glTranslatef( 13.5, -17.0, 11.5);
        glRotatef(180,0,1,0);
        glRotatef(90,1,0,0);
        rueda->draw(dib, modo_actual);
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef( 13.75, -15.0, 11.0);
        glRotatef(90,0,0,1);
        glRotatef(45,0,1,0);
        soporte_rueda->draw(dib, modo_actual);
    glPopMatrix();
    
    
    glPushMatrix();
        glTranslatef( 13.5, -17.0, -11.5);
        glRotatef(180,0,1,0);
        glRotatef(90,1,0,0);
        rueda->draw(dib, modo_actual);
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef( 13.75, -15.0, -11.0);
        glRotatef(90,0,0,1);
        glRotatef(45,0,1,0);
        soporte_rueda->draw(dib, modo_actual);
    glPopMatrix();
    
    
    glPushMatrix();
        glTranslatef( 0.0, 10.0, 13.0+mover_z);
        glScalef(17.5f,1.0f,1.0f);
        tirador->draw(dib, modo_actual);
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef( 0.0, 2.0, 13.0);
        glScalef(17.5f,1.0f,1.0f);
        tirador->draw(dib, modo_actual);
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef( 0.0, -5.0, 13.0);
        glScalef(17.5f,1.0f,1.0f);
        tirador->draw(dib, modo_actual);
    glPopMatrix();
    
glPopMatrix();
}

void Caja::moverCajon(float incremento)
{
    if(mover_z<=0){
        topeCajon=true;
    }
    else if(mover_z>=10){
        topeCajon=false;
    }
    if(topeCajon==false){
        if(mover_z>=0)
            mover_z-=incremento;
    }
    if(topeCajon==true){
        if(mover_z<=10)
            mover_z+=incremento;
    }
}
