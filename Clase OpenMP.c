// OpenMP

/*
    
  OpenMP es una API que facilita la programacion paralela en sistemas conmultiples procesadores o nucleos.
  
  omp.h es una libreria de cabecera en C que proporciona las funciones y directivas necesarias para
  utilizar OpenMP.

 */



#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


int main (int argc, char **argv){


	double a[1000];


	#pragma omp parallel for    //''#pragma omp parallel'', permite que el bucle for se ejecute en paralelo.


	for (int i = 0; i < 100; i++){
	
		a[i] = i * 444;
	
	}


      	for (int i = 0; i < 100; i++){

            printf("\na[%d] vale: %lf\n",i,a[i]);

        }



}
