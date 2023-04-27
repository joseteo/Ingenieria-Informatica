INC = include
OBJ = obj
SRC = src
BIN = bin
CXX = g++

all: $(BIN)/Pila_max_VD

$(BIN)/Pila_max_VD: $(OBJ)/Pila_max_VD.o $(OBJ)/usopilas_max.o
	$(CXX) -o $(BIN)/Pila_max_VD $(OBJ)/Pila_max_VD.o $(OBJ)/usopilas_max.o

$(OBJ)/usopilas_max.o: $(SRC)/usopilas_max.cpp
	$(CXX) -c -I$(INC) $(SRC)/usopilas_max.cpp -o $(OBJ)/usopilas_max.o

$(OBJ)/Pila_max_VD.o: $(INC)/Pila_max_VD.h $(INC)/VDG.h
	$(CXX) -c -I$(INC) $(SRC)/Pila_max_VD.cpp -o $(OBJ)/Pila_max_VD.o


clean:
	rm -fr $(OBJ)/*

mrproper: clean
	rm -fr $(BIN)/*

