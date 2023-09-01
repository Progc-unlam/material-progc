#include <thread>
#include <iostream>
#include <vector>
#include <numeric>
#include <future>

std::vector<int> values = {1,2,3,4};
int sum;

void AddValues( std::promise<int> add_values_promise )
{
    sum = std::accumulate(values.begin(), values.end(), 0);
    add_values_promise.set_value(sum);
};

int main( int argc, char *argv[] )
{
    std::promise<int> add_values_promise;
    std::future<int> add_values_future = add_values_promise.get_future();

    std::thread hilo_a(AddValues, std::move(add_values_promise));

    std::cout<<"Suma: "<<add_values_future.get()<<std::endl;

    hilo_a.join();

    return EXIT_SUCCESS;
}
