#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " was created!" << std::endl;
}

//Default constructor
ClapTrap::ClapTrap(void) : _name("claptrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default constructor was created!" << std::endl;
}
//Destructor
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " was destroid!" << std::endl;
}
//Copy constructor
ClapTrap::ClapTrap(const ClapTrap& other)
{
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	std::cout << "ClapTrap " << _name << "'s copy contructor was called!" << std::endl;
}
//Copy assignment operator
ClapTrap &ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout << "ClapTrap " << _name << "'s copy assignment operator was called!" << std::endl;
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0 || _energyPoints <= 0)
		std::cout << "ClapTrap " << _name << " can't attack when exhausted." << std::endl;
	else{
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints -= 1;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << " just took " << amount << " points of damage!" << std::endl;
	_hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(_energyPoints > 0)
	{
		std::cout << "ClapTrap " << _name << " is repairing itself with " << amount << " hit points!" << std::endl;
		_hitPoints += amount;
		_energyPoints -= 1;
	}
	else
		std::cout << "ClapTrap " << _name << " is exhausted!" << std::endl;
}