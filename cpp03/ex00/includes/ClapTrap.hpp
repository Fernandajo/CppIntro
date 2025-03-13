#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string.h>

class ClapTrap
{
private:
	std::string _name;
	int	_hitPoints;
	int	_energyPoints;
	int	_attackDamage;
public:
	ClapTrap(std::string name);
	ClapTrap(void);
	ClapTrap(const ClapTrap&other);
	~ClapTrap();
	ClapTrap& operator=(const ClapTrap& other);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};





#endif