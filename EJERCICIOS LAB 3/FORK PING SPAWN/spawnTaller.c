#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(int argc, char* argv[]){ 

	int spawn(char * programa, char ** argumentos){
		pid_t pid_hijo;
		pid_hijo = fork();
		if(pid_hijo != 0){
			//padre ejecuta el codigo
			wait(NULL);
			printf("termino %s\n", programa);
			return pid_hijo;
		} else {
			//hijo ejecuta codigo
			execvp(programa, argumentos);
			fprintf(stderr, "error programa %s\n", programa);
			abort();
		}
	}

	char * argumentos1[] = {"gcc", argv[1], "-o", argv[2], NULL};
	char * argumentos2[] = {argv[2], NULL};

	spawn(argumentos1[0], argumentos1);
	sleep(2);
	spawn(argumentos2[0], argumentos2);


	return 0;
}