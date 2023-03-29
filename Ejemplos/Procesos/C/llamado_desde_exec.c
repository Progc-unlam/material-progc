#include  <stdio.h>
#include  <stdlib.h>
#include  <unistd.h>

int main( int argc, char *argv[] )
{
	printf("Programa B ejecutado con execv. PID: %d\n", getpid() );

	printf("Nombre: %s\n", argv[0]);
 	printf("Arg 1: %s\n", argv[1]);
 	
	return EXIT_SUCCESS;	
}

