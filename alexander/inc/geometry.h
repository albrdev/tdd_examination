#ifndef __GEOMETRY_H__
#define __GEOMETRY_H__

#ifdef __cplusplus
extern "C"
{
#endif

double getSquarePerimiter(const double x, const double y);
double getSquareArea(const double x, const double y);
double getCuboidVolume(const double x, const double y, const double z);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __GEOMETRY_H__ */
