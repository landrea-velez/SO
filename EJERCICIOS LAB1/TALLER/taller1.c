#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR_NAME 50

/*Declaración de las funciones*/
void getOption(char *_option);
void registerEmployees(char (*names)[MAX_CHAR_NAME], float *_wages);
void showList(char (*names)[MAX_CHAR_NAME], float *_wages, float *_total);
void getTotal(float *_wages, float *_total);
int existEmployees();

/*Variables globales*/
int max_employees=0;
int enlisted_employees=0;

int main (int argc, char *argv[]){
    /*variables locales*/
    char option = 'x';
    char (*names)[MAX_CHAR_NAME];
    float *wages;
    float total=0;
    
    /*Validar numero de argumentos desde la consola*/
    if(argc!=2){
    printf("Error, numero de parametros invalido\n Debe iniciar asi: ./taller.out <numero maximo trabajadores>\n");
    exit(0);
    }
    /*obtener argumento desde consola y convertir a numero*/
    max_employees = atoi(argv[1]);

    /*Validar que el argumento es entero positivo*/
    if(max_employees<=0){
    printf("Error, numero de parametros invalido\n Debe iniciar asi: ./taller.out <numero maximo trabajadores>\n");
    exit(0);
    }

    printf("La lista tendrá capacidad de %d trabajadores", max_employees);
    
    names = (char (*)[MAX_CHAR_NAME]) malloc(sizeof(char[MAX_CHAR_NAME]) * max_employees);
    wages = (float *) malloc(sizeof(float) * max_employees);

    do{
        getOption(&option);
        switch (option){
            case 'a':            
                registerEmployees(names, wages);
                break;    
            case 'b':            
                getTotal(wages, &total);
                break;    
            case 'q':            
                showList(names, wages, &total);
                printf("Saliendo del programa...\n");
                break;    
            default:            
                printf("La opción '%c' no es valida. Volviendo a menu\n", option);
                break;    
        }
    }while (option != 'q');
    
    /*Liberar memoria*/
    free(names);
    free(wages);
return 0;
}

/*Implementando las funciones*/

/*Mostrar un menu con las opciones disponibles*/
void getOption(char *_option){
    printf("\nMENU DE OPCIONES\n");
    printf("\ta) Registrar trabajadores\n");
    printf("\tb) Obtener el pago total\n");
    printf("\tq) Mostrar la lista y salir del programa\n");
    printf("Seleccione una opcion\n");
    setbuf(stdin, NULL);
    scanf("\n%c", _option);
}

/*Registrar los trabajadores*/
void registerEmployees(char (*_names)[MAX_CHAR_NAME], float *_wages){
    /*Variables locales*/
    int i =0;
    int num_new_employees =0;

    printf("Ingrese el número de trabajadores a registrar: ");
    setbuf(stdin, NULL);
    scanf("%d", &num_new_employees);

    if(enlisted_employees + num_new_employees > max_employees){
    printf("No es posible registrar %d trabajadores.\n ", num_new_employees);
    printf("La capacidad maximas es %d y actualmente están registrados %d.\n ",max_employees, enlisted_employees);
return;
    }

    for(i=enlisted_employees; i < enlisted_employees + num_new_employees; i++){
        printf("\nNombre del empleado #%d\n", i+1);
        setbuf(stdin, NULL);
        scanf("%s", (char *) (_names+i));

        printf("\nSalario\n");
        setbuf(stdin, NULL);
        scanf("%f", _wages+i);    
    }
    enlisted_employees += num_new_employees;
    printf("\nSe han registrado %d trabajadores en la lista\n", num_new_employees);
}

/*Obtener el pago total*/

void getTotal(float *_wages, float *_total){
    int i=0;
    
    if(!existEmployees()){
        printf("No se puede calcular el total porque no se han registrado trabajadores\n");
        return;
    }

    *_total=0;
    
    for(i=0; i< enlisted_employees; i++){
        *_total += (*_wages+i);
    }
    printf("\n el pago total es de: %.2f$\n", *_total);
}

void showList(char (*_names)[MAX_CHAR_NAME], float *_wages, float *_total){
    int i=0;

    if(!existEmployees()){
        printf("No hay trabajadores para mostrar\n");
        return;
    }

    printf("|%-12s|%-12s|\n","Nombre","Salario");
    for (i=0; i<enlisted_employees;i++){
        printf("|%-12s|%-12.2f|\n",*(_names+i),*(_wages+i));
    }
    printf("|%-12s|%-12.2f|\n","Total",*_total);
}

int existEmployees(){
    if(enlisted_employees){
        return 1;
    }
    return 0;
}
