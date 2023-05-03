#include <stdlib.h>
#include <stdio.h>
#include <sys/ipc.h>  
#include <sys/shm.h> 	
#include <fcntl.h>	
#include <semaphore.h> 
#define SEGMENTO_ID	234 
#define REGISTROS 	5

int main(){	
	sem_t *leer		 =	sem_open("/leer",		O_CREAT);
	sem_t *escribir =	sem_open("/escribir",O_CREAT);
	
	int shmid = shmget(SEGMENTO_ID, sizeof(int), IPC_CREAT | 0666);	
	
	int *area_compartida = (int*)shmat( shmid, NULL, 0);
	
	for( int i=0; i< REGISTROS; i++ ){ 
		sem_wait( leer );
		printf("Proceso B leyó %d\n",*area_compartida);
		sem_post( escribir );
	}

	shmdt( &area_compartida );	

	sem_close( leer );
	sem_close( escribir ); 	
	 	
	return 0;
}





