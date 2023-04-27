#include <iostream>
#include <cmath>

using namespace std;

double MediaArit(double x[], int N){
	double media=0;
	
	for(int i=0; i < N; i++){
		media += ( x[i] / N );
	}
	
	return media;
}

double MediaGeom(double x[], int N){
	double media;
	
	media=x[0];
	for(int i=1; i < N; i++){
		media *= x[i];
	}
	
	media = pow(media, 1/N);
	
	return media;
}

int main(){
}

