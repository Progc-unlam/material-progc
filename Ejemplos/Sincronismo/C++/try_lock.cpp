#include <thread>
#include <vector>
#include <mutex>
#include <iostream>

std::mutex mtx;
int value = 0;

void ThreadDo()
{
    int attempts = 10;
    while (attempts)
    {
        if (mtx.try_lock())
        {
            value++; 
            mtx.unlock();	
            attempts = 0;
        }
        else
        {
            std::cout<<"No se pudo obtener mtx"<<std::endl;
            attempts--;
        }
    }
}

int main( int argc, char *argv[] )
{
    const int kMaxThreads = 1000;

    std::thread threads[kMaxThreads];

    for (int i=0; i<kMaxThreads; ++i)
    {
        threads[i] = std::thread(ThreadDo);
    }

    for (int i=0; i<kMaxThreads; ++i)
    {
        threads[i].join();
    }

    std::cout<<"Valor: "<<value<<std::endl;

    return EXIT_SUCCESS;
}
