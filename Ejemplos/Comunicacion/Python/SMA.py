from multiprocessing import shared_memory
import time

TAM = 5

try:
    mc = shared_memory.SharedMemory(name="mi_mem", create=True, size=TAM)
    print(f"Memoria compartida creada con nombre: {mc.name}")
except FileExistsError:
    print("La memoria compartida ya existe.")
    return shared_memory.SharedMemory(name="mi_mem")

for i in range(TAM):
    mc.buf[i] = i+1

time.sleep(15)

mc.close()
mc.unlink()
