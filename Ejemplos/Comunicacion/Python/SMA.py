from multiprocessing import shared_memory
import time
import numpy 

ENTEROS = 5  
TAM_ENT = numpy.dtype(numpy.int32).itemsize  # Calcular bytes por entero

try:
    mc = shared_memory.SharedMemory(name="mi_mem", create=True, size=TAM_ENT*ENTEROS)
    print(f"Memoria compartida creada con nombre: {mc.name}")
except FileExistsError:
    print("La memoria compartida ya existe.")
   
for i in range(ENTEROS):
    mc.buf[i] = i+1

time.sleep(5)

mc.close()
mc.unlink()
print("Finalizando SHMA.py")
