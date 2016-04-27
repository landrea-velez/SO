/*
    Taller #1   
    Mares en c
    Calcula el promedio de n materias
    por: Jaiber Yepes
*/
#include <stdio.h>
#include <stdlib.h>

//Macros
#define MAXSUBJ 20
#define NUMCHARNAME 20

typedef struct{
    char name[20];
    float grade;
    int credits;
}strSubjet;

typedef unsigned int uint;

//Declaracion de funciones
int numberSubjets(FILE *file);
void getData(strSubjet *pSubjets, uint numSubjets, FILE *file);
void calculateAverage(strSubjet *pSubjets, uint numSubjets);
void printResult(strSubjet *pSubjets, uint numSubjets, FILE *file);


int main(int argc, char *argv[]){
       
    FILE *inFile;
    char *fileName;
    //char buffer[100];
    //int cred;
    //float grade;

    uint numSubjets;

    //strSubjet subjets[20];
    strSubjet *subjets;
   
   
    if(argc != 2){
        printf("Numero de parametros no valido, debe ingresar asi:     ./a.out <nombrefichero>\n");
        exit(EXIT_FAILURE);
    }
    fileName = argv[1];

    inFile = fopen(fileName, "r");
    if(inFile == NULL){
        printf("No se puede abrir el fichero: %s\n", fileName);
        exit(EXIT_FAILURE);
    }
   
    numSubjets = numberSubjets(inFile);
    //printf("La cantida de materias es: %d\n", numSubjets);   

   
    subjets = (strSubjet *) malloc(sizeof(strSubjet)*numSubjets);

    getData(subjets, numSubjets, inFile);
    printResult(subjets, numSubjets, inFile);  
    calculateAverage(subjets, numSubjets);
    fclose(inFile);

    return 0;
}


//Functions implementation
int numberSubjets(FILE *file){
    int num = 0;
    char buffer[NUMCHARNAME];
    while(!feof(file)){
        fgets(buffer, NUMCHARNAME, file);
        //    puts(buffer);
        num++;
    }   
    rewind(file);
    return num/3;
}

void getData(strSubjet *pSubjets, uint numSubjets, FILE *file){
    int i = 0;
    for(i=0; i<numSubjets; i++){
       
        fscanf(file, "%s", &pSubjets->name[0]);
        printf("%s\n", pSubjets->name);
   
        fscanf(file, "%f", &pSubjets->grade);
        printf("%f\n", pSubjets->grade);

        fscanf(file, "%d", &pSubjets->credits);
        printf("%d\n", pSubjets->credits);
       
        pSubjets++;
    }
}

void calculateAverage(strSubjet *pSubjets, uint numSubjets){
   
    int i;
    int acumCredit=0;
    float sum = 0;
    for(i=0; i< numSubjets; i++){
        sum+= (pSubjets->grade) * (pSubjets->credits);
	acumCredit += pSubjets->credits;
	//printf("grade: %d %d\n",i, acumCredit); 
	pSubjets++;
    }
	printf("\nEl promedio es: %.2f\n", sum /= acumCredit); 
}


void printResult(strSubjet *pSubjets, uint numSubjets, FILE *file){
	//escribir en fichero de salida
 	int i = 0;
	printf("\n%-10s %-5s %-8s\n", "Nombre", "Nota", "Creditos" );
	for(i=0; i<numSubjets; i++){
		printf("%-10.10s %-5.1f  %-5d\n", pSubjets->name, pSubjets->grade, pSubjets->credits);
		pSubjets++;
	}

 	file = fopen ( "resultado.txt", "r+" ); 	
 	fprintf(file, "\n%-10s %-5s %-8s\n", "Nombre", "Nota", "Creditos"  );

	for(i=0; i<numSubjets; i++){
	   fprintf(file, "%-10.10s %-5.1f  %-5d\n", pSubjets->name, pSubjets->grade, pSubjets->credits);
           pSubjets++;
	}	
 	fclose ( file );

	
}



