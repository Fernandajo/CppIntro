#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;
}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon& hWeapon)
{
	this->_weapon = &hWeapon;
}

void HumanB::attack()
{
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}