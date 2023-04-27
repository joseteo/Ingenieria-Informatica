all: bin/usodiccionario

documentacion:
	doxygen doc/Doxyfile

bin/usodiccionario: obj/diccionario.o obj/usodiccionario.o
	g++ -g -o bin/usodiccionario obj/diccionario.o obj/usodiccionario.o

obj/usodiccionario.o: include/diccionario.h src/diccionario.cpp src/usodiccionario.cpp
	g++ -g -I./include -c -o obj/usodiccionario.o src/usodiccionario.cpp

obj/diccionario.o: include/diccionario.h src/diccionario.cpp
	g++ -g -I./include -c -o obj/diccionario.o src/diccionario.cpp

clean:
	echo "Limpiando..."
	rm -f obj/*.o

mrproper: clean
	rm -f bin/usodiccionario doc/html/*
