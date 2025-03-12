#include "../includes/Point.hpp"

static Fixed sign(Point p1, Point p2, Point p3)
{
    return ((p1.getFixedX() - p3.getFixedX()) * (p2.getFixedY() - p3.getFixedY()) - (p2.getFixedX() - p3.getFixedX()) * (p1.getFixedY() - p3.getFixedY()));
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed den = sign(b,c,a);
	Fixed d1 = sign(b,c,point);
	Fixed d2 = sign(c,a,point);

	d1 = d1 / den;
	d2 = d2 / den;
	Fixed d3 = Fixed(1) - d1 - d2;
	if (d1 > Fixed(0) && d1 < Fixed(1) && d2 > Fixed(0) && d2 < Fixed(1) && d3 > Fixed(0) && d3 < Fixed(1))
		return true;
	else
		return false;
}