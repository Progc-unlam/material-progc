import os
import signal
import sys
import time

CHILD = 0

def manejador(sig, frame):
    print("Recibido ", signal.Signals(sig).name)

def main():
    signal.signal(signal.SIGCONT, manejador)

    for i in range(2):
        process = os.fork()
        if process < 0:
            print("Error al crear el proceso ",i+1)
            sys.exit(1)

        if process == CHILD:
           signal.raise_signal(signal.SIGSTOP)
           os._exit(0)

    time.sleep(2)
    os.killpg(os.getpgrp(), signal.SIGCONT)

    for i in range(2):
        os.wait()

if __name__ == '__main__':
    main()
