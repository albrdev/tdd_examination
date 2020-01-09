#include "unity.h"
#include "unity_fixture.h"
#include "generic.hpp"
#include <string>

static double result;

TEST_GROUP(NamespaceInput);

TEST_SETUP(NamespaceInput)
{
    result = 0.0;
}

TEST_TEAR_DOWN(NamespaceInput)
{
}

TEST(NamespaceInput, ParseDouble)
{
    std::string remaining;

    // Test random valid numeric strings.
    TEST_ASSERT_EQUAL(input::PE_NONE, input::parseDouble("10", result, remaining));
    TEST_ASSERT_EQUAL_DOUBLE(10.0, result);
    TEST_ASSERT_EQUAL(input::PE_NONE, input::parseDouble("10.0", result, remaining));
    TEST_ASSERT_EQUAL_DOUBLE(10.0, result);
    TEST_ASSERT_EQUAL(input::PE_NONE, input::parseDouble("123.456", result, remaining));
    TEST_ASSERT_EQUAL_DOUBLE(123.456, result);
    TEST_ASSERT_EQUAL(input::PE_NONE, input::parseDouble("0.000001", result, remaining));
    TEST_ASSERT_EQUAL_DOUBLE(0.000001, result);
    TEST_ASSERT_EQUAL(input::PE_NONE, input::parseDouble("999.999", result, remaining));
    TEST_ASSERT_EQUAL_DOUBLE(999.999, result);
    TEST_ASSERT_EQUAL(input::PE_NONE, input::parseDouble(".1", result, remaining));
    TEST_ASSERT_EQUAL_DOUBLE(0.1, result);
    TEST_ASSERT_EQUAL(input::PE_NONE, input::parseDouble("1.", result, remaining));
    TEST_ASSERT_EQUAL_DOUBLE(1.0, result);
    TEST_ASSERT_EQUAL(input::PE_NONE, input::parseDouble(" 1", result, remaining));
    TEST_ASSERT_EQUAL_DOUBLE(1.0, result);
    TEST_ASSERT_EQUAL(input::PE_NONE, input::parseDouble(" 1", result, remaining));
    TEST_ASSERT_EQUAL_DOUBLE(1.0, result);
    TEST_ASSERT_EQUAL(input::PE_NONE, input::parseDouble(" 1 ", result, remaining));
    TEST_ASSERT_EQUAL_DOUBLE(1.0, result);

    // Test random out-of-range numeric strings.
    std::string oorValue1(500, '9');
    std::string oorValue2 = "-" + oorValue1;

    TEST_ASSERT_EQUAL(input::PE_NUMERICRANGE, input::parseDouble(oorValue1, result, remaining));
    TEST_ASSERT_EQUAL(input::PE_NUMERICRANGE, input::parseDouble(oorValue2, result, remaining));

    // Test random numeric strings and capture remaining characters.
    TEST_ASSERT_EQUAL(input::PE_NONE, input::parseDouble("1test", result, remaining));
    TEST_ASSERT_EQUAL_DOUBLE(1.0, result);
    TEST_ASSERT_EQUAL_STRING("test", remaining.c_str());
    TEST_ASSERT_EQUAL(input::PE_NONE, input::parseDouble("1.0test", result, remaining));
    TEST_ASSERT_EQUAL_DOUBLE(1.0, result);
    TEST_ASSERT_EQUAL_STRING("test", remaining.c_str());
    TEST_ASSERT_EQUAL(input::PE_NONE, input::parseDouble("-1test", result, remaining));
    TEST_ASSERT_EQUAL_DOUBLE(-1.0, result);
    TEST_ASSERT_EQUAL_STRING("test", remaining.c_str());
    TEST_ASSERT_EQUAL(input::PE_NONE, input::parseDouble("-1.0test", result, remaining));
    TEST_ASSERT_EQUAL_DOUBLE(-1.0, result);
    TEST_ASSERT_EQUAL_STRING("test", remaining.c_str());

    // Test random invalid (numeric) strings.
    TEST_ASSERT_EQUAL(input::PE_INVALID, input::parseDouble(".", result, remaining));
    TEST_ASSERT_EQUAL(input::PE_INVALID, input::parseDouble("-", result, remaining));
    TEST_ASSERT_EQUAL(input::PE_NONE, input::parseDouble(".1.", result, remaining));
    TEST_ASSERT_EQUAL(input::PE_INVALID, input::parseDouble("t", result, remaining));
    TEST_ASSERT_EQUAL(input::PE_INVALID, input::parseDouble("test", result, remaining));
    TEST_ASSERT_EQUAL(input::PE_INVALID, input::parseDouble("t1", result, remaining));

    // Test empty and whitespace strings.
    TEST_ASSERT_EQUAL(input::PE_INVALID, input::parseDouble(" ", result, remaining));
    TEST_ASSERT_EQUAL(input::PE_INVALID, input::parseDouble("", result, remaining));
}

