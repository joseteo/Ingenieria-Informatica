#include <iostream>
#include <string>
#include <list>
#include "../include/diccionario.h"

using namespace std;

/* Busca la clave p en el diccionario. Si está devuelve un iterador a
dónde está clave. Si no está, devuelve end() y deja el iterador de salida
apuntando al sitio dónde debería estar la clave
*/
template <class T, class U>
bool Diccionario<T,U>::Esta_Clave(const T &p, typename  list<data<T,U> >::iterator &it_out){
    if (datos.size()>0){
        typename list<data<T,U> >::iterator it;

        for (it=datos.begin(); it!=datos.end(); ++it){
          if ((*it).clave==p){
            it_out=it;
            return true;
          } else if ((*it).clave>p){
            it_out=it;
            return false;
          }
        }
        it_out=it;
        return false;
    } else {
        it_out=datos.end();
        return false;
    }
 }

 /* Inserta un nuevo registro en el diccionario. Lo hace a través de la clave
 e inserta la lista con toda la información asociada a esa clave. Si el
 diccionario no estuviera ordenado habría que usar la función sort()
 */
 template <class T, class U>
 void Diccionario<T,U>::Insertar(const T& clave,const list<U> &info){
     typename list<data<T,U> >::iterator it;

     if (!Esta_Clave(clave,it)){
         data<T,U> p;
         p.clave = clave;
         p.info_asoci=info;

         datos.insert(it,p);
     }else
        cout << "La palabra introducida ya está definida en el diccionario" << endl;
 }

 /*Añade una nueva informacion asocida a una clave que está en el diccionario.
 la nueva información se inserta al final de la lista de información.
              Si no esta la clave la inserta y añade la informacion asociada.
 */
 template <class T, class U>
 void Diccionario<T,U>::AddSignificado_Palabra(const U & s ,const T &p){
   typename list<data<T,U> >::iterator it;

   if (!Esta_Clave(p,it)){
     list<U> lista;
     lista.push_back(s);
     Insertar(p,lista);
   }else
    //Insertamos el siginificado al final
         (*it).info_asoci.insert((*it).info_asoci.end(),s);

}

 /* Devuelve la información (una lista) asociada a una clave p. Podrían
 haberse definido operator[] como
 data<T,U> & operator[](int pos){ return datos.at(pos);}
 const data<T,U> & operator[](int pos)const { return datos.at(pos);}
  */
  template <class T, class U>
  list<U>  Diccionario<T,U>::getInfo_Asoc(const T & p) {
     typename list<data<T,U> >::iterator it;

     if (!Esta_Clave(p,it)){
       return list<U>();
     }else{
       return (*it).info_asoci;
     }
   }

 /*Busca una definicion dado su indice*/
 template <class T, class U>
 bool Diccionario<T,U>::Esta_Def(const T &p, const int &indice, typename  list<data<T,U> >::iterator &it_out1, typename list<U>::iterator &it_out2){

    if (datos.size()>0){

        typename list<data<T,U> >::iterator it1;
        typename list<U>::iterator it2;

        for (it1=datos.begin(); it1!=datos.end() ;++it1){
            if ((*it1).clave==p) {
              it2 = (*it1).info_asoci.begin();
              advance(it2,indice);
              it_out1=it1;
              it_out2=it2;
              return true;
            }
            else if ((*it1).clave>p){
               it_out1=it1;
               it_out2=it2;
               return false;
            }

        }

        it_out1=it1;
        it_out2=it2;
        return false;
    }
    else {
        it_out1=datos.end();
        it_out2=(*it_out1).info_asoci.end();
        return false;
    }
 }

 /*Elimina una determinada informacon asociada a una clave que está en el diccionario.
 Si no está la clave muestra un mensaje de error. Si sí está elimina la informacion asociada.
 */
 template <class T, class U>
 void Diccionario<T,U>::EliminaSignificado_Palabra(const int &indice, const T &p){
   typename list<data<T,U> >::iterator it1;
   typename list<U>::iterator it2;

   if (!Esta_Def(p,indice,it1,it2)){
     cout << "No existe la definiccion " << indice << " en la palabra " << p << endl;
   } else {
     (*it1).info_asoci.erase(it2);
   }
 }

 /*Elimina todo el contenido asociado a una palabra clave*/
 template <class T, class U>
 void Diccionario<T,U>::Elimina_Palabra(const T &p){
   typename list<data<T,U> >::iterator it;

   if (!Esta_Clave(p,it)){
     cout << "No existe la clave " << p << " en el diccionario" << endl;
   } else {
     //datos.remove(p);  //Elimina elementos de la lista con el valor dado como parámetro
     datos.erase(it);
     /*otra opción:  datos.erase(it);  Elimina uno o varios elementos de la lista.
      Se le pasa como parámetro o el iterador del valor a eliminar o dos iteradores marcando el inicio y final del rango a eliminar
      (inicio incluido y final sin incluir)*/

   }
 }
