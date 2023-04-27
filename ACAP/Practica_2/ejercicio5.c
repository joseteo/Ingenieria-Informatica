#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <limits.h>
#include <mpi.h>


int main(int argc, char* argv[]){

    int size, tarea_hijo, num_filas, i, j, k, NFA, NCA, NCB;
    MPI_Status status;
    double startwtime, endwtime;
    MPI_Init(&argv, &argc);
    MPI_Comm_rank(MPI_COMM_WORLD, &tarea_hijo);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if(argc!=4){	//El primer argumento siempre es el nombre del programa
			printf("La forma es ./practica5 Num_filas_A Num_col_A Num_col_B\n");
		}
    NFA = atoi(argv[1]);
    NCA = atoi(argv[2]);
    NCB = atoi(argv[3]);
    float a[NFA][NCA];
    float b[NCA][NCB];
    float c[NFA][NCB];
    num_filas = NFA / size;
    //inicializacion matriz a
    for (i = tarea_hijo * num_filas; i < (tarea_hijo + 1) * num_filas; i++)
       for (j = 0; j < NCA; j++){
           srand(time(NULL));
           a[i][j] = rand() % 11 + 1;
       }
    //inicializacion matriz b
    for (i = 0; i < NCA; i++)
       for (j = 0; j < NCB; j++){
         srand(time(NULL));
         b[i][j] = rand() % 11 + 1;
       }
    if (tarea_hijo == 0)
       startwtime = MPI_Wtime();
    //calculo matriz c
    for (k = 0; k < NCB; k++)
       for (i = tarea_hijo * num_filas; i < (tarea_hijo + 1) * num_filas; i++){
           c[i][k] = 0.0;
           for (j = 0; j < NCA; j++)
                c[i][k] = c[i][k] + a[i][j] * b[j][k];
        }
    if (tarea_hijo > 0){
        int fila = tarea_hijo * num_filas;
        MPI_Send(&c[fila][0], num_filas * NCB, MPI_FLOAT, 0, 99,
                 MPI_COMM_WORLD);
    }
    if (tarea_hijo == 0){
        for (i = size - 1; i >= 1; i--){
            int fila = i * num_filas;
            MPI_Recv(&c[fila][0], num_filas * NCB, MPI_FLOAT, i, 99,
                      MPI_COMM_WORLD, &status);
        }
        endwtime = MPI_Wtime();
        printf("Tiempo = %lf\n", endwtime - startwtime);
        for (i = 0; i < NCA; i++){
             for (k = 0; k < NCB; k++)
                printf("c[%d][%d] = %.4f \t", i, k, c[i][k]);
             printf("\n");
        }
    }
    MPI_Finalize();
    return 0;
}
