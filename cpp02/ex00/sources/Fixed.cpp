#include "../includes/Fixed.hpp"

Fixed::Fixed() //default constructor
{
	std::cout << "Default constructor called." << std::endl;
	this->_value = 0;
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
		this->_value = other.getRawBits();
	}
	return (*this); //Required for chaining
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