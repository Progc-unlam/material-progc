import threading

MAX_THREADS = 5

value = 0

def thread_do():
    global value
    try:
        sem.acquire()
        value+=1
        sem.release()
        sem.release()
    except ValueError:
        print("Se liberó mas de una vez")

sem = threading.BoundedSemaphore(1)	

def main():
    threads = [] 

    for i in range(MAX_THREADS):
        threads.append(threading.Thread(target=thread_do))
        threads[i].start()
    
    for i in range(MAX_THREADS):
        threads[i].join()

    threads.clear()	

    print("Valor final: ", value)


if __name__ == '__main__':
    main()
