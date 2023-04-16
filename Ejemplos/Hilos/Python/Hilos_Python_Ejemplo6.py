import threading

MAX_HILOS = 5

#Creando una clase
class Hilo( threading.Thread ):
	def run(self):
		print( threading.current_thread().name )

hilos = [] 

for i in range( MAX_HILOS ):
	hilos.append( Hilo() )
	hilos[i].start()
    
for i in range( MAX_HILOS ):
    hilos[ i ].join()

hilos.clear()	

