import os
	
def parent():
	pid = os.fork()

	if pid < 0:
		print("Error al crear el nuevo proceso")
		os._exit(1)
		
	if pid:
		print("Soy el proceso padre. PID: ", os.getpid() )
		print( os.wait() )
	else:
		print("Soy el proceso hijo. PID: ",  os.getpid())
		print("Mi padre es el proceso con PID: ",  os.getppid())
		os._exit(0)
	os._exit(0)	
parent()

