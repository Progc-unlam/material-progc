import socket

PUERTO = 5000

def cliente():
    cs = socket.socket()

    try:
        cs.connect(("127.0.0.1", PUERTO))
    except ConnectionRefusedError:
        print("Error: no se pudo conectar al servidor.")
        return

    print("Conectado al servidor. Escribe 'fin' para salir.")
    while True:
        envie = input("> ").strip()
        cs.send(envie.encode("utf-8"))
        if envie == "fin":
            break

    print("Conexión cerrada.")
    cs.close()

if __name__ == '__main__':
    cliente()
