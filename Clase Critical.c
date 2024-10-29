#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>


int main(int argc, char **argv){

	int numero1 = 4;
	int numero2 = 10;
	int resultado = 0;


	#pragma omp parallel
	{
	
	int suma = numero1 + numero2;

	#pragma omp critical //Asegura que solo un hilo escriba el resultado a la vez.
	{
	
		resultado += suma;

	}
	}

	printf("\nEl resultado de la suma es: %d \n\n", resultado);
}
