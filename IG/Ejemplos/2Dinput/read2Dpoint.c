/*

	C.A.D. 						Curso 2001-2002
	
	Dpto. Lenguajes y Sistemas Informáticos
	E.T.S.I. Informática
	Univ. de Granada

        Rutina de entrada de puntos 2D.

*/

#include "read2Dpoint.h"
static float cursorx,cursory;    // coordenadas normalizadas
static int drawingcursor=0;
static float WAncho=300, WAlto=300, Deep;
static int VAlto=100, VAncho=100;	
				// ancho y alto de la ventana y Viewport
static int showCursorPosition=1;		
static char buffer[14];
int i;
static int softCursorEnabled=1; // Poner a uno para dibujar el cursor en el progrma

void notifyWindowSize(float wx,float wy,int vx,int vy,float deep)
{
WAncho=wx;
WAlto=wy;
VAncho=vx;
VAlto=vy;
Deep=deep;
}

void enableDrawCursor()
{
drawingcursor=1;
if(softCursorEnabled)
	glutSetCursor(GLUT_CURSOR_NONE);		
else
	glutSetCursor(GLUT_CURSOR_CROSSHAIR);		
}

void disableDrawCursor()
{
drawingcursor=0;
glutSetCursor(GLUT_CURSOR_RIGHT_ARROW);

}
void enableCursorPosition()
{
showCursorPosition=1;
}

void disableCursorPosition()
{
showCursorPosition=0;
}

void getCursor(float *xc, float *yc)
{
*xc = cursorx*WAncho;
*yc = cursory*WAlto;
}
void drawCursor()
{
if(drawingcursor)
	{
	glPushAttrib(GL_CURRENT_BIT);
	glColor3f( 0.0, 1.0,1.0);

//printf("%6.1f %6.1f %6.1f %6.1f %6.1f\n",cursorx,cursory,WAncho,WAlto,Deep);

	if(softCursorEnabled) {
		glBegin(GL_LINES);
			glVertex3f( cursorx*WAncho-5, cursory*WAlto, -Deep-1);
			glVertex3f( cursorx*WAncho+5, cursory*WAlto,-Deep-1);
			glVertex3f( cursorx*WAncho, cursory*WAlto-5,-Deep-1);
			glVertex3f( cursorx*WAncho, cursory*WAlto+5,-Deep-1);
	  	glEnd();
    	}
/*	glBegin(GL_LINES);
		glVertex3f( cursorx-5, cursory, -82);
		glVertex3f(cursorx+5, cursory, -82);
		glVertex3f( cursorx, cursory-5, -82);
		glVertex3f(cursorx, cursory+5, -82);
  	glEnd();*/

	if(showCursorPosition){
		sprintf(buffer,"%6.2f %6.2f",cursorx*WAncho, cursory*WAlto);
		glRasterPos3f(WAncho*0.5,-WAlto*0.8,-Deep-1);
	    for(i=0;i<13;++i) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, (int) buffer[i]);
            }
	}

	glPopAttrib();

	}
}



/* ------------------------------------------------------------------------- */

void cursorMovido( int x, int y )
{
	if(drawingcursor) {
		cursorx = 2.0*((1.0*x) / VAncho -0.5);
   		cursory = - 2.0*((1.0*y) / VAlto - 0.5);
//	   	glutPostRedisplay();
		}
}


