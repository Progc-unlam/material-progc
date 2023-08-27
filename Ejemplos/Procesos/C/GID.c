#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    pid_t pid = fork();	
    if( pid < 0 )
    {
        printf("Error al crear el nuevo proceso\n");
        return EXIT_FAILURE;
    }	
    if( pid )
    {
        printf("Padre. PID: %d - GID: %d\n",getpid(),getpgrp());
        wait( NULL );		
    }
    else
    {
        printf("Hijo. PID: %d - GID: %d\n",getpid(),getpgrp());
    }

    return EXIT_SUCCESS;
}