#include <iostream>
#include <cmath>

using namespace std;

bool metapentagonal(int n1, int n2, int p[], int tope){
	int meta=0, media, val_abs;
	bool meta1=false, meta2=false, metapentagonal=false;
	
	media=(n1+n2)/2;
	val_abs=abs(n1-n2);
	
	for(int i=0; i<tope; i++){
		if(media==p[i])
			meta1=true;
		if(val_abs==p[i])
			meta2=true;
	}
	
	if(meta1 && meta2)
		metapentagonal=true;
	
	return metapentagonal;
}

int main(){
	int tope=0;
	
	cout << "\nIntroduce un entero tope: " << endl;
	cin >> tope;
	while( (tope < 0) || (tope > 1000) ){
		cout << "\nIntroduce un entero tope(entre 0 y 1000): " << endl;
		cin >> tope;
	}
	
	int p[tope], dist=0, pareja[2];
	
	for(int i=0; i<=tope; i++){
		p[i] = ( i*( (3*i)-1 ) ) / 2 ;
	}
	
	int meta=0, media, val_abs;
	bool meta1=false, meta2=false, metapentagonal=false;
		
	
	
	for(int i=0; i<tope-1; i++)
		for(int j=i+1; j<tope;j++){
			media=(i+j)/2;
			val_abs=abs(i-j);
			for(int i=0; i<tope; i++){
					if(media==p[i])
						meta1=true;
					if(val_abs==p[i])
						meta2=true;
			}
			if (meta1 && meta2)
				if ( abs(i-j)>dist ){
					dist = abs(i-j);
					pareja[0]=i;
					pareja[1]=j;
				}
		}
			
	
	cout << "\n" << pareja[0] << " " << pareja[1] << endl;
	
}
