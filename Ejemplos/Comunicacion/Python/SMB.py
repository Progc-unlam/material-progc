from multiprocessing import shared_memory
from multiprocessing.resource_tracker import unregister

ENTEROS = 5

try:
    mc = shared_memory.SharedMemory(name="mi_mem")
    print(f"Memoria compartida accedida: {mc.name}")
except FileNotFoundError:
    print("La memoria compartida no existe.")
    sys.exit(1)

for i in range(ENTEROS):
    print( mc.buf[i] )

mc.close()
#Para evitar el comportamiento reportado en:
#https://bugs.python.org/issue39959#msg368770
unregister(mc._name, "shared_memory")
print("Finalizando SHMB.py")
