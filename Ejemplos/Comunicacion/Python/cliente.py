import socket

PUERTO = 5000

def cliente():
    #Creación del socket
    cs = socket.socket()

    #Se emite una solicitud de conexión
    cs.connect(("127.0.0.1", PUERTO))

    while True:
        envie = input("> ")
        cs.send(envie.encode())
        if envie == "fin":
            break
    print("finalizado")

    #Cierre del socket
    cs.close()

if __name__ == '__main__':
    cliente()
