#include <iostream>
#include <iomanip>
#include <chrono>
#include <future>
#include <vector>
#include <cmath>

//AUTOR= José Teodosio Lorente Vallecillos
//se compila con g++ -std=c++11 -pthread -o calculo_integral_exe calculo_integral.cpp

using namespace std;
using namespace std::chrono;
const long m=1024l*1024l*1024l, h=4;


double f(double x){
  return 4.0/(1.0+x*x);
}


double calcular_integral_sec(){
  double suma=0.0;
  for(long i=0; i<m; i++)
    suma+=f((i+double(0.5))/m);
  return suma/m;
}


double funcion_hebra(long i){
  double suma=0.0;
  for(unsigned long j=i; j<m; j+=h)
    suma+=f((j+double(0.5))/m);
  return suma;
}


double calcular_integral_conc(){
  double total=0.0;
  future<double> futuros[h];

  for(int i=0; i<h; i++)
    futuros[i]=async(launch::async, funcion_hebra, i);

  for(int i=0; i<h; i++)
    total+=futuros[i].get();

  return total/m;
}

int main(){
  time_point<steady_clock> inicio_sec=steady_clock::now();
  const double result_sec=calcular_integral_sec();

  time_point<steady_clock> fin_sec=steady_clock::now();

  double x=sin(0.4567);

  time_point<steady_clock> inicio_conc=steady_clock::now();
  const double result_conc=calcular_integral_conc();

  time_point<steady_clock> fin_conc=steady_clock::now();
  duration<float,milli> tiempo_sec=fin_sec - inicio_sec, tiempo_conc=fin_conc - inicio_conc;
  const float porc=100.0*tiempo_conc.count()/tiempo_sec.count();

  constexpr double pi=3.14159265358979323846l;

  cout<<"Numero de muestras (m)=            "<<m<<endl
      <<"Numero de hebras (h)=              "<<h<<endl
      <<setprecision(20)
      <<"Valor de PI=                       "<<pi<<endl
      <<"Resultado secuencial=              "<<result_sec<<endl
      <<"Resultado concurrente=             "<<result_conc<<endl
      <<setprecision(6)
      <<"Tiempo secuencial=                 "<< tiempo_sec.count()<<" milisegundos"<<endl
      <<"Tiempo concurrente=                "<< tiempo_conc.count()<<" milisegundos"<<endl
      <<setprecision(4)
      <<"% tiempo conc/tiempo sec=          "<<porc<<"%"<<endl;
}
