#include <stdlib.h>
#include <stdio.h>
#include <sys/ipc.h> 	//Biblioteca para los flags IPC_ 
#include <sys/shm.h> 	//Para memoria compartida SYSTEM-V
#include <unistd.h>

#define SEG_ID 1234	//La clave también puede ser creada con ftok()
#define TAM 5

int main(){
	//Creación de memoria compartida
	int shmid = shmget(	SEG_ID, sizeof(int)*TAM, IPC_CREAT | IPC_EXCL | 0600);	

	//Vincular la memoria compartida a una variable local
	int *mc = (int*)shmat(shmid,NULL,0);
	
	for( int i=0; i< TAM; i++ )
	{ 
		mc[ i ] = i+1;
		printf("Proceso A escribió %d\n", mc[ i ] );
	}
	
	sleep(10);
	
	shmdt( &mc );	
	shmctl( shmid, IPC_RMID, NULL );	
	return EXIT_SUCCESS;
}






