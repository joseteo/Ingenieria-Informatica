/*compilacion y ejecucion

Usar el makefile=
	make && make ejemplo
o usar esto otro=
	flex++ cadenas.l
	g++ lex.yy.cc -o cadenas
	./cadenas texto.txt
*/
%option noyywrap
%{
  #include <iostream>
  #include <fstream>
  using namespace std;

  ifstream fichero;
	int cadenas_v = 0;
%}

signo				(\+|\-)
digito				[0-9]
caracter 			[a-zA-Z]
numero_entero_o_decimales	{digito}+(\.{digito}*)?
caracteres_juntos_separados	{caracter}+\_*

exp_reg	\${signo}?{numero_entero_o_decimales}\#{caracteres_juntos_separados}*\!!

%%
{exp_reg}	{++cadenas_v; cout << "Cadena valida: " << yytext << "\n";}
.|\n	{;}
%%

int main(int argc, char *argv[]){
  if(argc == 2){
    fichero.open(argv[1]);
  } else{
    cout << "Formato: ./cadenas <Nombre-fichero>" << endl;
    exit(-1);
  }

  yyFlexLexer flujo(&fichero, 0);
  flujo.yylex();

  cout << "Hay " << cadenas_v << " cadenas validas que cumplan esta expresion regular" << endl;

	return 0;
}
