from multiprocessing import Pipe
import os
import pickle
import sys

recepcion, envio = Pipe( False )

pid = os.fork()
if pid < 0:
	print("Error al crear el nuevo proceso")
	sys.exit(1)
		
if pid:
	envio.send_bytes( pickle.dumps( (1, 'Yerba "La Tranquera"') ) )
	envio.close()
	os.wait() 
else:
	print( "Recibido: ", pickle.loads( recepcion.recv_bytes() ) )
	recepcion.close()	
	os._exit(0)

