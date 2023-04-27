INC = include
OBJ = obj
SRC = src
BIN = bin

.PHONY: clean mrproper


#all:  $(OBJ)/usoguia.o  $(INC)/guiatlf.h $(BIN)/prueba


$(BIN)/prueba : $(OBJ)/usoguia.o $(INC)/guiatlf.h
	g++ -o $(BIN)/prueba $(OBJ)/usoguia.o $(INC)/guiatlf.h

$(OBJ)/%.o: $(SRC)/%.cpp
	g++ -c -I./$(INC) -o $@ $<

#$(OBJ)/usoguia.o : $(SRC)/usoguia.cpp
#$(OBJ)/guiatlf.o : $(INC)/guiatlf.h

clean:
	@rm -fr $(OBJ)/*
	@echo "Limpiando obj..."

mrproper: clean
	@rm -fr $(BIN)/*
	@echo "Limpiando bin..."

