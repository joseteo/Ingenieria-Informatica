#ifndef CAMARA_H_INCLUDED
#define CAMARA_H_INCLUDED

#include "aux.h"

typedef enum {CUBO, TETRAEDRO, CONNO, ESFERA, PLY, CILINDRO, ANT, BEETHOVEN, LATA,NINGUNO} objetos;

class Camara{
    private:
        Tupla3f eye;
        Tupla3f at;
        Tupla3f up;
        int tipo;//Perspectiva(0) o Ortogonal(1)
        
        objetos seleccionado;

    public:
        Camara(Tupla3f eye, Tupla3f at, Tupla3f up, int tipo, float left, float right, float near, float far, float top, float bottom);
        void rotarXExaminar(float angle);
        void rotarYExaminar(float angle);
        void rotarZExaminar(float angle);
        void rotarXFirstPerson(float angle);
        void rotarYFirstPerson(float angle);
        void rotarZFirstPerson(float angle);
        void mover(float x, float y, float z);
        void zoom(float factor, float left, float rigth, float top, float bottom);
        void setObserver();
        void setProyeccion();
        float getLeft();
        float getRight();
        void setEye(const Tupla3f & newEye);
        void setAt(const Tupla3f & newAt);
        void setUp(const Tupla3f & newUp);
        float left, right, near, far, top, bottom;
        
        void setObjetoSeleccionado(const objetos & obj);
        objetos getObjetoSeleccionado() const;
};
#endif
