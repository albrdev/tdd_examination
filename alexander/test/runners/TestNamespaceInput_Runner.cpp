#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(NamespaceInput)
{
    RUN_TEST_CASE(NamespaceInput, ParseDouble);
    RUN_TEST_CASE(NamespaceInput, ParsePrefixedDouble);
}
