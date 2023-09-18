#include <iostream>
#include <thread>
#include <vector>
#include <atomic>

std::atomic<int> count(0);

void Sum()
{
    for (int i=0; i<100; ++i) 
    {
        atomic_fetch_add(&count, 1);
    }
}

int main() 
{
    std::vector<std::thread> threads;

    for(int i=0; i<1000; ++i)
    {
        threads.push_back( std::thread(Sum) );
    }

    for(int i=0; i<1000; ++i)
    {
        threads[i].join();
    }

    std::cout<<"Resultado "<<count.load()<<std::endl;

    return EXIT_SUCCESS;
} 
