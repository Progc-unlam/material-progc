import threading

valor = 0

def cambiarValor( nuevo_valor ):
	global valor	#Para que pueda ver la variable valor
	print( threading.current_thread().name," - TID: ", threading.get_native_id() )
	valor = nuevo_valor
		

#Main
#Creación de los hilos
HiloA = threading.Thread( target=cambiarValor, args=(1,), name="Hilo A" ) 
HiloB = threading.Thread( target=cambiarValor, args=(2,), name="Hilo B" ) 

#Inicio de los hilos
HiloA.start()
HiloB.start()

#Espera de los hilos
HiloA.join()
HiloB.join()

print( "Valor final: ", valor )

