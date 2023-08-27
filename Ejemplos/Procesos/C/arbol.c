#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CHILD 2

int main(int argc, char *argv[])
{
    pid_t pid;

    for(int i = 0; i < MAX_CHILD; i++)
    {
        pid = fork();
        if( pid < 0 )
        {
            printf("Error de creación\n");
            return EXIT_FAILURE;
        }
        if( ! pid )	
        {
            printf("Proceso hijo %d\n",i+1);
            return EXIT_SUCCESS;
        }
    }

    for(int i = 0; i < MAX_CHILD; i++)
    {
        wait(NULL);
    }

    return EXIT_SUCCESS;
}

