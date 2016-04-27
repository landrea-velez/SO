#include <pthread.h>
#include <stdio.h>

//Esta estructura sirve para pasar parámetros a el hijo

struct parametros_hilo{
	//parámetro 1: Caracter a imprimir
	char caracter;
	//parámetro 2: número de veces que desea imprimir
	int contador;
};

/* Esta función imprime un número de caracteres a la salida del error, 
*tal y como lo indica el parámetro de la funcuón*/
void* imprimir_caracter(void* parametros){
	// se hace un cast al tipo de dato correcto
	struct parametros_hilo* p = (struct parametros_hilo*) parametros;
	int i;
	for(i = 0; i < p->contador; ++i){
		fputc(p->caracter, stderr);
		return NULL;
	}
}

//programa principal
int main (){
	pthread_t id_hilo1;
	pthread_t id_hilo2;
	struct parametros_hilo hilo1_param;
	struct parametros_hilo hilo2_param;
	
	//Crear un hilo para imprimir 30.000 x
	hilo1_param.caracter = 'x';
	hilo1_param.contador = 300;
	pthread_create(&id_hilo1, NULL, &imprimir_caracter, &hilo1_param);
	
	//Crear un hilo para imprimir 20.000 x
	hilo2_param.caracter = 'o';
	hilo2_param.contador = 200;
	pthread_create(&id_hilo2, NULL, &imprimir_caracter, &hilo2_param);
	
	//Conectando hilos
	pthread_join(id_hilo1, NULL);
	pthread_join(id_hilo2, NULL);
		
	return 0;
}
