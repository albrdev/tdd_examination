#include <iostream>
#include <string>
#include "generic.hpp"
#include "geometry.h"

const double INPUT_MINVALUE = 0.0;
const double INPUT_MAXVALUE = 1000.0;

input::parseerror_t parseValue(const std::string& input, double& result)
{
    input::parseerror_t status;
    if((status = input::parsePrefixedDouble(input, result)) != input::PE_NONE)
    {
        return status;
    }

    return (result > INPUT_MINVALUE && result < INPUT_MAXVALUE) ? input::PE_NONE : input::PE_NUMERICRANGE;
}

bool inputLengthAndWidth(double& lengthResult, double& widthResult)
{
    std::string input;
    input::parseerror_t status;

    std::cout << "Input length: ";
    std::getline(std::cin, input);
    input = string::trimWhitespace(input);
    if((status = parseValue(input, lengthResult)) != input::PE_NONE)
    {
        std::cerr << "*** Error: " << input::getParseErrorMessage(status) << std::endl;
        return false;
    }

    std::cout << "Input width: ";
    std::getline(std::cin, input);
    input = string::trimWhitespace(input);
    if((status = parseValue(input, widthResult)) != input::PE_NONE)
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

    std::string input;
    input::parseerror_t status;
    std::cout << "Input height: ";
    std::getline(std::cin, input);
    input = string::trimWhitespace(input);
    if((status = parseValue(input, height)) != input::PE_NONE)
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
        std::getline(std::cin, input);
        input = string::trimWhitespace(input);
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
