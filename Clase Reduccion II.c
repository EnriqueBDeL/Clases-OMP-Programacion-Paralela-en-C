#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char **argv){

    int valores[10] = {23,45,12,56,87,56,45,22,32,67};

    int maximo = 0;

    #pragma omp parallel for reduction(max:maximo)  // "max" se usa para encontrar el valor maximo entre todas las variables de los hilos.
                                                    // Cada hilo tiene su propia copia privada de la variable, que en este caso es "maximo"
                                                    // Al final, OpenMP selecciona el valor mas grande de esas copias.
    for(int i = 0; i < 10; i++){

        if(valores[i] > maximo){
        
            maximo = valores[i];
        
        }

    }   

    printf("\nEl valor maximo es: %d\n\n");


//-------------------------------------------------------------------------|


    int valores2[10] = {23,45,12,-1,87,56,-4,22,32,67};

    int minimo = 999;


    #pragma omp parallel for reduction(min:minimo)  // "min" se usa para encontrar el valor minimo entre todas las variables de los hilos.
                                                    // Cada hilo tiene su propia copia privada de la variable, que en este caso es "minimo"
                                                    // Al final, OpenMP selecciona el valor mas pequeño de esas copias.

    for(int i = 0; i < 10; i++){

        if(valores2[i] < minimo){

            minimo = valores2[i];

        }

    }

    printf("\nEl valor minimo es: %d\n\n");



    return 0;
}
