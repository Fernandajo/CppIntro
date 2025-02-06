#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string.h>

class Weapon
{
private:
	std::string _type;
public:
	Weapon(std::string name);
	Weapon();
	~Weapon();
	void setType(const std::string &type);
	const std::string	&getType() const;
};




#endif