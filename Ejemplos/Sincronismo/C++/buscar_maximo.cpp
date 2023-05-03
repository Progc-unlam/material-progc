#include <thread>
#include <vector>
#include <mutex>
#include <iostream>

#define MAX_MED 10
#define MAX_HIL  2
#define FIN_MED  5

std::mutex mtx;
std::vector<int> mediciones( MAX_MED, 0 ); 

int max = 0;

void buscarMaximo( int inicio )
{
	for( int i=inicio; i<inicio+FIN_MED; i++)
	{
		mtx.lock(); 					//P( mtx )
		if( mediciones[ i ] > max )		//Región crítica
			max = mediciones[ i ];
		mtx.unlock();					//V( mtx )
	}
}

int main( int argc, char *argv[] )
{
	std::vector<std::thread> hilos;
	
	srand( time(NULL) );
	
	for( int i=0; i<MAX_MED; i++ )
		mediciones[ i ]=rand()%100;	

	//Creación de los hilos
	for( int i=0; i<MAX_HIL; i++ ) 
		hilos.push_back( std::thread( buscarMaximo, i*FIN_MED ) );

	//Espera la finalización de los hilos creados
	for( int i=0; i<MAX_HIL; i++ ) 
		hilos[ i ].join();
	
	std::cout<<"Medición máxima: "<<max<<std::endl;

	hilos.clear();
			
	return EXIT_SUCCESS;
}

