#include "../includes/Character.hpp"

// Default constructor
Character::Character() : _name("Default")
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	
	std::cout << "Default Character constructor was called!" << std::endl;
}

// Destructor
Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		delete _inventory[i];
	}
	
	std::cout << "Character destructor called!" << std::endl;
}

// Constructor
Character::Character(std::string const &name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << "Character " << _name << " was created!" << std::endl;
}

// Copy constructor
Character::Character(const Character &other)
{
	*this = other;
}

// Copy assignment operator
Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < 4; i++)
		{
			delete _inventory[i];
			_inventory[i] = other._inventory[i]->clone();
		}
	}
	return *this;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		return ;
	if (_inventory[idx] != NULL)
	{
		_inventory[idx]->use(target);
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return ;
	if (_inventory[idx] != NULL)
	{

		_inventory[idx] = NULL;
	}
	
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			std::cout << "AMateria " << m->getType() << " was equipped to Character " << _name << std::endl;
			return ;
		}
	}
	std::cout << "Character " << _name << "'s inventory is full! Can't equip AMateria!" << std::endl;
}

std::string const &Character::getName() const
{
	return _name;
}
