#include "unity.h"
#include "unity_fixture.h"
#include "calculator.hpp"

extern double INPUTVALUE_MIN;
extern double INPUTVALUE_MAX;

TEST_GROUP(Calculator);

TEST_SETUP(Calculator)
{
}

TEST_TEAR_DOWN(Calculator)
{
}

TEST(Calculator, ParseValue)
{
    double result;

    // Test random valid numeric strings.
    TEST_ASSERT_EQUAL(input::PE_NONE, parseValue("10", result));
    TEST_ASSERT_EQUAL_DOUBLE(10.0, result);
    TEST_ASSERT_EQUAL(input::PE_NONE, parseValue("10.0", result));
    TEST_ASSERT_EQUAL_DOUBLE(10.0, result);
    TEST_ASSERT_EQUAL(input::PE_NONE, parseValue("123.456", result));
    TEST_ASSERT_EQUAL_DOUBLE(123.456, result);
    TEST_ASSERT_EQUAL(input::PE_NONE, parseValue("1", result));
    TEST_ASSERT_EQUAL_DOUBLE(INPUTVALUE_MIN + 1.0, result);
    TEST_ASSERT_EQUAL(input::PE_NONE, parseValue("999", result));
    TEST_ASSERT_EQUAL_DOUBLE(INPUTVALUE_MAX - 1.0, result);
    TEST_ASSERT_EQUAL(input::PE_NONE, parseValue("0.000001", result));
    TEST_ASSERT_EQUAL_DOUBLE(0.000001, result);
    TEST_ASSERT_EQUAL(input::PE_NONE, parseValue("999.999", result));
    TEST_ASSERT_EQUAL_DOUBLE(999.999, result);
    TEST_ASSERT_EQUAL(input::PE_NONE, parseValue(".1", result));
    TEST_ASSERT_EQUAL_DOUBLE(0.1, result);
    TEST_ASSERT_EQUAL(input::PE_NONE, parseValue("1.", result));
    TEST_ASSERT_EQUAL_DOUBLE(1.0, result);
    TEST_ASSERT_EQUAL(input::PE_NONE, parseValue(" 1", result));
    TEST_ASSERT_EQUAL_DOUBLE(1.0, result);
    TEST_ASSERT_EQUAL(input::PE_NONE, parseValue(" 1", result));
    TEST_ASSERT_EQUAL_DOUBLE(1.0, result);

    // Test prefixed valid numeric strings.
    TEST_ASSERT_EQUAL(input::PE_NONE, parseValue("0.1k", result));
    TEST_ASSERT_EQUAL_DOUBLE(100.0, result);
    TEST_ASSERT_EQUAL(input::PE_NONE, parseValue("1000d", result));
    TEST_ASSERT_EQUAL_DOUBLE(100.0, result);
    TEST_ASSERT_EQUAL(input::PE_NONE, parseValue("1000c", result));
    TEST_ASSERT_EQUAL_DOUBLE(10.0, result);
    TEST_ASSERT_EQUAL(input::PE_NONE, parseValue("1000m", result));
    TEST_ASSERT_EQUAL_DOUBLE(1.0, result);

    // Test random out-of-range numeric strings.
    TEST_ASSERT_EQUAL(input::PE_NUMERICRANGE, parseValue("1000", result));
    TEST_ASSERT_EQUAL(input::PE_NUMERICRANGE, parseValue("12345.12345", result));
    TEST_ASSERT_EQUAL(input::PE_NUMERICRANGE, parseValue("-10", result));
    TEST_ASSERT_EQUAL(input::PE_NUMERICRANGE, parseValue("-10.0", result));
    TEST_ASSERT_EQUAL(input::PE_NUMERICRANGE, parseValue("0", result));
    TEST_ASSERT_EQUAL(input::PE_NUMERICRANGE, parseValue("0.0", result));
    TEST_ASSERT_EQUAL(input::PE_NUMERICRANGE, parseValue("-0", result));
    TEST_ASSERT_EQUAL(input::PE_NUMERICRANGE, parseValue("-0.0", result));
    TEST_ASSERT_EQUAL(input::PE_NUMERICRANGE, parseValue("-.1", result));

    // Test prefixed out-of-range numeric strings.
    TEST_ASSERT_EQUAL(input::PE_NUMERICRANGE, parseValue("1k", result));
    TEST_ASSERT_EQUAL(input::PE_NUMERICRANGE, parseValue("10000d", result));
    TEST_ASSERT_EQUAL(input::PE_NUMERICRANGE, parseValue("100000c", result));
    TEST_ASSERT_EQUAL(input::PE_NUMERICRANGE, parseValue("1000000m", result));

    // Test random invalid (numeric) strings.
    TEST_ASSERT_EQUAL(input::PE_INVALID, parseValue(".", result));
    TEST_ASSERT_EQUAL(input::PE_INVALID, parseValue("-", result));
    TEST_ASSERT_EQUAL(input::PE_INVALID, parseValue(".1.", result));
    TEST_ASSERT_EQUAL(input::PE_INVALID, parseValue("t", result));
    TEST_ASSERT_EQUAL(input::PE_INVALID, parseValue("test", result));
    TEST_ASSERT_EQUAL(input::PE_INVALID, parseValue("1t", result));
    TEST_ASSERT_EQUAL(input::PE_INVALID, parseValue("1.0t", result));
    TEST_ASSERT_EQUAL(input::PE_INVALID, parseValue("-1t", result));
    TEST_ASSERT_EQUAL(input::PE_INVALID, parseValue("-1.0t", result));
    TEST_ASSERT_EQUAL(input::PE_INVALID, parseValue("t1", result));
    TEST_ASSERT_EQUAL(input::PE_INVALID, parseValue(" 1 ", result));

    // Test empty and whitespace strings.
    TEST_ASSERT_EQUAL(input::PE_INVALID, parseValue(" ", result));
    TEST_ASSERT_EQUAL(input::PE_INVALID, parseValue("", result));
}
