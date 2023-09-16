#include <thread>
#include <vector>
#include <mutex>
#include <iostream>
#include <chrono>

const int kWaitTime = 1000;
const int kSleepTime = 500;

std::timed_mutex timed_mtx;

void ThreadDo()
{
    while (! timed_mtx.try_lock_for(std::chrono::milliseconds(kWaitTime)))
    {
        std::cout<<".";
    }
    std::cout<<" Acceso"<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(kSleepTime));
    timed_mtx.unlock();
}

int main( int argc, char *argv[] )
{
    const int kMaxThreads = 10;

    std::thread threads[kMaxThreads];
  
    for (int i=0; i<kMaxThreads; ++i)
    {
        threads[i] = std::thread(ThreadDo);
    }

    for (int i=0; i<kMaxThreads; ++i)
    {
        threads[i].join();
    }

    return EXIT_SUCCESS;
}
