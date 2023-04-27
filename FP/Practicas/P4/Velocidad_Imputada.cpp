#include <iostream>

using namespace std;

int main(){
	double vC=0, vI=0;
	char tipoR; //caracteres en ascii F=70 y M=77
	
	cout << "\nIntroduce el tipo de radar( F / M ) y la velocidad captada" << endl;
	cin >> tipoR >> vC;
	
	if(tipoR == 70){
		if(vC <= 100)
			vI = vC-5;
		else
			vI = vC - vC*0.05;
	}else{
		if(vC <= 100)
			vI = vC-7;
		else
			vI = vC - vC * 0.07;
	}
	
	cout << "\nVelocidad Imputada: " << vI << endl;
	
	
	return 0;
}
