#include <position.h>
#include <cmath>

position_t deg2rad(const position_t & p)
{
	position_t res;
	res.lat = M_PI / 180.0 * p.lat;
	res.lon = M_PI / 180.0 * p.lon;
	return res;
}

position_t rad2deg(const position_t & p)
{
	position_t res;
	res.lat = p.lat / M_PI * 180.0;
	res.lon = p.lon / M_PI * 180.0;
	return res;
}

