#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(Calculator)
{
    RUN_TEST_CASE(Calculator, ParseValue);
}
