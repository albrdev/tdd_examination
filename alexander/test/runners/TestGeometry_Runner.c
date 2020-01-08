#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(Geometry)
{
    RUN_TEST_CASE(Geometry, Perimeter);
    RUN_TEST_CASE(Geometry, Area);
    RUN_TEST_CASE(Geometry, Volume);
}
