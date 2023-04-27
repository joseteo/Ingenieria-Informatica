#include <iostream>

using namespace std;

int main(){
	int x=0, y=0, z=0, aux=0;
	
	cout << "\nIntroduce 'X' 'Y' y 'Z': ";
	cin >> x >> y >> z;
	
	aux = x;
	x = z;
	z = y;
	y = aux;
	
	cout << "\nX vale: " << x;
	cout << "\nY vale: " << y;
	cout << "\nZ vale: " << z << endl;
	
	return 0;
}
