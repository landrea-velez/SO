/* Inclusion de cabeceras o bibliotecas. */
#include <stdio.h>      // printf, scanf, setbuf
#include <string.h>     // Manejo de strings

/* Definicion de macros y constantes. */
#define MAX_CHAR 11
#define MAXI 3

/* Main function. */
int main() {
    /* Variables locales. */
    //char cursos[MAX_CHAR], niveles[MAX_CHAR];
    int i;
    char curso[MAXI], nivel[MAXI];

    for (i = 0; i < MAXI; i++) {
	    /* Obtener y almacenar un curso */
	    printf("Ingrese curso: ");
	    setbuf(stdin, NULL);
	    scanf("%s", &curso[i]);	        

	    /* Obtener y almacenar un curso */
	    printf("Ingrese nivel: ");
	    setbuf(stdin, NULL);
	    scanf("%s", &nivel[i]);	   
	    
    }

    /* Imprimir resultados en consola. */
    printf("|%-25s|%-25s|\n", "Curso", "Dificultad");
    
    for (i = 0; i < MAXI; i++) {
    	printf("|%25s|%25s|\n", curso[i],nivel[i]);
    }
    return 0;
}






