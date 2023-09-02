import threading

value = 0

def change_value(new_value):
    global value #Para que pueda escribir la variable
    print(threading.current_thread().name, "TID", threading.get_native_id())
    value = new_value

def main():
    hilo_a = threading.Thread(target=change_value, args=(1,), name="A") 
    hilo_b = threading.Thread(target=change_value, args=(2,), name="B") 

    hilo_a.start()
    hilo_b.start()

    hilo_a.join()
    hilo_b.join()

    print( "Valor final: ", value )

if __name__ == '__main__':
    main()
