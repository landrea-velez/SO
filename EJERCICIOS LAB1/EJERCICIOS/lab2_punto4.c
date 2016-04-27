/*Programa que determine el promedio de un arreglo de 100 posiciones, 
el programa debe crear aleatoriamente el arreglo*/
#include <stdio.h>

float promedio(int v[]);

int main(void){
	int vector[100];
	int i=0;
	int range;
	srand(time(NULL));
	range = 200;

	for(i = 0; i < 100; ++i){
		vector[i] = rand() % range + 1;
	}

	printf("\n Vector con números aleatorios \n");    
	
	for(i = 0; i < 100; i++){
      		printf("\n%d",vector[i]);
    	} 
	
	float prom = promedio(vector);
	printf("\nEl promedio del vector es %.2f\n", prom);

	return 0;
}

float promedio(int v[]) {
    int i;
    int suma = 0;

    for (i = 0; i < 100; ++i)
        suma += v[i];

    return suma / 100;
}
