#include <cmath>
#include <string>
#include <iostream>

using namespace std;

/*    
   class FormateadorDoubles
   
   private:
      double Redondea(double real, int num_decimales)
      string EliminaUltimos(string cadena, char a_borrar)
      
   public:
      FormateadorDoubles()  // <- Por defecto ser� con "" a izda y dcha, 
                            // con punto como separador decimal 
                            // y con 2 cifras decimales
      FormateadorDoubles(string delimitador_izda,
                         string delimitador_dcha,
                         int num_decimales_a_mantener)
      void SetSeparadorPunto()
      void SetSeparadorComa()
      SetDelimitadores(string delimitador_izda, string delimitador_dcha)
      SetDelimitadorIzda(string delimitador_izda)
      SetDelimitadorDcha(string delimitador_dcha)
      void SetNumeroDecimales(int num_decimales_a_mantener)
      string GetCadena(double real)
*/

/*
Esquema:
   
   Decisiones que se han tomado en el dise�o de esta soluci�n:   
   
   Se han incluido como m�todos privados los siguientes: 
      
      double Redondea(...)
      string EliminaUltimos(...)
   
   Tambi�n los podr�amos haber puesto como funciones globales ya que trabajan
   sobre tipos de datos simples y pueden ser funciones que podr�an usarse en otros
   contextos.
   
   Se ha creado la clase FormateadorDoubles atendiendo a lo siguiente:   
   
   - La clase proporciona un constructor sin par�metros por lo que:   
      =  Los separadores izda y dcha se asignar�n por defecto a ""
      =  El n�mero de decimales se asignar� por defecto a 2
      =  El separador por defecto entre la parte entera y la decimal ser� el punto
   
   - La clase tambi�n proporciona un constructor con par�metros para especificar:   
      =  Los separadores
      =  El n�mero de decimales
      
   - Una vez construido el objeto, se permitir� cambiar el separador,
     el n�mero de decimales y los delimitadores a trav�s de m�todos:
   
      =  Como s�lo hay dos posibilidades para especificar el separador, es mucho
         mejor usar dos m�todos:      
            void SetSeparadorComa()
            void SetSeparadorPunto()            
         que un m�todo del tipo:         
            void SetSeparador(char caracter);   // :-( �Dejamos demasiadas posibilidades!
      
      = Para cambiar el n�mero de decimales:      
            void SetNumeroDecimales(int num_decimales)
      
      = Para cambiar los delimitadores se proporcionan sendos m�todos
        para cambiarlos por separado y otro m�todo por si se quiere
        cambiar ambos delimitadores en una �nica sentencia.
*/

class FormateadorDoubles{
private:
   enum class SeparadorDecimal {PUNTO, COMA};  // <- Podemos definir un tipo enumerado PRIVADO
   string izda    = "";  
   string dcha    = "";  
   int decimales  = 2;   
   SeparadorDecimal separador = SeparadorDecimal::PUNTO;   
   
   double Redondea(double real, int num_decimales){
      double real_redondeado;
      long long potencia_10;
   
      potencia_10 = pow(10, num_decimales);
      real_redondeado = round(real * potencia_10);
      real_redondeado = real_redondeado / potencia_10;
   
      return real_redondeado;
   }
   
   string EliminaUltimos(string cadena, char a_borrar){
      // MUY IMPORTANTE: Las modificaciones que hagamos sobre cadena NO afectan
      // al par�metro actual.
   
      while (! cadena.empty() && cadena.back() == a_borrar)
         cadena.pop_back();
   
      /*
      Otra forma:
   
         int ultimo = cadena.size() - 1;
   
         while (ultimo >= 0 && cadena[ultimo] == a_borrar){
            cadena.erase(ultimo);
            ultimo--;
         }
      */
      return cadena;
   }

public:
   // Constructor sin par�metros ("por defecto")
   // Usar� para los datos miembro los valores especificados arriba, es decir:
   // Delimitadores izda y dcha: "", 2 cifras decimales y el punto como separador   
   FormateadorDoubles(){      
   }   
   
   FormateadorDoubles(string delimitador_izda,
                      string delimitador_dcha)
   {
      SetDelimitadores(delimitador_izda, delimitador_dcha);
   }
   
   FormateadorDoubles(string delimitador_izda,
                      string delimitador_dcha,
                      int num_decimales_a_mantener)
      :FormateadorDoubles(delimitador_izda, delimitador_dcha)
   {
      SetNumeroDecimales(num_decimales_a_mantener);
   }
   
