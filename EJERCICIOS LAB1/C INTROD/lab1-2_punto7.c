
/* Inclusion de cabeceras o bibliotecas. */
#include <stdio.h>      // printf, scanf, fflush

/* Definicion de macros y constantes. */
#define MAX_CHAR 20


/* Main function. */
int main() {
	/* Variables locales. */
	char archivo[MAX_CHAR];
	int acceso;
	enum permisos {restringido, lectura, lectura_escritura};

    /* Obtener y almacenar las el nombre del archivo */    
        printf("Ingrese el nombre del archivo: ");
        fflush(stdin);
        scanf("%s", archivo);  
	printf("Ingrese nivel de acceso: ");
        fflush(stdin);
        scanf("%d", &acceso);

	if (acceso==restringido) {
		printf("El archivo %s tiene acceso restringido", archivo);
	} 
	if (acceso==lectura){
		printf("El archivo %s tiene acceso de lectura", archivo);
	} 
	if (acceso==lectura_escritura){
		printf("El archivo %s tiene acceso de lectura y escritura ", archivo);
	}

    return 0;
}
