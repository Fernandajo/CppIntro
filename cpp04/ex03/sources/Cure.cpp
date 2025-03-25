#include "../includes/Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::~Cure()
{
}

Cure::Cure(const Cure &other)
{
	*this = other;
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