#include <iostream>
#include <string>
#include "generic.hpp"
#include "geometry.h"

const double INPUT_MINVALUE = 0.0;
const double INPUT_MAXVALUE = 1000.0;

bool inputLengthAndWidth(double& lengthResult, double& widthResult)
{
    input::parseerror_t status;

    std::cout << "Input length: ";
    if((status = input::readPrefixedDouble(lengthResult, INPUT_MINVALUE, INPUT_MAXVALUE)) != input::PE_NONE)
    {
        std::cerr << "*** Error: " << input::getParseErrorMessage(status) << std::endl;
        return false;
    }

    std::cout << "Input height: ";
    if((status = input::readPrefixedDouble(widthResult, INPUT_MINVALUE, INPUT_MAXVALUE)) != input::PE_NONE)
    {
        std::cerr << "*** Error: " << input::getParseErrorMessage(status) << std::endl;
        return false;
    }

    return true;
}

void calcPerimeter(void)
{
    double length, width;
    if(!inputLengthAndWidth(length, width))
    {
        return;
    }

    std::cout << "Result: " << getRectanglePerimeter(length, width) << std::endl;
}

void calcArea(void)
{
    double length, width;
    if(!inputLengthAndWidth(length, width))
    {
        return;
    }

    std::cout << "Result: " << getRectanglePerimeter(length, width) << std::endl;
}

void calcVolume(void)
{
    double length, width, height;
    if(!inputLengthAndWidth(length, width))
    {
        return;
    }

    input::parseerror_t status;
    std::cout << "Input height: ";
    if((status = input::readPrefixedDouble(height, INPUT_MINVALUE, INPUT_MAXVALUE)) != input::PE_NONE)
    {
        std::cerr << "*** Error: " << input::getParseErrorMessage(status);
        return;
    }

    std::cout << "Result: " << getCuboidVolume(length, width, height) << std::endl;
}

void printMainMenu(void)
{
    std::cout << "=========================" << std::endl;
    std::cout << "Main Menu" << std::endl;
    std::cout << " (P)erimeter" << std::endl;
    std::cout << " (A)rea" << std::endl;
    std::cout << " (V)olume" << std::endl;
}

void mainMenu(void)
{
    printMainMenu();

    std::string input;
    do
    {
        std::cout << "> ";
        if(!input::readString(input))
        {
            std::cerr << "Invalid input" << std::endl;
            return;
        }
    } while(input.empty());

    if(string::compareIgnoreCase(input, "p") == 0 || string::compareIgnoreCase(input, "perimeter") == 0)
    {
        calcPerimeter();
    }
    else if(string::compareIgnoreCase(input, "a") == 0 || string::compareIgnoreCase(input, "area") == 0)
    {
        calcArea();
    }
    else if(string::compareIgnoreCase(input, "v") == 0 || string::compareIgnoreCase(input, "volume") == 0)
    {
        calcVolume();
    }
    else
    {
        std::cerr << "Unknown option: " << input << std::endl;
        return;
    }
}

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
