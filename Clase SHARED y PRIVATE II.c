#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char **argv){

    int s = 0;

    printf("\nShared:\n");


    #pragma omp parallel shared(s)
    {

        #pragma omp critical

        s += 1;

        printf("Hilo %d | s = %d\n", omp_get_thread_num(), s);

    }

    printf("\nValor final de s = %d\n", s);

//----------------------------------------------------------------------------|

    int p = 0;
    
    printf("\nPrivate:\n");


    #pragma omp parallel private(p)
    {


        p = omp_get_thread_num(); //cada hilo tiene su copia de p

        p = p + 1;

        printf("Hilo %d | p = %d\n", omp_get_thread_num(), p);

    }


    printf("\nValor final de p = %d\n", p);

//------------------------------------------------------------------------------|


    int sf = 0;

    printf("\nShared for:\n");

    #pragma omp parallel for shared(sf)
    
    for(int i = 0; i < 12; i++){


        #pragma omp critical
          
        sf += 1;

        printf("Hilo %d | sf  = %d\n", omp_get_thread_num(), sf);


    }

    printf("\nValor final de sf = %d\n", sf);

//------------------------------------------------------------------------------|


    int pf = 0;
          
    printf("\nPrivate for:\n");

    #pragma omp parallel for private(pf)

    for(int i = 0; i < 12; i++){


        pf = 0;

        pf += 1;

        printf("Hilo %d | pf  = %d\n", omp_get_thread_num(), pf);

    }

    printf("\nValor final de pf = %d\n\n", pf);

    return 0;    
}
