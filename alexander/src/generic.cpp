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

static const char _whitespaceCharacters[] = " \t\v\n\r\f";
std::string string::trimWhitespace(const std::string& str)
{
    std::size_t startPos = str.find_first_not_of(_whitespaceCharacters);
    if(startPos == std::string::npos)
    {
        return std::string();
    }

    std::size_t endPos = str.find_last_not_of(_whitespaceCharacters);

    return str.substr(startPos, (endPos - startPos) + 1);
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
