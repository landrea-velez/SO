#include <pthread.h>
#include <stdio.h>

/*Creación de u  hilo*
* imprime 'x' en la salida de error stderr.
El parámetro no es usado. No tienen retorno*/

void* imprime_x (void* unused){
	while(1) fputc('x', stderr);
	return NULL;
}

int main(){
	pthread_t id_hilo;
	// crea un nuevo hilo sobre la función imprime_x
	pthread_create(&id_hilo, NULL, &imprime_x, NULL);
	//imprime 'o' en la salida del error stderr
	while(1) fputc('o', stderr);
	return 0;
}
