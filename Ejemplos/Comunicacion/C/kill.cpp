#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define CHILD 0

int main(int argc, char *argv[])
{
    pid_t process = fork(); 	

    if( process < 0 )
    {
        printf("Error al crear el nuevo proceso\n");
        return EXIT_FAILURE;
    }
	
    if( process == CHILD )	
    {
        printf("Hijo se detiene a si mismo\n");
        raise( SIGSTOP );
        printf("Hijo reanuda su ejecución\n");
        return EXIT_SUCCESS;
    }
    
    sleep(2);
    printf("Padre reanuda Hijo con el envio de SIGCONT\n");		
    kill(process, SIGCONT);
    wait(NULL);

    return EXIT_SUCCESS;
}
