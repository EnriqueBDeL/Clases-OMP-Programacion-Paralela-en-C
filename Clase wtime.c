#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main (int argc, char **argv){

	double empezar, terminar;
	int a = 0;

	empezar = omp_get_wtime(); // Devuelve el tiempo en segundos desde un momento específico


	#pragma omp parallel for


	for(int i = 0; i < 1000; i++){

		a +=i; 

	}

	terminar = omp_get_wtime();


	printf("Tiempo transcurrido: %f segundos\n", terminar - empezar);


return 0;

}	
