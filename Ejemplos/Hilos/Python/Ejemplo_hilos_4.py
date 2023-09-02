import sys
import threading
import time

PARAM_MAX_THREAD = 1

#Creando una clase con parámetros
class DaemonThread(threading.Thread):
    def __init__(self, args=()):
        super().__init__(daemon=True)
        self.first_arg = args[0]

    def run(self):
        print("Parámetro", self.first_arg)

def main(param):
    if len(param) < 2:
        sys.exit("Se necesita la cantidad de hilos a generar.")

    for i in range(int(param[PARAM_MAX_THREAD])):
        DaemonThread(args=(i,)).start()

    time.sleep(1)

if __name__ == '__main__':
    main(sys.argv)
