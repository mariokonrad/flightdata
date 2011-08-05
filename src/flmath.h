#ifndef __FLMATH__H__
#define __FLMATH__H__

#include <position.h>

double central_spherical_angle(const position_t &, const position_t &);
double distance_sphere(const position_t &, const position_t &);
double distance_ellipsoid_vincenty(const position_t &, const position_t &, double &, double &);
position_t point_ellipsoid_vincenty(const position_t &, double, double, double &);
double distance_ellipsoid_lambert(const position_t &, const position_t &);

#endif
