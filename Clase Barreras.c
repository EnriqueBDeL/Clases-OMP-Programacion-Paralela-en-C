#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>

int main(int argc, char **argv){

 int total = 0;

 	#pragma omp parallel shared(total)
 	{
	
		int id = omp_get_thread_num();
		int suma = id + 1;

		printf("\nHilo: %d | suma = %d", id, suma);


		#pragma omp barrier //Garantiza que todos los hilos lleguen a este punto antes de continuar.

		#pragma omp atomic
		
		total += suma;

		//printf("\nHilo %d | total = %d",id,total);	

	}

	printf("\n\n[ Total = %d ]\n\n",total);

	return 0;

}
