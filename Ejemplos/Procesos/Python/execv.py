import os

def parent():
	print("Proceso A. PID: ", os.getpid() )
	
	try:
		os.execv("/bin/ls", ["/bin/ls","-l"] )
	
	except Exception as error:
		print("Error: ", os.strerror(error.errno) )
		os._exit(1)
	
parent()

