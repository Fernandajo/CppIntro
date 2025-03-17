#include "../includes/Fixed.hpp"

Fixed::Fixed() //default constructor
{
	// std::cout << "Default constructor called." << std::endl;
	this->_value = 0;
}

Fixed::Fixed(const int intValue) : _value(intValue << _bits) // constructor that converts the int to fixed-point
{
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatValue)// constructor that converts the float to fixed-point
{
	_value = (int)(roundf(floatValue * (1 << _bits)));
	// std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) //Copy constructor
{
	// std::cout << "Copy constructor called." << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed& other) //copy assignment operator overload
{
	// std::cout << "Copy assignment operator called" << std::endl;
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

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed ret(toFloat() + other.toFloat());
	return ret;
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed ret(toFloat() - other.toFloat());
	return ret;
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed ret(toFloat() * other.toFloat());
	return ret;
}

Fixed Fixed::operator/(const Fixed& other) const
{
	if (other.toInt() == 0)
		return 0;
	Fixed ret(toFloat() / other.toFloat());
	return ret;
}

// prefix increment
Fixed &Fixed::operator++()
{
	_value++;
	return (*this);
}

//posfixed increment
Fixed Fixed::operator++(int){
	Fixed old = *this;
	operator++();
	return old;
}

Fixed &Fixed::operator--()
{
	_value--;
	return (*this);
}

Fixed Fixed::operator--(int){
	Fixed old = *this;
	operator--();
	return old;
}

bool Fixed::operator<(const Fixed& other) const
{
	return (_value < other._value);
}

bool Fixed::operator>(const Fixed& other) const
{
	return (_value > other._value);
}

bool Fixed::operator>=(const Fixed& other) const
{
	return !(_value < other._value);
}

bool Fixed::operator<=(const Fixed& other) const
{
	return !(_value > other._value);
}

bool Fixed::operator==(const Fixed& other) const
{
	return (_value == other._value);
}

bool Fixed::operator!=(const Fixed& other) const
{
	return !(_value == other._value);
}

Fixed &Fixed::min(Fixed& lhs, Fixed& rhs)
{
	if((lhs < rhs) == true)
		return (lhs);
	else
		return rhs;
}
const Fixed &Fixed::min(const Fixed& lhs, const Fixed& rhs)
{
	if((lhs < rhs) == true)
		return (lhs);
	else
		return rhs;
}
Fixed &Fixed::max(Fixed& lhs, Fixed& rhs)
{
	if((lhs > rhs) == true)
		return (lhs);
	else
		return rhs;
}
const Fixed &Fixed::max(const Fixed& lhs, const Fixed& rhs)
{
	if((lhs > rhs) == true)
		return (lhs);
	else
		return rhs;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called" << std::endl;
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
