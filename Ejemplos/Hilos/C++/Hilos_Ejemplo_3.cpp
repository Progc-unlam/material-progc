#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

void incrementar( std::atomic<int> &var )
{
	var++;
}

int main(int argc, char *argv[]) 
{
	std::vector<std::thread> hilos;
	std::atomic<int> x(0);
	int cant_hilos = atoi(argv[1]);
	
	for(int i=0; i<cant_hilos; i++)
	{
		hilos.push_back( std::thread( incrementar, std::ref( x ) ) );
	}
	
	for(int i=0; i<cant_hilos; i++)
	{
		hilos[i].join();
	}
	
	std::cout<<"Valor: "<<x<<std::endl;
}
