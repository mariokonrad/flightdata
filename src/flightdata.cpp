#include <cstdio>
#include <flmath.h>
#include <vector>

static void print(const position_t & p)
{
	printf("{%g, %g}", p.lat, p.lon);
}

int main(int, char **)
{
	position_t BNA = { 36.12,  -86.67 };
	position_t LAX = { 33.94, -118.40 };
	double alpha1 = 0.0;
	double alpha2 = 0.0;
	double s;

	printf("BNA={%g, %g}\n", BNA.lat, BNA.lon);
	printf("LAX={%g, %g}\n", LAX.lat, LAX.lon);

	printf("\n");

	BNA = deg2rad(BNA);
	LAX = deg2rad(LAX);

	s = distance_sphere(BNA, LAX);
	printf("spherical dist          (BNA-LAX): %10.20g m (must be: 2889615.861940 m)\n", s);
	s = distance_ellipsoid_vincenty(BNA, LAX, alpha1, alpha2);
	printf("ellipsoid dist vincenty (BNA-LAX): %10.20g m (approx : 2892777.000000 m, exact: 2892777.232346 m)\n", s);
	s = distance_ellipsoid_lambert(BNA, LAX);
	printf("ellipsoid dist lambert  (BNA-LAX): %10.20g m (approx : 2892777.000000 m)\n", s);

	printf("\n");

	alpha1 = 0.0;
	alpha2 = 0.0;
	s = distance_ellipsoid_vincenty(BNA, LAX, alpha1, alpha2);

	printf("s=%10.20g m\n", s);
	printf("alpha1=%g\n", alpha1);
	printf("alpha2=%g\n", alpha2);
	printf("\n");

	alpha2 = 0.0;
	position_t pos_LAX = point_ellipsoid_vincenty(BNA, s, alpha1, alpha2);
	pos_LAX = rad2deg(pos_LAX);
	printf("pos_LAX={%g, %g}\n", pos_LAX.lat, pos_LAX.lon);
	printf("alpha2=%g\n", alpha2);

	printf("\n");
	std::vector<position_t> pos;
	int N = 40;
	for (int i = 0; i < N; ++i) {
		position_t p = point_ellipsoid_vincenty(BNA, (s / (N - 1)) * i, alpha1, alpha2);
		pos.push_back(rad2deg(p));
	}
	for (std::vector<position_t>::const_iterator i = pos.begin(); i < pos.end(); ++i) {
		print(*i);
		printf("\n");
	}
	printf("\n");

	return 0;
}

