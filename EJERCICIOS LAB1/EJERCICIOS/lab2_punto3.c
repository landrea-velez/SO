/*Programa que determine cual es el valor mas grande de
un arreglo de 100 posiciones, el programa debe crear aleatoriamente el arreglo*/
#include <stdio.h>

int main(void){
    int vec[100];
    int i=0, mayor=0;
    int range;
    srand(time(NULL));
    range = 200;

    for(i = 0; i < 100; ++i){
      vec[i] = rand() % range + 1;
    }

    printf("\n Vectorcon números aleatorios \n");   
    for(i = 0; i < 100; i++){
      printf("\n%d",vec[i]);
    }

    for(i = 0; i < 100; i++){
      if (vec[i] > mayor){
	mayor= vec[i];
      }
    }

    printf("\n el mayor numero es %d\n", mayor);
return 0;
}
