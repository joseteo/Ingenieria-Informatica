#ifndef _TEXTURA_H_INCLUDED
#define _TEXTURA_H_INCLUDED

#include "aux.h"
#include "string.h"
#include "jpg_imagen.hpp"


class Textura{

private:
    
    GLuint idTex=0;
    std::vector<unsigned char> data;
    int width, height;
    unsigned char * texels;
    
public:
    Textura(std::string archivo);
    void activar();

};


#endif
