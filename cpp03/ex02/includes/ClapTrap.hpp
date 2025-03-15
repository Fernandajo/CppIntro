#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string.h>

class ClapTrap
{
protected:
	std::string _name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;
public:
	ClapTrap(std::string name);
	ClapTrap(void);
	ClapTrap(const ClapTrap&other);
	~ClapTrap();
	ClapTrap& operator=(const ClapTrap& other);
	void setHitPoints(unsigned int points);
	void setEnergyPoints(unsigned int points);
	void setAttackDamage(unsigned int amount);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};





#endif