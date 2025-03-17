#include "../includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name")
{
	_name = name;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << _name << " was created!" << std::endl;
}

DiamondTrap::DiamondTrap() : ClapTrap("DiamondTrap_clap_name")
{
	_name = "DiamondTrap";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << _name << " was created!(Default)" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " was destroyed!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
{
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	std::cout << "DiamondTrap " << _name << "'s copy constructor called!" << std::endl;
}
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout << "DiamondTrap " << _name << "'s copy assignment operator called!" << std::endl;
	return *this;
}

void DiamondTrap::attack(std::string target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "My DiamondTrap name is " << _name << std::endl;
	std::cout << "My ClapTrap name is " << ClapTrap::_name << std::endl;
}