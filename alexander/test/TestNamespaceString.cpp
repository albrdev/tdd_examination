#include "unity.h"
#include "unity_fixture.h"
#include "generic.hpp"

TEST_GROUP(NamespaceString);

TEST_SETUP(NamespaceString)
{
}

TEST_TEAR_DOWN(NamespaceString)
{
}

TEST(NamespaceString, CompareIgnoreCase)
{
    // Test identical strings.
    TEST_ASSERT_EQUAL(0, string::compareIgnoreCase("test", "test"));
    TEST_ASSERT_EQUAL(0, string::compareIgnoreCase("Test", "Test"));
    TEST_ASSERT_EQUAL(0, string::compareIgnoreCase("TEST", "TEST"));

    // Test strings with case difference.
    TEST_ASSERT_EQUAL(0, string::compareIgnoreCase("test", "Test"));
    TEST_ASSERT_EQUAL(0, string::compareIgnoreCase("Test", "test"));
    TEST_ASSERT_EQUAL(0, string::compareIgnoreCase("Test", "tesT"));
    TEST_ASSERT_EQUAL(0, string::compareIgnoreCase("TEST", "TeST"));
    TEST_ASSERT_EQUAL(0, string::compareIgnoreCase("TeSt", "tEsT"));

    // Test different strings of equal length.
    TEST_ASSERT_GREATER_THAN(0, string::compareIgnoreCase("test", "sest"));
    TEST_ASSERT_LESS_THAN(0, string::compareIgnoreCase("sest", "test"));
    TEST_ASSERT_GREATER_THAN(0, string::compareIgnoreCase("test", "Sest"));
    TEST_ASSERT_LESS_THAN(0, string::compareIgnoreCase("Sest", "test"));

    // Test strings of different length.
    TEST_ASSERT_GREATER_THAN(0, string::compareIgnoreCase("test", "tes"));
    TEST_ASSERT_LESS_THAN(0, string::compareIgnoreCase("tes", "test"));
    TEST_ASSERT_GREATER_THAN(0, string::compareIgnoreCase("test", "Tes"));
    TEST_ASSERT_LESS_THAN(0, string::compareIgnoreCase("Tes", "test"));

    // Test empty strings.
    TEST_ASSERT_GREATER_THAN(0, string::compareIgnoreCase("test", ""));
    TEST_ASSERT_LESS_THAN(0, string::compareIgnoreCase("", "test"));
    TEST_ASSERT_EQUAL(0, string::compareIgnoreCase("", ""));
}

TEST(NamespaceString, TrimWhitespace)
{
    TEST_ASSERT_EQUAL_STRING("test", string::trimWhitespace("test").c_str());

    // Test spaces at begingin and end.
    TEST_ASSERT_EQUAL_STRING("test", string::trimWhitespace(" test").c_str());
    TEST_ASSERT_EQUAL_STRING("test", string::trimWhitespace("test ").c_str());
    TEST_ASSERT_EQUAL_STRING("test", string::trimWhitespace(" test ").c_str());
    TEST_ASSERT_EQUAL_STRING("t", string::trimWhitespace(" t").c_str());
    TEST_ASSERT_EQUAL_STRING("t", string::trimWhitespace("t ").c_str());

    // Test spaces in-between.
    TEST_ASSERT_EQUAL_STRING("t e s t", string::trimWhitespace("t e s t").c_str());
    TEST_ASSERT_EQUAL_STRING("t e s t", string::trimWhitespace(" t e s t ").c_str());

    // Test other whitespace characters.
    TEST_ASSERT_EQUAL_STRING("test", string::trimWhitespace(" \t\v\n\r\ftest \t\v\n\r\f").c_str());
    TEST_ASSERT_EQUAL_STRING("te \t\v\n\r\fst", string::trimWhitespace(" \t\v\n\r\fte \t\v\n\r\fst \t\v\n\r\f").c_str());

    // Test whitespace only.
    TEST_ASSERT_EQUAL_STRING("", string::trimWhitespace(" \t\v\n\r\f").c_str());

    // Test empty string.
    TEST_ASSERT_EQUAL_STRING("", string::trimWhitespace("").c_str());
}
