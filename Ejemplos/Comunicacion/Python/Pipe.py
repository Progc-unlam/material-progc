from multiprocessing import Pipe
import os
import sys

recepcion, envio = Pipe(False)

hijo = os.fork()
if hijo < 0:
    sys.exit("Error al crear el nuevo proceso")

if hijo:
    recepcion.close()
    envio.send((1, 'Yerba "La Tranquera"'))
    envio.close()
    os.wait() 
else:
    envio.close()
    print("Recibido: ", recepcion.recv())
    recepcion.close()
    os._exit(0)
