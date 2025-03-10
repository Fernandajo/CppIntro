#include "../includes/Point.hpp"

Point::Point() : x(0), y(0)
{}
Point::Point(float _x, float _y) : x(_x), y(_y)
{}
//copy constructor
Point::Point(const Point& other)
{
	*this = other;
}
Point &Point::operator=(const Point& other) //copy assignment operator overload
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		*this = other;
	}
	return (*this); //Required for chaining
}
Point::~Point()
{}

int	Point::getRawValueX()
{
	return x.getRawBits();
}

int	Point::getRawValueY()
{
	return y.getRawBits();
}

float	Point::getFloatValueX()
{
	return x.toFloat();
}

float	Point::getFloatValueY()
{
	return x.toFloat();
}
