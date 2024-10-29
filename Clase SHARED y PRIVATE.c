#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>


int main(int argc, char **argv){


	int total = 0;

	#pragma omp parallel shared(total) //Las variables definidas por shared son accesibles por todos los hilos.
	{

		#pragma omp atomic //Garantiza que cada incremento se realice por un solo hilo a la vez.

		total += 1;

	}	

	
	 printf("\n Total = %d",total);


	int suma = 0; 
	
	printf("\n"); 

	#pragma omp parallel private(suma) //private, crea copias unicas de la variable, para cada hilo.
	{
	
		suma = omp_get_thread_num();

		printf("\n Hilo: %d | suma = %d", omp_get_thread_num(), suma);
	}	

	 printf("\n");

	 return 0;
}