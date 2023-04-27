#include "aux.h"
#include "malla.h"
//#include "textura.h"

// *****************************************************************************
//
// Clase Malla3D
//
// *****************************************************************************



GLuint Malla3D::crearVBO( GLuint tipo_vbo, GLuint tamanio_bytes, GLvoid * puntero_ram )
{
    GLuint id_vbo;
    glGenBuffers( 1, & id_vbo);
    glBindBuffer( tipo_vbo, id_vbo);
    
    glBufferData( tipo_vbo, tamanio_bytes, puntero_ram, GL_STATIC_DRAW);
    glBindBuffer(tipo_vbo, 0);
    
    return id_vbo;
}

void Malla3D::asignarCarasAjedrez()
{
    for (int i = 0; i < f.size(); i++) {
            if (i % 2 == 0)
                caras_p.push_back(f[i]);
            else
                caras_i.push_back(f[i]);
    }
}


void Malla3D::establecer_color_s(int cr, int cg, int cb){
    for(int i = 0; i<color_s.size(); i++)
        color_s[i] = Tupla3u(cr, cg, cb);
}

void Malla3D::establecer_color_p(int cr, int  cg, int cb){
    for(int i = 0; i<color_p.size(); i++)
        color_p[i] = Tupla3u(cr, cg, cb);
}

void Malla3D::establecer_color_l(int cr, int cg, int cb){
    for(int i = 0; i<color_l.size(); i++)
        color_l[i] = Tupla3u(cr, cg, cb);
}

void Malla3D::establecer_color_activo(unsigned char modo){
    activa_color = &color_p[0];
    if(modo == 'p')
        activa_color = &color_p[0];
    if(modo == 'l'){
        activa_color = &color_l[0];
    }
    if(modo == 's'){
        activa_color = &color_s[0];
    }
}



// Visualización en modo inmediato con 'glDrawElements'

void Malla3D::draw_ModoInmediato(std::vector< Tupla3f > vertices, std::vector< Tupla3i > caras, int modo_v, int modo_d)
{
    glEnableClientState(GL_VERTEX_ARRAY);
    //glEnableClientState(GL_COLOR_ARRAY);
    
    glVertexPointer( 3, GL_FLOAT , 0, vertices.data());
    glEnableClientState(GL_NORMAL_ARRAY);
    glNormalPointer(GL_FLOAT, 0, nv.data());
    glPointSize(4);
    
    glPolygonMode(modo_v, modo_d);
    

    glDrawElements( GL_TRIANGLES , caras.size ()*3,GL_UNSIGNED_INT , caras.data() );
    
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisable(GL_TEXTURE_2D);
}
// -----------------------------------------------------------------------------
// Visualización en modo diferido con 'glDrawElements' (usando VBOs)

void Malla3D::draw_ModoDiferido(std::vector< Tupla3f > vertices, std::vector< Tupla3i > caras, int modo_v, int modo_d)
{
    glEnableClientState(GL_NORMAL_ARRAY);
    glNormalPointer(GL_FLOAT, 0, nv.data());
    if(idV == 0)
        idV = crearVBO(GL_ARRAY_BUFFER, vertices.size()*sizeof(float)*8, vertices.data());
    
    if(idT == 0)
        idT = crearVBO(GL_ELEMENT_ARRAY_BUFFER, caras.size()*sizeof(float)*8, caras.data());

    
    glBindBuffer( GL_ARRAY_BUFFER, idV);
    glVertexPointer( 3, GL_FLOAT, 0, 0);
    glBindBuffer( GL_ARRAY_BUFFER, 0);
    glEnableClientState( GL_VERTEX_ARRAY );
    
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, idT);
    
    glPolygonMode(modo_v, modo_d);
    glDrawElements( GL_TRIANGLES, 3*caras.size(), GL_UNSIGNED_INT, 0);
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0);
    
    glDisableClientState( GL_VERTEX_ARRAY );
}
// -----------------------------------------------------------------------------
// Función de visualización de la malla,
// puede llamar a  draw_ModoInmediato o bien a draw_ModoDiferido

