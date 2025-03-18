#include "../includes/AAnimal.hpp"

AAnimal::AAnimal() : _type("Default")
{
	std::cout << "AAnimal " << _type << " was created!" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal " << _type << " was destroyed!" << std::endl;
}
AAnimal::AAnimal(std::string typeAAnimal) : _type(typeAAnimal)
{
	std::cout << "AAnimal " << _type << " was created!" << std::endl;
}
AAnimal::AAnimal(const AAnimal &other)
{
	_type = other._type;
	std::cout << "AAnimal " << _type << "'s copy constructor was called!" << std::endl;
}
AAnimal &AAnimal::operator=(const AAnimal &other)
{
	if(this != &other)
		_type = other._type;
	std::cout << "AAnimal " << _type << "'s copy operator was called!" << std::endl;
	return *this;
}

std::string AAnimal::getType(void) const { return _type; }
