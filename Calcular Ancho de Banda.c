#include <stdio.h>
#include <stdlib.h>
#include <omp.h>




int main(int argc, char **argv){



	printf("%nEl tamano de la arquitectura de la maquina es: %zu bits%n",sizeof(size_t) * 8);
	


	size_t tamano = 1L <<30;	 //"size_t" es un tipo de entero sin signo, cuyo tamaño esta vinculado al ancho de arquitectura de la maquina.
			
	// "1L" quiere decir que es tipo long

	// "1L << 30" = 10000...binario = 2^30 = 1GB
			
	char *array = (char*)malloc(tamano); //Reserva memoria para 1GB



if(array == NULL){


	printf("%nNo se pudo asignar memoria%n");

	return 1;

}






double empezar = omp_get_wtime();





#pragma omp parallel for

for(size_t i = 0; i < tamano; i++){

	array[i] = (char)(i % 256);

}




double fin = omp_get_wtime();



double duracion = fin - empezar;




double ancho_de_banda = (tamano / (1020.0 * 1024.0 * 1024.0)) / duracion; //Formula ancho de banda


printf("%nAncho de banda: %f GB/seg%n%n",ancho_de_banda);

free(array);

return 0;
}
