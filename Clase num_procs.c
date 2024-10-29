#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <omp.h>


int main(int argc, char **argv){

	int numhilos = omp_get_num_procs(); //Devuelve el numero de hilos fisicos capaz de generar el sistema.

	printf("\nEl sistema tiene %d hilos fisicos.\n\n", numhilos);

	return 0;

}
