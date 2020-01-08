#include "geometry.h"

double getRectanglePerimeter(const double x, const double y)
{
    return (x * 2.0) + (y * 2.0);
}

double getRectangleArea(const double x, const double y)
{
    return x * y;
}

double getCuboidVolume(const double x, const double y, const double z)
{
    return x * y * z;
}
