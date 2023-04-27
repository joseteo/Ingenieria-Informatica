BIN = bin
DOC = doc
INC = include
OBJ = obj
SRC = src
CXX = g++
CPPFLAGS = -Wall -g -I$(INC) -c


$(BIN)/pila_lista: $(OBJ)/uso_pila_lista.o $(OBJ)/pila_lista.o
	$(CXX) -o $@ $<

$(OBJ)/uso_pila_lista.o: $(SRC)/uso_pila_lista.cpp $(INC)/pila_lista.h
	$(CXX) $(CPPFLAGS) -o $@ $<

$(OBJ)/pila_lista.o: $(INC)/pila_lista.h $(SRC)/pila_lista.cpp  
	$(CXX) $(CPPFLAGS) -o $@ $<

documentacion:
	doxygen doc/doxys/Doxyfile

clean:
	-rm $(OBJ)/* $(LIB)/*

mrproper: clean
	-rm $(BIN)/* doc/html doc/latex


ejecutar:
	./bin/pila_lista
	
