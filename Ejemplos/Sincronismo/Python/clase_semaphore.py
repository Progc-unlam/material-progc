import threading

MAX_THREADS = 5
sem = threading.Semaphore(1)	
value = 0

def thread_do():
    global value
    sem.acquire()
    value+=1
    sem.release()

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
