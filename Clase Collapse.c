#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main (int argc, char **argv){

    int x = 0;

    #pragma omp parallel for collapse(2) reduction(+:x) //Collapse se utiliza para combinar múltiples bucles anidados en un único bucle. 
							//En este caso se pone collapse(2) porque hay dos bucles.
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 10; j++){
            x = x + i + j; 
        }
    }

    printf("\n\nSuma total: %d \n\n", x); 

    return 0;
}
