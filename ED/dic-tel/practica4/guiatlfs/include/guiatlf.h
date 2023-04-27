/**
 * @ file : guiatlf.h
 * @brief: TDA guia de telefonos
 * */

#ifndef _GUIA_TLF_H
#define _GUIA_TLF_H
#include <map>
#include <iostream>
#include <string>

using namespace std;

istream & operator>>(istream &is,pair<string,string> &d){
	  getline(is,d.first,'\t');
	  getline(is,d.second);
	  return is;
}

ostream & operator<<(ostream &os,const pair<const string,string> &d){
	  os<<d.first<<'\t'<<d.second<<endl;
	  return os;
}


/**
  *  @brief T.D.A. Guia_Tlf
  *
  * Una instancia @e c del tipo de datos abstracto @c Guia_Tlf es un objeto
  * formado por una colección de pares {(e11,e21),(e12,e22),(e13,e23),...,(e1n-1,e2n-1)}
  * ordenados por la el primer elemento del par denominado clave o key. No existen
  * elementos repetidos.
  *
  *
  * Un ejemplo de su uso:
  *
  *
  * @author Rosa Rodríguez
  * @date Marzo 2012
  */

class Guia_Tlf{
  /**
  * @page repGuia_Tlf Rep del TDA Guia_Tlf
  *
  * @section invGuia_Tlf Invariante de la representación
  *
  * El invariante es \e para todo \e i y \e j tal que i<j entonces \e e1i y e1j son distintos
  *
  * @section faGuia_Tlf Función de abstracción
  *
  * Un objeto válido @e rep del TDA Guia_Tlf representa al valor
  *
  * {(rep.begin().first,rep.begin().second),(rep.begin()+1.first,rep.begin()+1.second),....,(rep.begin()+n-1.first,rep.begin()+n-1.second)}
  *
  */
	  private:
		    map<string,string> datos; //si admites que haya nombres repetidos tendrías que usar un
					     //multimap

	  public:

		    /**
		      @brief Acceso a un elemento
		      @param nombre: nombre del elemento  elemento acceder
		      @return devuelve el valor asociado a un nombre, es decir el teléfono
		    */
		    //si fuese un multimap no podriamos usar []. Ademas que deberiamos devolver p.e un vector con todos
		    // los telefonos asociados a dicho nombre
		    string & operator[](const string &nombre) {
			      return datos[nombre];
		    }

				/**
				* @brief Dado un nombre devuelve su telefono
				* @param nombre: nombre del elemento
				* @return Devuelve el valor asociado a un nombre, es decir el telefono
				*/
		    string  getTelefono(const string & nombre);

		    /**
		     @brief Insert un nuevo telefono
		     @param nombre: nombre clave del nuevo telefono
		     @param tlf: numero de telefono
		     @return : un pair donde first apunta al nuevo elemento insertado y bool es true si se ha insertado el nuevo tlf o
			      o false en caso contrario
		    */
		    pair<map<string,string>::iterator,bool>  insert(string nombre, string tlf);

		    /**
		     @brief Insert un nuevo telefono
		     @param p: pair con el nombre y el telefono asociado

		     @return : un pair donde first apunta al nuevo elemento insertado y bool es true si se ha insertado el nuevo tlf o
			      o false en caso contrario
		    */
		    pair<map<string,string>::iterator,bool>  insert(pair<string,string> p);

		    /**
		      @brief Borrar un telefono
		      @param nombre: nombre que se quiere borrar
		      @note: en caso de que fuese un multimap borraria todos con ese nombre
		    */
		    void borrar(const string &nombre);

		    /**
		      @brief Borrar un telefono
		      @param nombre: nombre que se quiere borrar y telefono asociado
		      @note: esta funcion nos permite borrar solamente aquel que coincida en nombre y tlf
		    */
		    //con map siempre hay uno con multimap puede existir mas de uno
		    void borrar(const string &nombre,const string &tlf);

		    /**
		      @brief  Numero de telefonos
		      @return el numero de telefonos asociados
		     */
		    int size()const{
			      return datos.size();
		    }
		    /**
		      @brief Contabiliza cuantos telefonos tenemos asociados a un nombre
		      @param nombre: nombre sobre el que queremos consultar
		      @return numero de telefonos asociados a un nombre

		     */
		    //al ser un map debe de ser 0 o 1. Si fuese un multimap podríamos tener mas de uno
		    unsigned int contabiliza(const string &nombre){
			      return datos.count(nombre);
		    }

