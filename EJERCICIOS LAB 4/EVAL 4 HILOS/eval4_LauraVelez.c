#include <stdio.h>     
#include <stdlib.h>     
#include <string.h>
#include <pthread.h>

/* Definition of macros and constants. */
#define MAX_CHARS_LINE 2


/* Definition of structures. */
typedef struct {
    int entero;
} numero;

/* Declaration of functions (prototypes). */

int getTotNumeros(numero *comp,FILE *f);
void readNumbers(numero *comp, FILE *f);
void showNumbers(numero *comp, FILE *f);
void *perfecto(void *param);

int totNumeros = 0;

int main(int argc, char* argv[])
{
	FILE *inFile;
	char *fileName;
	numero *numeros;
	int i;
	
	if(argc != 2){
			printf("error arguments\n");
			printf("./a.out <nombre archivo> \n");
			exit(1);
		}

	fileName = argv[1];
    inFile = fopen(fileName, "r");

	if(inFile == NULL){
        printf("No se puede abrir el fichero: %s\n", fileName);
        exit(EXIT_FAILURE);
    }

	/*Invo functions*/
	
    numeros = (numero *)malloc(sizeof(numero) * totNumeros);
	totNumeros = getTotNumeros(numeros, inFile);
	showNumbers(numeros, inFile);	
	
	
	pthread_t id[totNumeros];	
	numero str_n[totNumeros];
	
	//invocando la función perfecto
	for(i = 0; i < totNumeros; i++){
		str_n[i].entero = numeros[i].entero;
		pthread_create(&id[i], NULL, perfecto, (void *)&str_n[i]);
	}

	/*Esperando los hilos
	for(i = 0; i < totNumeros; i++){
		pthread_join(id[i], (void**)&results[i]);		
		
	}*/

	/*Close*/
	fclose(inFile);
return 0;
}



/* Implementation of functions. */
int getTotNumeros(numero *comp, FILE *f) {
    int num = 0;
	char buffer[100];	
	char *pch;
    
	//Lectura de datos del archivo csv
	if (fgets(buffer , 100 , f) != NULL ){
		puts (buffer);
	}
    if ( fgets (buffer , 100 , f) != NULL ){
		
		pch = strtok(buffer, ";");
			while(pch != NULL){
				//Leyendo datos y contando	
				comp->entero = atoi(pch);
				pch=strtok(NULL, ";");
				num++;
				comp++;
			}
	
	}
    return num;
}

void showNumbers(numero *comp, FILE *f){
	int i = 0;

    printf("|%-12s|\n", "Números");
    for (i = 0; i < totNumeros; i++) {
        printf("|%-12d|\n",  comp->entero);
        comp++;
    }
}

void *perfecto(void *param){
	numero str_n = *((numero *) param);
	int i;
	int sum = 0;
	int mod = 0;
      	
	for(i = 0; i < str_n.entero; i++) {
		mod = str_n.entero%i;
		if(mod == 0) {
			sum+=i;
		}
	}
    /*sum se compara sum con num */
	if(sum==str_n.entero){
		printf("El numero %d es perfecto.\n", str_n.entero);
	}
	else{
		printf("El numero %d NO es perfecto.\n", str_n.entero);
	}
return 0;
}

