#include <thread>
#include <iostream>

void Sleep()
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout<<"Finalizando hilo"<<std::endl;
};

int main( int argc, char *argv[] )
{
    std::thread hilo_a(Sleep);

    hilo_a.detach();

    if ( not hilo_a.joinable() )
    {
        std::cout<<"El hilo es Independiente"<<std::endl;
    }
	
    std::this_thread::sleep_for(std::chrono::seconds(4));
	
    std::cout<<"Hilo principal finaliza."<<std::endl;

    return EXIT_SUCCESS;
}
