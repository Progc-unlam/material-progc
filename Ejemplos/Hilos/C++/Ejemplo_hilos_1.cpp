#include <thread>
#include <iostream>

void ShowValue(int value)
{
    std::cout<<"TID: "<<std::this_thread::get_id()<<std::endl;
    std::cout<<"Value: "<<value<<std::endl;
}

int main( int argc, char *argv[] )
{
    //Creación de los hilos
    std::thread thread_a(ShowValue, 1);
    std::thread thread_b(ShowValue, 2);

    //Espera la finalización de los hilos creados
    thread_a.join();
    thread_b.join();

    return EXIT_SUCCESS;
}
