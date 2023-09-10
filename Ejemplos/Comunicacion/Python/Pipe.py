from multiprocessing import Pipe
import os
import sys

CHILD = 0

def main():
    recepcion, envio = Pipe(False)

    process = os.fork()
    if process < 0:
        sys.exit("Error al crear el nuevo proceso")

    if process == CHILD:
        envio.close()
        print("Recibido: ", recepcion.recv())
        recepcion.close()
        os._exit(0)
    else:
        recepcion.close()
        envio.send((1, 'Yerba "La Tranquera"'))
        envio.close()
        os.wait()

if __name__ == '__main__':
    main()
