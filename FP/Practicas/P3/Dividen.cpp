#include <iostream>

using namespace std;

int main(){
	int uno=0, dos=0, cont=0;
	
	cout << "\nIntroduce los dos valores: \n";
	cin >> uno >> dos;
	
	if(uno%dos == 0){
		cont++;
		if(dos%uno == 0)
			cont++;
	}else if(dos%uno == 0)
		cont++;
	
	if(cont == 1)
		cout << "\n Uno de ellos divide al otro" << endl;
	else if (cont == 2)
		cout << "\n Los dos se dividen entre ellos" << endl;
	else if (cont == 0)
		cout << "\n Ninguno divide al otro" << endl;
		
	
	return 0;
}
