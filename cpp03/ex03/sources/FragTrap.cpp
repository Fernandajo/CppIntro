#include "../includes/FragTrap.hpp"

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " was created!" << std::endl;
}
FragTrap::FragTrap() : ClapTrap("FragTrap")
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " was created! (Default)" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " was destroyed!" << std::endl;
}
FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout << "FragTrap " << _name << "'s copy assignment operator called!" << std::endl;
	return *this;
}

FragTrap::FragTrap(const FragTrap &other)
{
	*this = other;
	std::cout << "ScavTrap " << _name << "'s copy constructor called!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if (_hitPoints > 0 && _energyPoints > 0)
		std::cout << "FragTrap " << _name << " requests a positive high-five!" << std::endl;
	else
		std::cout << "FragTrap " << _name << " can't High Five when dead!" << std::endl;
}
void FragTrap::attack(const std::string& target)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints -= 1;
	}
	else
		std::cout << "FragTrap " << _name << " can't attack when exhausted!" << std::endl;
}