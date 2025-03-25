#include "../includes/WrongAnimal.hpp"

//default constructor
WrongAnimal::WrongAnimal(void) : _type("Default")
{
	std::cout << "Wrong Animal type: " << _type << " was created!" << std::endl;
}

//name constructor
WrongAnimal::WrongAnimal(std::string name) : _type(name)
{
	std::cout << "Wrong Animal type: " << _type << " was created!" << std::endl;
}

//copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	*this = other;
	std::cout << "Wrong animal type: " << _type << "'s copy constructor was called!" << std::endl;
}

//copy assignment constructor
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if(this != &other)
		_type = other._type;
	std::cout << "Wrong animal type: " << _type << "'s copy assignment operator was called!" << std::endl;
	return *this;
}

//deconstructor
WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Wrong Animal type: " << _type << " was destroyed!" << std::endl;
}

std::string WrongAnimal::getType(void) const { return _type; }

void WrongAnimal::makeSound(void) const
{
	std::cout << "* General wrong animal sound*" << std::endl;
}