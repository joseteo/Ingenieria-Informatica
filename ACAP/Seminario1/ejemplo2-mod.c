#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>

#define BUFF_SIZE 10

int main(int argc, char* argv[]){
	int rank, size;
	int *buffer;
	MPI_Status status;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	if(size!=2){
		if(rank==0){
			printf("Ejecuta este programa con 2 procesos!\n");
		}
	}else{
		if(rank==0){
			buffer=malloc(BUFF_SIZE*sizeof(int));
			for(int i=0; i<BUFF_SIZE; i++){
				buffer[i] = i;
			}
			MPI_Send(buffer, BUFF_SIZE, MPI_INT, 1, 0, MPI_COMM_WORLD);
			free(buffer);
		}else{
			MPI_Probe(0, 0, MPI_COMM_WORLD, &status);
			int cont;
			MPI_Get_count(&status, MPI_INT, &cont);
			buffer=malloc(cont*sizeof(int));

			MPI_Recv(buffer, BUFF_SIZE, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
			printf("Soy el proceso 1 y he recibido:\n");
			for(int i=0; i<BUFF_SIZE; i++){
				printf("%d\t", buffer[i]);
			}
			printf("\n");
			free(buffer);
		}//A veces, si mostramos muchas cosas, tal vez no se vean como esperamos.
	}	 //Es porque estan en el buffer de salida => fflush(stdout) nos ayuda
	MPI_Finalize();
	return 0;
}
