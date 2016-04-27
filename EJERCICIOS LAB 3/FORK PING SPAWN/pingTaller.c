

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

struct str_addr{
    char network[15];
    int host;
};

//declaracion funciones
int exec_ping();

int main(int argc, char* argv[])
{
	pid_t pid;
	int status, i;
	int ans;
	int init_host, quantity;
	char *pch;
	struct str_addr addr;
	int aciertos = 0;
		
	if(argc != 3){
		printf("error arguments\n");
		printf("./a.out <network> <quantity> \n");
		printf("%s 192.168.0.10 5\n", argv[0]);
		exit(1);
	}
	
	pch=strrchr(argv[1],'.');		//Busca el ultimo punto y  
	*pch = '\0';						//lo reemplaza por el caracter nulo
	init_host = atoi(pch+1);
	strcpy(addr.network, argv[1]);
	quantity = atoi(argv[2]);
	
	printf("network %s\n", addr.network);
	printf("host %d\n\n", init_host);
	
	for(i=0; i<quantity; i++){
		
		pid_t hijo;
		hijo = fork();
		
		if(hijo == 0){
			printf("running host %d\n", init_host+i);
			addr.host = init_host+i;
			ans = exec_ping(&addr);	
			exit(ans);	
		}					
	}

	for(i=0; i<quantity; i++){
		wait(&status);
		if(status == 0){
			aciertos++;	
		}	
	
	}
}

int exec_ping(struct str_addr *_addr){

	FILE *ping_response;
	char ping_comand[100];
	char buffer[100];
	char no_response[] = "0 received";

	sprintf(ping_comand,"ping -w 2 %s.%d",_addr->network,_addr->host); //FORMATEA UN STRING PARA HACER UN COMANDO SHELL PING.
	ping_response = popen(ping_comand, "r"); //popen: abre un pipe para ejecutar un comando en shell.
	
	while (!feof(ping_response)) {
	  fgets(buffer, 100, ping_response);
	  if (strstr(buffer, no_response)) { //strstr: recibe 2 string para buscar un string en el otro string. 
	  		printf("Host %s.%d no response\n\n",_addr->network,_addr->host);
	  		return _addr->host;
	  }
	}
	printf("Host %s.%d response\n\n",_addr->network,_addr->host);
	pclose(ping_response);
	return 0;   
}

