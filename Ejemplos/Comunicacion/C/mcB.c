#include <stdlib.h>
#include <stdio.h>
#include <sys/ipc.h>  
#include <sys/shm.h> 	

#define SEG_ID 1234 
#define TAM 5

int main()
{
    int shmid = shmget(SEG_ID, sizeof(int)*TAM, 0600);	

    int *mc = (int*)shmat(shmid, NULL, 0);

    for(int i = 0; i < TAM; i++)
    { 
        printf("Proceso B leyó %d\n", mc[i]);
    }

    shmdt(&mc);	
    return EXIT_SUCCESS;
}
