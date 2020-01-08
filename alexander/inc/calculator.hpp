#ifndef __CALCULATOR_HPP__
#define __CALCULATOR_HPP__

#include <string>
#include "generic.hpp"

input::parseerror_t parseValue(const std::string& input, double& result);

bool inputLengthAndWidth(double& lengthResult, double& widthResult);

void calcPerimeter(void);
void calcArea(void);
void calcVolume(void);

void printMainMenu(void);
void mainMenu(void);

#endif /* __CALCULATOR_HPP__ */
