/*
 
   ¿CUANDO UN CODIGO ES PARALELIZABLE?

   1. El codigo es paralelizable si las operaciones se pueden realizar de manera independiente, sin que una operacion dependa del resultado de otra operacion.
 
*/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char **argv){

int N = 10;
int array[10] = {1,2,3,4,5,6,7,8,9,10};
int array2[10] = {1,2,3,4,5,6,7,8,9,10};


//Paralelizable:

// #pragma omp parallel for
	for(int i = 0; i < N; i++){
	
		array[i] = array[i] * 2; 

	}	


//No Paralelizable:

      for(int i = 1; i < N; i++){

                array2[i] = array2[i-1] + array2[i]; //Depende del contenido guardado en la posicion anteriror del array.

        }




return 0; 
}
