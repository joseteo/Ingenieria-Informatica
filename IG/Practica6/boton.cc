#include "objrevolucion.h"
#include "objply.h"
#include "boton.h"

Boton::Boton()
{
    caja= new Cubo(1);
    caja->asignarCarasAjedrez();
    caja->establecer_color_s(0.0,0.0,0.0);
    boton= new Cilindro(3,50,1.5,2.5);
    boton->asignarCarasAjedrez();
    boton->establecer_color_s(1.0,0.0,0.0);
    
}

void Boton::dibujar(int dib, int modo_actual)
{
glPushMatrix();
    glTranslatef(-80.0,40.0,0.0);

    glPushMatrix();
        glScalef(1.0f,10.0f,5.0f);
        caja->draw(dib, modo_actual);
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(-1.5+cantidad,0.0,0.0);
        glRotatef(90,0,0,1);
        glRotatef(180,1,0,0);
        boton->draw(dib, modo_actual);
    glPopMatrix();
glPopMatrix();
}

void Boton::moverBoton(float incremento)
{
    if(cantidad+incremento<=-0.9 && cantidad+incremento>=-1.5){
        cantidad+=incremento;
    }
}
