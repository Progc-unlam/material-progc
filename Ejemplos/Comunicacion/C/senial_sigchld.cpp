#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdbool.h>

bool fin = false;

void manejador(int sig)
{
    printf("Señal nro: %d\n",sig);
    wait(NULL);
    fin = true;
};

int main(int argc, char *argv[])
{
    struct sigaction psa;			
    psa.sa_handler = manejador;		
    sigaction(SIGCHLD, &psa, NULL); 

    if( ! fork() )	
    {
        //Proceso Hijo
        return EXIT_SUCCESS;
    }

    //Proceso Padre
    while( ! fin )
    {
        usleep(100000);
    }

    return EXIT_SUCCESS;
}
