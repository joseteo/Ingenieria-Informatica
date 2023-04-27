#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "diccionario.cpp"

using namespace std;

/*Operator<<. Obsérvese el uso de 2 tipos diferentes de iteradores. Uno sobre
listas de listas y otro sobre listas
*/
ostream & operator<<(ostream & os, const Diccionario<string,string> & D){

	  //list<data<string,string> >::const_iterator it;
		Diccionario<string,string>::const_iterator it;

		cout<<endl<<"DICCIONARIO:"<< endl;
		cout << "Hay ";
		os << D.size();
		cout << " palabras definidas en el diccionario" << endl;


	  for (it=D.begin(); it!=D.end(); ++it){

		    list<string>::const_iterator it_s;

		    os<<endl<<(*it).clave<<endl;
		    for (it_s=(*it).info_asoci.begin();it_s!=(*it).info_asoci.end();++it_s){
			      os<<(*it_s)<<endl;
		    }
		    os<<"**************************************"<<endl;
	  }

	  return os;
}

/*Operator >>. El formato de la entrada es:
     numero de claves en la primera linea
     clave-iésima retorno de carro
     numero de informaciones asociadas en la siguiente linea
     y en cada linea obviamente la informacion asociada
*/

istream & operator >>(istream & is,Diccionario<string,string> &D){
	  int np;
	  is>>np;
	  is.ignore();//quitamos \n
	  Diccionario<string,string> Daux;
	  for (int i=0;i<np; i++){
		    string clave;

		    getline(is,clave);
				//cout << "Palabra leida "<<clave<<endl;
		    int ns;
		    is>>ns;
		    is.ignore();//quitamos \n
		    list<string>laux;
		    for (int j=0;j<ns; j++){
			      string s;
			      getline(is,s);

			      //cout<<"Significado leido "<<s<<endl;
			      laux.insert(laux.end(),s);
		    }
		    Daux.Insertar(clave,laux);

	  }
	  D=Daux;
	  return is;
}

/*Recorre la lista de información asociada a una clave y la imprime*/
void EscribeSigni(const list<string>&l){
	  list<string>::const_iterator it_s;

	  for (it_s=l.begin();it_s!=l.end();++it_s){
		    cout<<*it_s<<endl;
	  }
}

//Imprime unicamente las palabras definidas del diccionario
void Mostrar_SoloPalabras(const Diccionario<string,string> & D){
	//list<data<string,string> >::const_iterator it;
	Diccionario<string,string>::const_iterator it;

	cout << endl << "Palabras:" << endl;

	for (it=D.begin(); it!=D.end(); ++it){
		cout << "\t\t" << (*it).clave << endl;
	}
}


/*Lee un diccioario e imprime datos asociados a una clave.
Hay un fichero ejemplo de prueba: data.txt.Para lanzar el programa con ese fichero se escribe:
                  ./usodiccionario < data.txt
*/
int main(int argc , char * argv[]){
	if (argc != 2){
		cout << "No se ha introducido el nombre del fichero" << endl;
		return 0;
	}
	ifstream f(argv[1]);
	if (!f){
		cout << "No se ha podido abrir el fichero " << argv[1] << endl;
		return 0;
	}

 Diccionario<string,string> D;

f>>D;

cout << D;

string palabra, definiciones;
list<string> l;

//Mostrar las palabras sobre las que hay definicion en el diccionario
cout << "Estas son las palabras definidas en el diccionario:" << endl;
Mostrar_SoloPalabras(D);

//Mostrar las definiciones de una palabra introducida
cout << "Introduce una palabra para obtener sus definiciones: " << endl;
while (getline(cin,palabra)){
	l=D.getInfo_Asoc(palabra);
	if (l.size() > 0)
		EscribeSigni(l);
	cout << "[Pulse CTRL+D para finalizar] Introduce una palabra para obtener sus definiciones: " << endl;
}

//Mostrar las palabras sobre las que hay definicion en el diccionario
cout << "Estas son las palabras definidas en el diccionario:" << endl;
Mostrar_SoloPalabras(D);

cin.clear();
//Introducir una nueva palabra en el diccionario
cout << "Introduce una nueva palabra para añadirla al diccionario: " << endl;
while (getline(cin,palabra)){
	cout << "Introduce la definicion: " << endl;
	while(getline(cin,definiciones)){
		l.push_back(definiciones);
		cout << "[Pulse CTRL+D para finalizar] Introduce la definicion: " << endl;
	}

	D.Insertar(palabra,l);
	//Mostrar las palabras sobre las que hay definicion en el diccionario
	cout << "Estas son las palabras definidas en el diccionario:" << endl;
	Mostrar_SoloPalabras(D);
	cout << "[Pulse CTRL+D para finalizar] Introduce una nueva palabra para añadirla al diccionario: " << endl;
}

//Mostrar las palabras sobre las que hay definicion en el diccionario
cout << "Estas son las palabras definidas en el diccionario:" << endl;
Mostrar_SoloPalabras(D);

cin.clear();
//Añadir significados a una palabra
cout << "Introduce la palabra a la cual añadir definiciones: " << endl;
while (getline(cin,palabra)){
	cout << "Introduce la definicion a añadir: " << endl;
	while (getline(cin,definiciones)){
		D.AddSignificado_Palabra(definiciones,palabra);
		cout << "[Pulse CTRL+D para finalizar] Introduce la definicion a añadir: " << endl;
	}
	//Mostrar las palabras sobre las que hay definicion en el diccionario
	cout << "Estas son las palabras definidas en el diccionario:" << endl;
	Mostrar_SoloPalabras(D);

	cin.clear();
	cout << "[Pulse CTRL+D para finalizar] Introduce la palabra a la cual añadir definiciones: " << endl;
}

cin.clear();
//Eliminar palabras
cout << "Introduce la palabra que se quiere eliminar del diccionario: " << endl;
while (getline(cin,palabra)){
	D.Elimina_Palabra(palabra);
	//Mostrar las palabras sobre las que hay definicion en el diccionario
	cout << "Estas son las palabras definidas en el diccionario:" << endl;
	Mostrar_SoloPalabras(D);
	cout << "[Pulse CTRL+D para finalizar] Introduce la palabra que se quiere eliminar del diccionario: " << endl;
}


cin.clear();
//Eliminar definicion de palabra
cout << "Introduce la palabra a la que se quiere eliminar una definicion: " << endl;
while(getline(cin,palabra)){
	l = D.getInfo_Asoc(palabra);
	if (l.size() > 0){
		EscribeSigni(l);
	}

	cout << "Introduce el numero de la definicion que se quiere eliminar (empieza desde el 0): " << endl;
	int indice;
	while(getline(cin,definiciones)){
		indice = stoi(definiciones);
		D.EliminaSignificado_Palabra(indice, palabra);
		l = D.getInfo_Asoc(palabra);
		if (l.size() > 0){
			EscribeSigni(l);
		}

		cin.clear();
		cout << "[Pulse CTRL+D para finalizar] Introduce el numero de la definicion que se quiere eliminar (empieza desde el 0): " << endl;
	}


	cin.clear();
	//Mostrar las palabras sobre las que hay definicion en el diccionario
	cout << "Estas son las palabras definidas en el diccionario:" << endl;
	Mostrar_SoloPalabras(D);
	cout << "[Pulse CTRL+D para finalizar] Introduce la palabra a la que se quiere eliminar una definicion: " << endl;
}



}  //FIN MAIN
