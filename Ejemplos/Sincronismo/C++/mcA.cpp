#include <stdlib.h>
#include <stdio.h>
#include <sys/ipc.h> 	//Biblioteca para los flags IPC_ 
#include <sys/shm.h> 	//Para memoria compartida SYSTEM-V	
#include <semaphore.h>	//Para semáforos POSIX
#include <fcntl.h>		//Para utilizar los flags O_

#define SEGMENTO_ID	234 //La clave también puede ser creada con ftok()
#define REGISTROS 	5

int main(){	
	//Creación de los semáforos
	sem_t *leer		=	sem_open( "/leer",		O_CREAT | O_EXCL,	0666,	0);
	sem_t *escribir	=	sem_open( "/escribir",	O_CREAT | O_EXCL,	0666,	1); 
	
	//Creación de memoria compartida
	int shmid = shmget(	234, sizeof(int), IPC_CREAT | 0666);	

	//Vincular la memoria compartida a una variable local
	int *area_compartida = (int*)shmat(shmid,NULL,0);
	
	for( int i=0; i< REGISTROS; i++ ){ 
		sem_wait(escribir);	//P( escribir )
		*area_compartida = i;	//Región crítica (escribo algo)
		sem_post(leer);		//V( leer ) 
		printf("Proceso A escribió %d\n",*area_compartida);
	}

	//Desvincular la memoria compartida de la variable local
	shmdt( &area_compartida );	
	
	//Marcar la memoria compartida para borrar
	shmctl( shmid, IPC_RMID, NULL );	
	
	//Cierre de los semáforos
	sem_close(leer); 
	sem_close(escribir); 	

	//Marcar los semáforos para destruirlos
	sem_unlink("/leer");
	sem_unlink("/escribir");
	
	return 0;
}





