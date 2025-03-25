#include "../includes/AMateria.hpp"

// Default constructor
AMateria::AMateria() : _type ("Default")
{
	std::cout << "Default constructor of AMateria was called!" << std::endl;
}

// Constructor
AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << "AMateria of type " << _type << " was called!" << std::endl;
}

// Destructor
AMateria::~AMateria()
{
	std::cout << "AMateria of type " << _type << " destructor called!" << std::endl;
}

// Copy constructor
AMateria::AMateria(const AMateria &other)
{
	*this = other;
	std::cout << "AMateria copy constructor called!" << std::endl;
}

// copy assignment operator
AMateria &AMateria::operator=(const AMateria &other)
{
	if(this != &other)
	_type = other._type;
	return *this;
}

std::string const & AMateria::getType() const
{
	return _type;
} //Returns the materia type

void AMateria::use(ICharacter& target)
{
	//will be overriden
}