#include <iostream>
#include <thread>
using namespace std;

int TOTAL_NUMBER_OF_FORKS = 3;

int getFork(int usersForkCount, int philosopherId)
{
    if (TOTAL_NUMBER_OF_FORKS > 1)
    {
        TOTAL_NUMBER_OF_FORKS--;
        std::cout << philosopherId;
        std::cout << " Retrieved a Fork\n";
        return 1;
    }
    else if (TOTAL_NUMBER_OF_FORKS == 1 && usersForkCount == 1)
    {
        TOTAL_NUMBER_OF_FORKS--;
        std::cout << philosopherId;
        std::cout << " Retrieved a Fork\n";
        return 1;
    }
    else
    {
        std::cout << philosopherId;
        std::cout << " Could not get a Fork\n";
        return 0;
    }
}

int main()
{
    thread philosopher1([]
                        { 
        int currentNumberOfForks = 0;
        std::cout << "Philosopher 1 Here!\n"; 
        while(currentNumberOfForks != 2) {
            currentNumberOfForks += getFork(currentNumberOfForks, 1);
         }

        std::cout << "Philosopher 1: LETS EAT!\n"; 
        TOTAL_NUMBER_OF_FORKS = 3; });

    thread philosopher2([]
                        {                             
        int currentNumberOfForks = 0;
        std::cout << "Philosopher 2 Here!\n"; 
        while(currentNumberOfForks != 2) {
            currentNumberOfForks += getFork(currentNumberOfForks, 2);
        }
        std::cout << "Philosopher 2: LETS EAT!\n";
        TOTAL_NUMBER_OF_FORKS = 3; });

    thread philosopher3([]
                        {
        int currentNumberOfForks = 0;
        std::cout << "Philosopher 3 Here!\n"; 
        while(currentNumberOfForks != 2) {
            currentNumberOfForks += getFork(currentNumberOfForks, 3);
        }
        std::cout << "Philosopher 3: LETS EAT!\n";
        TOTAL_NUMBER_OF_FORKS = 3; });

    philosopher1.join();
    philosopher2.join();
    philosopher3.join();

    std::cout << "\nBack on the main thread!\n";
    return 0;
}