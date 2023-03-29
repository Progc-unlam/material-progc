import threading
import random

MAX_MED = 10 
FIN_MED =  5 
MAX_HIL =  2 

mediciones = [ 0 ] * MAX_MED  
min = 100

def calcularMinimo( inicio ):
	global min
	for i in range( inicio, inicio+FIN_MED ):
		mtx.acquire()					# P(mtx)
		if mediciones[ i ] < min:
			min = mediciones[ i ]
		mtx.release()  					# V(mtx)
    	

#Main
hilos = []

#Creación del semáforo
mtx = threading.Lock()	

#Carga de mediciones aleatorias entre 0 y 99 
random.seed()
for i in range( MAX_MED ):
	mediciones[ i ] = random.randrange( 100 )
	
#Creación de los hilos
for i in range( MAX_HIL ):
	hilos.append( threading.Thread( target=calcularMinimo, args=(i*FIN_MED,) ) )

#Inicio de los hilos
for i in range( MAX_HIL ):
	hilos[ i ].start()

#Espera de los hilos
for i in range( MAX_HIL ):
	hilos[ i ].join()

print( "Medición mínima: ", min )


