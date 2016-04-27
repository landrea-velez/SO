/* Inclusion de cabeceras o bibliotecas. */
#include <stdio.h>      // printf, scanf, setbuf
#include <string.h>     // Manejo de strings

/* Definicion de macros y constantes. */
#define MAX_CHAR 15
#define MAXI 2 // 15

/* Main function. */
int main() {
	int i;
	char nombre[MAXI][MAX_CHAR];
	int edad[MAXI];
	float estatura[MAXI];

	for (i = 0; i < MAXI; i++) {
	    printf("Ingrese nombre: ");
	    setbuf(stdin, NULL);
	    scanf("%s", nombre[i]);	

	    printf("Ingrese su edad: ");
	    setbuf(stdin, NULL);
	    scanf("%d", &edad[i]);        

	    printf("Ingrese estarura: ");
	    setbuf(stdin, NULL);
	    scanf("%f", &estatura[i]);	   
	}

	/* Imprimir resultados en consola. */
	printf("|%25s|%25s|%25s|\n", "Nombre", "Edad","Estatura");
    
	for (i = 0; i < MAXI; i++) {
    	    printf("|%-25s|%-25d|%-25.2f|\n", nombre[i],edad[i],estatura[i]);
	}

    return 0;
}






