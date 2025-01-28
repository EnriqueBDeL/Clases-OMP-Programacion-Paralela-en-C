/*
 
   ¿CUANDO UN CODIGO ES PARALELIZABLE?

   3. Los bucles anidados pueden ser paralelizables, pero debes asegurarte de que las iteraciones del bucle interno sean independientes. 
 
*/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {

    int N = 4; 

    int M = 5;  

    int matrix[4][5];  


//Paralelizable:

//#pragma omp parallel for collapse(2)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            matrix[i][j] = i + j; 
        }
    }


//No Paralelizable:

  for (int i = 0; i < N; i++) {
        for (int j = 1; j < M; j++) {
            matrix[i][j] = matrix[i][j - 1] + 1;  // Cada iteración depende de la anterior.
        }
    }


    return 0;
}
