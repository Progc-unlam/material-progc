#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

struct persona
{
    int dni;
    char nombre[30];	
};

int main (int argc, char *argv[])
{
    int r = open("./fifo", O_RDONLY);

    struct persona alumno;
    if (read(r, &alumno, sizeof(struct persona)) == -1)
    {
        perror("Error en read()");
        return EXIT_FAILURE;
    }

    printf("%d\n",alumno.dni);	
    printf("%s\n",alumno.nombre);	

    close(r);	
    
    return EXIT_SUCCESS;
}
