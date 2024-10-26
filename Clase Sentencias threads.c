#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char **argv){

	omp_set_num_threads(4);//Establece que se van a usar 4 hilos.
	
	/*En el caso de no establecer un numero de hilos, la cantidad de hilos de puede ver influenciada por
	  la variable entorno OMP_NUM_THREADS o si esta variable no esta no está configurada, el sistema usar el
	  valor predeterminado, que es el numero de nucleos logicos.*/

	int i[100];
	

	printf("\nHilos del Sistema: \n");

	#pragma omp parallel //Esto hace que el codigo que este entre corchetes, se ejecute una vez por cada hilo.
        {


        int id_hilos = omp_get_thread_num(); //Obtiene el ID del hilo actual
        int num_hilos = omp_get_num_threads(); //Obtiene el numero de hilos totales

        printf("\nID hilo: %d | Nº de hilos: %d\n", id_hilos, num_hilos);

        }


	
printf("\nOperaciones: ");

	#pragma omp parallel for

	for(int j = 0; j < 100; j++){
	
		i[j] = j *100;
		printf("\nPara almacenar %d se utilizo:\nID hilo: %d\n", i[j],omp_get_thread_num());

	}
 
	 
	printf("\n\nContenido de i:\n");

	 for(int k = 0; k < 100; k++){
	
		 printf("| %d |",i[k]);
	
	 }


	return 0;	
}
