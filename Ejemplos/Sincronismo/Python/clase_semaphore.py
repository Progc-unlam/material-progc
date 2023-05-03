import threading

MAX_HILOS = 5

valor = 0

def hiloHace():
	global valor
	sem.acquire()
	valor+=1
	sem.release()
		
sem = threading.Semaphore(1)	

hilos = [] 

for i in range( MAX_HILOS ):
	hilos.append( threading.Thread( target=hiloHace ) )
	hilos[ i ].start()
    
for i in range( MAX_HILOS ):
    hilos[ i ].join()

hilos.clear()	

print( "Valor final: ", valor )

