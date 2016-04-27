/*
Programa que recibe n números y calcula la resta de 100 menos los numeros. 
Debe almacenar todos los numeros en memoria dinámica.
Suponga que n es máximo 10 y que el usuario siempre ingresa información válida.
*/
#include <stdio.h>	//print, scanf
#include <stdlib.h>	//malloc, free
#define MAX_NUMEROS 10

//Note que los parámetros y las variables en main no tienen que llamarse igual
void obtenerNumeros(int *totalN, int *numEnMemoria);
int calcularDiferencia(int totalN, int *numEnMemoria);
//Incluso puede omitir los nombres de los parámetros e indicar solo el tipo
//void obtenerNumeros(int *, int *);
//void obtenerNumeros(int , int *);

int main(){
	int totalNumeros, diferencia;
	// Creamos un apuntador a un arregle de enteros
	int *numerosEnMemoria;

	//Casting a objetos de Tipo int
	numerosEnMemoria = (int (*)) malloc(sizeof(int) * MAX_NUMEROS);

	//Conteste que variables son pasadas por valor y cuales por referencia
	obtenerNumeros(&totalNumeros, numerosEnMemoria);
	diferencia = calcularDiferencia(totalNumeros, numerosEnMemoria);

	//Ya no utilizamos mas numerosEnMemoria: liberar
	//Para los exámenes puede dejar los llamados a free antes del return	
	//no elvide llamar a free

	free(numerosEnMemoria);

	printf("La diferencia  es %d\n", diferencia);
	
	return 0;
}



void obtenerNumeros(int *totalN, int *numEnMemoria){
	int i=0;
	// obtener la cantidad de números que se van a ingresar
	printf("cantidad de números que se van a ingresar\n");
	setbuf(stdin, NULL);
	scanf("%d", totalN);

	for(i=0; i< *totalN; i++){
		printf("#%d", i+1);
		setbuf(stdin,NULL);
		//Importante recuerde el incremento decremento de apuntadores
		scanf("%d", numEnMemoria+i);
	}
}



int calcularDiferencia(int totalN, int *numEnMemoria) {
	int i = 0, dif = 100;

	for(i=0; i< totalN; i++){
		//Importante recuerde el incremento decremento de apuntadores
		dif -= *(numEnMemoria+i);
	}
	return dif;
}







