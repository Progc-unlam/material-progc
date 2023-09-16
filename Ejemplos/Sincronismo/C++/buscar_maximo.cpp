#include <thread>
#include <vector>
#include <mutex>
#include <iostream>

const int kMaxValues = 10;
const int kMaxThreads = 2;
const int kLimit = 5;

std::mutex mtx;
std::vector<int> values(kMaxValues, 0); 

int max = 0;

void BuscarMaximo(int begin, int end)
{
    for (int i=begin; i<end; ++i)
    {
        mtx.lock();   //P( mtx )
        if (values[i] > max)
            max = values[i];
        mtx.unlock(); //V( mtx )
    }
}

int main( int argc, char *argv[] )
{
    std::vector<std::thread> hilos;

    srand(time(NULL));

    for (int i=0; i<kMaxValues; ++i)
        values[i]=rand()%100;	

    //Creación de los hilos
    for (int i=0; i<kMaxThreads; ++i) 
        hilos.push_back(std::thread(BuscarMaximo, i*kLimit, i*kLimit+kLimit));

    //Espera la finalización de los hilos creados
    for (int i=0; i<kMaxThreads; ++i) 
        hilos[i].join();

    std::cout<<"Medición máxima: "<<max<<std::endl;

    hilos.clear();

    return EXIT_SUCCESS;
}
