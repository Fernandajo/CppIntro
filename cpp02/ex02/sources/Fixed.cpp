#include "../includes/Fixed.hpp"

Fixed::Fixed() //default constructor
{
	std::cout << "Default constructor called." << std::endl;
	this->_value = 0;
}

Fixed::Fixed(const int intValue) : _value(intValue << _bits) // constructor that converts the int to fixed-point
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatValue)// constructor that converts the float to fixed-point
{
	_value = (int)(roundf(floatValue * (1 << _bits)));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) //Copy constructor
{
	std::cout << "Copy constructor called." << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed& other) //copy assignment operator overload
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_value = other._value;
	}
	return (*this); //Required for chaining
}

std::ostream	&operator<<(std::ostream &out, const Fixed& other)
{
	out << other.toFloat();
	return (out);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(this->_value);
}

void Fixed::setRawBits( int const raw )
{
	this->_value = raw;
}

float	Fixed::toFloat( void ) const
{
	return ((float)_value / (1 << _bits));
}

int	Fixed::toInt( void ) const
{
	return (_value >> _bits);
}
