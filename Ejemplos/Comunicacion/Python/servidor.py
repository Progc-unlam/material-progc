import socket

MAX_PEND = 10
PUERTO = 5000

def servidor():
    ss = socket.socket()

    try:
        ss.bind(("127.0.0.1", PUERTO))
    except OSError as e:
        print(f"Error al enlazar el socket: {e}")
        return

    ss.listen(MAX_PEND)
    print(f"Servidor escuchando en 127.0.0.1:{PUERTO}...")

    cs, dir = ss.accept()
    print(f"Conexión aceptada desde {dir}")

    try:
        while True:
            data = cs.recv(1024)
            if not data:
                break
            recibi = data.decode("utf-8")
            if recibi.strip() == "fin":
                break
            print("Recibido:", recibi)
    except Exception as e:
        print(f"Error durante la comunicación: {e}")
    finally:
        cs.close()
        ss.close()
        print("Conexión cerrada.")

if __name__ == '__main__':
    servidor()
