/*! main.cpp
    Main source file for this application.
    \file   main.cpp
    \author albrdev (albrdev@gmail.com)
    \date   2020-01-08
*/

#include "generic.hpp"
#include <map>
#include <limits>
#include <stdexcept>

#ifndef __NAMESPACE_STRING__
int string::compareIgnoreCase(const std::string& a, const std::string& b)
{
    std::size_t i;

    // Loop through both strings until at least one of them ends or the characters differ.
    for (i = 0; (a[i] != '\0' && b[i] != '\0') && tolower(a[i]) == tolower(b[i]); i++);

    // Will return 0 if both string are equal, otherwise the last characters checked in the loop was different from each other.
    return a[i] - b[i];
}

static const char WHITESPACE_CHARACTERS[] = " \t\v\n\r\f";
std::string string::trimWhitespace(const std::string& str)
{
    std::size_t startPos = str.find_first_not_of(WHITESPACE_CHARACTERS);

    // If no non-whitespace character is found, return empty string.
    if (startPos == std::string::npos)
    {
        return std::string();
    }

    std::size_t endPos = str.find_last_not_of(WHITESPACE_CHARACTERS);

    // Return all characters between first and last non-whitespace character.
    return str.substr(startPos, (endPos - startPos) + 1);
}
#endif /* __NAMESPACE_STRING__ */

#ifndef __NAMESPACE_INPUT__
input::parseerror_t input::parseDouble(const std::string& str, double& result, std::string& remaining)
{
    std::size_t charPos = 0;

    try
    {
        result = std::stod(str, &charPos);
    }
    catch (const std::invalid_argument & e)
    {
        // Invalid characters in numeric string.
        return PE_INVALID;
    }
    catch (const std::out_of_range & e)
    {
        // Number is out of range for the given type (double).
        return PE_NUMERICRANGE;
    }

    // Copy the remaining non-numeric character.
    remaining = str.substr(charPos);

    return PE_NONE;
}

// A small set of numeric SI-prefixes.
static const std::map<std::string, double> PREFIX_MAP =
{
    { "k", 1000.0 },
    { "d", 0.1 },
    { "c", 0.01 },
    { "m", 0.001 }
};

input::parseerror_t input::parsePrefixedDouble(const std::string& str, double& result)
{
    std::string remaining;

    parseerror_t status = parseDouble(str, result, remaining);

    if (status != PE_NONE)
    {
        return status;
    }

    remaining = string::trimWhitespace(remaining);

    if (!remaining.empty())
    {
        // Check if remaining character are a numeric prefix.
        std::map<std::string, double>::const_iterator iter = PREFIX_MAP.find(remaining);

        // If no prefix is found, the remaining character is considered invalid.
        if (iter == PREFIX_MAP.cend())
        {
            return PE_INVALID;
        }

        // If found, multiply the parsed number by prefix value.
        result *= iter->second;
    }

    return PE_NONE;
}

std::string input::getErrorMessage(const input::parseerror_t id)
{
    switch (id)
    {
        case PE_NONE:
            return "No error";
        case PE_INVALID:
            return "Invalid character(s) in input";
        case PE_NUMERICRANGE:
            return "Number is out of range";
        default:
            return "Unknown error"; // Handle invalid enum value (possible through casting).
    };
}
#endif /* __NAMESPACE_INPUT__ */
