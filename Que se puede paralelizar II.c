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
int count = 0;

	
//Paralelizable (Caso 1):

//#pragma omp parallel for reduction(+:sum)
	for(int i = 0; i < N; i++){

		sum += array[i];

	}	


 printf("Suma total: %d\n", sum);



//Paralelizable (Caso 2):

//#pragma omp parallel for reduction(+:count)
    for(int i = 0; i < N; i++){
        count++;  
    }

 printf("Suma total con sum++: %d\n", count);

	
return 0;
}
