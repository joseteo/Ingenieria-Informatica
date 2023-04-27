/**
* @ file : diccionario.h
* @brief: TDA Diccionario
**/

#ifndef _DICCIONARIO_H
#define _DICCIONARIO_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <list>

using namespace std;

/*Tipo elemento que define el diccionario. T es el tipo de dato asociado a una clave que
no se repite (DNI p.ej.) y list<U> es una lista de datos (string p.ej) asociados a la clave
de tipo T. El diccionario está ordenado de menor a mayor clave.
*/
template <class T,class U>
struct data{
    T clave;
    list<U> info_asoci;
 };


 /*Comparador de datos. Ordena 2 registros de acuerdo a la clave de tipo T. Puede usarse como
 un funtor.
 */
template <class T, class U>
bool operator< (const data<T,U> &d1,const data <T,U>&d2){
	   if (d1.clave<d2.clave)
		     return true;
	   return false;
}

/*Un diccionario es una lista de datos de los definidos anteriormente. Cuidado porque se
manejan listas de listas. Se añaden 2 funciones privadas que hacen más facil la implementación
de algunos operadores o funciones de la parte pública. Copiar copia un diccioario en
otro y borrar elimina todos los elementos de un diccionario. La implementación de copiar
puede hacerse usando iteradores o directamente usando la función assign.
*/
/**
* @brief TDA Diccionario
* Una instancia @e c del tipo de datos abstracto @c Diccionario es lista de datos formado
por una lista de la estructura data ordenados alfabeticamente. No existen elementos reperitos.
**/
template <class T,class U>
class Diccionario{
	  private:


 		    list<data<T,U> > datos;

        /**
        * @bried Funcion para copiar diccionarios
        * @param D: el otro diccionario del que se va a copiar
        **/
		    void Copiar(const Diccionario<T,U>& D){
			   /*typename list<data<T,U> >::const_iterator it_d;
			   typename list<data<T,U> >::iterator it=this->datos.begin();*/

			   datos.assign(D.datos.begin(),D.datos.end());
			   /*for (it_d=D.datos.begin(); it_d!=D.datos.end();++it_d,++it){
				     this->datos.insert(it,*it_d);
			   }*/
		    }

        /**
        * @brief Funcion para borrar un diccionario
        **/
		    void Borrar(){
			      this->datos.erase(datos.begin(),datos.end());
		    }


	  public:
	   /* Constructor por defecto*/
     /**
     * @brief Constructor por defecto
     **/
		 Diccionario():datos(list<data<T,U> >()){}

		 /* Constructor de copias*/
     /**
     * @brief Constructor de copias
     * @param D: el otro diccionario del que se va a copiar
     **/
		 Diccionario(const Diccionario &D){
			   Copiar(D);
		 }

		 /* Destructor*/
     /**
     * @brief Destructor de la clase
     **/
		 ~Diccionario(){}

		 /* Operador de asignación*/
     /**
     * @brief Sobrecarga del operador de asignacion
     * @param D: diccionario del que se iguala (lo que está a la derecha del igual)
     * @return El diccionario que se estaba igualando al otro
     **/
		 Diccionario<T,U> & operator=(const Diccionario<T,U> &D){
			   if (this!=&D){
				     Borrar();
				     Copiar(D);
			   }
			   return *this;
		 }

		/* Busca la clave p en el diccionario. Si está devuelve un iterador a
		dónde está clave. Si no está, devuelve end() y deja el iterador de salida
		apuntando al sitio dónde debería estar la clave
		*/
    /**
    * @brief Comprueba si una palabra está en el diccionario y escribe su posicion en el
    iterador pasado como parametro
    * @param p: palabra del diccionario
    * @param it_out: iterador con la posicion de la palabra dentro del diccionario
    * @return Un bool indicando si la palabra ha sido encontrada o no dentro del diccionario
    **/
		bool Esta_Clave(const T &p, typename  list<data<T,U> >::iterator &it_out);

		 /* Inserta un nuevo registro en el diccionario. Lo hace a través de la clave
		 e inserta la lista con toda la información asociada a esa clave. Si el
		 diccionario no estuviera ordenado habría que usar la función sort()
		 */
     /**
     * @brief Inserta un nuevo registro en el diccionario
     * @param clave: palabra que va a ser insertada
     * @param info: lista con la informacion asociada a la clave
     **/
		 void Insertar(const T& clave,const list<U> &info);

