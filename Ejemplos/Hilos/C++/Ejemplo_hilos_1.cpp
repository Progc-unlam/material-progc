#include <thread>
#include <iostream>

//Valor que los hilos imprimirán en pantalla
int value = 0;

void ShowValue(int id)
{
    std::cout<<"ID: "<<id<<" - Value: "<<value<<std::endl;
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
