all: bin/usoguia

documentacion:
	doxygen doc/Doxyfile

bin/usoguia: obj/guiatlf.o obj/usoguia.o
	g++ -g -o bin/usoguia obj/usoguia.o

obj/usoguia.o: include/guiatlf.h src/guiatlf.cpp src/usoguia.cpp
	g++ -g -I./include -c -o obj/usoguia.o src/usoguia.cpp

obj/guiatlf.o: include/guiatlf.h src/guiatlf.cpp
	g++ -g -I./include -c -o obj/guiatlf.o src/guiatlf.cpp

clean:
	echo "Limpiando..."
	rm -f obj/*.o

mrproper: clean
	rm -f bin/usoguia doc/html/*
