#include <thread>
#include <vector>
#include <mutex>
#include <iostream>

std::mutex mtx;
int value = 0;

void ThreadDo()
{
    std::lock_guard<std::mutex> mi_lock(mtx); //P( mtx )
    value++; //Región crítica
    //V( mtx ) - Cuando se destruye mi_lock
}

int main( int argc, char *argv[] )
{
    const int kMaxThreads = 10000;

    std::thread hilos[kMaxThreads];

    for (int i=0; i<kMaxThreads; i++)
    {
        hilos[i] = std::thread(ThreadDo);
    }

    for (int i=0; i<kMaxThreads; i++) 
    {
        hilos[i].join();
    }

    std::cout<<"Value: "<<value<<std::endl;

    return EXIT_SUCCESS;
}
