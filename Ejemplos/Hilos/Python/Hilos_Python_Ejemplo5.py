import threading
import time

def mostrarTid():
	time.sleep(2) #Jugar con/sin esta línea
	print( "TID: ", threading.get_native_id() )


for _ in range(5):
	threading.Thread( target=mostrarTid, daemon=True ).start() 


for hilo in threading.enumerate():
	print( hilo.name )

