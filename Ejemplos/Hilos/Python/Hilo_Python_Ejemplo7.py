import threading
import time

#Creando una clase con parámetros
class HiloDemonio( threading.Thread ):
	def __init__(self, args=()):
		super().__init__( daemon=True )
		self.arg1 = args[0]
		
	def run(self):
		print("Arg1", self.arg1)
		

for i in range(10):
    HiloDemonio( args=(i,) ).start()


time.sleep(1)

