#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string _name;
public:
	DiamondTrap(const std::string &name);
	DiamondTrap(void);
	~DiamondTrap();
	DiamondTrap(const DiamondTrap &other);
	DiamondTrap& operator=(const DiamondTrap& other);
	void attack(std::string target);
	void whoAmI();
};





#endif