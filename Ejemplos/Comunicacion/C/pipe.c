#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define READER 0
#define WRITER 1
#define CHILD 0

struct product
{
    int id;
    char info[20];
};

int main( int argc, char **argv )
{
    int my_pipe[2];	
    if (pipe(my_pipe) == -1)
    {
        perror("Error en pipe");
        return EXIT_FAILURE;
    }

    pid_t process = fork();
    if (process < 0) 
    {
        perror("Error de fork()");
        return EXIT_FAILURE;
    }	
	
    struct product my_product;
    if (process == CHILD) 		
    {
        close(my_pipe[WRITER]); 

        if (read(my_pipe[READER], &my_product, sizeof(struct product)) == -1)
        {
            perror("Error en read()");
            return EXIT_FAILURE;
        }
        printf("Id: %d \nDetalle: %s\n", my_product.id, my_product.info);

        close(my_pipe[READER]);

        return EXIT_SUCCESS;
    }

    close(my_pipe[READER]); 

    my_product.id = 1;
    strcpy(my_product.info, "Yerba La Tranquera");
    if (write(my_pipe[WRITER], &my_product, sizeof(struct product)) == -1)
    {
        perror("Error en write()");
        return EXIT_FAILURE;
    }

    close(my_pipe[WRITER]);

    wait(NULL);
    
    return EXIT_SUCCESS;
}
