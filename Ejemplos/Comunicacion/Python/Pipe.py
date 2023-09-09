from multiprocessing import Pipe
import os
import sys

recepcion, envio = Pipe(False)

pid = os.fork()
if pid < 0:
    sys.exit("Error al crear el nuevo proceso")

if pid:
    recepcion.close()
    envio.send((1, 'Yerba "La Tranquera"'))
    envio.close()
    os.wait() 
else:
    envio.close()
    print("Recibido: ", recepcion.recv())
    recepcion.close()
    os._exit(0)
