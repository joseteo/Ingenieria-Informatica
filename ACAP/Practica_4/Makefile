#Makefile
#definir variables
objects= ejer1 ejer2 ejer3
NVCC= nvcc		#compilador c cuda
opt= -O2 -g -G		#optimizador de flags

#compilar
all: ejer1 ejer2 ejer3

ejer1:
	$(NVCC) $(opt) -o ejer1 ejer1.cu

ejer2:
	$(NVCC) $(opt) -o ejer2 ejer2.cu

ejer3:
	$(NVCC) $(opt) -o ejer3 ejer3.cu

#clean
clean:
	rm $(objects)
