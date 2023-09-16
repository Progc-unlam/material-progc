import threading
import random

MAX_VALUES = 10 
MAX_RANGE = 5 
MAX_THREADS = 2 

values = [0] * MAX_VALUES  
min = 100
mtx = threading.Lock()	

def calculate_min(begin):
    global min
    for i in range(begin, begin + MAX_RANGE):
        mtx.acquire()
        if values[i] < min:
            min = values[i]
        mtx.release()

def main():
    threads = []

    #Carga de mediciones aleatorias entre 0 y 99 
    random.seed()
    for i in range(MAX_VALUES):
        values[ i ] = random.randrange( 100 )

    #Creación de los hilos
    for i in range(MAX_THREADS):
        threads.append(threading.Thread(target = calculate_min, args=(i * MAX_RANGE,)))

    #Inicio de los hilos
    for i in range(MAX_THREADS):
        threads[i].start()

    #Espera de los hilos
    for i in range(MAX_THREADS):
        threads[i].join()

    print("Valores generados: ", values)
    print("Valor mínimo: ", min)


if __name__ == '__main__':
    main()
