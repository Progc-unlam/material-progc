import socket

MAX_PEND = 10
PUERTO = 5000

def servidor():
    #Creación del socket
    ss = socket.socket()

    #Vincular puerto y dirección IP con el socket
    ss.bind(("127.0.0.1", PUERTO))

    #Ponemos en modo escucha y establecemos la
    #cantidad de peticiones que puede encolar
    ss.listen(MAX_PEND)

    #Espera por una petición de conexión
    (cs, dir) = ss.accept()

    while True:
        recibi = cs.recv(1024).decode("ascii")
        if recibi == "fin":
            break
        print(recibi)

    print("finalizado")

    #Cierre de los sockets
    ss.close()
    cs.close()

if __name__ == '__main__':
    servidor()
