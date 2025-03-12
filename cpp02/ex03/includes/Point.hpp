#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	const Fixed x;
	const Fixed y;

public:
	Point();
	Point(const Fixed& _x, const Fixed& _y);
	Point(const Point& other);
	~Point();
	Point &operator=(const Point& other);
	int	getRawValueX();
	int	getRawValueY();
	float	getFloatValueX();
	float	getFloatValueY();
	Fixed	getFixedX() const;
	Fixed	getFixedY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);


#endif