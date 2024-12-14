#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char **argv) {

    printf("\nSu sistema tiene %d hilos fisicos.\n", omp_get_num_procs());

    // schedule estatico
    printf("\nEstatico:\n");

    #pragma omp parallel for schedule(static, 2)    //schedule(estrategia de iteracion, tamaño de bloque de iteracion asignado a cada hilo)
    // Los bloques se asignan a los hilos en orden. 
    // Ej de este caso: bloque[i = 0 y i = 1] es ejecutado por el hilo 0.
    for (int i = 0; i < 10; i++) {
        printf("Iteracion %d ejecutada por el hilo %d.\n", i, omp_get_thread_num());
    }

    printf("\n");
    //----------------------------------------------------------------------------------------------------|

    // schedule dinamico
    printf("\nDinamico:\n");

    #pragma omp parallel for schedule(dynamic, 3)
    // Los bloques se asignan a los hilos más rápidos.
    // Ej de este caso: bloque[i = 0, i = 1 y i = 2] es ejecutado por el hilo 8.
    for (int i = 0; i < 10; i++) {
        printf("Iteracion %d ejecutada por el hilo %d.\n", i, omp_get_thread_num());
    }

    printf("\n");
    //----------------------------------------------------------------------------------------------------|

    // schedule estatico simple
    printf("\nEstatico simple:\n");

    #pragma omp parallel for schedule(static) // Tamaño de bloque establecido automáticamente como (total iteraciones / número de hilos)
    for (int i = 0; i < 10; i++) {
        printf("Iteracion %d ejecutada por el hilo %d.\n", i, omp_get_thread_num());
    }

    printf("\n");
    //----------------------------------------------------------------------------------------------------|

    // schedule dinamico simple
    printf("\nDinamico simple:\n");

    #pragma omp parallel for schedule(dynamic) // Tamaño de bloque establecido automáticamente como 1.
    for (int i = 0; i < 10; i++) {
        printf("Iteracion %d ejecutada por el hilo %d.\n", i, omp_get_thread_num());
    }

    return 0;
}

