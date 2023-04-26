import sys
import os

try:
	os.mkfifo( "./fifo", 0o600 )

except OSError as err:
	print(f"Error al crear fifo {err}")
	sys.exit(1)
	
fifo = os.open( "./fifo", os.O_WRONLY )

os.write( fifo,  ("Café La Morenita").encode() )

os.close( fifo )

os.unlink("./fifo")

