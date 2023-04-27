#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <limits.h>
#include <mpi.h>




int main(int argc, char* argv[]){
  MPI_Init(&argc, &argv);
	MPI_Status status;
  int n_clientes;
	int rank, size, suma_g=0, suma_i=0, s_g, s_i;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  int *ingresos, *gastos;
	if(rank==0){
		if(argc!=2){	//El primer argumento siempre es el nombre del programa
			printf("El numero ha introducir como numero de clientes debe ser mayor a 0\n");
		}else{
			n_clientes = atoi(argv[1]);
			if(n_clientes<=0)
				printf("El número de iteraciones debe ser un entero positivo!\n");
			else{
        MPI_Bcast(&n_clientes, 1, MPI_INT, 0, MPI_COMM_WORLD);
        ingresos = malloc(sizeof(int)*n_clientes);
				gastos = malloc(sizeof(int)*n_clientes);
				int workSize = n_clientes/size;
				int offset = n_clientes % size;

        int s = 0;
        int cantidad = workSize + (s<offset);

        generaVector(ingresos, gastos, n_clientes);

        for(int i=1; i<size; i++){
          MPI_Send(&ingresos[i*cantidad], cantidad, MPI_INT, i, TAG_INGRESOS, MPI_COMM_WORLD);
					MPI_Send(&gastos[i*cantidad], cantidad, MPI_INT, i, TAG_GASTOS, MPI_COMM_WORLD);
        }
        suma_vector(ingresos, gastos, cantidad, &suma_i, &suma_g);
      }
    }
  }else{
    int clientes;
    MPI_Bcast(&clientes, 1, MPI_INT, 0, MPI_COMM_WORLD);
    int workSize = clientes/size;
    int offset = clientes % size;
    int s= rank*workSize + (rank<offset?rank:offset);
    int cantidad = s + workSize + (s<offset);

    ingresos = malloc(sizeof(int)*cantidad);
    gastos = malloc(sizeof(int)*cantidad);

    MPI_Recv(ingresos, cantidad, MPI_INT, 0, TAG_INGRESOS, MPI_COMM_WORLD, &status);
    MPI_Recv(gastos, cantidad, MPI_INT, 0, TAG_GASTOS, MPI_COMM_WORLD, &status);

    suma_vector(ingresos, gastos, cantidad, &suma_i, &suma_g);
  }

  MPI_Reduce(&suma_i, &s_i, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
  MPI_Reduce(&suma_g, &s_g, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

  unsigned int resta = abs(s_i)-abs(s_g);

  if(rank == 0)
    printf("\n\nHemos obtenido unos ingresos de %d y unos gastos de %d y el resultado es %d\n", abs(s_i), abs(s_g), resta);

  free(ingresos);
  free(gastos);

  MPI_Finalize();
}
