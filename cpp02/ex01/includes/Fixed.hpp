#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string.h>

class Fixed
{
private:
	int	_value;
	static const int _bits = 8;
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed& other);
	Fixed(const int intValue);
	Fixed(const float floatValue);
	Fixed &operator=(const Fixed& other);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};


#endif