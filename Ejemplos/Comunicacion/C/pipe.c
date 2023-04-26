#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define LARGO 	   20
#define LECTURA	    0
#define ESCRITURA   1
#define DESCRIPTOR  2

struct mensaje
{
	int id;
	char detalle[ LARGO ];
};
 
int main( int argc, char **argv )
{
	pid_t pid;
	struct mensaje msj;

	int p[ DESCRIPTOR ];	//DESCRIPTOR vale 2
	if( pipe( p ) == -1 )
	{
		perror("Error en pipe");
		return EXIT_FAILURE;
	}

	pid = fork();
	if( pid == -1 ) 
	{
		perror("Error de fork()");
		return EXIT_FAILURE;
	}	
	
	if( pid == 0 ) //Hijo		
	{
		//ESCRITURA vale 1
		close( p[ ESCRITURA ] ); 
		
		if( read( p[ LECTURA ], &msj, sizeof(struct mensaje) ) == -1)
		{
			perror("Error en read()");
			return EXIT_FAILURE;
		}
		
		printf("Id: %d \nDetalle: %s\n", msj.id, msj.detalle );
		
		close( p[ LECTURA ] );
	}
	else //Padre
	{
		//LECTURA vale 0
		close( p[ LECTURA ] ); 
		
		msj.id = 1;
		strcpy( msj.detalle, "Yerba La Tranquera" );
		
		if( write( p[ ESCRITURA ], &msj, sizeof( struct mensaje ) ) == -1)
		{
			perror("Error en write()");
			return EXIT_FAILURE;
		}	
		
		close( p[ ESCRITURA ] );
			
		wait( NULL );
	}
	return EXIT_SUCCESS;
}