#ifndef __CALCULATOR_HPP__
#define __CALCULATOR_HPP__

#include <string>
#include "generic.hpp"

/*! parseValue()
    Wrapper function for input::parsePrefixedDouble() with custom numeric range limitations.
    Converts a numeric string to a double and extracts any trailing non-floating-point characters.
    This value must have a valid range from > 0 and < 1000.
    \fn parseValue()
    \param[in]  input       The string that is to be converted.
    \param[out] result      The resulting value.
    \return                 'PE_NONE' on success. 'PE_INVALID' if string conatins invalid character(s) in front or middle of a presumed number (invalid characters at the end is not taken into account). 'PE_NUMERICRANGE' if the number is out of range (less or equal than 0 or greater or equal than 1000). If a value other then 'PE_NONE' is returned, 'result' is not altered.
*/
input::parseerror_t parseValue(const std::string& input, double& result);

/*! inputLengthAndWidth()
    Asks for input for length and height.
    These values must have a valid range from > 0 and < 1000.
    \fn inputLengthAndWidth()
    \param[in]  lengthResult    The resulting value for length.
    \param[out] heightResult    The resulting value for height.
    \return                     N/A
*/
bool inputLengthAndHeight(double& lengthResult, double& heightResult);

/*! calcPerimeter()
    Asks for input for length and height, then calculates and prints the rectangle perimeter based on those values.
    \fn calcPerimeter()
    \return N/A
*/
void calcPerimeter(void);

/*! calcArea()
    Asks for input for length and height, then calculates and prints the rectangle area based on those values.
    \fn calcArea()
    \return N/A
*/
void calcArea(void);

/*! calcVolume()
    Asks for input for length, width and height, then calculates and prints the cuboid volume based on those values.
    \fn calcVolume()
    \return N/A
*/
void calcVolume(void);

/*! printMainMenu()
    Prints the main menu.
    \fn printMainMenu()
    \return N/A
*/
void printMainMenu(void);

/*! mainMenu()
    Prints the main menu and asks for an option input, then calls the correct function or prints an error message.
    \fn mainMenu()
    \return N/A
*/
void mainMenu(void);

#endif /* __CALCULATOR_HPP__ */