		    /**
		      @brief Limpia la guia
		     */
		    void clear(){
			      datos.clear();
		    }
		    /**
		      @brief Union de guias de telefonos
		      @param g: guia que se une
		      @return: una nueva guia resultado de unir el objeto al que apunta this y g
		    */
		    Guia_Tlf operator+(const Guia_Tlf & g){
					Guia_Tlf aux(*this);
					map<string,string>::const_iterator it;
					for (it=g.datos.begin();it!=g.datos.end();++it){
			  		aux.insert(it->first,it->second);
					}
					return aux;
				}

		    /**
		      @brief Diferencia de guias de telefonos
		      @param g: guia a restar
		      @return: una nueva guia resultado de la diferencia del objeto al que apunta this y g
		    */
		    Guia_Tlf operator-(const Guia_Tlf & g){
					Guia_Tlf aux(*this);
					map<string,string>::const_iterator it;
					for (it=g.datos.begin();it!=g.datos.end();++it){
			  		aux.borrar(it->first,it->second);
					}
					return aux;
		    }

		    /**
		      @brief  Obtiene una guia con los nombre previos a uno dado
		      @param nombre: nombre delimitador
		      @param tlf: telefono asociado a nombre
		      @return nueva guia sin nombres mayores que \a  nombre
		     */
		    Guia_Tlf previos(const string &nombre,const string &tlf);

		    /**
		      @brief Escritura de la guia de telefonos
		      @param os: flujo de salida. Es MODIFICADO
		      @param g: guia de telefonos que se escribe
		      @return el flujo de salida
		     */
		    friend ostream & operator<<(ostream & os, Guia_Tlf & g){
			   	map<string,string>::iterator it;
			    for (it=g.datos.begin(); it!=g.datos.end();++it){
						os<<it->first<<"\t"<<it->second<<endl;
			    }
			    return os;
		    }

		    /**
		      @brief Lectura de  la guia de telefonos
		      @param is: flujo de entrada. ES MODIFICADO
		      @param g: guia de telefonos. ES MODIFICADO
		      @return el flujo de entrada
		    */
		    friend istream & operator>>(istream & is, Guia_Tlf & g){
			    pair<string,string> p;
			    Guia_Tlf aux;

			    while (is>>p){
				  	aux.insert(p);
			    }
			    g=aux;
			    return is;
		    }

				/**
				* @brief Buscar los contactos que empiezan por una letra dada
				* @param letra: la letra por la que queremos filtrar la guia
				* @return Devuelve una guia de telefonos con todos los
				contactos que empiezan por esa letra
				*/
				Guia_Tlf buscarPorInicial(char letra);

				/**
				* @brief Buscar los contactos que su numero empieza por un numero dado
				* @param numero: numero entre el 1 y el 9 por el que queremos filtrar la guia
				* @return Duelve una guia de telefonos con todos los contactos cuyo
				numero empieza por ese numero
				*/
				Guia_Tlf buscarPorNumero(int numero);

				/**
				* @brief Obtiene la inicial de un nombre dado
				* @param nombre: primer componente del pair del map
				* @return Devuelve un char de la inicial del nombre dado
				*/
				char obtenerInicial(const string &nombre){
					return (char)toupper(nombre[0]);
				}

				/**
				* @brief Obtiene el primer digito de un numero dado
				* @param numero: segunda componente del pair del map
				* @return Devuelve un char del primer digito del numero dado
				*/
				int obtenerPrimerDigito(const string &numero){
					char num = (char)(numero[0]);
					return ((int)num -48);
					//return (char)(numero[0]);
				}

		    /**
		     * @brief clase para iterar sobre la guia
		     * */
		    class iterator{
			    private:
			    	map<string,string>::iterator it;
			    public:
				    iterator & operator++(){
					  	++it;
				    }
				    iterator & operator--(){
					  	--it;
				    }
				    pair<const string,string> &operator *(){
					  	return *it;
				    }
				    bool operator ==(const iterator &i){
					  	return i.it==it;
				    }
				    bool operator !=(const iterator &i){
					  	return i.it!=it;
				    }
				    friend class Guia_Tlf;
		    };

		    /**
		     * @brief Inicializa un iterator al comienzo de la guia
		     * */
		    iterator begin(){
					iterator i;
					i.it=datos.begin();
					return i;
		    }

		    /**
		     * @brief Inicializa un iterator al final de la guia
		     * */
		    iterator end(){
					iterator i;
					i.it=datos.end();
					return i;
		    }


};
#endif
