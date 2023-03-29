#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	pid_t pid;
	
  	pid = fork();
	
	if( pid < 0 )
	{
		printf("Error al crear el nuevo proceso\n");
  		return EXIT_FAILURE;
	}
	
	if( pid )
	{
		printf("Soy el proceso padre. PID: %d\n",getpid());
		wait(NULL);
	}
	else
	{
		printf("Soy el proceso hijo. PID: %d\n",getpid());
		printf("Mi padre es el proceso con PID: %d\n",getppid());
		return EXIT_SUCCESS;	
	}
	
  	return EXIT_SUCCESS;
}

