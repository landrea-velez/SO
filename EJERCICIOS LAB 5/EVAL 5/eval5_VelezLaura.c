#include <stdio.h>          /* printf()                 */
#include <stdlib.h>         /* exit(), malloc(), free() */
#include <sys/types.h>      /* key_t, sem_t, pid_t      */
#include <sys/shm.h>        /* shmat(), IPC_RMID        */
#include <semaphore.h>      /* sem_open(), sem_destroy(), sem_wait()..   */
#include <fcntl.h>          /* O_CREAT, O_EXEC          */
#include <pthread.h>        /* sem_init(), sem_post(), sem_wait(), sem_destroy() */
#include <math.h>           /* powf(), sqrtf()          */
#include <string.h>         /* strtok()                 */
#include <unistd.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <sys/mman.h>
//gcc -Wall eval5_VelezLaura.c -o sincro.out -lpthread -lm -lrt

/* Declaracion de funciones */

int divisorProp1(int N,int S);
int divisorProp2(int N,int S);
void verificar(int N1,int N2,int S1,int S2);


/*Variables globales*/
int num1=0;
int num2=0;
int i;

/* Main */
int main(int argc, char *argv[]) {
	
	int sum1=1;
	int sum2=1;
	pid_t pid1, pid2, pid3;
    sem_t *sem1;
    sem_t *sem2;
    sem_t *sem3;
	int descriptorMC1;
	int descriptorMC2;
    void *direccionMC;
    void *direccionMC2;
    const char *nombreMC = "MC 1";
    const char *nombreMC2 = "MC 2";

 /*Validar numero de argumentos desde la consola*/
    if(argc!=3){
    	printf("Error, numero de parametros invalido\n Debe iniciar asi: ./a.out <numero> <numero>\n");
    	exit(0);
    }
    /*obtener argumento desde consola y convertir a numero*/
    num1 = atoi(argv[1]);
	num2 = atof(argv[2]);


	// Se crea un segmento de memoria compartida para enviar el la suma de divisores al proceso 'hermano'
    descriptorMC1 = shm_open(nombreMC, O_CREAT | O_RDWR, 0666);
	// Se crea un segmento de memoria compartida para enviar el la suma de divisores al proceso 'hermano'
    descriptorMC2 = shm_open(nombreMC2, O_CREAT | O_RDWR, 0666);
    printf("Se crea segmento de memoria compartida\n");

    // Se configura el tamanho del segmento
    ftruncate(descriptorMC1, sizeof(int));
    ftruncate(descriptorMC2, sizeof(int));

    // Se mapea el segmento en el espacio de direcciones del proceso
    direccionMC = mmap(0, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, descriptorMC1, 0);
    if (direccionMC == MAP_FAILED) {
        printf("Error: Mapeo de memoria compartida fallido\n");
        return(-1);
    }

    direccionMC2 = mmap(0, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, descriptorMC2, 0);
    if (direccionMC2 == MAP_FAILED) {
        printf("Error: Mapeo de memoria compartida fallido\n");
        return(-1);
    }

    // Se crean dos semaforos en memoria compartida
    sem1 = mmap(0, sizeof(sem_t), PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1, 0);
    sem2 = mmap(0, sizeof(sem_t), PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1, 0);
	sem3 = mmap(0, sizeof(sem_t), PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1, 0);

    // Se inicializan los semaforos
    if( sem_init(sem1,1,0) < 0){
      printf("Error: No es posible inicializar el primer semaforo\n");
      exit(-1);
    }
    if( sem_init(sem2,1,0) < 0){
      printf("Error: No es posible inicializar el segundo semaforo\n");
      exit(-1);
    }
	if( sem_init(sem3,1,0) < 0){
      printf("Error: No es posible inicializar el tercer semaforo\n");
      exit(-1);
    }
    printf("Se inicializan 3 semaforos: Compartidos entre procesos con valor inicial 0\n");

	pid1 = fork();
    if (pid1 < 0) { // Caso de error: No se puede crear un proceso hijo
        printf ("Error: No fue posible crear al primer proceso hijo\n");
        exit(-1);
    } else if(pid1 == 0) { // Primer proceso hijo
        printf("[01] Nuevo proceso (1): Calcular suma de divisores propios numero 1 %d\n",num1);
		sum1 = divisorProp1(num1,sum1);
		printf("[02] divisores propios numero 1 es: %d. Termina proceso (1)\n", sum1);
		sprintf(direccionMC, "%d", sum1);
        printf("[03] Se escribe en el segmento la suma de divisores propios: %s\n", (char *)direccionMC);

        // Se le indica al proceso hermano con el semaforo que la tarea del
        // primer proceso fue completada
        sem_post(sem1);
        exit(0);
	} else { // Vuelve al proceso padre

        // Se crea el segundo proceso hijo
        pid2 = fork();
        if (pid2 < 0) {
            printf ("Error: No fue posible crear al segundo proceso hijo\n");
            exit(-1);
        } else if (pid2 == 0) { // Segundo proceso hijo

            // No se realiza ninguna operacion hasta obtener 'permiso' del proceso hermano
            sem_wait(sem1);
            printf("[04] Nuevo proceso (2): Calcular suma de divisores propios numero 2 %d\n", num2);
			sum2 = divisorProp2(num2,sum2);
			printf("[05] divisores propios numero 2 es: %d. Termina proceso (2)\n", sum2);
			sprintf(direccionMC2, "%d", sum2);
        	printf("[06] Se escribe en el segmento la suma de divisores propios: %s\n", (char *)direccionMC2);
 	        sem_post(sem2);
            exit(0);

        } else {// Vuelve al proceso padre
        // Se crea el tercer proceso hijo
        pid3 = fork();
        if (pid3 < 0) {
            printf ("Error: No fue posible crear al segundo proceso hijo\n");
            exit(-1);
        } else if (pid3 == 0) { // Tercer proceso hijo

            // No se realiza ninguna operacion hasta obtener 'permiso' del proceso hermano
            sem_wait(sem2);
			sum1 = atoi(direccionMC);
			sum2 = atoi(direccionMC2);		
			printf("[07] Nuevo proceso (3): verifica que %d, %d sean números amigos\n", sum1,sum2); 
			verificar(num1, num2,sum1, sum2);       
			printf("Termina proceso (3)\n");          
			sem_post(sem3);
            exit(0);

        }else { // Vuelve al proceso padre
sem_wait(sem3);
            printf("Proceso padre: Todos mis hijos terminaron\n");
        }			

            
    }
	

 // Se elimina el segmento de memoria compartida
    if (shm_unlink(nombreMC) == -1) {
        printf("Error: No es posible leer a %s\n", nombreMC);
        exit(-1);
    }
	if (shm_unlink(nombreMC2) == -1) {
        printf("Error: No es posible leer a %s\n", nombreMC2);
        exit(-1);
    }
    printf("Se libera la memoria compartida\n");

 // Se destruyen los semaforos
    sem_destroy(sem1);
    sem_destroy(sem2);
    sem_destroy(sem3);
    printf("Se destruyen los semaforos\n");
}
    
	

return 0;
}

int divisorProp1(int N,int S){
    for(i=2;i<N;i++){
            if(N % i==0){
                    S=S+i;
            }
    }
    return S;
}

int divisorProp2(int N,int S){
    for(i=2;i<N;i++){
            if(N % i == 0){
                    S = S + i;
            }
    }
    return S;
}

void verificar(int N1,int N2,int S1,int S2){
	if((S1==N2)&&(S2==N1)){
    	printf("los numeros %d y %d Si son numeros amigos\n",N1,N2);
    }else{
    	printf("los numeros %d y %d No son numeros amigos\n",N1,N2);
    }
}


