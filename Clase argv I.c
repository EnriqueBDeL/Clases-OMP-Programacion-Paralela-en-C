#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){

    // "argc" indica la cantidad de argumentos pasados a través de la línea de comandos.
    // El primer argumento es el nombre del programa. 

    // "argv" cada uno de estos, contiene uno de los argumentos pasados a través de la línea de comandos.
    // argv[0] siempre es el nombre del programa.

    // Ejemplo: ./nombre_programa hola mundo

    printf("\nEl programa recibio %d argumentos:\n\n", argc);

    for (int i = 0; i < argc; i++) {
        printf("Argumento %d: %s\n", i, argv[i]);
    }

    printf("\n");

    return 0;    
}
