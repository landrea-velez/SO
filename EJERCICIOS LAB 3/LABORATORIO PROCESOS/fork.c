#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	pid_t pid_hijo;
	
	printf("Ejemplo fork. Este proceso va a crear otro proceso \n\n");
	printf("el pid del programa principal es:%d\n", (int)getpid());
	pid_hijo = fork();
	switch(pid_hijo){
		case -1: //Código ejecutado en caso de error
			printf("Error al crear el proceso");
			return -1;
		case 0: //Código ejecutado por el hijo
			printf("Proceso hijo\n");
			printf("PID hijo %d\n", (int)pid_hijo);

			printf("PID  %d\n", (int)getpid());
			break;
		default: //Código ejecutado por el padre
			wait(NULL);
			printf("Proceso padre: Proceso hijo con PID %d creado\n", (int)pid_hijo);
	}

	//Esta línea será ejecutada por ambos procesos
	printf("Fin del proceso cuyo hijo tiene (lo que retorna el fork) de %d\n", (int)pid_hijo);
	return 0;

}
