#include <thread>
#include <iostream>
#include <atomic>
#include <vector>

int array[] = { 1, 2, 3, 4 };
std::atomic<int> suma(0);

void sumarRango( int inicio, int fin )
{
	for( int i=inicio; i<=fin;i++)
	{
		suma+=array[i];
	}
};

int main( int argc, char *argv[] )
{
	std::thread HiloA( sumarRango, 0, 1 );
	std::thread HiloB( sumarRango, 2, 3 );
	
	HiloA.join();
	HiloB.join();
	
	std::cout<<"Suma: "<<suma<<std::endl;
			
	return EXIT_SUCCESS;
}