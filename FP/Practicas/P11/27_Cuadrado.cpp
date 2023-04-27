#include <iostream>

using namespace std;

class Cuadrado{
	private:
		double x=0, y=0, lado=0, area=0, perimetro=0;
		
	public:
		
		void set_pos(double equis, double igriega){
			x = equis;
			y = igriega;
		}
		void set_lado(double l){
			lado = l;
		}
		
		double get_x(){
			return x;
		}
		
		double get_y(){
			return y;
		}
		
		double get_lado(){
			return lado;
		}
		
		void calc_area(){
			area = lado * lado;
		}
		
		double get_area(){
			return area;
		}
		
		void calc_perimetro(){
			perimetro = lado * 4;
		}
		
		double get_perimetro(){
			return perimetro;
		}
};

int main(){
	Cuadrado parcela;
	Cuadrado otra_parcela;
	double x,y,lado;
	
	cout << "\nIntroduce las coordenadas de la esquina y la longitud del lado: ";
	cin >> x >> y >> lado;
	
	parcela.set_pos(x,y);
	parcela.set_lado(lado);
	
	cout << "\nIntroduce las coordenadas de la esquina y la longitud del lado: ";
	cin >> x >> y >> lado;
	
	otra_parcela.set_pos(x,y);
	otra_parcela.set_lado(lado);
	
	parcela.calc_area();
	parcela.calc_perimetro();
	otra_parcela.calc_area();
	otra_parcela.calc_perimetro();
	
	cout << "\nParcela:" 
	<< "\n\tCoordenadas: " << parcela.get_x() << " , " << parcela.get_y()
	<< "\n\tLongitud: " << parcela.get_lado()
	<< "\n\tArea:" << parcela.get_area()
	<< "\n\tPerimetro:" << parcela.get_perimetro();
	
	cout << "\n\nOtra Parcela:" 
	<< "\n\tCoordenadas: " << otra_parcela.get_x() << " , " << otra_parcela.get_y()
	<< "\n\tLongitud: " << otra_parcela.get_lado()
	<< "\n\tArea:" << otra_parcela.get_area()
	<< "\n\tPerimetro:" << otra_parcela.get_perimetro();

}


