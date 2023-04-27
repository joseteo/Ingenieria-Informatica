#include<mpi.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<sys/time.h>

double get_wall_time(){
	struct timeval time;

	if (gettimeofday(&time, NULL)){
		fprintf(stderr, "ERROR de medición del tiempo\n");
		return 0;
	}
	return (double) time.tv_sec + (double) time.tv_usec * 0.000001;
}

void genera_datos( double* v, int tam){
	double high = 1000, low = -high;

	for( int i=0; i<tam; i++)
		v[i]= (double)rand() / (double)RAND_MAX + low;
}

double encuentra_min( double *v, int tam ){
	int pos=0;

	for( int i=1; i<tam; i++){
		if( v[pos] < v[i] ){
			pos = i;
		}
	}
	return v[pos];
}

int main( int argc, char** argv){
	double *v, solucion;
	int tam_t, tam;

	double start_t, end_t, t_time;
	int size, rank;
	MPI_Status status;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if( argc == 2 && size >=2 ){
		if( rank == 0 ){
			tam_t = atoi(argv[1]);
			v = malloc( tam_t*sizeof(double));
			genera_datos(v, tam_t);
			tam=tam_t/size;
			for ( int i=1; i<size; i++){
				MPI_Send(&tam_t, 1, MPI_INT, i, 0, MPI_COMM_WORLD);

				if( i != size -1 )
					MPI_Send( &v[i*tam], tam, MPI_DOUBLE, i, 0, MPI_COMM_WORLD);
				else
					MPI_Send( &v[i*tam], tam + tam_t%size, MPI_DOUBLE, i, 0, MPI_COMM_WORLD);
			}

		}
		else{
			MPI_Recv(&tam_t, 1, MPI_INT , 0, 0, MPI_COMM_WORLD, &status);
			tam = tam_t/size;

			if (rank == size-1)
				tam +=tam_t%size;

			v = malloc( tam*sizeof(double));
			MPI_Recv(v, tam, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, &status);
		}
	}
	else{
		fprintf(stderr, "Uso: mpirun -np <2 o más> %s <tamaño del vector>\n", argv[0]);
		exit(1);
	}

	if ( rank == 1 )
		start_t=get_wall_time();

	solucion = encuentra_min( v, tam );

	if ( rank == 1 ){
		end_t = get_wall_time();
		t_time = end_t-start_t;
	}

	// Gather para el 1
	MPI_Gather(&solucion, 1, MPI_DOUBLE, v, 1, MPI_DOUBLE, 1, MPI_COMM_WORLD);
	if( rank == 1 ){
		solucion = encuentra_min(v, size);
		printf("\nSolución con \t%d\t nucleos, tam\t%d\t:\t%lf\t en \t%f\t segundos\n", size, tam_t, solucion, t_time);
	}

	free(v);
	MPI_Finalize();

	return 0;
}
