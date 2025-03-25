#include "../includes/AMateria.hpp"

AMateria::AMateria() : _type ("Default")
{
}

AMateria::AMateria(std::string const & type) : _type(type)
{
}

AMateria::~AMateria()
{
}
AMateria::AMateria(const AMateria &other)
{
	_type = other._type;
}

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