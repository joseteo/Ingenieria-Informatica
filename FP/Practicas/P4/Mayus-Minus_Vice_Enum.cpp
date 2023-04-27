#include <iostream>

using namespace std;

enum class TipoLetra{ Mayu, Minu, No_alf };

int main(){
   char letra_convertida, letra_original;
   const int DISTANCIA_MAY_MIN = 'a'-'A';
	TipoLetra tipo_letra;

   cout << "\nIntroduzca una letra: ";
   cin >> letra_original;

   if ((letra_original >= 'A') && (letra_original <= 'Z')){
   	tipo_letra = TipoLetra::Mayu;
      letra_convertida = letra_original + DISTANCIA_MAY_MIN;
   }else if ((letra_original >= 'a') && (letra_original <= 'z')){
   	tipo_letra = TipoLetra::Minu;
		letra_convertida = letra_original - DISTANCIA_MAY_MIN;
	}else
		tipo_letra = TipoLetra::No_alf;

	if(tipo_letra == TipoLetra::Mayu)
   	cout  << "\nLa letra era una mayúscula. Una vez convertida es " << letra_convertida << "\n";
   else if(tipo_letra == TipoLetra::Minu)
		cout  << "\nLa letra era una minúscula. Una vez convertida es " << letra_convertida << "\n";
	else
		cout << "\nEl carácter no era una letra" << endl;
}
