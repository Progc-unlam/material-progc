import threading
import time

MAX_THREADS = 5

def show_tid():
    print("TID "+str(threading.get_native_id()))
    #time.sleep(2)
    
def main():
    my_threads = []

    for _ in range(MAX_THREADS):
        my_threads.append(threading.Thread(target=show_tid, daemon=False)) 
    
    for i in range(MAX_THREADS):
        my_threads[i].start() 
    
    #time.sleep(2) 
    for thread in my_threads:
        print(thread.name)

if __name__ == '__main__':
    main()
