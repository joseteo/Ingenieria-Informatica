#include <map>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "../include/guiatlf.h"

using namespace std;

string Guia_Tlf::getTelefono(const string & nombre){
    map<string,string>::iterator it=datos.find(nombre);
    if (it==datos.end())
      return string("");
    else
      return it->second;
}

pair<map<string,string>::iterator,bool>  Guia_Tlf::insert(string nombre, string tlf){
    pair<string,string> p (nombre,tlf);
    pair< map<string,string> ::iterator,bool> ret;

    ret=datos.insert(p); //datos.insert(datos.begin(),p); tambien funcionaría
    return ret;

}

pair<map<string,string>::iterator,bool>  Guia_Tlf::insert(pair<string,string> p){

    pair<map<string,string> ::iterator,bool> ret;

    ret=datos.insert(p);  //datos.insert(datos.begin(),p); tambien funcionaría
    return ret;

}

void Guia_Tlf::borrar(const string &nombre){
  //map<string,string>::iterator itlow = datos.lower_bound(nombre);//el primero que tiene dicho nombre
  //map<string,string>::iterator itupper = datos.lower_bound(nombre);//el primero que ya no tiene dicho nombre
  //datos.erase(itlow,itupper);//borramos todos aquellos que tiene dicho nombre
  //OTRA ALTERNATIVA
  pair<map<string,string>::iterator,map<string,string>::iterator>ret;
  ret = datos.equal_range(nombre);
  datos.erase(ret.first,ret.second);
}

void Guia_Tlf::borrar(const string &nombre,const string &tlf){
  map<string,string>::iterator itlow = datos.lower_bound(nombre);//el primero que tiene dicho nombre
  map<string,string>::iterator itupper = datos.upper_bound(nombre);//el primero que ya no tiene dicho nombre
  map<string,string>::iterator it;
  bool salir =false;
  for (it=itlow; it!=itupper && !salir;++it){
    if (it->second==tlf){
      datos.erase(it);
      salir =true;
    }
  }
}

Guia_Tlf Guia_Tlf::previos(const string &nombre,const string &tlf){
  map<string,string>::value_compare vc=datos.value_comp(); //map<string,string>::key_compare vc=datos.key_comp()
  Guia_Tlf aux;
  pair<string,string>p(nombre,tlf);
  map<string,string>::iterator it=datos.begin();
  while (vc(*it,p)){
    aux.insert(*it++);
  }
  return aux;
}

Guia_Tlf Guia_Tlf::buscarPorInicial(char letra){
  Guia_Tlf gaux;
  Guia_Tlf::iterator it;
  char laux = toupper(letra);  //Para asegurar que la letra esté en mayuscula
  //Comparar cada nombre obteniendo su inicial y comparandolo con la letra dada como parametro
  for (it = begin(); it != end(); ++it){
    char c = obtenerInicial((*it).first);
    if (c == laux)
      gaux.insert(*it);
  }
  return gaux;
}

Guia_Tlf Guia_Tlf::buscarPorNumero(int numero){
  Guia_Tlf gaux;
  Guia_Tlf::iterator it;
  for (it = begin(); it != end(); ++it){
    int i = obtenerPrimerDigito((*it).second);
    if (i == numero)
      gaux.insert(*it);
  }
  return gaux;
}
