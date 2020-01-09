#include "calculator.hpp"
#include <cstdlib>
#include <iostream>
#include "geometry.h"

#define OPTION_SHORT_PERIMETER  "P"
#define OPTION_LONG_PERIMETER   "perimeter"
#define OPTION_SHORT_AREA       "A"
#define OPTION_LONG_AREA        "area"
#define OPTION_SHORT_VOLUME     "V"
#define OPTION_LONG_VOLUME      "volume"
#define OPTION_SHORT_QUIT       "Q"
#define OPTION_LONG_QUIT        "quit"

double INPUTVALUE_MIN = 0.0;
double INPUTVALUE_MAX = 1000.0;

input::parseerror_t parseValue(const std::string& input, double& result)
{
    input::parseerror_t status;

    if ((status = input::parsePrefixedDouble(input, result)) != input::PE_NONE)
    {
        return status;
    }

    // Return success if value is within our custom range, otherwise return error code.
    return (result > INPUTVALUE_MIN && result < INPUTVALUE_MAX) ? input::PE_NONE : input::PE_NUMERICRANGE;
}

void inputLengthAndHeight(double& lengthResult, double& heightResult)
{
    std::string input;
    input::parseerror_t status;

    do
    {
        std::cout << "Input length: ";
        std::getline(std::cin, input);
        input = string::trimWhitespace(input);

        // Parse double value and apply possible prefix.
        if ((status = parseValue(input, lengthResult)) != input::PE_NONE)
        {
            std::cerr << "*** Error: " << input::getErrorMessage(status) << std::endl;
            continue;
        }
        else
        {
            break;
        }
    } while (true);

    do
    {
        std::cout << "Input height: ";
        std::getline(std::cin, input);
        input = string::trimWhitespace(input);

        // Parse double value and apply possible prefix.
        if ((status = parseValue(input, heightResult)) != input::PE_NONE)
        {
            std::cerr << "*** Error: " << input::getErrorMessage(status) << std::endl;
            continue;
        }
        else
        {
            break;
        }
    } while (true);
}

void calcPerimeter(void)
{
    double length;
    double height;

    inputLengthAndHeight(length, height);

    std::cout << "Result: " << getRectanglePerimeter(length, height) << std::endl;
}

void calcArea(void)
{
    double length;
    double height;

    inputLengthAndHeight(length, height);

    std::cout << "Result: " << getRectangleArea(length, height) << std::endl;
}

void calcVolume(void)
{
    double length;
    double height;
    double width;

    inputLengthAndHeight(length, height);

    do
    {
        std::string input;
        input::parseerror_t status;

        std::cout << "Input width: ";
        std::getline(std::cin, input);
        input = string::trimWhitespace(input);

        // Parse double value and apply possible prefix.
        if ((status = parseValue(input, width)) != input::PE_NONE)
        {
            std::cerr << "*** Error: " << input::getErrorMessage(status) << std::endl;
            continue;
        }
        else
        {
            break;
        }
    } while(true);

    std::cout << "Result: " << getCuboidVolume(length, height, width) << std::endl;
}

void printMainMenu(void)
{
    std::cout << "=========================" << std::endl;
    std::cout << "Main Menu" << std::endl;
    std::cout << " (P)erimeter" << std::endl;
    std::cout << " (A)rea" << std::endl;
    std::cout << " (V)olume" << std::endl;
    std::cout << " (Q)uit" << std::endl;
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
    } while (input.empty()); // Ask for input til we get any.

    // Check if input is any of the possible option strings or its shorthand (case-insensitive).
    if (string::compareIgnoreCase(input, OPTION_SHORT_PERIMETER) == 0 ||
       string::compareIgnoreCase(input, OPTION_LONG_PERIMETER) == 0)
    {
        calcPerimeter();
    }
    else if (string::compareIgnoreCase(input, OPTION_SHORT_AREA) == 0 ||
            string::compareIgnoreCase(input, OPTION_LONG_AREA) == 0)
    {
        calcArea();
    }
    else if (string::compareIgnoreCase(input, OPTION_SHORT_VOLUME) == 0 ||
            string::compareIgnoreCase(input, OPTION_LONG_VOLUME) == 0)
    {
        calcVolume();
    }
    else if (string::compareIgnoreCase(input, OPTION_SHORT_QUIT) == 0 ||
            string::compareIgnoreCase(input, OPTION_LONG_QUIT) == 0)
    {
        exit(EXIT_SUCCESS);
    }
    else
    {
        std::cerr << "Unknown option: " << input << std::endl;
        return;
    }
}
