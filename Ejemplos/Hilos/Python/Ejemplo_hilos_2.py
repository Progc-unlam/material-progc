import threading
import time


def show_tid():
    time.sleep(2) #Jugar con/sin esta línea
    print("TID", threading.get_native_id())

def main():
    for _ in range(5):
        threading.Thread( target=show_tid, daemon=True ).start() 

    for hilo in threading.enumerate():
        print( hilo.name )

if __name__ == '__main__':
    main()
