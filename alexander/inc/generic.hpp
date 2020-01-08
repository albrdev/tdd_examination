#ifndef __GENERIC_HPP__
#define __GENERIC_HPP__

#include <string>
#include <iostream>

namespace string
{
    int compareIgnoreCase(const std::string& a, const std::string& b);
    std::string trimWhitespace(const std::string& str);
}

namespace input
{
    typedef enum
    {
        PE_NONE = 0,
        PE_INVALID = -1,
        PE_NUMERICRANGE = 1
    } parseerror_t;

    input::parseerror_t parseInt(const std::string& str, int& result);
    input::parseerror_t parseDouble(const std::string& str, double& result, std::string& remaining);
    input::parseerror_t parsePrefixedDouble(const std::string& str, double& result);

    bool readString(std::string& result);
    input::parseerror_t readPrefixedDouble(double& result, const double min, const double max);

    std::string getParseErrorMessage(const input::parseerror_t id);
}

#endif /* __GENERIC_HPP__ */
