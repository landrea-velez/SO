#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[]){

	pid_t pid_hijo,pid_padre;
	printf("El PID del programa principal es: %d\n",(int)getpid());
	
	switch(pid_hijo = fork()){
	
		case -1: 
			printf("Error al crear el proceso");
			return -1;
		case 0:	//código ejecutado por el hijo
				printf("Proceso hijo\n");
				printf("PID del proceso hijo: %d\n", (int)pid_hijo);
				printf("PID del proceso padre: %d\n", (int)getppid());
				exit(0);
				printf("Esta instrucción nuca será ejecutada en el proceso hijo\n");
				break;
		
		default:
			printf("PROCESO PADRE: Proceso hijo con PID %d creado\n", (int)pid_hijo);
			printf("PID del proceso hijo: %d\n", (int)pid_hijo);
			printf("PID del proceso padre: %d\n", (int)getppid());
	}

return 0;
}
