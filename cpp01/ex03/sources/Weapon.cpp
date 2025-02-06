#include "../includes/Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->_type = type;
}

Weapon::Weapon() {}

Weapon::~Weapon() {}

void	Weapon::setType(const std::string &type)
{
	this->_type = type;
}

const std::string	&Weapon::getType() const
{
	return (this->_type);
}