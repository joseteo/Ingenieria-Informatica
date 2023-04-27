
							Authors

Aida Martín Cuéllar
José Teodosio Lorente Vallecillos

							Letras



						El Problema de las Cifras

En un conjunto dado de enteros positivos representado como "C", y otro entero dado representado como "E". Se ha de encontrar una solucion tal que con los enteros dados del conjunto C, y mediante operaciones simples, suma, resta, multiplicacion y division, se pueda obtener como resultado E.

Si C = (1,2,3,4,5,6) y E = 100 una solucion al problema es= 4 * (5 * (6 - 1)) = 100; por ejemplo.

Y para llegar a encontrar una solucion al problema un algoritmo que funciona de la siguiente manera:

Para C = (1,2,3,4,5,6) y E = 100.

n = C.size 	siendo en este caso 6 la cantidad de enteros con los que consta C.
Se guardan los enteros de C en clases con indice de 2^0 hasta 2^(n-1)
Es decir:
clase[1]  = (6) (1  = 000001)
clase[2]  = (5) (2  = 000010)
clase[4]  = (4) (4  = 000100)
clase[8]  = (3) (8  = 001000)
clase[16] = (2) (16 = 010000)
clase[32] = (1) (32 = 100000)
Estas son las clases con code ó indices 2^0 - 2^(n-1) que almacenan los enteros originales de C
Pero el indice de las clases llega hasta (2^n)-1, en este ejemplo hasta (2^6)-1= 63
Las igualdades de la columna de la derecha son para entender mejor el desarrollo.
El metodo de resolucion para hallar los resultados que coincidan con E es:
Para calcular la clase[3], hay que tener en cuenta su valor en binario (3 = 000011), es decir, la suma de los enteros originales (1  = 000001) y (2  = 000010), de esta forma se puede asegurar que ninguno de los enteros originales es repetido o usado para calcular el resultado varias veces; por lo tanto el contenido de la clase[3] = (6+5, 6-5, 6*5, 6/5) las operaciones generadas por los enteros iniciales de las clases 1 y 2.
De la misma forma el calculo de la clase[7] serian las operaciones entre las clases (4+3), (1+6), (2+5), (1+2+4), pero no serian correctas las soluiones en las que se repitan el mismo bit de posicion en la suma de los valores binarios de los indices, es decir, las clases (2+2+3) ya que:
clase[2]  = (5) 		(2 = 000010)
clase[2]  = (5) 		(2 = 000010)
clase[3] = (6+5, 6-5, 6*5, 6/5) (3 = 000011)
en este caso se estaria repitiendo el bit de posicion 2, cuyo valor en el conjunto C es 5, tres veces en las operaciones.

Y de esta forma hasta el indice (2^n)-1, en este caso hasta 63, cuya clase sería
clase[63] = (operaciones de las clases que cumplen los requisitos para poder calcular la solucion) (63 = 111111)

De todas las soluciones posibles que salgan como resultado, el algoritmo tiene preferencia por las operaciones con mas importancia segun los calculos de las operaciones convencionales.


						EJECUCION DEL PROGRAMA
Carpetas
bin = Donde se guarda el ejecutable tras compilar el programa
include = Donde se guardan los archivos .h
src = Donde se guardan los archivos .cpp
obj = Donde se guardan los archivos .o

Archivos
makefile = Compila el programa
ordenes del makefile:
	make mr = sirve para borrar todos los archivos .o de la carpeta obj y el ejecutable de la carpeta bin
	make clean = sirve para borrar todos los archivos .o de la carpeta obj
	make (all) = sirve para compilar el programa y crear el ejecutable
datos = archivo que contiene los datos del problema
Arquitectura del archivo datos:

numerodatos= 14
Datos= 1 2 3 4 5 6 7 8 9 10 25 50 75 100
Valorrequerido= 853

numerodatos = es el numero de datos introducidos en el parametro Datos
Datos = los numeros enteros originales del programa necesarios
Valorrequerido = el numero entero requerido para calcularlo

Con estos parametros y previa compilacion del programa con la orden make, la cual se lleva acabo sin fallos en la compilacion, y ejecucion con el comando=

./bin/el_problema_de_las_cifras datos

salen estos resultados por pantalla=

Tiempo de calculos= 0.02763 segundos
El valor requerido se ha alcanzado
Calculos realizados= 
3 + (50 * (7 + 10)) = 853




