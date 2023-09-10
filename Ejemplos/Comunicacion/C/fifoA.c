#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>

struct persona
{
    int dni;
    char nombre[30];	
};

int main (int argc, char *argv[])
{
    if (mkfifo("./fifo",0666) == -1)
    {
        perror("Error al crear ./fifo");
        return EXIT_FAILURE;	
    }

    int w = open("./fifo", O_WRONLY);	

    struct persona alumno;
    alumno.dni = 29383491;
    strcpy(alumno.nombre,"Darío Hirschfeldt");
    if (write(w, &alumno, sizeof(struct persona)) == -1)
    {
        perror("Error en write()");
        return EXIT_FAILURE;
    }	

    close(w);

    unlink("./fifo");

    return EXIT_SUCCESS;
}
