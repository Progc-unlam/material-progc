from multiprocessing import shared_memory
from multiprocessing.resource_tracker import unregister

TAM = 5

mc = shared_memory.SharedMemory(name = "mi_mem")

#Para evitar el comportamiento reportado en: 
#https://bugs.python.org/issue39959#msg368770
unregister(mc._name, "shared_memory")  

for i in range(TAM):
    print( mc.buf[i] )

mc.close()
