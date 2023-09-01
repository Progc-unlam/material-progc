#include <thread>
#include <iostream>

void IncreaseValue(int &value)
{
    value++;
};

int main( int argc, char *argv[] )
{
    int value = 0;

    std::thread hilo_a(IncreaseValue, std::ref(value));

    hilo_a.join();

    std::cout<<"Valor final: "<<value<<std::endl;

    return EXIT_SUCCESS;
}
