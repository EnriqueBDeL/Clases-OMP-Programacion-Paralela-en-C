#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>


int main(int argc, char **argv){

	int x = 4;
	int y = 0;

	printf("\nSolucion con FIRSTPRIVATE:\n");

	#pragma omp parallel firstprivate(x) 	 //Se utiliza para inicializar una variable privada con el valor de la variable original al inicio de la region paralela.
	{				     	 //Cada hilo comienza con el mismo valor de la variable, pero aunque la modifiques, la original no se modificará.

		printf("\nHilo %d, x inicial: %d", omp_get_thread_num(),x);

		x += omp_get_thread_num(); //Modifica la copia privada

		printf("\nHilo %d, x modificada: %d", omp_get_thread_num(), x);
	

	}	

	printf("\nEl valor de x es: %d \n\n",x);	





	 printf("\nSolucion con LASTPRIVATE:\n");


	#pragma omp parallel for lastprivate(y)  // Hace lo mismo que "firstprivate", pero permite que el ultimo hilo que termina el bloque paralelo actualice la variable original.

	 for(int i = 0; i <= 12;i++){
	 
		 y = i; //Modifica la copia privada

		printf("\nHilo %d, y = %d", omp_get_thread_num(), y); 
	 
	 }

	
	printf("\nEl valor de y es: %d \n\n",y);


	return 0;
}