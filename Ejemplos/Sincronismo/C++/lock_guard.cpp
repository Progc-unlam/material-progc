#include <thread>
#include <vector>
#include <mutex>
#include <iostream>

std::mutex mtx;
int var = 0;

void hiloHace()
{
	std::lock_guard<std::mutex> mi_lock(mtx);	//P( mtx ) 
	var++;	//Región crítica	
} 			//V( mtx ) - Cuando se destruye mi_lock

int main( int argc, char *argv[] )
{
	const int MAX_THREADS = 10000;
	
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