TEST(NamespaceInput, ParsePrefixedDouble)
{
    // Test prefixed valid numeric strings.
    TEST_ASSERT_EQUAL(input::PE_NONE, input::parsePrefixedDouble("0.1k", result));
    TEST_ASSERT_EQUAL_DOUBLE(100.0, result);
    TEST_ASSERT_EQUAL(input::PE_NONE, input::parsePrefixedDouble("1000d", result));
    TEST_ASSERT_EQUAL_DOUBLE(100.0, result);
    TEST_ASSERT_EQUAL(input::PE_NONE, input::parsePrefixedDouble("1000c", result));
    TEST_ASSERT_EQUAL_DOUBLE(10.0, result);
    TEST_ASSERT_EQUAL(input::PE_NONE, input::parsePrefixedDouble("1000m", result));
    TEST_ASSERT_EQUAL_DOUBLE(1.0, result);
    TEST_ASSERT_EQUAL(input::PE_NONE, input::parsePrefixedDouble("1k", result));
    TEST_ASSERT_EQUAL_DOUBLE(1000.0, result);
    TEST_ASSERT_EQUAL(input::PE_NONE, input::parsePrefixedDouble("10000d", result));
    TEST_ASSERT_EQUAL_DOUBLE(1000.0, result);
    TEST_ASSERT_EQUAL(input::PE_NONE, input::parsePrefixedDouble("100000c", result));
    TEST_ASSERT_EQUAL_DOUBLE(1000.0, result);
    TEST_ASSERT_EQUAL(input::PE_NONE, input::parsePrefixedDouble("1000000m", result));
    TEST_ASSERT_EQUAL_DOUBLE(1000.0, result);

    // Test prefixed random out-of-range numeric strings.
    std::string oorValue1(497, '9');
    oorValue1 += 'k';
    std::string oorValue2 = "-" + oorValue1;

    TEST_ASSERT_EQUAL(input::PE_NUMERICRANGE, input::parsePrefixedDouble(oorValue1, result));
    TEST_ASSERT_EQUAL(input::PE_NUMERICRANGE, input::parsePrefixedDouble(oorValue2, result));

    // Test random invalid (numeric) strings.
    TEST_ASSERT_EQUAL(input::PE_INVALID, input::parsePrefixedDouble(".", result));
    TEST_ASSERT_EQUAL(input::PE_INVALID, input::parsePrefixedDouble("-", result));
    TEST_ASSERT_EQUAL(input::PE_INVALID, input::parsePrefixedDouble(".1.", result));
    TEST_ASSERT_EQUAL(input::PE_INVALID, input::parsePrefixedDouble("t", result));
    TEST_ASSERT_EQUAL(input::PE_INVALID, input::parsePrefixedDouble("test", result));
    TEST_ASSERT_EQUAL(input::PE_INVALID, input::parsePrefixedDouble("1t", result));
    TEST_ASSERT_EQUAL(input::PE_INVALID, input::parsePrefixedDouble("1.0t", result));
    TEST_ASSERT_EQUAL(input::PE_INVALID, input::parsePrefixedDouble("-1t", result));
    TEST_ASSERT_EQUAL(input::PE_INVALID, input::parsePrefixedDouble("-1.0t", result));
    TEST_ASSERT_EQUAL(input::PE_INVALID, input::parsePrefixedDouble("t1", result));

    // Test empty and whitespace strings.
    TEST_ASSERT_EQUAL(input::PE_INVALID, input::parsePrefixedDouble(" ", result));
    TEST_ASSERT_EQUAL(input::PE_INVALID, input::parsePrefixedDouble("", result));
}
