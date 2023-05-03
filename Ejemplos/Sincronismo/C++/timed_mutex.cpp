#include <thread>
#include <vector>
#include <mutex>
#include <iostream>
#include <chrono>

const int WAIT_TIME = 1000;
const int SLEP_TIME = 500;

std::timed_mutex t_mtx;

void hiloHace()
{
	while( ! t_mtx.try_lock_for( std::chrono::milliseconds( WAIT_TIME ) ) )
	{
		std::cout<<"...";
	}
	std::cout<<" Acceso"<<std::endl;
	std::this_thread::sleep_for( std::chrono::milliseconds( SLEP_TIME ) );
	t_mtx.unlock();
	
}

int main( int argc, char *argv[] )
{
	const int MAX_THREADS = 10;
	
	std::thread hilos[ MAX_THREADS ];
  
	for( int i=0; i<MAX_THREADS; ++i )
	{
    	hilos[ i ] = std::thread( hiloHace );
	}
	
  	for( int i=0; i<MAX_THREADS; ++i ) 
	{
		hilos[ i ].join();
	}	
	
	return EXIT_SUCCESS;
}

