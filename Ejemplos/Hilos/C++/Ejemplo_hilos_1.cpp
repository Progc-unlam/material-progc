#include <thread>
#include <iostream>
#include <string>

//Valor que los hilos imprimirán en pantalla
int valor = 0;

void IncrementarValor( std::string nombre )
{
    std::cout<<"Nombre: "<<nombre<<" - Valor: "<<valor<<std::endl;
}

int main( int argc, char *argv[] )
{
    //Creación de los hilos
    std::thread hilo_a( IncrementarValor, "Hilo A" );
    std::thread hilo_b( IncrementarValor, "Hilo B" );

    //Espera la finalización de los hilos creados
    hilo_a.join();
    hilo_b.join();

    return EXIT_SUCCESS;
}
