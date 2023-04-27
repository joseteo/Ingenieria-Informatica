/*compilacion y ejecucion
	flex plantilla.l
	gcc -lfl lex.yy.c -o plantilla
	./plantilla < texto.txt

	no he podido hacerlo en c++, fallaba yylex() como no declarado o libreria no incluida,
*/

%{
	#include <stdio.h>
	int cadenas_v = 0;
%}

signo				(\+|\-)
digito				[0-9]
caracter 			[a-zA-Z]
numero_entero_o_decimales	{digito}+(\.{digito}*)?
caracteres_juntos_separados	{caracter}+\_*

exp_reg	\${signo}?{numero_entero_o_decimales}\#{caracteres_juntos_separados}*\!

%%
{exp_reg}	{++cadenas_v;printf("Cadena valida: %s \n", yytext);}
.|\n	{;}
%%
int yywrap(){
	printf("Hay %d cadenas validas que cumplan esta expresion regular\n", cadenas_v);
	return 1;
}
int main(){
	yylex();
	return 0;
}
