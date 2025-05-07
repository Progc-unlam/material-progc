import sys
import os

try:
    os.mkfifo("./fifo", 0o600)  # Crear el FIFO si no existe
except OSError as err:
    print(f"Error al crear fifo: {err}")
    sys.exit(1)

try:
    fifo = os.open("./fifo", os.O_WRONLY)  # Abrir el FIFO para escribir
    os.write(fifo, "Café La Morenita".encode())  # Escribir en el FIFO
    os.close(fifo)  # Cerrar el FIFO
    os.unlink("./fifo")  # Eliminar el FIFO
except OSError as err:
    print(f"Error al trabajar con el FIFO: {err}")
    sys.exit(1)
