#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>

typedef struct
{
    int dni;
    char nombre[60000];	
} t_dato;

int main (int argc, char *argv[])
{
    t_dato alumno;

    if( mkfifo("./fifo",0666) == -1 )
    {
        perror("Error al crear ./fifo");
        return EXIT_FAILURE;	
    }

    int w = open("./fifo", O_WRONLY);	

    alumno.dni=29383491;
    strcpy(alumno.nombre,"Darío Hirschfeldt");	

    if( write( w, &alumno, sizeof( t_dato ) ) == -1 )
    {
        perror("Error en write()");
        return EXIT_FAILURE;
    }	

    close(w);	
    unlink("./fifo");		
    return EXIT_SUCCESS;
}
