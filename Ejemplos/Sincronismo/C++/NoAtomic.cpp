#include <iostream>
#include <thread>
#include <vector>

int count=0;

void Sum()
{
    for (int i=0; i<100; ++i) 
    {
        count++;
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

    std::cout<<"Resultado "<<count<<std::endl;

    return EXIT_SUCCESS;
} 
