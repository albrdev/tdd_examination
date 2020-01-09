/*! geometry.hpp
    Contains functions for geometry calculations.
    \file   geometry.hpp
    \author albrdev (albrdev@gmail.com)
    \date   2020-01-08
*/

#ifndef __GEOMETRY_H__
#define __GEOMETRY_H__

#ifdef __cplusplus
extern "C"
{
#endif

/*! getRectanglePerimeter()
    Calculates the perimeter for a rectangle given the length and height.
    \fn getRectanglePerimeter()
    \param[in]  x   Length.
    \param[in]  y   Height.
    \return         The perimeter based on the input values.
*/
double getRectanglePerimeter(const double x, const double y);

/*! getRectangleArea()
    Calculates the area for a rectangle given the length and height.
    \fn getRectangleArea()
    \param[in]  x   Length.
    \param[in]  y   Height.
    \return         The area based on the input values.
*/
double getRectangleArea(const double x, const double y);

/*! getCuboidVolume()
    Calculates the volume for a cuboid given the length, width and height.
    \fn getCuboidVolume()
    \param[in]  x   Length.
    \param[in]  y   Width.
    \param[in]  z   Height.
    \return         The volume based on the input values.
*/
double getCuboidVolume(const double x, const double y, const double z);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __GEOMETRY_H__ */
