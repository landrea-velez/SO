#include <stdio.h>
#include <stdlib.h>

const char FILE_NAME[] = "input.txt";
int main (){
	int count = 0; //número de caracteres leidos
	FILE *in_file;
	int ch;
	
	/*abrir el archivo*/
	in_file = fopen(FILE_NAME, "r"); // Abrir el archivo en modo lectura
	// Siempre realice esta verificación
	if(in_file == NULL){
		printf("No puede abrirse %s\n", FILE_NAME);
		exit(8);
	}
	/*Leer el archivo*/
	while(1){
		ch = fgetc(in_file);
		printf("%c\n", ch);
		
		if(ch == EOF){
			break;
		}
		++count;
	}
	
	fputc("x", in_file);
	printf("Numero de caracteres en el archivo %s: %d\n", FILE_NAME, count);
	//Cerrar el archivo
	fclose(in_file);
return 0;
}
