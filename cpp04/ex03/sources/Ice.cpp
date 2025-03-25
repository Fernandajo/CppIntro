#include "../includes/Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice constructor was called!" << std::endl;
}
Ice::Ice(const Ice &other)
{
	AMateria::
}

Ice &Ice::operator=(const Ice &other)
{
	if(this != &other)
	{
		_type = other._type;
	}
	return *this;
}

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