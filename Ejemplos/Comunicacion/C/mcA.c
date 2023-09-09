#include <stdlib.h>
#include <stdio.h>
#include <sys/ipc.h> //Biblioteca para los flags IPC_ 
#include <sys/shm.h> //Para memoria compartida (MC) SYSTEM-V
#include <unistd.h>

//La clave (SEG_ID) también puede ser creada con ftok()
#define SEG_ID 1234	
#define TAM 5

int main()
{
    //Creación del área de MC
    int shmid = shmget(	SEG_ID, sizeof(int)*TAM, IPC_CREAT | IPC_EXCL | 0600);	

    //Vincular la MC a una variable local
    int *mc = (int*)shmat(shmid,NULL,0);

    for( int i=0; i< TAM; i++ )
    {
        mc[ i ] = i+1;
        printf("Proceso A escribió %d\n", mc[ i ] );
    }

    //Para frenar hasta que se ejecute B por consola
    sleep(10);

    //Desvincular la MC del proceso
    shmdt( &mc );	
    
    //Marcar la MC para ser borrada posteriormente 
    shmctl( shmid, IPC_RMID, NULL );	
    return EXIT_SUCCESS;
}
