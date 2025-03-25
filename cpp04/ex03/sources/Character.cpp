#include "../includes/Character.hpp"

Character::Character() : _name("Default")
{
}

Character::~Character()
{
}

Character::Character(std::string &name) : _name(name)
{

}

Character::Character(const Character &other)
{

}

Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < 4; i++)
		{
			_inventory[i] = _inventory[i];
		}
	}
	return *this;
}

void Character::use(int idx, ICharacter& target)
{

}

void Character::unequip(int idx)
{

}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			return ;
		}
	}

	
}

std::string const &Character::getName() const
{
	return _name;
}
