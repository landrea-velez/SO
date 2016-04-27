/*
Programa que recibe el nombre de un usuario y muestra un mensaje de despedida. Almacena la edad en memoria dinámica.
El nombre del usuario solo puede tener como máximo 10 caracteres
*/
#include <stdio.h>	//print, scanf
#include <stdlib.h>	//malloc, free

#define MAX_CHAR_NOMBRE 10

int main(){
	//Apuntador a un array de caracteres: Apuntador a un String
	char (*nombre)[MAX_CHAR_NOMBRE];
	//Casting a apuntador de un string
	nombre = (char (*)[MAX_CHAR_NOMBRE]) 
		malloc(sizeof(char[MAX_CHAR_NOMBRE]));//Tamanho del string

	printf("Nombre: ");
	setbuf(stdin, NULL);	
	//Scan espera un char*: espera un string
	scanf("%s", (char*) nombre);
		
	//printf tambien espera un string
	printf("Hasta luego %s\n", (char *)nombre);
	
	free(nombre);

return 0;
}

