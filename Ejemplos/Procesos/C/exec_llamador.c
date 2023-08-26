#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    char *arg[] = { "B.bin", "Hola mundo", NULL };
    pid_t pid;
    int estado;

    pid = fork();
    if( pid < 0 )
    {
        printf("Error al crear el nuevo proceso\n");
        return EXIT_FAILURE;
    }

    if( pid )
    {
        printf("Soy el proceso padre. PID: %d\n",getpid());
        wait( &estado );

        if( estado == 0 )
        {
            printf("Hijo finalizado con éxito\n");
        }
        else
        {
            printf("Hijo finalizado con error\n");
        }
    }
    else
    {
        execv("B.bin", arg );
        printf("Error: %d\n",errno);	
        perror("execv");
        exit(EXIT_FAILURE);		
    }

    return EXIT_SUCCESS;
}
