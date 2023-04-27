#include "textura.h"

Textura::Textura(std::string archivo)
{
    jpg::Imagen * pimg = NULL;
    pimg = new jpg::Imagen(archivo);

    height=pimg->tamY();
    width=pimg->tamX();
    texels=pimg->leerPixels();
    
}


void Textura::activar()
{
    glEnable(GL_TEXTURE_2D);
    if(idTex==0){
        glGenTextures(1, &idTex);
        glBindTexture(GL_TEXTURE_2D, idTex);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, texels);
    }
    glBindTexture(GL_TEXTURE_2D, idTex);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

    glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL, GL_SEPARATE_SPECULAR_COLOR);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}
