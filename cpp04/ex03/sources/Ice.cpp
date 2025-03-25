#include "../includes/Ice.hpp"

// Default constructor
Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice constructor was called!" << std::endl;
}

// Copy constructor
Ice::Ice(const Ice &other)
{
	*this = other;
	std::cout << "Ice copy constructor called!" << std::endl;
}

// Copy assignment operator
Ice &Ice::operator=(const Ice &other)
{
	if(this != &other)
	{
		_type = other._type;
	}
	return *this;
}

// Destructor
Ice::~Ice()
{
	std::cout << "Ice destructor was called!" << std::endl;
}

Ice* Ice::clone() const
{
	Ice *ret = new Ice();
	return ret;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}