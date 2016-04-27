#include <stdio.h>

/*Declaracion de variables golbales*/

char nombres [3][10] = {"Laura", "Andrea", "Mar"};

int main(void){
	char i;
	char *a;
	char (*b)[10]; //apuntador 10 posiciones?

	a =(char *)nombres; //????????
	printf("El nombre es: %s \n", a);

	b =(char (*)[10]) nombres[0]; //????????

	for(i=0; i<3; i++){
		printf("El nombre[%d] es: %s \n", i, (char *)(b+i));//???
	}
return 0;

}
