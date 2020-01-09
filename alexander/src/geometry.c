#include "geometry.h"
#include <errno.h>

double getRectanglePerimeter(const double x, const double y)
{
    // Check for invalid values and set errno accordingly.
    if (x <= 0.0 || y <= 0.0)
    {
        errno = ERANGE;
        return -1.0;
    }

    return (x * 2.0) + (y * 2.0);
}

double getRectangleArea(const double x, const double y)
{
    // Check for invalid values and set errno accordingly.
    if (x <= 0.0 || y <= 0.0)
    {
        errno = ERANGE;
        return -1.0;
    }

    return x * y;
}

double getCuboidVolume(const double x, const double y, const double z)
{
    // Check for invalid values and set errno accordingly.
    if (x <= 0.0 || y <= 0.0 || z <= 0.0)
    {
        errno = ERANGE;
        return -1.0;
    }

    return x * y * z;
}
