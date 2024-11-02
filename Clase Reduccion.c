#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>

int main(int argc, char **argv){

	int total = 0;
	long long  total3 = 2; //long long es para usar datos demasiado grandes para un int.

//SUMA
	#pragma omp parallel for reduction(+:total) //'reduction' permite combinal los resultados de varias iteraciones de un bucle paralelo en una unica variable.
						    //'+:' indica que quiero hacer una suma.

	for ( int i = 1; i <= 100; i++){
	
		total += i;

		//printf("\ntotal = %d | i = %d",total,i);

	}	

	printf("\nLa suma total es: %d \n\n", total);


//MULTIPLICACION
	#pragma omp parallel for reduction(*:total3)

	for ( int i = 1; i < 20; i++){

		total3 *=i;

	}

     	printf("\nLa multiplicacion total es: %lld \n\n", total3); //%lld es para imprimir los long long




return 0;	
}