void Malla3D::draw(int dib, int tipo)
{
    if(tipo==0){ //modo solido
        GLfloat mat[16];
        glGetFloatv(GL_MODELVIEW_MATRIX, mat);

        Tupla3f n_centro;

        // aplicamos la transformacion de la matriz al punto
        n_centro(0) = mat[0] * centro(0) + mat[4] * centro(1) + mat[8] * centro(2) + mat[12];
        n_centro(1) = mat[1] * centro(0) + mat[5] * centro(1) + mat[9] * centro(2) + mat[13];
        n_centro(2) = mat[2] * centro(0) + mat[6] * centro(1) + mat[10] * centro(2) + mat[14];

        centro_transformado = n_centro;
        
        if(textura!=nullptr){
            textura->activar();
            glEnableClientState(GL_TEXTURE_COORD_ARRAY);
            glTexCoordPointer(2, GL_FLOAT, 0, ct.data());
        }
        if(glIsEnabled(GL_LIGHTING)){
            if(m!=nullptr){
                m->aplicar();
            }
        }
        else{
            activa_color=&color_s[0];
            glColorPointer(3, GL_UNSIGNED_INT, 0, &this->activa_color[0]);
        }
        if(dib==0){
            draw_ModoInmediato(v, f, GL_BACK, GL_FILL);
        }else{
            draw_ModoDiferido(v, f, GL_BACK, GL_FILL);
        }
    }
    else if(tipo==1){ //modo linea
        if(textura!=nullptr){
            textura->activar();
            glEnableClientState(GL_TEXTURE_COORD_ARRAY);
            glTexCoordPointer(2, GL_FLOAT, 0, ct.data());
        }
        if(glIsEnabled(GL_LIGHTING)){
            if(m!=nullptr){
                m->aplicar();
            }
        }
        else{
            activa_color=&color_l[0];
            glColorPointer(3, GL_UNSIGNED_INT, 0, &this->activa_color[0]);
        }
        if(dib==0){
            draw_ModoInmediato(v, f, GL_FRONT_AND_BACK, GL_LINE);
        }else{
            draw_ModoDiferido(v, f, GL_FRONT_AND_BACK, GL_LINE);
        }
    }
    else if(tipo==2){ //modo ajedrez
        establecer_color_p(1,1,1);
        if(dib==0){
            glColorPointer(3, GL_UNSIGNED_INT, 0, color_l.data());
            draw_ModoInmediato(v, caras_i, GL_FRONT_AND_BACK, GL_FILL);
            glColorPointer(3, GL_UNSIGNED_INT, 0, color_p.data());
            draw_ModoInmediato(v, caras_p, GL_FRONT_AND_BACK, GL_FILL);
        }else{
            glColorPointer(3, GL_UNSIGNED_INT, 0, &this->activa_color[0]);
            draw_ModoDiferido(v, caras_i, GL_FRONT_AND_BACK, GL_FILL);
            glColorPointer(3, GL_UNSIGNED_INT, 0, &this->activa_color[0]);
            draw_ModoDiferido(v, caras_p, GL_FRONT_AND_BACK, GL_FILL);
        }
    }
    else if(tipo==3){ //modo puntos
        if(textura!=nullptr){
            textura->activar();
            glEnableClientState(GL_TEXTURE_COORD_ARRAY);
            glTexCoordPointer(2, GL_FLOAT, 0, ct.data());
        }
        if(glIsEnabled(GL_LIGHTING)){
            if(m!=nullptr){
                m->aplicar();
            }
        }
        else{
            activa_color=&color_p[0];
            glColorPointer(3, GL_UNSIGNED_INT, 0, &this->activa_color[0]);
        }
        glPointSize(4);
        if(dib==0){
            draw_ModoInmediato(v, f, GL_FRONT_AND_BACK, GL_POINT);
        }else{
            draw_ModoDiferido(v, f, GL_FRONT_AND_BACK, GL_POINT);
        }
    }
}

void Malla3D::calcular_normales()
{
    Tupla3f p, q, r, a, b, w;
    std::vector<Tupla3f> nc;
    
    for(int i=0; i < f.size(); i++){
        p=v[f[i](0)];
        q=v[f[i](1)];
        r=v[f[i](2)];
        
        a=q-p;
        b=r-p;
        
        w=a.cross(b);
        a=w.normalized();
        nc.push_back(a);
    }
    
    nv.resize(v.size());
    for(int i=0; i<f.size();i++){
        nv[f[i](0)]=nv[f[i](0)]+nc[i];
        nv[f[i](1)]=nv[f[i](1)]+nc[i];
        nv[f[i](2)]=nv[f[i](2)]+nc[i];
    }
    for(int i=0; i<nv.size(); i++){
        // calcular módulo al cuadrado 
        // Si es mayor que epsilon
        nv[i]=nv[i].normalized();
        // si no nv = (0,1,0)
    }
}

void Malla3D::set_material(material* mat)
{
    m=mat;
}

void Malla3D::set_textura(Textura* tex)
{
    textura=tex;
}

Tupla3u Malla3D::getColor() const
{
    return color_s[0];
}

Tupla3f Malla3D::getCentro() const {
    return centro_transformado;
}

void Malla3D::calcularCentro(){
    for (auto it = v.begin(); it != v.end(); ++it){
        centro = centro + (*it);
    }

    centro = centro / v.size();

}
