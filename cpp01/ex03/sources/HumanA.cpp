#include "../includes/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {}

HumanA::~HumanA() {}

void HumanA::attack( void ) const
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}

void HumanA::setWeapon(Weapon& hWeapon)
{
	this->_weapon = hWeapon;
}