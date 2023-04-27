#include <stdio.h>
#include <stdlib.h>

#ifdef _OPENMP
    #include <omp.h>
#else
    #define omp_get_thread_num() 0
#endif

int main(int argc, char **argv)
{
    int i, n=200, chunk, modif, a[n], suma=0;
    omp_sched_t tipo;

    if(argc < 3)
    {
        fprintf(stderr,"\nFalta iteraciones o chunk\n");
        exit(-1);
    }

    n = atoi(argv[1]);
    if (n>200)
        n=200;

    chunk = atoi(argv[2]);

    omp_get_schedule(&tipo, & modif);

    for (i=0; i<n; i++)
        a[i] = i;

    #pragma omp parallel for firstprivate(suma) \
                lastprivate(suma) schedule(dynamic,chunk)
    for (i=0; i<n; i++)
    {
        if(i==0)
            printf("Dentro del parallel; num_threads=%d, num_procs=%d, omp_in_parallel=%d\n",
                    omp_get_num_threads(), omp_get_num_procs(), omp_in_parallel());

        suma = suma + a[i];
        printf(" thread %d suma a[%d]=%d suma=%d \n",
               omp_get_thread_num(),i,a[i],suma);
    }

    printf("\nFuera de 'parallel for' suma=%d\n",suma);
    printf("omp_get_num_threads()=%d\n",omp_get_num_threads());
    printf("omp_get_num_procs()=%d\n",omp_get_num_procs());
    printf("omp_in_parallel()=%d\n",omp_in_parallel());
}
