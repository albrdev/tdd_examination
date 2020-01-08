#include "unity.h"
#include "unity_fixture.h"
#include "geometry.h"
#include <errno.h>

TEST_GROUP(Geometry);

TEST_SETUP(Geometry)
{
    errno = 0;
}

TEST_TEAR_DOWN(Geometry)
{
}

TEST(Geometry, Perimeter)
{
    // Test random valid numbers.
    TEST_ASSERT_EQUAL_DOUBLE(40.0, getRectanglePerimeter(10.0, 10.0));
    TEST_ASSERT_EQUAL_DOUBLE(498.0, getRectanglePerimeter(150.5, 98.5));
    TEST_ASSERT_EQUAL_DOUBLE(22.74, getRectanglePerimeter(3.54, 7.83));
    TEST_ASSERT_EQUAL_DOUBLE(5350000.7, getRectanglePerimeter(2500000.1, 175000.25));
    TEST_ASSERT_EQUAL_DOUBLE(1.0, getRectanglePerimeter(1.0 / 3.0, 1.0 / 6.0));
    TEST_ASSERT_EQUAL_DOUBLE(0.0002004, getRectanglePerimeter(0.0001, 0.0000002));

    // Test negative numbers.
    TEST_ASSERT_EQUAL_DOUBLE(-1.0, getRectanglePerimeter(-10.0, 10.0));
    TEST_ASSERT_TRUE(errno == ERANGE);
    TEST_ASSERT_EQUAL_DOUBLE(-1.0, getRectanglePerimeter(10.0, -10.0));
    TEST_ASSERT_TRUE(errno == ERANGE);
    TEST_ASSERT_EQUAL_DOUBLE(-1.0, getRectanglePerimeter(-10.0, -10.0));
    TEST_ASSERT_TRUE(errno == ERANGE);

    // Test zero.
    TEST_ASSERT_EQUAL_DOUBLE(-1.0, getRectanglePerimeter(0.0, 0.0));
    TEST_ASSERT_TRUE(errno == ERANGE);
}

TEST(Geometry, Area)
{
    // Test random valid numbers.
    TEST_ASSERT_EQUAL_DOUBLE(100.0, getRectangleArea(10.0, 10.0));
    TEST_ASSERT_EQUAL_DOUBLE(14824.25, getRectangleArea(150.5, 98.5));
    TEST_ASSERT_EQUAL_DOUBLE(27.7182, getRectangleArea(3.54, 7.83));
    TEST_ASSERT_EQUAL_DOUBLE(437500642500.0, getRectangleArea(2500000.1, 175000.25));
    TEST_ASSERT_EQUAL_DOUBLE(1.0, getRectangleArea(1.0 / 3.0, 3.0));
    TEST_ASSERT_EQUAL_DOUBLE(0.00000000002, getRectangleArea(0.0001, 0.0000002));

    // Test negative numbers.
    TEST_ASSERT_EQUAL_DOUBLE(-1.0, getRectangleArea(-10.0, 10.0));
    TEST_ASSERT_TRUE(errno == ERANGE);
    TEST_ASSERT_EQUAL_DOUBLE(-1.0, getRectangleArea(10.0, -10.0));
    TEST_ASSERT_TRUE(errno == ERANGE);
    TEST_ASSERT_EQUAL_DOUBLE(-1.0, getRectangleArea(-10.0, -10.0));
    TEST_ASSERT_TRUE(errno == ERANGE);

    // Test zero.
    TEST_ASSERT_EQUAL_DOUBLE(-1.0, getRectanglePerimeter(0.0, 0.0));
    TEST_ASSERT_TRUE(errno == ERANGE);
}

TEST(Geometry, Volume)
{
    // Test random valid numbers.
    TEST_ASSERT_EQUAL_DOUBLE(1000.0, getCuboidVolume(10.0, 10.0, 10.0));
    TEST_ASSERT_EQUAL_DOUBLE(529225.725, getCuboidVolume(150.5, 98.5, 35.7));
    TEST_ASSERT_EQUAL_DOUBLE(64.306224, getCuboidVolume(3.54, 7.83, 2.32));
    TEST_ASSERT_EQUAL_DOUBLE(5468911156475187.50875, getCuboidVolume(2500000.1, 175000.25, 12500.35));
    TEST_ASSERT_EQUAL_DOUBLE(0.015625, getCuboidVolume(1.0 / 2.0, 1.0 / 4.0, 1.0 / 8.0));
    TEST_ASSERT_EQUAL_DOUBLE(0.0000000000006, getCuboidVolume(0.0001, 0.0000002, 0.03));

    // Test negative numbers.
    TEST_ASSERT_EQUAL_DOUBLE(-1.0, getCuboidVolume(-10.0, 10.0, 10.0));
    TEST_ASSERT_TRUE(errno == ERANGE);
    TEST_ASSERT_EQUAL_DOUBLE(-1.0, getCuboidVolume(10.0, -10.0, 10.0));
    TEST_ASSERT_TRUE(errno == ERANGE);
    TEST_ASSERT_EQUAL_DOUBLE(-1.0, getCuboidVolume(10.0, 10.0, -10.0));
    TEST_ASSERT_TRUE(errno == ERANGE);
    TEST_ASSERT_EQUAL_DOUBLE(-1.0, getCuboidVolume(-10.0, -10.0, -10.0));
    TEST_ASSERT_TRUE(errno == ERANGE);

    // Test zero.
    TEST_ASSERT_EQUAL_DOUBLE(-1.0, getCuboidVolume(0.0, 0.0, 0.0));
    TEST_ASSERT_TRUE(errno == ERANGE);
}
