#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <time.h>

#define TAM_ARRAY 1000

int main (int argc, char *argv[])
{
	struct rusage uso_hijo;
	int array[ TAM_ARRAY ];

	srand( time(NULL) );
	for(int i=0; i<TAM_ARRAY; i++)
	{
		array[ i ] = rand()%100;
	}

	if( ! fork() ) //Hijo
	{
		int suma=0;
		for(int i=0; i<TAM_ARRAY; i++)
		{
			suma+=array[i];
		}
		printf("Suma del array: %d\n\n",suma);
		return EXIT_SUCCESS;
	}
	
	if( wait3(NULL,0,&uso_hijo) < 0 )
	{
		perror("wait3");
		return EXIT_FAILURE;
	}
	
	printf("Tiempo CPU sistema:	%ld.%06ld\n", uso_hijo.ru_stime.tv_sec, uso_hijo.ru_stime.tv_usec); 
	printf("Tiempo CPU usuario:	%ld.%06ld\n", uso_hijo.ru_utime.tv_sec, uso_hijo.ru_utime.tv_usec); 
	printf("Soft Page Faults:	%ld\n",uso_hijo.ru_minflt);
	printf("Hard page faults:	%ld\n",uso_hijo.ru_majflt);
	printf("Señales recibidas: 	%ld\n",uso_hijo.ru_nsignals);
	printf("CS voluntario:   	%ld\n",uso_hijo.ru_nvcsw);
	printf("CS involuntario:	%ld\n",uso_hijo.ru_nivcsw);
	
	return EXIT_SUCCESS;
}

