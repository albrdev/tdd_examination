#include "generic.hpp"
#include <map>
#include <limits>
#include <stdexcept>

#ifndef __NAMESPACE_STRING__
int string::compareIgnoreCase(const std::string& a, const std::string& b)
{
    size_t i = 0;
    while((a[i] != '\0' && b[i] != '\0') && tolower(a[i]) == tolower(b[i]))
    {
        i++;
    }

    return a[i] - b[i];
}

static const std::map<std::string, double> _prefixMap =
{
    { "k", 1000.0 },
    { "d", 0.1 },
    { "c", 0.01 },
    { "m", 0.001 }
};
#endif /* __NAMESPACE_STRING__ */

#ifndef __NAMESPACE_INPUT__
input::parseerror_t input::parseInt(const std::string& str, int& result)
{
    std::size_t charPos = 0;
    try
    {
        result = std::stoi(str, &charPos);
    }
    catch(const std::invalid_argument & e)
    {
        return PE_INVALID;
    }
    catch(const std::out_of_range & e)
    {
        return PE_NUMERICRANGE;
    }

    return PE_NONE;
}

input::parseerror_t input::parseDouble(const std::string& str, double& result, std::string& remaining)
{
    std::size_t charPos = 0;
    try
    {
        result = std::stod(str, &charPos);
    }
    catch(const std::invalid_argument & e)
    {
        return PE_INVALID;
    }
    catch(const std::out_of_range & e)
    {
        return PE_NUMERICRANGE;
    }

    remaining = str.substr(charPos);
    return PE_NONE;
}

input::parseerror_t input::parsePrefixedDouble(const std::string& str, double& result)
{
    std::string remaining;
    parseerror_t status = parseDouble(str, result, remaining);
    if(status != PE_NONE)
    {
        return status;
    }

    if(!remaining.empty())
    {
        std::map<std::string, double>::const_iterator iter = _prefixMap.find(remaining);
        if(iter == _prefixMap.cend())
        {
            return PE_INVALID;
        }

        result *= iter->second;
    }

    return PE_NONE;
}

bool input::readString(std::string& result)
{
    getline(std::cin, result);
    if(!std::cin)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }

    return true;
}

input::parseerror_t input::readPrefixedDouble(double& result, const double min, const double max)
{
    std::string input;
    if(!readString(input))
    {
        return PE_INVALID;
    }

    parseerror_t status;
    if((status = parsePrefixedDouble(input, result)) != PE_NONE)
    {
        return status;
    }

    return (result > min&& result < max) ? PE_NONE : PE_NUMERICRANGE;
}

std::string input::getParseErrorMessage(const input::parseerror_t id)
{
    switch(id)
    {
        case PE_NONE:
            return "No error";
        case PE_INVALID:
            return "Invalid character(s) in input";
        case PE_NUMERICRANGE:
            return "Number is out of range";
        default:
            return "Unknown error";
    };
}
#endif /* __NAMESPACE_INPUT__ */
