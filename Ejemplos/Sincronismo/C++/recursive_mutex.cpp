#include <thread>
#include <vector>
#include <mutex>
#include <iostream>

std::recursive_mutex r_mtx;
int nro = 10;

void calculoRecursivo()
{
	r_mtx.lock(); 	
	
	if( nro > 0 )
	{
		nro--;
		calculoRecursivo();
	}
	
	r_mtx.unlock();		
}

int main( int argc, char *argv[] )
{
	std::thread( calculoRecursivo ).join();
	
	std::cout<<"Nro: "<<nro<<std::endl;
	
	return EXIT_SUCCESS;
}

