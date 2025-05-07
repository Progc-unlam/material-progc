import os

BYTES = 1024

# Intentar abrir el FIFO para lectura
try:
    fifo = os.open("./fifo", os.O_RDONLY)
    
    # Leer datos del FIFO (hasta BYTES bytes)
    data = os.read(fifo, BYTES)
    
    # Imprimir los datos leídos después de decodificar
    print(data.decode())  
    
    # Cerrar el FIFO después de leer
    os.close(fifo)

except OSError as e:
    print(f"Error al abrir o leer el FIFO: {e}")
