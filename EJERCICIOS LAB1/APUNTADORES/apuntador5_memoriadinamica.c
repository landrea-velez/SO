/*
Programa que recibe la edad de un usuario y muestra la edad enmeses. Almacena la edad en memoria dinámica
*/
#include <stdio.h>	//print, scanf
#include <stdlib.h>	//malloc, free

int main(){
	//Malloc retorna un apuntador: Necesitamos un apuntador.
	int *edad;

	//El apuntador que retorna Malloc es genŕico;
	//Es necesario hacer un casting
	edad = (int *) malloc(sizeof(int));
	printf("Edad en anhos:" );
	setbuf(stdin, NULL);
	scanf("%d", edad);

	printf("usted tiene %d meses de vida\n", (*edad)*12);
	
	//Ya no utilizaremos esta variable, liberar
	free(edad);

return 0;
}

