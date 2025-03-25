#include "../includes/Cure.hpp"

// Default constructor
Cure::Cure() : AMateria("cure")
{	std::cout << "Cure constructor called!" << std::endl;
}

// Destructor
Cure::~Cure()
{
	std::cout << "Cure destructor called!" << std::endl;
}

// Copy constructor
Cure::Cure(const Cure &other)
{
	*this = other;
	std::cout << "Cure copy constructor called!" << std::endl;
}


Cure &Cure::operator=(const Cure &other)
{
	if(this != &other)
	{
		_type = other._type;
	}
	return *this;
}

Cure* Cure::clone() const
{
	Cure *ret = new Cure();
	return ret;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}