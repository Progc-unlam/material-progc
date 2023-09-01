#include <thread>
#include <iostream>
#include <vector>

//Array de valores a sumar por los hilos
std::vector<int> values = {1, 2, 3, 4};

void AddRange(std::string name, int begin, int end)
{
    int total = 0;
    for (int i = begin; i <= end; i++)
    {
        total+=values[i];
    }
    std::cout<<name<<": "<<total<<std::endl;
};

int main( int argc, char *argv[] )
{
    std::thread hilo_a(AddRange,"A", 0, 1);
    std::thread hilo_b(AddRange,"B", 2, 3);

    hilo_a.join();
    hilo_b.join();
    
    return EXIT_SUCCESS;
}
