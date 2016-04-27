/* Inclusion de cabeceras o bibliotecas. */
#include <stdio.h>	 // printf, scanf, fflush
//#include <conio.h>

/* Definicion de macros y constantes. */


/* Main function. */
int main()
{
	/* Variables locales. */    
	char op; //operacion[20], resultado[10];
	float num1,num2;

	//operacion = (char (*)[20]) malloc(sizeof(char[20]));//Tamanho del string


	/* Imprimir menú en consola. */
	while(op!='q')
	{
		printf("1.- Sumar\n");
		printf("2.- Restar\n");
		printf("3.- Multiplicar\n");
		printf("4.- Dividir\n");
		printf("q.- Salir\n");
		printf("Indica la opcion: ");
		// Limpiar el buffer de la consola para no registrar datos residuales
		// cuando utilice la funcion 'scanf'.
	    	setbuf(stdin, NULL);
		scanf("%c", &op);

		if(op!='q'){
			printf("Ingrese el primer número: ");
			// Limpiar el buffer de la consola para no registrar datos residuales
			// cuando utilice la funcion 'scanf'.
		    	setbuf(stdin, NULL);
			scanf("%f", &num1);
			printf("Ingrese el segundo número: ");
			// Limpiar el buffer de la consola para no registrar datos residuales
			// cuando utilice la funcion 'scanf'.
		    	setbuf(stdin, NULL);
			scanf("%f", &num2);
		}

        switch(op)
        {
            case '1': 
		printf("Suma: %.4f\n", (num1+num2));
				
		break;
            case '2': 
		printf("Resta: %.4f\n", (num1-num2));
		break;
            case '3': 
		printf("Multiplicacion: %.4f\n", (num1*num2));
		break;
	    case '4': 
		printf("Division: %.4f\n", (num1/num2));
		break;
            case 'q': break;
        }
    }

    return 0;
}


