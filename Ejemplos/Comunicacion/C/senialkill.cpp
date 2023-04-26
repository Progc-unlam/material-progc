#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

bool fin = false;
void manejador( int sig )
{
	
	raise( SIGCONT );
	
};

int main(int argc, char *argv[])
{
	pid_t pid = fork(); 	
	
	if( pid == 0 )	//Proceso Hijo
	{
		raise( SIGSTOP );
		return EXIT_SUCCESS;
	}	

	//Proceso Padre
	sleep(1);
	kill( pid, SIGCONT );
	wait( NULL );
	
	return EXIT_SUCCESS;
}

