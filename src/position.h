#ifndef __POSITION__H__
#define __POSITION__H__

struct position_t
{
	double lat;
	double lon;
};

position_t deg2rad(const position_t &);
position_t rad2deg(const position_t &);

#endif
