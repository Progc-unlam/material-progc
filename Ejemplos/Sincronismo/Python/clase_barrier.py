import threading

MAX_THREADS = 5
shared_value = -1
mtx = threading.Lock()	

def start():
    global shared_value
    print(threading.current_thread().name)
    shared_value = 0

bar = threading.Barrier(MAX_THREADS, action=start)

def thread_do():
    global shared_value
    bar.wait()
    mtx.acquire()
    shared_value+=1
    mtx.release()

def main():
    threads = [] 

    for i in range(MAX_THREADS):
        threads.append(threading.Thread(target = thread_do))

    for i in range(MAX_THREADS):
        threads[i].start()
    
    for i in range(MAX_THREADS):
        threads[i].join()

    threads.clear()	

    print("Valor compartido: ", shared_value)

if __name__ == '__main__':
    main()
