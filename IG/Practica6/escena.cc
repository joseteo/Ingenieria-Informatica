

#include "aux.h"     // includes de OpenGL/glut/glew, windows, y librería std de C++
#include "escena.h"
#include "malla.h" // objetos: Cubo y otros....
#include "objply.h"
#include "objrevolucion.h"
#include "luz.h"
#include "camara.h"
#include "material.h"


//**************************************************************************
// constructor de la escena (no puede usar ordenes de OpenGL)
//**************************************************************************

Escena::Escena()
{
    Front_plane       = 50.0;
    Back_plane        = 2000.0;
    Observer_distance = 4*Front_plane;
    Observer_angle_x  = 0.0 ;
    Observer_angle_y  = 0.0 ;

    ejes.changeAxisSize( 5000 );

    cubo = new Cubo(50);
    cubo->asignarCarasAjedrez();
    tetraedro = new Tetraedro();
    tetraedro->asignarCarasAjedrez();
    objply_ant = new ObjPLY("ant.ply");
    objply_ant->asignarCarasAjedrez();
    objply_beethoven = new ObjPLY("beethoven.ply");
    objply_beethoven->asignarCarasAjedrez();
    peonB = new ObjRevolucion("peon.ply", 30, false, false);
    peonB->asignarCarasAjedrez();
    peonB->set_material(m_B);
    peonN = new ObjRevolucion("peon.ply", 30, true, true);
    peonN->asignarCarasAjedrez();
    peonN->set_material(m_N);
    cilindro = new Cilindro(3,50,30,10,true,true,true);
    cilindro->asignarCarasAjedrez();
    cono = new Cono();
    cono->asignarCarasAjedrez();
    esfera = new Esfera(50,50,15,true);
    esfera->asignarCarasAjedrez();
    esfera->set_textura(madera);
    //esfera->set_material(m_B);
    objrev_pcue = new ObjRevolucion("lata-pcue", 20, true, true,true);
    objrev_pcue->asignarCarasAjedrez();
    objrev_pcue->set_material(m_B);
    objrev_pcue->set_textura(cocacola);
    objrev_pinf = new ObjRevolucion("lata-pcue", 20, false, false);
    objrev_pinf->asignarCarasAjedrez();
    objrev_psup = new ObjRevolucion("lata-pcue", 20, false, false);
    objrev_psup->asignarCarasAjedrez();
    

    
    //luces
    luzPos1 = new luzposicional({250, 0, 0}, GL_LIGHT0, {0.24725, 0.1995, 0.0745, 0.6}, {0.75164, 0.60648, 0.22648, 0.0}, {0.628281, 0.555802, 0.366065, 0.0});
    luzPos2 = new luzposicional({-250, 0, 0}, GL_LIGHT1, {1,1,1,1}, {1,1,1,1}, {1,1,1,1});
    luzPos3 = new luzposicional({0, 250, 0}, GL_LIGHT2, {0.24725, 0.1995, 0.0745, 0.6}, {0.75164, 0.60648, 0.22648, 0.0}, {0.628281, 0.555802, 0.366065, 0.0});
    luzPos4 = new luzposicional({0, -250, 0}, GL_LIGHT3, {0.24725, 0.1995, 0.0745, 0.6}, {0.75164, 0.60648, 0.22648, 0.0}, {0.628281, 0.555802, 0.366065, 0.0});
    luzPos5 = new luzposicional({0, 0, 250}, GL_LIGHT4, {0.24725, 0.1995, 0.0745, 0.6}, {0.75164, 0.60648, 0.22648, 0.0}, {0.628281, 0.555802, 0.366065, 0.0});
    luzPos6 = new luzposicional({0, 0, -250}, GL_LIGHT5, {0.24725, 0.1995, 0.0745, 0.6}, {0.75164, 0.60648, 0.22648, 0.0}, {0.628281, 0.555802, 0.366065, 0.0});
    luzDir7 = new luzdireccional({0, 50, 259}, GL_LIGHT6, {0.24725, 0.1995, 0.0745, 0.6}, {0.75164, 0.60648, 0.22648, 0.0}, {0.628281, 0.555802, 0.366065, 0.0});
    luzDir8 = new luzdireccional({259, 50, 0}, GL_LIGHT7, {0.24725, 0.1995, 0.0745, 0.6}, {0.75164, 0.60648, 0.22648, 0.0}, {0.628281, 0.555802, 0.366065, 0.0});

    //camaras
    cam0 = new Camara({0.0, 100.0, 200.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, 0, -1.0, 1.0, 1.0, 450.0, 1.0,-1.0);
    cam1 = new Camara({100.0, 100.0, 200.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, 0, -1.0, 1.0, 0.5, 450.0, 1.0,-1.0);
    cam2 = new Camara({0.0, 100.0, -200.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, 0, -1.0, 1.0, 0.5, 450.0, 1.0,-1.0);
    cam3 = new Camara({-100.0, 100.0, 200.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, 0, -1.0, 1.0, 0.5, 450.0, 1.0,-1.0);
    cam4 = new Camara({-100.0, 100.0, 200.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, 1, -1.0, 1.0, 0.5, 450.0, 1.0,-1.0);

    camaras.push_back(*cam0);
    camaras.push_back(*cam1);
    camaras.push_back(*cam2);
    camaras.push_back(*cam3);
    camaras.push_back(*cam4);
    
    
    //objetos lamborghini
    
    taller = new Taller();
    elevador = new Elevador();
    caja = new Caja();
    mecanico = new Mecanico();
    boton = new Boton();

}

//va**************************************************************************
// inicialización de la escena (se ejecuta cuando ya se ha creado la ventana, por
// tanto sí puede ejecutar ordenes de OpenGL)
// Principalmemnte, inicializa OpenGL y la transf. de vista y proyección
//**************************************************************************

void Escena::inicializar( int UI_window_width, int UI_window_height )
{
    glClearColor( 1.0, 1.0, 1.0, 1.0 );// se indica cual sera el color para limpiar la ventana	(r,v,a,al)

    glEnable( GL_DEPTH_TEST );	// se habilita el z-bufer

    Width  = UI_window_width/10;
    Height = UI_window_height/10;

    change_projection( float(UI_window_width)/float(UI_window_height) );
    glViewport( 0, 0, UI_window_width, UI_window_height );
}


// **************************************************************************
//
// función de dibujo de la escena: limpia ventana, fija cámara, dibuja ejes,
// y dibuja los objetos
//
// **************************************************************************


void Escena::dibujar()
{
    glEnable(GL_NORMALIZE);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_FLAT);
    glEnable(GL_DITHER);
    
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Limpiar la pantalla
    change_observer();
    ejes.draw();
    
    if(iluminacion){
        if(mod_vis==0)
            glShadeModel(GL_SMOOTH);
        else
            glShadeModel(GL_FLAT);
        
        if(interruptorLuz[0]){
            glEnable(GL_LIGHT0);
            luzPos1->activar();
        }
        else{
            glDisable(GL_LIGHT0);
        }
        if(interruptorLuz[1]){
            glEnable(GL_LIGHT1);
            luzPos2->activar();
        }
        else{
            glDisable(GL_LIGHT1);
        }
        if(interruptorLuz[2]){
            glEnable(GL_LIGHT2);
            luzPos3->activar();
        }
        else{
            glDisable(GL_LIGHT2);
        }
        if(interruptorLuz[3]){
            glEnable(GL_LIGHT3);
            luzPos4->activar();
        }
        else{
            glDisable(GL_LIGHT3);
        }
        if(interruptorLuz[4]){
            glEnable(GL_LIGHT4);
            luzPos5->activar();
        }
        else{
            glDisable(GL_LIGHT4);
        }
        if(interruptorLuz[5]){
            glEnable(GL_LIGHT5);
            luzPos6->activar();
        }
        else{
            glDisable(GL_LIGHT5);
        }
        if(interruptorLuz[6]){
            glEnable(GL_LIGHT6);
            luzDir7->activar();
        }
        else{
            glDisable(GL_LIGHT6);
        }
        if(interruptorLuz[7]){
            glEnable(GL_LIGHT7);
            luzDir8->activar();
        }
        else{
            glDisable(GL_LIGHT7);
        }
    }
    
    if(obj == CUB){
        glPushMatrix();
        cubo->draw(dib, modo_actual);
        glPopMatrix();
    }
    else if(obj == TRI){
        glPushMatrix();
        tetraedro->draw(dib, modo_actual);
        glPopMatrix();
    }
            //d.push_back( (d.at(j) + fabsf( (v_aux.at(j+1)[1] - v_aux.at(j)[1]) ) ) );
    else if(obj == PL){
        
        glPushMatrix();
            glTranslatef(100.0, 0.0, -200.0);
            
            tetraedro->draw(dib, modo_actual);
        glPopMatrix();
        
        glPushMatrix();
            glTranslatef(100.0, 0.0, -100.0);
            glScalef(5.0f,5.0f,5.0f);
            objply_ant->draw(dib, modo_actual);
        glPopMatrix();
        
        glPushMatrix();
            glTranslatef(-100.0, 0.0, -100.0);
            glScalef(10.0f,10.0f,10.0f);
            objply_beethoven->draw(dib, modo_actual);
        glPopMatrix();
        
        glPushMatrix();
            glTranslatef(-100.0, 0.0, -200.0);
            glScalef(5.0f,5.0f,5.0f);
            cilindro->draw(dib, modo_actual);
        glPopMatrix();
    }
    else if(obj == OBJREV){
        /*
        glPushMatrix();
            //glTranslatef(0.0, 0.0, 0.0);
            glScalef(4.0f,4.0f,4.0f);
            cilindro->draw(dib, modo_actual);
        glPopMatrix();
        
        
        glPushMatrix();
            glTranslatef(100.0, 0.0, -100.0);
            glScalef(4.0f,4.0f,4.0f);
            cono->draw(dib, modo_actual);
        glPopMatrix();
        
        
        glPushMatrix();
            glTranslatef(30.0, 35.0, 0.0);
            glScalef(29.0f,29.0f,29.0f);
            peonB->draw(dib, modo_actual);
        glPopMatrix();
        
        glPushMatrix();
            glTranslatef(-30.0, 35.0, 0.0);
            glScalef(29.0f,29.0f,29.0f);
            peonN->draw(dib, modo_actual);
        glPopMatrix();
        
        */
        glPushMatrix();
            glTranslatef(-60.0, 50.0, 0.0);
            glScalef(3.0f,3.0f,3.0f);
            esfera->draw(dib, modo_actual);
        glPopMatrix();
        
        glPushMatrix();
            glTranslatef(50.0, -1.0, 0.0);
            glScalef(110.0f,110.0f,110.0f);
            //glRotatef(90,0,1,0);
            //glRotatef(180,0,0,1);
            objrev_pcue->draw(dib, modo_actual);
        glPopMatrix();
        /*
        glPushMatrix();
            glTranslatef(0.0, 0.0, -100.0);
            glScalef(110.0f,110.0f,110.0f);
            objrev_pinf->draw(dib, modo_actual);
        glPopMatrix();
        
        glPushMatrix();
            glTranslatef(0.0, 0.0, -100.0);
            glScalef(110.0f,110.0f,110.0f);
            objrev_psup->draw(dib, modo_actual);
        glPopMatrix();*/
        
    }
    
    else if(obj == LAMBO){
        
        taller->dibujar(dib, modo_actual);
        elevador->dibujar(dib, modo_actual);
        caja->dibujar(dib, modo_actual);
        mecanico->dibujar(dib, modo_actual);
        boton->dibujar(dib, modo_actual);
    }
}

//**************************************************************************
//
// función que se invoca cuando se pulsa una tecla
// Devuelve true si se ha pulsado la tecla para terminar el programa (Q),
// devuelve false en otro caso.
//
//**************************************************************************

bool Escena::teclaPulsada( unsigned char tecla, int x, int y )
{
   using namespace std ;
   cout << "Tecla pulsada: '" << tecla << "'" << endl;
   bool salir=false;
   switch( toupper(tecla) )
   {
      case 'Q' :
          animacionManual=false;
         if (modoMenu!=NADA){
            modoMenu=NADA;
            cout<<endl<< "    PULSE q:para salir" <<endl;
            cout<< "    PULSE O:para modo seleccion de objeto" <<endl;
            cout<< "    PULSE V:para modo visualizacion" <<endl;
            cout<< "    PULSE D:para modo dibujado" <<endl;
            cout<< "    PULSE A:para animar Modelo" <<endl;
            cout<< "    PULSE M:para animar Modelo manualmente" <<endl;
            cout<< "    PULSE C:para modo seleccion de camaras" <<endl;
         }else {
            salir=true ;
         }
         break ;
      case 'O' :
        // ESTAMOS EN MODO SELECCION DE OBJETO
        cout <<endl<< "        Modo seleccion de objeto: ( C->cubo , T->tetraedro , F->figura PLY , R->objetosRevolucion , N->proyecto Lamborghini) " <<endl<<endl;
        modoMenu=SELOBJETO; 
        break ;
      case 'C' :
          /*
        if(modoMenu==SELOBJETO && obj!=CUB){
             obj=CUB;
             dibujar();
        }else if(modoMenu!=SELOBJETO){
            cout<<endl<< "no esta en modo seleccion"<<endl<<endl;
        }else if(modoMenu==SELOBJETO && obj==CUB){
            obj=CERO;
            dibujar();
        }*/
        activoCamara=!activoCamara;
        
        break;
      case 'T' :
        if(modoMenu==SELOBJETO && obj!=TRI){
             obj=TRI;
             dibujar();
        }else if(modoMenu!=SELOBJETO){
            cout<<endl<< "no esta en modo seleccion"<<endl<<endl;
        }else if(modoMenu==SELOBJETO && obj==TRI){
            obj=CERO;
            dibujar();
        }
        break;
      case 'F':
        if(modoMenu==SELOBJETO && obj!=PL){
            obj=PL;
            dibujar();
        }else if(modoMenu!=SELOBJETO){
            cout<<endl<< "no esta en modo seleccion"<<endl<<endl;
        }else if(modoMenu==SELOBJETO && obj==PL){
            obj=CERO;
            dibujar();
        }
        break;
      case 'R':
        if(modoMenu==SELOBJETO && obj!=OBJREV){
            obj=OBJREV;
            dibujar();
        }else if(modoMenu!=SELOBJETO){
            cout<<endl<< "no esta en modo seleccion"<<endl<<endl;
        }else if(modoMenu==SELOBJETO && obj==OBJREV){
            obj=CERO;
            dibujar();
        }
        break;
      case 'N':
        if(modoMenu==SELOBJETO && obj!=LAMBO){
            obj=LAMBO;
            dibujar();
        }else if(modoMenu!=SELOBJETO){
            cout<<endl<< "no esta en modo seleccion"<<endl<<endl;
        }else if(modoMenu==SELOBJETO && obj==LAMBO){
            obj=CERO;
            dibujar();
        }
        break;
      case 'V' :
         // ESTAMOS EN MODO SELECCION DE MODO DE VISUALIZACION
         cout <<endl<< "        Modo visualizacion de objeto: ( P->punto , L->lado , S->solido , A->ajedrez , I->iluminacion ) " <<endl<<endl;
         modoMenu=SELVISUALIZACION;
         break ;
      case 'P' :
        if(modoMenu==SELVISUALIZACION && modo_actual!=3){
            glDisable(GL_LIGHTING);
            iluminacion=false;
            modo_actual=3;
            dibujar();
        }else if(modoMenu!=SELVISUALIZACION){
            cout<<endl<<"no esta en modo visualizacion"<<endl;
        }else if(modoMenu==SELVISUALIZACION && modo_actual==3){
            modo_actual=0;
            dibujar();
        }
        break;
      case 'L' :
        if(modoMenu==SELVISUALIZACION && modo_actual!=1){
            glDisable(GL_LIGHTING);
            iluminacion=false;
            modo_actual=1;
            dibujar();
        }else if(modoMenu!=SELVISUALIZACION){
            cout<<endl<<"no esta en modo visualizacion"<<endl;
        }else if(modoMenu==SELVISUALIZACION && modo_actual==1){
            modo_actual=0;
            dibujar();
        }
        break;
      case 'S' :
        if(modoMenu==SELVISUALIZACION && modo_actual!=0){
            glDisable(GL_LIGHTING);
            iluminacion=false;
            modo_actual=0;
            dibujar();
        }else if(modoMenu!=SELVISUALIZACION){
            cout<<endl<<"no esta en modo visualizacion"<<endl;
        }else if(modoMenu==SELVISUALIZACION && modo_actual==0){
            modo_actual=0;
            dibujar();
        }
        break;
      case 'A' :

        if(modoMenu==SELVISUALIZACION && modo_actual!=2){
            if(glIsEnabled(GL_LIGHTING)){
                alpha=true;
                beta=false;
            }
//             glDisable(GL_LIGHTING);
//             iluminacion=false;
            modo_actual=2;
            dibujar();
        }else if(modoMenu!=SELVISUALIZACION){
            animacionAuto=!animacionAuto;
            animacionManual=false;
            cout << "Activando animacion AUTOMATICA" << endl;
            cout << "Ahora pulsa + para aumentar la velocidad o - para disminuirla" << endl;
            anguloDer=1;
            anguloIzq=2;
            moverElevador=0.5;
            moverCajon=0.45;
            this->animarModeloJerarquico();
        }else if(modoMenu==SELVISUALIZACION && modo_actual==2){
            if(glIsEnabled(GL_LIGHTING))
                alpha=!alpha;
            else{
            modo_actual=0;
            dibujar();
            }
        }
        break;
      case 'M':
            animacionManual=!animacionManual;
            animacionAuto=false;
            cout << "Activando animacion MANUAL Pulsa 0 (mecanico) 1 (elevador) 2 (cajon) para mover esa parte." << endl;
        break;
      case 'I' :
        if(modoMenu==SELVISUALIZACION && modo_actual!=4){
            modo_actual=4;
            iluminacion=!iluminacion;
            if(iluminacion)
                glEnable(GL_LIGHTING);
            else
                glDisable(GL_LIGHTING);
            cout << "Pulse Y para suavizada" << endl;
            cout << "Pulse U para plana" << endl;
            cout << "Pulse A para activar alfa" << endl;
            cout << "Pulse B para activar beta" << endl;
            cout << "Pulse > para incrementar el angulo" << endl;
            cout << "Pulse < para decrementar el angulo" << endl;
            cout << "Pulse 0 para activar/desactivar la luz 0" << endl;
            cout << "Pulse 1 para activar/desactivar la luz 1" << endl;
            cout << "Pulse 2 para activar/desactivar la luz 2" << endl;
            cout << "Pulse 3 para activar/desactivar la luz 3" << endl;
            cout << "Pulse 4 para activar/desactivar la luz 4" << endl;
            cout << "Pulse 5 para activar/desactivar la luz 5" << endl;
            cout << "Pulse 6 para activar/desactivar la luz 6" << endl;
            cout << "Pulse 7 para activar/desactivar la luz 7" << endl;
        }else if(modoMenu!=SELVISUALIZACION){
            cout<<endl<<"no esta en modo visualizacion"<<endl;
        }else if(modoMenu==SELVISUALIZACION && modo_actual==4){
            modo_actual=0;
            glDisable(GL_LIGHTING);
            dibujar();
        }
        break;
      case 'B':
          beta=!beta;
          alpha=!alpha;
          dibujar();
        break;
      case 'Y':
          mod_vis=0;
          dibujar();
        break;
      case 'U':
          mod_vis=1;
          dibujar();
        break;
      case '0' :
        if(iluminacion && modoMenu==SELVISUALIZACION){
            interruptorLuz[0]=!interruptorLuz[0];
            modo_actual=0;
            dibujar();
        }if(animacionManual){
            cout << "Ahora pulsa + para aumentar el movimiento o - para disminuir" << endl;
            parteTaller[0]=!parteTaller[0];
            parteTaller[1]=false;
            parteTaller[2]=false;
        }if(activoCamara){
            camaraActiva[0]=!camaraActiva[0];
            camaraActiva[1]=false;
            camaraActiva[2]=false;
            camaraActiva[3]=false;
            camaraActiva[4]=false;
            numCamaraActiva=0;
        }
        else
            cout << "No se ha activado la iluminacion"<<endl;
            
        
        break;
      case '3' :
        if(iluminacion && modoMenu==SELVISUALIZACION){
            interruptorLuz[3]=!interruptorLuz[3];
            modo_actual=0;
            dibujar();
        }if(activoCamara){
            camaraActiva[3]=!camaraActiva[3];
            camaraActiva[0]=false;
            camaraActiva[1]=false;
            camaraActiva[2]=false;
            camaraActiva[4]=false;
            numCamaraActiva=3;
        }else
            cout << "No se ha activado la iluminacion"<<endl;
        
        break;
      case '4' :
        if(iluminacion && modoMenu==SELVISUALIZACION){
            interruptorLuz[4]=!interruptorLuz[4];
            modo_actual=0;
            dibujar();
        }if(activoCamara){
            camaraActiva[4]=!camaraActiva[4];
            camaraActiva[0]=false;
            camaraActiva[1]=false;
            camaraActiva[2]=false;
            camaraActiva[3]=false;
            numCamaraActiva=4;
        }else
            cout << "No se ha activado la iluminacion"<<endl;
        
        break;
      case '5':
        if(iluminacion && modoMenu==SELVISUALIZACION){
            interruptorLuz[5]=!interruptorLuz[5];
            modo_actual=0;
            dibujar();
        }else
            cout << "No se ha activado la iluminacion"<<endl;
        
        break;
      case '6':
        if(iluminacion && modoMenu==SELVISUALIZACION){
            interruptorLuz[6]=!interruptorLuz[6];
            modo_actual=0;
            dibujar();
        }else
            cout << "No se ha activado la iluminacion"<<endl;
        
        break;
      case '7':
        if(iluminacion && modoMenu==SELVISUALIZACION){
            interruptorLuz[7]=!interruptorLuz[7];
            modo_actual=0;
            dibujar();
        }else
            cout << "No se ha activado la iluminacion"<<endl;
        
        break;
      case '>':
          if(interruptorLuz[6]){
            if(alpha){
                if(variarAnguloAlpha<=360.0){
                    variarAnguloAlpha=0;
                }
                variarAnguloAlpha+=0.3;
                this->variarLuces(variarAnguloAlpha);
            }
            if(beta){
                if(variarAnguloBeta<=360.0){
                    variarAnguloBeta=0;
                }
                variarAnguloBeta+=0.3;
                this->variarLuces(variarAnguloBeta);
            }
        }
        if(interruptorLuz[7]){
            if(alpha){
                if(variarAnguloAlpha<=360.0){
                    variarAnguloAlpha=0;
                }
                variarAnguloAlpha+=0.3;
                this->variarLuces(variarAnguloAlpha);
            }
            if(beta){
                if(variarAnguloBeta<=360.0){
                    variarAnguloBeta=0;
                }
                variarAnguloBeta+=0.3;
                this->variarLuces(variarAnguloBeta);
            }
        }
        dibujar();
        break;
      case '<':
          if(interruptorLuz[6]){
            if(alpha){
                if(variarAnguloAlpha>=360.0){
                    variarAnguloAlpha=0;
                }
                variarAnguloAlpha-=0.3;
                this->variarLuces(variarAnguloAlpha);
            }
            if(beta){
                if(variarAnguloBeta>=360.0){
                    variarAnguloBeta=0;
                }
                variarAnguloBeta-=0.3;
                this->variarLuces(variarAnguloBeta);
            }
            
        }
        if(interruptorLuz[7]){
            if(alpha){
                if(variarAnguloAlpha>=360.0){
                    variarAnguloAlpha=0;
                }
                variarAnguloAlpha-=0.3;
                this->variarLuces(variarAnguloAlpha);
            }
            if(beta){
                if(variarAnguloBeta>=360.0){
                    variarAnguloBeta=0;
                }
                variarAnguloBeta-=0.3;
                this->variarLuces(variarAnguloBeta);
            }
            
        }
        dibujar();
        break;
      case 'D' :
         // ESTAMOS EN MODO SELECCION DE DIBUJADO
         cout <<endl<< "        Modo seleccion de dibujado: ( 1->glDrawElements , 2->VBOs ) " <<endl<<endl;
         modoMenu=SELDIBUJADO;
         break ;
      case '1':
        if(activoCamara){
            camaraActiva[1]=!camaraActiva[1];
            camaraActiva[0]=false;
            camaraActiva[2]=false;
            camaraActiva[3]=false;
            camaraActiva[4]=false;
            numCamaraActiva=1;
        }
        if(animacionManual){
            cout << "Ahora pulsa + para aumentar el movimiento o - para disminuir" << endl;
            parteTaller[1]=!parteTaller[1];
            parteTaller[0]=false;
            parteTaller[2]=false;
        }
        if(modoMenu==SELDIBUJADO && dib!=0){
            dib=0;
            dibujar();
        }else if(modoMenu!=SELDIBUJADO){
            if(iluminacion && modoMenu==SELVISUALIZACION){
                interruptorLuz[1]=!interruptorLuz[1];
                modo_actual=0;
                dibujar();
            }else
                cout << "No se ha activado la iluminacion"<<endl;
            
            cout<<endl<<"no esta en modo dibujado"<<endl;
        }
        break;
      case '2':
        if(activoCamara){
            camaraActiva[2]=!camaraActiva[2];
            camaraActiva[0]=false;
            camaraActiva[1]=false;
            camaraActiva[3]=false;
            camaraActiva[4]=false;
            numCamaraActiva=2;
        }
        if(animacionManual){
            cout << "Ahora pulsa + para aumentar el movimiento o - para disminuir" << endl;
            parteTaller[2]=!parteTaller[2];
            parteTaller[0]=false;
            parteTaller[1]=false;
        }
        if(modoMenu==SELDIBUJADO && dib!=1){
            dib=1;
            dibujar();
        }else if(modoMenu!=SELDIBUJADO){
            if(iluminacion && modoMenu==SELVISUALIZACION){
                interruptorLuz[2]=!interruptorLuz[2];
                modo_actual=0;
                dibujar();
            }else
                cout << "No se ha activado la iluminacion"<<endl;
            
            
            cout<<endl<<"no esta en modo dibujado"<<endl;
        }
        break;

      case '+':
        if(animacionAuto){
            anguloDer+=0.15;
            anguloIzq+=0.15;
            moverElevador+=0.15;
            moverCajon+=0.15;
        }
        if(animacionManual){
            if(velocidad<0)
                velocidad=velocidad*(-1);
            if(parteTaller[0]==true){
                anguloDer+=0.5;
                anguloIzq+=0.5;
                this->animarMecanico();
            }
            if(parteTaller[1]==true){
                moverElevador+=0.5;
                this->animarElevador();
            }
            if(parteTaller[2]==true){
                moverCajon+=0.5;
                this->animarCajon();
            }
        }
        break;
        
        case '-':
        if(animacionAuto){
            if(anguloDer>0)
                anguloDer-=0.15;
            if(anguloIzq>0)
                anguloIzq-=0.15;
            if(moverElevador>0)
                moverElevador-=0.15;
            if(moverCajon>0)
                moverCajon-=0.15;
        }
        if(animacionManual){
            if(velocidad<0)
                velocidad=velocidad*(-1);
            if(parteTaller[0]==true){
                if(anguloDer>0)
                    anguloDer-=0.5;
                if(anguloIzq>0)
                    anguloIzq-=0.5;
                this->animarMecanico();
            }
            if(parteTaller[1]==true){
                if(moverElevador>0)
                    moverElevador-=0.5;
                this->animarElevador();
            }
            if(parteTaller[2]==true){
                if(moverCajon>0)
                    moverCajon-=0.5;
                this->animarCajon();
            }
        }
        break;
   }
   return salir;
}
//**************************************************************************

void Escena::teclaEspecial( int Tecla1, int x, int y )
{
   switch ( Tecla1 )
   {/*
	   case GLUT_KEY_LEFT:
         Observer_angle_y-- ;
         break;
	   case GLUT_KEY_RIGHT:
         Observer_angle_y++ ;
         break;
	   case GLUT_KEY_UP:
         Observer_angle_x-- ;
         break;
	   case GLUT_KEY_DOWN:
         Observer_angle_x++ ;
         break;
	   case GLUT_KEY_PAGE_UP:
         Observer_distance *=1.2 ;
         break;
	   case GLUT_KEY_PAGE_DOWN:
         Observer_distance /= 1.2 ;
         break;
         */
       case GLUT_KEY_LEFT:
         if(activoCamara){
            camaras[numCamaraActiva].rotarYFirstPerson(-3.0);
                
         }
         else{
            Observer_angle_y-- ;
         }
        break;
       case GLUT_KEY_RIGHT:
         if(activoCamara){
            camaras[numCamaraActiva].rotarYFirstPerson(3.0);
         }
         else{
            Observer_angle_y++ ;
         }
        break;
       case GLUT_KEY_UP:
         if(activoCamara){
            camaras[numCamaraActiva].rotarXFirstPerson(3.0);
         }
         else{
            Observer_angle_x-- ;
         }
        break;
       case GLUT_KEY_DOWN:
         if(activoCamara){
            camaras[numCamaraActiva].rotarXFirstPerson(-3.0);
         }
         else{
            Observer_angle_x++ ;
         }
        break;
       case GLUT_KEY_PAGE_UP:
         if(activoCamara){
            camaras[numCamaraActiva].zoom(2.0, camaras[numCamaraActiva].left, camaras[numCamaraActiva].right, camaras[numCamaraActiva].top, camaras[numCamaraActiva].bottom);
         }
         else{ 
            Observer_distance *=1.2 ;
         }
        
        break;
       case GLUT_KEY_PAGE_DOWN:
         if(activoCamara){
            camaras[numCamaraActiva].zoom(0.5, camaras[numCamaraActiva].left, camaras[numCamaraActiva].right, camaras[numCamaraActiva].top, camaras[numCamaraActiva].bottom);
         }
         else{ 
            Observer_distance /= 1.2 ;
         }
        break;
	}

	//std::cout << Observer_distance << std::endl;
}

//**************************************************************************
// Funcion para definir la transformación de proyeccion
//
// ratio_xy : relacción de aspecto del viewport ( == ancho(X) / alto(Y) )
//
//***************************************************************************

void Escena::change_projection( const float ratio_xy )
{
   glMatrixMode( GL_PROJECTION );
   glLoadIdentity();
   
   if(!activoCamara){
        const float wx = float(Height)*ratio_xy ;
        glFrustum( -wx, wx, -Height, Height, Front_plane, Back_plane );
   }else{
       camaras[numCamaraActiva].setProyeccion();
   }
}
//**************************************************************************
// Funcion que se invoca cuando cambia el tamaño de la ventana
//***************************************************************************

void Escena::redimensionar( int newWidth, int newHeight )
{
    const float ratio = (float)newWidth/(float)newHeight;
    
    for (int i = 0; i < camaras.size(); i++){

        camaras[i].left=camaras[i].bottom*ratio;
        camaras[i].right=camaras[i].top*ratio;

    }
//    Width  = newWidth/10;
//    Height = newHeight/10;
   change_projection( float(newHeight)/float(newWidth) );
   glViewport( 0, 0, newWidth, newHeight );
}

//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************

void Escena::change_observer()
{
   // posicion del observador
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   
   if(!activoCamara){
       glTranslatef( 0.0, 0.0, -Observer_distance );
       glRotatef( Observer_angle_y, 0.0 ,1.0, 0.0 );
       glRotatef( Observer_angle_x, 1.0, 0.0, 0.0 );
   }else{
       camaras[numCamaraActiva].setObserver();
       glGetFloatv(GL_MODELVIEW_MATRIX, matrix);
   }
}

void Escena::variarLuces(float incremento)
{
    if(this->interruptorLuz[6]){
        if(alpha){
            luzDir7->variarAnguloAlpha(incremento);
        }
        if(beta){
            luzDir7->variarAnguloBeta(incremento);
        }
    }
    if(this->interruptorLuz[7]){
        if(alpha){
            luzDir8->variarAnguloAlpha(incremento);
        }
        if(beta){
            luzDir8->variarAnguloBeta(incremento);
        }
    }
}

void Escena::animarModeloJerarquico()
{
    if(this->animacionAuto==true){
        mecanico->moverBrazoDer(anguloDer);
        mecanico->moverBrazoIzq(anguloIzq);
        elevador->moverElevador(moverElevador);
        caja->moverCajon(moverCajon);
    }
}

void Escena::animarMecanico()
{
    mecanico->moverBrazoDer(anguloDer);
    mecanico->moverBrazoIzq(anguloIzq);
}

void Escena::animarElevador()
{
    elevador->moverElevador(moverElevador);
}

void Escena::animarCajon()
{
    caja->moverCajon(moverCajon);
}

void Escena::mover(int x, int y)
{
    camaras[numCamaraActiva].rotarXFirstPerson(x);
    camaras[numCamaraActiva].rotarYFirstPerson(y);
}


void Escena::ratonMovido(int x, int y)
{
    if( moverse){
        this->mover(x-xant, y-yant);
        xant=x;
        yant=y;
    }
}

void Escena::zoom(float factor)
{
    camaras[numCamaraActiva].zoom(factor, camaras[numCamaraActiva].left, camaras[numCamaraActiva].right, camaras[numCamaraActiva].top, camaras[numCamaraActiva].bottom);
}


void Escena::dibujaSeleccion(){

    // deshabilitamos el degradado
    glDisable(GL_DITHER);
    glDisable(GL_LIGHTING);
    glDisable(GL_TEXTURE);


    //glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Limpiar la pantalla

    change_observer();

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    int dib_tmp = dib;

    cout << endl << dib << endl;
    dibujar();    // usar los id como colores

    dib = dib_tmp;



    glEnable(GL_DITHER);
    glEnable(GL_LIGHTING);
    glEnable(GL_TEXTURE);

}


Tupla3f Escena::centroCamara(const Tupla3f& centro)
{
    Tupla3f n_centro;

    GLfloat inv[16];

    for(int i=0; i< 16; i++)
        inv[i] = matrix[15-i];

    // aplicamos la transformacion de la matriz al punto
    n_centro(0) = inv[0] * centro(0) + inv[4] * centro(1) + inv[8] * centro(2) + inv[12];
    n_centro(1) = inv[1] * centro(0) + inv[5] * centro(1) + inv[9] * centro(2) + inv[13];
    n_centro(2) = inv[2] * centro(0) + inv[6] * centro(1) + inv[10] * centro(2) + inv[14];

    return n_centro;
}



void Escena::processPick(int x, int y){

    glDisable(GL_DITHER);
    glDisable(GL_LIGHTING);
    glDisable(GL_TEXTURE);

    GLint viewport[4];
    GLfloat pixel[3];

    // llamar a dibujar , la escena tiene modificada los colores por la iluminacion u otros factores.
    glGetIntegerv(GL_VIEWPORT, viewport);

    glReadPixels(x, viewport[3]-y, 1, 1, GL_RGB, GL_FLOAT, (void *) pixel);

    Tupla3f leido = {pixel[0], pixel[1], pixel[2]};

    Tupla3f centro;

    if (cubo != nullptr && *leido == *cubo->getColor()){
        centro = cubo->getCentro();

        centro = centroCamara(centro);

        camaras[numCamaraActiva].setAt(centro);

        camaras[numCamaraActiva].setObjetoSeleccionado(CUBO);


    } else if (/*tetraedro != nullptr &&*/ *leido == *tetraedro->getColor()){
        
        tetraedro->establecer_color_s(1.0,1.0,0.0);
        
        cout << endl << " TETRAEDRO " << endl;
        
        centro = tetraedro->getCentro();

        centro = centroCamara(centro);

        camaras[numCamaraActiva].setAt(centro);

        camaras[numCamaraActiva].setObjetoSeleccionado(TETRAEDRO);



    } else if (objply_ant != nullptr && *leido == *objply_ant->getColor()){
        
        cout << endl << " ANT " << endl;
        
        centro = objply_ant->getCentro();

        centro = centroCamara(centro);

        camaras[numCamaraActiva].setAt(centro);

        camaras[numCamaraActiva].setObjetoSeleccionado(ANT);



    } else if (objply_beethoven != nullptr && *leido == *objply_beethoven->getColor()){
        centro = objply_beethoven->getCentro();

        centro = centroCamara(centro);

        camaras[numCamaraActiva].setAt(centro);

        camaras[numCamaraActiva].setObjetoSeleccionado(BEETHOVEN);



    } else if (objrev_pcue != nullptr && *leido == *objrev_pcue->getColor()){
        centro = objrev_pcue->getCentro();

        centro = centroCamara(centro);

        camaras[numCamaraActiva].setAt(centro);

        camaras[numCamaraActiva].setObjetoSeleccionado(LATA);



    } else if (/*cilindro != nullptr &&*/ *leido == *cilindro->getColor()){
        centro = cilindro->getCentro();

        centro = centroCamara(centro);

        camaras[numCamaraActiva].setAt(centro);

        camaras[numCamaraActiva].setObjetoSeleccionado(CILINDRO);



    } else if (cono != nullptr && *leido == *cono->getColor()){
        centro = cono->getCentro();

        centro = centroCamara(centro);

        camaras[numCamaraActiva].setAt(centro);

        camaras[numCamaraActiva].setObjetoSeleccionado(CONNO);



    } else if (esfera != nullptr && *leido == *esfera->getColor()){
        centro = esfera->getCentro();

        centro = centroCamara(centro);

        camaras[numCamaraActiva].setAt(centro);

        camaras[numCamaraActiva].setObjetoSeleccionado(ESFERA);



    } else {
        camaras[numCamaraActiva].setObjetoSeleccionado(NINGUNO);
    }

    cout<< camaras[numCamaraActiva].getObjetoSeleccionado()<< " // " << leido << " // " << cilindro->getColor() << endl;

    change_observer();

    dibujar();
    glEnable(GL_DITHER);
    glEnable(GL_LIGHTING);
    glEnable(GL_TEXTURE);

}
