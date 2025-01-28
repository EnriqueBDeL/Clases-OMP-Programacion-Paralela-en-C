/*
 
   ¿CUANDO UN CODIGO ES PARALELIZABLE?

   2. Si el código involucra datos compartidos entre hilos, como la acumulación en una sola variable, se deben usar mecanismos de sincronización para evitar condiciones de carrera.
 
*/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char **argv){


int N = 10;
 
int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int sum = 0;


//Paralelizable


//#pragma omp parallel for reduction(+:sum)
	for(int i = 0; i < N; i++){

		sum += array[i];

	}	


 printf("Suma total: %d\n", sum);


return 0;
}
