#include <stdio.h>

/*Declaración de funciones*/

void swap(int *d1, int *d2);

int main(void){

	int x = 1;
	int y = 2;
	int *p = &y;

	printf("Valor de x: %d\n", x);
	printf("Valor de y: %d\n", y);

	//printf("Valor de y: %d\n", *p);
	//printf("Valor de y: %d\n", &p);
	//printf("Valor de y: %d\n", p);
	//swap(&x, p);

	swap(&x, &y); //Paso por referencia

	printf("Valor de x: %d\n", x);
	printf("Valor de y: %d\n", y);

	return 0;
}

/*Definición funciones*/
void swap(int *d1, int *d2){
	int temporal;
	temporal = *d1;
	*d1 = *d2;
	*d2 = temporal;	
}







