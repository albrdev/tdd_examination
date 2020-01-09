#include <iostream>
#include <string>
#include "calculator.hpp"
#include "generic.hpp"

int main(int argc, char* argv[])
{
    // Set floating-point precision and fixed decimal output.
    std::cout.precision(2);
    std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);

    // Main loop
    while (true)
    {
        mainMenu();
        std::cout << std::endl;
    }

    return 0;
}
