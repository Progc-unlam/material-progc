from multiprocessing import shared_memory
import time

TAM = 5

mc = shared_memory.SharedMemory( name="mi_mem", create=True, size=TAM )

for i in range(TAM):
	mc.buf[ i ] = i+1

time.sleep(5)

mc.close()
mc.unlink()