   void SetSeparadorPunto(){
      separador = SeparadorDecimal::PUNTO;
   }
   void SetSeparadorComa(){
      separador = SeparadorDecimal::COMA;
   }
   
   void SetDelimitadorIzda(string delimitador_izda){
      izda = delimitador_izda;
   }
   
   void SetDelimitadorDcha(string delimitador_dcha){
      dcha = delimitador_dcha;
   }
   
   void SetDelimitadores(string delimitador_izda, string delimitador_dcha){
      SetDelimitadorIzda(delimitador_izda);
      SetDelimitadorDcha(delimitador_dcha);
   }

   void SetNumeroDecimales(int num_decimales_a_mantener){
      if (num_decimales_a_mantener >= 0)
         decimales = num_decimales_a_mantener;
   }
   
   //---------------------------------------------------------------------
   // string GetCadena(double real)
   // Transforma el real en string, redonde�ndolo al n�mero de
   // cifras decimales especificado en el correspondiente dato miembro
   
   // 1.23  1  1.2
   // 1.23  2  1.23
   // 1.23  3  1.23
   // 1.23 20  1.23
   // 1.25  1  1.3
   // 1.25  2  1.25
   
   string GetCadena(double real){
   // Algoritmo:
   //    Redondear el real al n�mero de cifras decimales especificado
   //    Inicializar la cadena a to_string de la parte entera del real
   //    A�adir a la cadena un punto o una coma
   //    Transformar a string todos y cada uno de los d�gitos
   //       de la parte real. Para ello, ir rest�ndole
   //       al real su parte entera y sacar el primer
   //       d�gito truncando el resultado de multiplicarlo por 10
   //       Transformar dicho d�gito con to_string y a�adirlo a la cadena

   // Supongamos num cifras decimales = 3
   // real = 12.345 -> trunc(real) = 12
   //    -> cadena = to_string(12) + "." -> "12."
   //    -> Redondea(12.345 - 12, 3) = 0.345
   //    -> (*10) -> real = 3.45
   //    -> (trunc) -> 3 -> to_string -> "3" -> cadena = "12.3"
   // -> Volver a hacer lo mismo con real = 3.45

   // Nota. Para evitar los problemas de precisi�n usamos la funci�n Redondea.
   // 1.23 - 1 da como resultado 0.22999999999999998
   // Redondea(1.23 - 1, decimales >= 2) da como resultado 1.23

   // Si se especifican m�s d�gitos de los que hay, el string
   // resultante contendr� ceros a la derecha, por lo que habr� que eliminarlos
   // 1.23 (con cinco decimales): -> "1.23000" -> "1.23"

   // Hemos establecido la constante MAX_DIGITOS_PRECISION_DOUBLE a 15
   // Preferiblemente, podr�amos usar la constante DBL_DIG definida
   // en la biblioteca est�ndar <cfloat>

      const int MAX_DIGITOS_PRECISION_DOUBLE = 15;
      int parte_entera;
      int num_digitos_precision;
      string cadena_separador;
      string cadena = "";  // No es necesario. C++ inicializa los string a ""

      if (real < 0)
         cadena = "-";

      real = abs(real);
      real = Redondea(real, decimales);
      parte_entera = trunc(real);
      cadena = cadena + to_string(parte_entera);
      num_digitos_precision = cadena.size();

      if (real != parte_entera
         && decimales > 0
         && num_digitos_precision < MAX_DIGITOS_PRECISION_DOUBLE){

         if (separador == SeparadorDecimal::PUNTO)
            cadena_separador = ".";
         else
            cadena_separador = ",";

         cadena = cadena + cadena_separador;

         for (int i = 0; i < decimales && num_digitos_precision < MAX_DIGITOS_PRECISION_DOUBLE; i++){
            real = Redondea(real - parte_entera, decimales);
            real = real * 10;
            parte_entera = trunc(real);
            cadena = cadena + to_string(parte_entera);
            num_digitos_precision++;
         }

         while (cadena.back() == '0')
            cadena.pop_back();
      }

      cadena = izda + cadena + dcha;

      return cadena;
   }
};

int main(){
	double real;
	FormateadorDoubles cadena1, cadena2;
	
	cout << "\nIntroduce un numero real: ";
	cin >> real;
	
	cadena1 = FormateadorDoubles();
	cadena2 = FormateadorDoubles();
	
	cout << cadena1.GetCadena(real);
	
	cadena2.SetSeparadorComa();
	cadena2.SetDelimitadores("<<", ">>");
	cadena2.SetNumeroDecimales(3);
	
	cout << "\t" << cadena2.GetCadena(real);
	
}
