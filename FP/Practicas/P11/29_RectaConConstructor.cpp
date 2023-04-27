#include <iostream>
#include <cmath>
using namespace std;


class Recta{
// Ax + By + C = 0
private:
   double A;
   double B;
   double C;
   bool Escorrecto(double num){
   	return num!=0;
	}
   
public:
	Recta(double a, double b, double c){
		A=a;
		B=b;
		C=c;
	}
	
   double CoefX(){
      return A;
   }

   double CoefY(){
      return B;
   }

   double CoefIndep(){
      return C;
   }

   void SetCoeficientes(double coef_x, double coef_y, double coef_indep){
      if (Escorrecto(coef_x) && Escorrecto(coef_y)){
         A = coef_x;
         B = coef_y;
         C = coef_indep;
      }
      // else los deja como estaban
   }
   
   double Ordenada(double x){
      return (-C - x*A ) / B;
   }

   double Abscisa(double y){
      return (-C - y*B ) / A;
   }

   double Pendiente(){
      return -A/B;
   }
   
   double AnguloRadEjeHoriz(){
      return atan(Pendiente());
   }
   
   void EspejoAbsc(){
      B = -B;
   }
};

int main(){
   double term_x_recta1, term_y_recta1, term_indep_recta1, 
          term_x_recta2, term_y_recta2, term_indep_recta2;
   double pendiente_recta1, pendiente_recta2, ang_horiz_recta1, ang_horiz_recta2;
   double x, ordenada_de_x, y, abscisa_de_y;
   
   Recta recta1(1, 2, 3), recta2(9, 3, 4);
   
   cout << "\nCoeficiente recta1: " << recta1.CoefX() 
   											<< " " << recta1.CoefY()
   											<< " " << recta1.CoefIndep();
   cout << "\nCoeficiente recta2: " << recta2.CoefX() 
   											<< " " << recta2.CoefY()
   											<< " " << recta2.CoefIndep();
   
   cout << "\nIntroduzca los coeficientes A, B, C de la recta Ax + By + C = 0\n";
   cin >> term_x_recta1 >> term_y_recta1 >> term_indep_recta1;
   cout << "\nIntroduzca los coeficientes de la otra recta\n";
   cin >> term_x_recta2 >> term_y_recta2 >> term_indep_recta2;
      
   cout << "\nIntroduzca un valor de abscisa\n";
   cin >> x;
   cout << "\nIntroduzca un valor de ordenada\n";
   cin >> y;
   
   recta1.SetCoeficientes(term_x_recta1, term_y_recta1, term_indep_recta1);
   recta2.SetCoeficientes(term_x_recta2, term_y_recta2, term_indep_recta2);
   
   pendiente_recta1 = recta1.Pendiente();
   pendiente_recta2 = recta2.Pendiente();
   
   ang_horiz_recta1 = recta1.AnguloRadEjeHoriz();
   ang_horiz_recta2 = recta2.AnguloRadEjeHoriz();

   ordenada_de_x = recta1.Ordenada(x);
   abscisa_de_y = recta1.Abscisa(y);

   cout << "\nT廨mino independiente de la recta 1: " << recta1.CoefIndep()
        << "\nT廨mino independiente de la recta 2: " << recta2.CoefIndep()
        << "\nPendiente de la recta 1: " << pendiente_recta1
        << "\nPendiente de la recta 2: " << pendiente_recta2
        << "\n聲gulo en radianes con el eje horizontal de la recta 1: " << ang_horiz_recta1
        << "\n聲gulo en radianes con el eje horizontal de la recta 2: " << ang_horiz_recta2
        << "\nOrdenada de la recta 1 en la abscisa " << x << " = " << ordenada_de_x
        << "\nAbscisa  de la recta 1 en la ordenada " << y << " = " << abscisa_de_y;

   recta1.EspejoAbsc();
   
   cout << "\nPendiente del espejo de recta 1: " << recta1.Pendiente()
        << "\n\n";
}
/*
3 2 -1    7 -8 9     5    6

T廨mino independiente de la recta 1: -1
T廨mino independiente de la recta 2: 9
Pendiente de la recta 1: -1.5
Pendiente de la recta 2: 0.875
聲gulo en radianes con el eje horizontal de la recta 1: -0.982794
聲gulo en radianes con el eje horizontal de la recta 2: 0.71883
Ordenada de la recta 1 en 5 = -7
Abscisa  de la recta 1 en 6 = -3.66667
Pendiente del espejo de recta 1: 1.5
*/
