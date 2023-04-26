import os

BYTES = 1024

fifo = os.open( "./fifo", os.O_RDONLY )

print( os.read( fifo, BYTES ).decode() )

os.close( fifo )

