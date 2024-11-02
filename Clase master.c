#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>

int main (int argc, char **argv){


	#pragma omp parallel //Todos los hilos ejecutarán este bloque
	{
		printf("El hilo %d esta ejecutando el bloque.\n",omp_get_thread_num());


		#pragma omp master //Solo el hilo maestro ejecutará este bloque
		{
			printf("El hilo maestro %d esta ejecutando este bloque.\n",omp_get_thread_num());
		}


	}

return 0;
}
