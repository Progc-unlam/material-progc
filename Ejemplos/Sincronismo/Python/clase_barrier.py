import threading

MAX_HILOS = 5

valor = -1

def reiniciar():
	global valor
	valor = 0
	
def hiloHace():
	global valor
	bar.wait()
	mtx.acquire()
	valor+=1
	mtx.release()
		
mtx = threading.Lock()		
bar = threading.Barrier( MAX_HILOS, action=reiniciar )

hilos = [] 

for i in range( MAX_HILOS ):
	hilos.append( threading.Thread( target=hiloHace ) )
	hilos[ i ].start()
    
for i in range( MAX_HILOS ):
    hilos[ i ].join()

hilos.clear()	

print( "Valor final: ", valor )

