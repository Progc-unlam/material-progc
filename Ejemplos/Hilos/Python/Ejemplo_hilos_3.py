import threading

MAX_HILOS = 5

#La clase MyThread hereda de Thread 
class MyThread(threading.Thread):
    #Redefinimos el método run de la clase Thread en MyThread
    def run(self):
        print(threading.current_thread().name)

def main():
    threads=[] 

    for _ in range(MAX_HILOS):
        threads.append(MyThread())

    for i in range(MAX_HILOS):
        threads[i].start()

    for i in range(MAX_HILOS):
        threads[i].join()

    threads.clear()

if __name__ == '__main__':
    main()
