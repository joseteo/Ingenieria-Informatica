#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
	double TERM_COD=0, TERM_NOTA=-1, cod_max=0,
	media_max=0, suma=0, num_notas=0, cod, nota, media;
	
	string nombreArchivo("notas.txt");
	string linea;
	ifstream archivo(nombreArchivo.c_str());
	
	if (!archivo.is_open()) {
		cerr << "No se pudo abrir este archivo - '" << nombreArchivo << "'" << endl;
		return EXIT_FAILURE;
   }

	archivo >> cod;
	while( cod != TERM_COD){
		suma=0;
		num_notas=0;
		archivo >> nota;
		
		while(nota != TERM_NOTA){
			suma+=nota;
			archivo >> nota;
			num_notas++;
		}
		media = suma/num_notas;
	
		if(media>media_max){
			media_max=media;
			cod_max=cod;
		}
		
		archivo >> cod;
	}
	
	cout << "\n" << cod_max << " " << media_max;
	archivo.close();
	
	return 0;
}
