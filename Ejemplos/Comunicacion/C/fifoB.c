#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

typedef struct
{
    int dni;
    char nombre[30];	
} t_dato;

int main (int argc, char *argv[])
{
    t_dato alumno;

    int r = open("./fifo", O_RDONLY);

    if( read( r, &alumno, sizeof( t_dato ) ) == -1 )
    {
        perror("Error en read()");
        return EXIT_FAILURE;
    }

    printf("%d\n",alumno.dni);	
    printf("%s\n",alumno.nombre);	

    close(r);	
    return EXIT_SUCCESS;
}
