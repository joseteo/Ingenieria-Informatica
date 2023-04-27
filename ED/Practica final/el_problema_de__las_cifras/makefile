CXX=g++
CPPFLAGS=-c -Wall -fpermissive
CXXFLAGS=-I$(INCLUDE) -g
BIN=./bin
INCLUDE =./include
OBJ=./obj
SRC=./src
DOC=./doc
EXECUTABLE=el_problema_de_las_cifras
EXECUTABLE_OBJECTS=$(OBJ)/resultado.o $(OBJ)/algorithm.o $(OBJ)/main.o


all: $(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(EXECUTABLE_OBJECTS)
	@echo Creando el ejecutable $@...
	$(CXX) $(CXXFLAGS) -o $(BIN)/$(EXECUTABLE) $^ $(INCLUDE)/resultado.h $(INCLUDE)/algorithm.h

$(OBJ)/main.o: $(SRC)/main.cpp $(INCLUDE)/resultado.h $(INCLUDE)/algorithm.h
	@echo Creando el objeto $@...
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $(SRC)/main.cpp

$(OBJ)/resultado.o: $(SRC)/resultado.cpp $(INCLUDE)/resultado.h
	@echo Creando el objeto $@...
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $(SRC)/resultado.cpp

$(OBJ)/algorithm.o: $(SRC)/algorithm.cpp $(INCLUDE)/algorithm.h $(INCLUDE)/resultado.h
	@echo Creando el objeto $@...
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $(SRC)/algorithm.cpp

clean:
	@echo Borrando los ficheros ./*.o del directorio $(OBJ)...
	rm $(OBJ)/*.o

mrproper: clean
	@echo Borrando el ejecutable $(EXECUTABLE) del directorio $(BIN)...
	rm $(BIN)/$(EXECUTABLE)


