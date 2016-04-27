#include <stdio.h>     
#include <stdlib.h>     
#include <string.h>

/* Definition of macros and constants. */
#define MAX_CHARS_LINE 20


/* Definition of structures. */
typedef struct {
    int real;
    int imaginario;
} complejo;

/* Declaration of functions (prototypes). */

int getNumComplejos(FILE *f);
void readNumbers(complejo *comp, FILE *f);
void showNumbers(complejo *comp, FILE *f);
void suma(complejo *comp);
void resta(complejo *comp);
void multiplicacion(complejo *comp);

int numComplejos = 0;

int main(int argc, char* argv[])
{
	FILE *inFile;
	char *fileName;
	complejo *complejos;

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
	numComplejos = getNumComplejos(inFile);
    complejos = (complejo *)malloc(sizeof(complejo) * numComplejos);
	readNumbers(complejos, inFile);
	showNumbers(complejos, inFile);	
	suma(complejos);
	resta(complejos);
	multiplicacion(complejos);



	/*Close*/
	fclose(inFile);


return 0;
}



/* Implementation of functions. */

int getNumComplejos(FILE *f) {
    int num = 0;
    char buffer[MAX_CHARS_LINE];
    while(!feof(f)) {
        fgets(buffer, MAX_CHARS_LINE, f);
        num++;
    }
    rewind(f);
    return num - 1;
}

//(20%) Lectura de archivo cvs
void readNumbers(complejo *comp, FILE *f){
/* Local variables. */
    int i = 0;
	char *token;
    char lines[MAX_CHARS_LINE];
    
    for (i = 0; i < numComplejos; i++) {
        fgets(lines, MAX_CHARS_LINE, f);
        token = strtok(lines, ";");
        while(token!=NULL) {            
            comp->real = atoi(token);
            token = strtok(NULL, ";");
            comp->imaginario = atoi(token);
            token = strtok(NULL, ";");
        }
        comp++;
    }


}

void showNumbers(complejo *comp, FILE *f){
	int i = 0;

    printf("|%-12s|%-12s|\n", "real", "entero");
    for (i = 0; i < numComplejos; i++) {
        printf("|%-12d|%-12d|\n",  comp->real, comp->imaginario);
        comp++;
    }
}

void suma(complejo *comp){
	int i = 0;
	int num1 = 0;
	int num2 = 0;

	for (i = 0; i < numComplejos/2; i++) {
		num1= (comp[i].real + comp[i+1].real);
		num2= (comp[i].imaginario + comp[i+1].imaginario);
		printf("Sumando (%d,%d)+(%d,%d) = (%d,%d)\n",comp[i].real, comp[i].imaginario, comp[i+1].real, comp[i+1].imaginario, num1, num2);
        comp++;
    }
}

void resta(complejo *comp){
	int i = 0;
	int num1 = 0;
	int num2 = 0;

	for (i = 0; i < numComplejos/2; i++) {
		num1= (comp[i].real - comp[i+1].real);
		num2= (comp[i].imaginario - comp[i+1].imaginario);
		printf("Restando (%d,%d)-(%d,%d) = (%d,%d)\n", comp[i].real, comp[i].imaginario, comp[i+1].real, comp[i+1].imaginario, num1, num2);
        comp++;
    }
}


void multiplicacion(complejo *comp){
	int i = 0;
	int num_ac = 0;
	int num_bd = 0;
	int num_ad = 0;
	int num_bc = 0;
	int res1 = 0;
	int res2 = 0;

	for (i = 0; i < numComplejos/2; i++) {
		num_ac = (comp[i].real * comp[i+1].real);
		num_bd = (comp[i].imaginario * comp[i+1].imaginario);

		res1 = (num_ac - num_bd);

		num_ad = (comp[i].real * comp[i+1].imaginario );
		num_bc = (comp[i].imaginario * comp[i+1].real);

		res2 = (num_ad + num_bc);
	
	

		printf("Multiplicando (%d,%d)*(%d,%d) = (%d,%d)\n", comp[i].real, comp[i].imaginario, comp[i+1].real, comp[i+1].imaginario, res1, res2 );
        comp++;
    }
}


