#include <thread>
#include <iostream>
#include <string>

int valor = 0;

void incrementarValor( std::string nombre )
{
	std::cout<<"Nombre: "<<nombre<<std::endl;
	valor++;
}

int main( int argc, char *argv[] )
{
	//Creación de los hilos
	std::thread HiloA( incrementarValor, "Hilo A" );
	std::thread HiloB( incrementarValor, "Hilo B" );

	//Espera la finalización de los hilos creados
	HiloA.join();
	HiloB.join();
	
	std::cout<<"Valor: "<<valor<<std::endl;
			
	return EXIT_SUCCESS;
}

