#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (){

	int i;
	int numHijos = 3;
	pid_t pid;
	
	for(i = 0; i <numHijos; i++){
		pid = fork();
		if (pid == -1){ //error 
			printf("No se pudo crear el hijo");
			return -1;
		}
		
		if(pid == 0){
		printf("Soy el hijo #%d con PID %d\n", i+1, getpid());
		sleep(1);
		}
	
	}
return 0;
}
