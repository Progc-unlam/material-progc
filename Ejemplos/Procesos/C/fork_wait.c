#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    pid_t pid = fork();

    if( pid < 0 )
    {
        printf("Error de creación\n");
        return EXIT_FAILURE;
    }
    
    if( pid )
    {
        printf("Soy el padre. PID: %d\n",getpid());
        wait(NULL);
    }
    else
    {
        printf("Soy el hijo. PID: %d\n",getpid());
        printf("Mi padre es PID: %d\n",getppid());
        return EXIT_SUCCESS;	
    }

    return EXIT_SUCCESS;
}
