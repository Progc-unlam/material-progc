#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <errno.h>
#include <string.h>

#define MSG_TIPO_1 1
#define MSG_TIPO_2 2
#define SIN_OPCION 0

struct mi_msg
{
    long id;
    char nombre[10];
    float altura;
};

int main(int argc, char *argv[])
{
    int id_cola;
    struct mi_msg mensaje;
    int tamanio = sizeof(mensaje)-sizeof(long);

    //Se crea una clave para el S.O. 
    key_t clave = ftok ("/bin/ls", 1);

    //Se crea la cola de mensajes.
    id_cola = msgget (clave, IPC_CREAT | 0600);

    if (id_cola == -1)
    {
        perror("msgget");
        return EXIT_FAILURE;
    }

    //Armamos un mensaje de tipo 1
    mensaje.id = MSG_TIPO_1;
    mensaje.altura = 1.72;
    strcpy(mensaje.nombre, "Dario");

    //Enviamos el mensaje
    msgsnd(id_cola, &mensaje, tamanio, IPC_NOWAIT);

    //Esperamos un mensaje de tipo 2
    msgrcv(id_cola, &mensaje, tamanio, MSG_TIPO_2, SIN_OPCION);

    printf( "Recibido:\n");
    printf( "Id:\t\t%ld\n",mensaje.id);
    printf( "Nombre:\t%s\n",mensaje.nombre);
    printf( "Altura:\t%.2f\n",mensaje.altura);

    if( msgctl(id_cola, IPC_RMID, NULL) < 0)
    {
        perror("msgctl");
        printf("%d",errno);
    }

    return EXIT_SUCCESS;
}
