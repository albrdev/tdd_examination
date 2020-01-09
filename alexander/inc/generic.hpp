/*! generic.hpp
    Contains generic string and input helper functions.
    \file   generic.hpp
    \author albrdev (albrdev@gmail.com)
    \date   2020-01-08
*/

#ifndef __GENERIC_HPP__
#define __GENERIC_HPP__

#include <string>
#include <iostream>

namespace string
{
    /*! compareIgnoreCase()
        Compares two strings, ignoring letter case.
        \fn compareIgnoreCase()
        \param[in]  a   First string.
        \param[in]  b   Second string.
        \return         0 if both string are case-insensitively equal, otherwise a value other than 0 is returned. A number greater than 0 if string 'a' is considered greater than 'b'. A value less than 0 if string 'a' is considered less than 'b'. These are based on length- or character difference.
    */
    int compareIgnoreCase(const std::string& a, const std::string& b);

    /*! trimWhitespace()
        Strips away any whitespace characters in front and end of a string.
        \fn trimWhitespace()
        \param[in]  str The string that is to be trimmed.
        \return         A new string instance that does not contain any whitespaces in the very front or end.
    */
    std::string trimWhitespace(const std::string& str);
}

namespace input
{
     /*! \enum parseerror_t
         Enum constants containing error codes for string parsing.
     */
    typedef enum
    {
        PE_NONE         = 0,    /*!< No error has occured. */
        PE_INVALID      = -1,   /*!< Invalid character(s) in input. */
        PE_NUMERICRANGE = 1     /*!< Number is out of range of a given type. */
    } parseerror_t;

    /*! parseDouble()
        Converts a numeric string to a double and extracts any trailing non-floating-point characters.
        \fn parseDouble()
        \param[in]  str         The string that is to be converted.
        \param[out] result      The resulting value.
        \param[out] remaining   The remaining non-floating-point characters at the end of the string.
        \return                 'PE_NONE' on success. 'PE_INVALID' if string conatins invalid character(s) in front or middle of a presumed number (invalid characters at the end is not taken into account). 'PE_NUMERICRANGE' if the number is out of range of the given numeric type. If a value other then 'PE_NONE' is returned, neither 'result' nor 'remaining' is altered.
    */
    input::parseerror_t parseDouble(const std::string& str, double& result, std::string& remaining);

    /*! parsePrefixedDouble()
        Converts a numeric string to a double and applies any given numeric SI-prefix that follows it.
        \fn parsePrefixedDouble()
        \param[in]  str     The string that is to be converted.
        \param[out] result  The resulting value, with prefixes applied.
        \return             'PE_NONE' on success. 'PE_INVALID' if string conatins invalid character(s) in front, middle or end of a presumed number (prefix characters at the end is not taken into account). 'PE_NUMERICRANGE' if the number is out of range of the given numeric type. If a value other then 'PE_NONE' is returned, 'result' is not altered.
    */
    input::parseerror_t parsePrefixedDouble(const std::string& str, double& result);

    /*! getErrorMessage()
        Translates a given error code to a human readable string.
        \fn getErrorMessage()
        \param[in]  id  The error code.
        \return         An error message describing the given error code or a message stating that the error code is invalid.
    */
    std::string getErrorMessage(const input::parseerror_t id);
}

#endif /* __GENERIC_HPP__ */
