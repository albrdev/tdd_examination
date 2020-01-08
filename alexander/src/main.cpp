#include <iostream>
#include <string>
#include "calculator.hpp"

int main(int argc, char* argv[])
{
    std::cout.precision(2);
    std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);

    while(1)
    {
        mainMenu();
        std::cout << std::endl;
    }

    return 0;
}
