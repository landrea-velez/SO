#include <syscall.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int main (void){
	long ID1, ID2;
	int idPadre, idUsuario, idUsuarioEfectivo, idGrupo, idGrupoEfectivo;
	int procesoNuevo;

	//LLAMADA INDIRECTA A LA FUNCIÓN SYSCALL
	ID1= syscall(SYS_getpid);
	printf ("syscall(SYS_getpid)=%1d\n", ID1);
	//FUNCIÓN RESERVADA
	ID2= getpid();// getpid() returns the process ID of the calling process.
	printf ("getpid()=%1d\n", ID2);
	
	/*IDENTIFICACIÓN DE PROCESOS*/
	idPadre= getppid();
	printf ("getppid()=%1d\n", idPadre);

	idUsuario= getuid();
	printf ("getuid()=%1d\n", idUsuario);

	idUsuarioEfectivo= geteuid();
	printf ("geteuid()=%1d\n", idUsuarioEfectivo);

	idGrupo= getgid();
	printf ("getgid()=%1d\n", idGrupo);

	idGrupoEfectivo= getegid();
	printf ("getegid()=%1d\n", idGrupoEfectivo);

	/*GESTIÓN DE PROCESOS*/
	//fork() CREACIÓN DE UN PROCESO
	procesoNuevo = fork();
	procesoNuevo= getpid();
	printf ("fork nuevo proceso getpid()=%1d\n", procesoNuevo);
	//int execl(char *path, char *arg)
	//void exit(int status)
	//pid_t wait
	//int sllep(unsigned int seconds)

	/*ENTORNO DE UN PROCESO*/
	// char *getenv(cnst char *name);
	//char *setenv(char **env)

	/*SEÑALES*/
	// int kill(pid_t pid, int sig)
	// int sigaction( int sig, struct sigaction * act, struct sigaction* oact)
	// int pause(void)
	// unsigned int alarm(unsigned int seconds)

	return(0);
}

