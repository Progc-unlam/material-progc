#include <thread>
#include <vector>
#include <mutex>
#include <iostream>

std::recursive_mutex recursive_mtx;
int number = 10;

void RecursiveFunction()
{
    recursive_mtx.lock();

    if (number > 0)
    {
        number--;
        RecursiveFunction();
    }

    recursive_mtx.unlock();		
}

int main( int argc, char *argv[] )
{
    std::thread(RecursiveFunction).join();

    std::cout<<"Número: "<<number<<std::endl;

    return EXIT_SUCCESS;
}
