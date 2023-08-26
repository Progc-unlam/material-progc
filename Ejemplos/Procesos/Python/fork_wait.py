import os
import sys

pid = os.fork()

if pid < 0:
    sys.exit("Error al crear el nuevo proceso")

if pid:
    print("Soy el proceso padre. PID: ", os.getpid() )
    print( os.wait() )
else:
    print("Soy el proceso hijo. PID: ",  os.getpid())
    print("Mi padre es el proceso con PID: ",  os.getppid())
    os._exit( os.EX_OK )
