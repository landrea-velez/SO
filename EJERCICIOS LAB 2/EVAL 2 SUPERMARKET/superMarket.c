#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAXCHAR 20
#define MAXITEMS 100

typedef struct{
	int code;
    char description[MAXCHAR];
    float value;
}strArticle;

typedef unsigned int uint;

//Declaracion de funciones
int numberSubjets(FILE *file);
void getData(strArticle *pArticles, uint numArticles, FILE *file);
void printResult(strArticle *pArticles, uint numArticles, FILE *file);
void newBill(strArticle *pArticles, uint numArticles);
void printBill(int n, int *quantity, int total, int *totals, int *pCodes, float *pValues);
void checkItem(strArticle *pArticles, uint numArticles);
    

	
int main(int argc, char *argv[]){

	FILE *inFile;
    char *fileName;
    
    char *fileName2;
    FILE *salida;
  	
    uint numArticles;
    strArticle *articles;
        
    // Validation: Number of arguments from console.
    // Validation: Number of arguments from console.
    if (argc != 3) {
        printf("Error: Numero de parametros invalido.\nDebe iniciar asi: ./a.out <archivoEntrada> <archivoSalida>\n");
		exit(0);
    }
       
    
    fileName = argv[1];
    fileName2 = argv[2];
 

    inFile = fopen(fileName, "r");
    if(inFile == NULL){
        printf("No se puede abrir el fichero: %s\n", fileName);
        exit(EXIT_FAILURE);
    }
    
    salida = fopen(fileName2, "w+");
    if(salida == NULL) {
        printf("No se pudo abrir el archivo\n");
        exit(0);
    }
    
        
    //Cantida de artículos  
    numArticles = numberSubjets(inFile);    
    articles = (strArticle *) malloc(sizeof(strArticle)*numArticles);
    getData(articles, numArticles, inFile);
    printResult(articles, numArticles, inFile);  
    
    char option;

	while(option!='q'){

		printf("Ingrese una opción:  \n a. Nueva factura \n b. Consultar articulo \n c. Ingresar articulo \n q. Salir \n");
		setbuf(stdin, NULL);
		scanf("%c", &option);

		 if (option=='a'){
		 	//Creating a new ticket
		 	newBill(articles, numArticles);
		 } else  if(option=='b'){
		 	//Checking an item
		 	checkItem(articles, numArticles);
		 } else  if(option=='c'){
		 	//Add new item to list
		 	
		 } else  if(option=='q'){
		 	return 0;
		 } else{
		 	 printf("Opcion no valida\n");
		 }
	}
	return 0;
}


int numberSubjets(FILE *file){
    int num = 0;
    char buffer[MAXCHAR];
    while(!feof(file)){
        fgets(buffer, MAXCHAR, file);
        num++;
    }   
    rewind(file);
    return num/3;
}

void getData(strArticle *pArticles, uint numArticles, FILE *file){
    int i = 0;
    for(i=0; i<numArticles; i++){            
        fscanf(file, "%d", &pArticles->code);        
        fscanf(file, "%s", &pArticles->description[0]);   
        fscanf(file, "%f", &pArticles->value);
        pArticles++;
    }
}

void printResult(strArticle *pArticles, uint numArticles, FILE *file){
 	int i = 0;
	printf("\n%-10s %-10s %-10s\n", "Código", "Descipción", "Valor" );
	for(i=0; i<numArticles; i++){
		printf("%-8d  %-5.10s %-10.1f  \n", pArticles->code, pArticles->description, pArticles->value);
		pArticles++;
	}
	printf("\n\n");
}


void newBill(strArticle *pArticles, uint numArticles){//int *codes, int *values
	int numItems;
	int inCode;
	int flag=0;
	int i=0;
	int j=0;

	int *pCodes;
	float *pValues;	
	int *pQuantities;
	int *pTotalPerCode;
	int total = 0;
	


	printf("Numero de articulos a facturar: ");
	scanf("%d", &numItems);

	pCodes = (int *)malloc(sizeof(int)*numItems);
	pQuantities = (int *)malloc(sizeof(int)*numItems);
	pTotalPerCode = (int *)malloc(sizeof(int)*numItems);

	while ( i<numItems ){
		setbuf(stdin, NULL);
		printf("\n\nArticulo #%d\n", i+1);
		printf("Codigo: \n");
		scanf("%d", &inCode);
		flag=0;
		
		//Para validar que el codigo es de un articulo existente
		//se maneja como arreglo para ir a cada valor j en la estructura		
		for (j=0; j<numArticles;j++){			
			if(inCode == pArticles[j].code){				
				pCodes[i] = inCode;
				printf("Cantidad: \n" );
				scanf("%d", pQuantities+i);				
				pTotalPerCode[i] = (pArticles[j].value)*(pQuantities[i]);
				pValues[i] = pArticles[j].value;
				total += pTotalPerCode[i];
				
				printf("Valor: %d --- Acumulado:  %d \n", pTotalPerCode[i], total);
				flag=1;
				i++;
			}	
		}
		if(flag==0){
			printf("El articulo con codigo %d no se encontró\n", inCode);
		}
		
	}

	printBill(numItems, pQuantities, total, pTotalPerCode, pCodes, pValues);
}

void printBill(int n, int *quantity, int total, int *totals, int *pCodes, float *pValues){
	printf("\n\n\t\tFactura de Venta\n");
	printf("\t\t Nombre Empresa \n");
	
	printf("Cantidad  | Codigo | V. unit   | Total\n");
	int i;
	for (i=0; i<n;i++){
		printf("%-8d  | %-5d | %-5.1f | %d\n", quantity[i], pCodes[i], pValues[i], totals[i] );
	}
	printf("Total: %d\n\n",total );
	
	
	printf("\nFactura guardada\n");		

	
    /*fprintf(f, "|%-12s|%-12s|%-12s|%-12s|\n", "Cantidad", "Codigo", "V. unit","Total\n");
    for (i = 0; i < n; i++) {
        fprintf(f, "%-8d  | %-5d | %-5.1f | %d\n", quantity[i], pCodes[i], pValues[i], totals[i]);
    }*/

}

void checkItem(strArticle *pArticles, uint numArticles){
	int i;
	int inCode;
	int flag = 0;
	printf("\nCodigo Articulo: ");
	scanf("%d", &inCode);

	for (i=0; i<numArticles;i++){
		if(inCode == pArticles[i].code){
			printf("%s --> %.1f \n\n", pArticles[i].description, pArticles[i].value);	
			flag=1;		
		}
	}
	if(flag == 0)
		printf("El articulo con codigo %d no se encontró\n", inCode);
}
