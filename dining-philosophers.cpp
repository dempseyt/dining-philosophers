#include <iostream>
#include <thread>
using namespace std;

int TOTAL_NUMBER_OF_FORKS = 2;

int getFork()
{
    if (TOTAL_NUMBER_OF_FORKS > 0)
    {
        TOTAL_NUMBER_OF_FORKS--;
        std::cout << "Retrieved a Fork\n";
        return 1;
    }
    else
    {
        std::cout << "Could not get a Fork\n";
        return 0;
    }
}

int main()
{
    thread philosopher1([]
                        { 
                            int currentNumberOfForks = 0;
                            std::cout << "\nPhilsopher 1 Here!\n"; 
                            while(currentNumberOfForks != 2) {
                                currentNumberOfForks += getFork();
                            }
                            std::cout << "LETS EAT!\n"; });

    thread philosopher2([]
                        {                             
                            int currentNumberOfForks = 0;
                            std::cout << "\nPhilsopher 2 Here!\n"; 
                            while(currentNumberOfForks != 2) {
                                currentNumberOfForks += getFork();
                            }
                            std::cout << "LETS EAT!\n"; });

    philosopher1.join();
    philosopher2.join();

    std::cout << "\nHello from the main thread!\n";
    return 0;
}