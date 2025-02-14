#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include <string.h>
#include "Weapon.hpp"

class HumanA
{
private:
	std::string _name;
	Weapon& _weapon;
public:
	HumanA(std::string name, Weapon& weapon);
	~HumanA();
	void setWeapon(Weapon& Hweapon);
	void attack( void ) const;
};

#endif