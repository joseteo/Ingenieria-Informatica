#include <iostream>

using namespace std;

int main(){
	int v_inicial=0, n_filas=0;
	
	cout << "\nIntroduce el valor inicial y el numero de filas: ";
	cin >> v_inicial >> n_filas;
	
	for(int i=v_inicial; i<=n_filas; i++){
		for(int j=i; j<=n_filas; j++)
			cout << j << " ";
		cout << "\n\n";
	}
	
	
	return 0;
}
