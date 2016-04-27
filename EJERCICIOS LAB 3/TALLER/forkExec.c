#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<wait.h>

int main(int argc, char *argv[]){

	pid_t pid_h1, pid_h2;
	int status;
	
	pid_h1 = fork();
	
	if(pid_h1 == 0){
		// proceso hijo el cual ejecuta comandos ls
		printf("proceso hijo el cual ejecuta comandos ls \n");
		execl("/bin/ls","bin/ls","/",NULL);
	}else{
		pid_h2=fork();
		if(pid_h2 == 0){
			// proceso hijo que ejecuta el comando date
			printf("proceso hijo que ejecuta el comando date \n");
			execl("/bin/date","bin/date",NULL);		
		}else{
			//proceso padre
			printf("proceso padre wait x2 \n");
			wait(&status);//espera un proceso
			wait(&status);// espera otro proceso
			printf("Hasta la vista baby");
		}	
	}
return 0;
}

