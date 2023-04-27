#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <limits.h>
#include <mpi.h>


int main(int argc, char* argv[]){

    int size, tarea_hijo, num_filas, i, j, NF, NC, sum;
    MPI_Status status;
    double startwtime, endwtime;
    MPI_Init(&argv, &argc);
    MPI_Comm_rank(MPI_COMM_WORLD, &tarea_hijo);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if(argc!=3){	//El primer argumento siempre es el nombre del programa
			printf("La forma es ./practica4 Num_filas Num_col\n");
		}
    NF = atoi(argv[1]);
    NC = atoi(argv[2]);
    float a[NF][NC];
    num_filas = NF / size;
    //inicializacion matriz a
    for (i = tarea_hijo * num_filas; i <= (tarea_hijo + 1) * num_filas; i++)
       for (j = 0; j <= NC; j++){
           srand(time(NULL));
           a[i][j] = rand() % 11 + 1;
       }
    if (tarea_hijo == 0)
       startwtime = MPI_Wtime();
    //calculo suma
    for (i = 0; i < NF; i++)
           for (j = 0; j < NC; j++)
                sum += a[i][j];

    if (tarea_hijo > 0){
        int fila = tarea_hijo * num_filas;
        MPI_Send(&a[fila][0], num_filas * NC, MPI_FLOAT, 0, 99,
                 MPI_COMM_WORLD);
    }
    if (tarea_hijo == 0){
        for (i = size - 1; i >= 1; i--){
            int fila = i * num_filas;
            MPI_Recv(&a[fila][0], num_filas * NC, MPI_FLOAT, i, 99,
                      MPI_COMM_WORLD, &status);
        }
        endwtime = MPI_Wtime();
        printf("Tiempo = %lf\n", endwtime - startwtime);
        for (i = 0; i < NF; i++){
             for (j = 0; j < NC; j++)
                printf("a[%d][%d] = %.4f \t", i, j, a[i][j]);
             printf("\n");
        }
        printf("suma = %.4d\n", sum);
    }
    MPI_Finalize();
    return 0;
}
