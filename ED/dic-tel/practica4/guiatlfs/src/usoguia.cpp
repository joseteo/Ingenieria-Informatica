#include <fstream>
#include <iostream>
#include <string>
#include "guiatlf.cpp"

using namespace std;

int main(int argc , char * argv[]){
  if (argc != 2){
    cout << "Dime el nombre del fichero con la guia" << endl;
    return 0;
  }
  ifstream f(argv[1]);
  if (!f){
    cout << "No puedo abrir el fichero " << argv[1] << endl;
    return 0;
  }

  Guia_Tlf G;
  string nombre, telefono;

  f>>G;
  cout << "La guia insertada: " << endl << G << endl;
  cin.clear();

  //Obtener el telefono de un contacto a partir de su nombre
  cout<<endl<<"Dime un nombre sobre el que quieres obtener el telefono: "<<endl;
  while (getline(cin,nombre)){
    cout<<"Buscando "<<nombre<<" ...."<<endl;
    string telefono = G.getTelefono(nombre);
    if (telefono==""){
      cout<<"No existe ese nombre en la guia"<<endl;
    }else
      cout<<"El telefono es "<<telefono<<endl;
    cout<<"[Pulse CTRL+D para finalizar] Dime un nombre sobre el que quieres obtener el telefono"<<endl;
  }

  //Borrar un contacto
  cin.clear();
  cout<<endl<<"Dime el nombre que quieres borrar"<<endl;
  while (getline(cin,nombre)){
    G.borrar(nombre);
    cout<<"Ahora la guia es:"<<endl;
    cout<<G<<endl;
    cout<<"[Pulse CTRL+D para finalizar] Dime el nombre que quieres borrar"<<endl;
  }

  //Hacer la union y la diferencia de dos guias
  cin.clear();
  Guia_Tlf otraguia;
  string guia2;
  cout<<endl<<"Introduce otra guia ([Pulse CTRL+D para finalizar])"<<endl;
  getline(cin,guia2);
  ifstream f2(guia2);
  f2>>otraguia;
  cin.clear();
  Guia_Tlf un = G+otraguia;
  Guia_Tlf dif = (G-otraguia)+(otraguia-G);
  cout<<endl<<"La union de las dos guias: " << endl << un << endl;
  cout<<endl<<"La diferencia de las dos guias:" <<  endl << dif << endl;

  //Listar los contactos previos a un nombre dado
  cin.clear();
  cout<<endl<<"Dime un nombre para establecer los previos"<<endl;
  getline(cin,nombre);
  telefono = G.getTelefono(nombre);
  Guia_Tlf prev = G.previos(nombre,telefono);
  cout<<endl<<"Los nombre previos: " << endl << prev << endl;

  //Insertar un contacto con su nombre y numero de telefono
  cin.clear();
  cout << endl << "Introduce el nombre a insertar: " << endl;
  while(getline(cin,nombre)){
    cout << "Introduce el telefono de la persona que se va a insertar: " << endl;
    getline(cin,telefono);
    while(telefono.size() != 9){
      cout << "El numero introducido no es correcto porque no es de 9 digitos, introduce un telefono con 9 digitos: " << endl;
      getline(cin,telefono);
    }
    G.insert(nombre,telefono);
    cout<<"Ahora la guia es:"<<endl;
    cout<<G<<endl;
    cin.clear();
    cout << "[Pulse CTRL+D para finalizar] Introduce un nombre a insertar: " << endl;
  }

  //Listar los contactos cuyo nombre empieze por una letra dada
  string laux;
  char letra;
  cin.clear();
  cout << endl << "Introduce una inicial para filtrar los contactos con esa inicial: " << endl;
  while(getline(cin,laux)){
    letra = laux[0];
    Guia_Tlf inicial = G.buscarPorInicial(letra);
    cout << "Los contactos que empieza por " << letra << " son: " << endl << inicial << endl;
    cout << "[Pulse CTRL+D para finalizar] Introduce una inicial para filtrar los contactos por esa inicial: " << endl;
  }

  //Listar los contactos cuyo telefono empiece por un numero dado
  string naux;
  int numero;
  cin.clear();
  cout << endl << "Introduce un numero para filtrar los contactos cuyo numero empieze por ese numero: " << endl;
  while(getline(cin,naux)){
    numero = (int)naux[0] - 48;
    Guia_Tlf num = G.buscarPorNumero(numero);
    cout << "Los contactos cuyo numero empieza por " << numero << " son: " << endl << num << endl;
    cout << "[Pulse CTRL+D para finalizar] Introduce un numero para filtrar los contactos cuyo numero empiece por ese numero: " << endl;
  }

  //Listar los contactos con ieradores 
  cout<<endl<<"Listando la guia con iteradores:"<<endl;
  Guia_Tlf::iterator it;
  for (it=G.begin(); it!=G.end(); ++it)
  cout<<*it<<endl;

} //FIN MAIN
