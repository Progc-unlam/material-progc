#include <thread>
#include <vector>
#include <mutex>
#include <iostream>

std::mutex mtx;
int var = 0;

void hiloHace()
{
	int intentos = 10;
	while( intentos )
	{
		if( mtx.try_lock() )//P( mtx )
		{
			var++;			//Región crítica
			mtx.unlock();	//V( mtx )
			intentos = 0;
		}
		else
		{
			std::cout<<"No se pudo obtener mtx"<<std::endl;
			intentos--;
		}
	}	
}

int main( int argc, char *argv[] )
{
	const int MAX_THREADS = 1000;
	
	std::thread hilos[ MAX_THREADS ];
  
	for( int i=0; i<MAX_THREADS; ++i )
	{
    	hilos[ i ] = std::thread( hiloHace );
	}
	
  	for( int i=0; i<MAX_THREADS; ++i ) 
	{
		hilos[ i ].join();
	}	

	std::cout<<"var: "<<var<<std::endl;
	
	return EXIT_SUCCESS;
}

