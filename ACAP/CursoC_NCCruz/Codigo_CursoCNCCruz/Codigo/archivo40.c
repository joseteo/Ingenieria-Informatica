#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>//Para sleep (Linux/UNIX)


//De: https://stackoverflow.com/questions/17432502/
	//how-can-i-measure-cpu-time-and-wall-clock-time-on-both-linux-windows
double get_wall_time(){ 
    struct timeval time;
    if (gettimeofday(&time,NULL)){
        printf("Error de medición de tiempo\n");
        return 0;
    }
    return (double) time.tv_sec + (double) time.tv_usec * 0.000001;
}

int main(void){
	double instanteA = get_wall_time();
	sleep(3);//Simulamos una tarea de 3 segundos
	double instanteB = get_wall_time();
	printf("He tardado: %.3lf segundos\n", instanteB-instanteA);
	return 0;
}
