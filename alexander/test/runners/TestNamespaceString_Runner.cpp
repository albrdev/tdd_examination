#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(NamespaceString)
{
    RUN_TEST_CASE(NamespaceString, CompareIgnoreCase);
    RUN_TEST_CASE(NamespaceString, TrimWhitespace);
}
