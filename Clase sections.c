#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char **argv) {

    #pragma omp parallel sections
    {    
        #pragma omp section 	//Define las tareas individuales dentro de sections. 
				//Cada una se asignará a un hilo diferente del equipo, permitiendo que se ejecuten en paralelo.
        {
            printf("Seccion 1 ejecutada por el hilo %d.\n", omp_get_thread_num());
        }

        #pragma omp section
        {
            printf("Seccion 2 ejecutada por el hilo %d.\n", omp_get_thread_num());
        }
    }

    return 0;
}