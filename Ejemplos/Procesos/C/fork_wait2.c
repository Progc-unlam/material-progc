#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_HIJOS 2

int finalizados = 0;

void manejador( int sig ){
	switch( sig )
	{
		case SIGCHLD:
			wait( NULL );
   			finalizados++;
		break;	
	}
};

int main(int argc, char *argv[])
{
	struct sigaction psa;			
    psa.sa_handler = manejador;		
    sigaction(SIGCHLD, &psa, NULL); //Asociación con el manejador propio
	
	pid_t pid;
		
	for(int i=0; i<MAX_HIJOS; i++)
	{
		pid = fork();
		
		if( pid < 0 )
		{
			printf("Error al crear el nuevo proceso\n");
  			return EXIT_FAILURE;
		}	
		
		if( ! pid )	//Proceso Hijo
		{
			printf("Proceso hijo %d\n",i+1);
  			return EXIT_SUCCESS;
		}
	}	

	while( finalizados < MAX_HIJOS )
		usleep(100000); //Duerme 100 miliseg para mitigar la espera activa
	
	return EXIT_SUCCESS;
}

