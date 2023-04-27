#include<iostream>

using namespace std;
int main(){
float ta,tb,np,sp,f;
ta=tb=np=sp=f=0;

cout<<"Introduce Ta"<<endl;
cin>>ta;
cout<<"Introduce Tb"<<endl;
cin>>tb;
cout<<"Introduce numero de procesadores"<<endl;
cin>>np;

sp=(ta+np*tb)/(ta+tb);
f=(ta/(ta+tb));

cout<<"La ganancia es: "<< sp<<endl;
cout<<"El valor de f  de la ley de gustafon es: "<<f<<endl;
cout<<"El valor de f  de la ley de gustafon en % es: "<<f*100<<endl;

cout<<"La formula de gustafon es: Ta/(Ta+Tb)"<<endl;
cout<<"El valor f en la ley de Amdahl es: Ta/(Ta+(Tb*p))"<<endl;
cout<<"La expresion de la ley de gustafon en terminos de los parametros f y p es: Sp=f+(1-f)*p"<<endl;

}
