import os, signal, time, sys

def manejador(sig, frame):
	print("Recibido ", signal.Signals(sig).name )

signal.signal(signal.SIGCONT, manejador)

for i in range(2):
	pid = os.fork()
	if pid < 0:
		print("Error al crear el proceso ",i+1)
		sys.exit(1)
	
	if not pid: #Proceso Hijo
		signal.raise_signal( signal.SIGSTOP )
		os._exit(0)

time.sleep(2)
os.killpg( os.getpgrp(), signal.SIGCONT )
os.wait()
os.wait()