		 /*Añade una nueva informacion asocida a una clave que está en el diccionario.
		 la nueva información se inserta al final de la lista de información.
                  Si no esta la clave la inserta y añade la informacion asociada.
		 */
     /**
     * @brief Añade nueva informacion asociada a una clave que está en el diccionario
     * @param s: informacion asocida a la clave
     * @param p: palabra a la que se le va a incluir informacion
     **/
		 void AddSignificado_Palabra(const U & s ,const T &p);

		 /* Devuelve la información (una lista) asociada a una clave p. Podrían
		 haberse definido operator[] como
		 data<T,U> & operator[](int pos){ return datos.at(pos);}
		 const data<T,U> & operator[](int pos)const { return datos.at(pos);}
		  */
      /**
      * @brief Consigue la informacion (una lista) asociada a una plave
      * @param p: palabra de la que se va a conseguir la info
      * @return Devuelve una lista con la informacion asociada a una clave
      **/
		  list<U>  getInfo_Asoc(const T & p);

		/*Devuelve el tamaño del diccionario*/
    /**
    * @brief Tamaño de la lista de datos
    * @return Devuelve el tamaño del diccionario, es decir, el numero de palabras definidas en él
    **/
		 int size()const{
			   return datos.size();
		 }


     /*METODOS AÑADIDOS*/

      /*Busca una definicion*/
      /**
      * @brief Comprueba si una definicion está asociada a determinada clave
      * @param p: palabra del diccionario
      * @param indice: indice de la definicion a buscar de esa palabra
      * @param it_out1: iterador con la posision de la palabra en el diccionario
      * @param it_out2: iterador con la posicion de la definicion
      * @return Devuelve un bool indicando si la definicion de la palabra ha sido encontrada o no
      **/
      bool Esta_Def(const T &p, const int &indice,
          typename  list<data<T,U> >::iterator &it_out1, typename list<U>::iterator &it_out2);

      /*Elimina una determinada informacon asociada a una clave que está en el diccionario.
      Si no está la clave muestra un mensaje de error. Si sí está elimina la informacion asociada.
      */
      /**
      * @brief Elimina una definicion de una palabra
      * @param indice: indice de la definicion a eliminar de la lista de esa palabra
      * @param p: palabra del diccionario a la que se le va a eliminar una definicion
      **/
      void EliminaSignificado_Palabra(const int &indice, const T &p);

      /*Elimina todo el conenido asociado a una palabra clave*/
      /**
      * @brief Elimina todo el contenido asociado a una palabra
      * @param p: palabra del diccionario qeu se va a eliminar
      **/
      void Elimina_Palabra(const T &p);

      /**
      * @brief TDA iterator
      **/
      class iterator{
        private:
          typename list<data<T,U> >::iterator it;
        public:
          iterator(){}

          bool operator==(const iterator &i){
            return i.it == it;
          }

          bool operator!=(const iterator &i){
            return i.it != it;
          }

          data<T,U> & operator*(){
            return *it;
          }

          iterator & operator++(){
            ++it;
            return *this;
          }

          iterator & operator=(const iterator &i){
            it = i;
            return *this;
          }

          friend class Diccionario;
      };

      /**
      * @brief TDA iterator_const
      **/
      class const_iterator{
        private:
          typename list<data<T,U> >::const_iterator it;
        public:
          const_iterator(){}

          bool operator==(const const_iterator &i){
            return i.it == it;
          }

          bool operator!=(const const_iterator &i){
            return i.it != it;
          }

          const data<T,U> & operator*() const{
            return *it;
          }

          const_iterator & operator++(){
            ++it;
            return *this;
          }

          const_iterator & operator=(const iterator &i){
            it = i.it;
            return *this;
          }

          friend class Diccionario;
      };

      /**
      * @brief Inicializa el iterador begin al comienzo de la lista de datos
      * @return Iterador al comienzo de la lista de datos
      **/
      iterator begin(){
        iterator i;
        i.it = datos.begin();
        return i;
      }
      /**
      * @brief Inicializa el iterador end al final de la lista de datos
      * @return Iterador al final de la lista de datos
      **/
      iterator end(){
        iterator i;
        i.it = datos.end();
        return i;
      }
      /**
      * @brief Inicializa el iterador begin al comienzo de la lista de datos
      * @return Iterador constante al comienzo de la lista de datos
      **/
      const_iterator begin() const{
        const_iterator i;
        i.it = datos.begin();
        return i;
      }
      /**
      * @brief Inicializa el iterador constante end al final de la lista de datos
      * @return Iterador constante al final de la lista de datos
      **/
      const_iterator end() const{
        const_iterator i;
        i.it = datos.end();
        return i;
      }
};

#endif
