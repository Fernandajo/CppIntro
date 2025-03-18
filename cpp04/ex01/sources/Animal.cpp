#include "../includes/Animal.hpp"

//default constructor
Animal::Animal() : _type("Default")
{
	std::cout << "Animal " << _type << " was created!" << std::endl;
}

//deconstructor
Animal::~Animal()
{
	std::cout << "Animal " << _type << " was destroyed!" << std::endl;
}

//name constructor
Animal::Animal(std::string typeAnimal) : _type(typeAnimal)
{
	std::cout << "Animal " << _type << " was created!" << std::endl;
}

//copy constructor
Animal::Animal(const Animal &other)
{
	_type = other._type;
	std::cout << "Animal " << _type << "'s copy constructor was called!" << std::endl;
}

//copy assignment constructor
Animal &Animal::operator=(const Animal &other)
{
	if(this != &other)
		_type = other._type;
	std::cout << "Animal " << _type << "'s copy assignment operator was called!" << std::endl;
	return *this;
}

std::string Animal::getType(void) const { return _type; }

void Animal::makeSound(void) const
{
	std::cout << "* General animal sound *" << std::endl;
}