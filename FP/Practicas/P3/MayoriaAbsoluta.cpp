#include <iostream>

using namespace std;

int main(){
	int votosA=0, votosA_c=0, votosB=0, votosB_c=0, votosC=0, votosC_c=0;
	int total_A=0, total_B=0, total_C=0, total_votos=0, votos_m=0;
	
	cout << "\nIntroduzca los votos y los votos por correo del partido A, B y C:" << endl;
	cin >> votosA >> votosA_c >> votosB >> votosB_c >> votosC >> votosC_c;
	
	total_A = votosA +votosA_c;
	total_B = votosB +votosB_c;
	total_C = votosC +votosC_c;
	
	total_votos = total_A + total_B +total_C;
	votos_m = total_votos/2;
	
	cout << "\nMayoria absoluta: ";
	
	if(total_A > votos_m)
		cout << "A " << endl;
	if(total_B > votos_m)
		cout << "B " << endl;
	if(total_C > votos_m)
		cout << "C " << endl;
	if( (total_A + total_B) > votos_m)
		cout << "AB " << endl;
	if( (total_A + total_C) > votos_m)
		cout << "AC " << endl;
	if( (total_B + total_C) > votos_m)
		cout << "BC " << endl;
	if(total_votos = 0)
		cout << "Error en los datos" << endl;
	
	return 0;
}
