#include "../includes/Dog.hpp"

//default constructor
Dog::Dog()
{
	_type = "Dog";
	std::cout << "Dog was created!" << std::endl;
}

//deconstructor
Dog::~Dog()
{
	std::cout << "Dog was destroyed!" << std::endl;
}

//copy constructor
Dog::Dog(const Dog &other)
{
	_type = other._type;
	std::cout << "Dog's copy constructor was called!" << std::endl;
}

//copy assignment constructor
Dog &Dog::operator=(const Dog&other)
{
	if(this != &other)
		_type = other._type;
	std::cout << "Dog's copy assignment operator was called!" << std::endl;
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "Bark!" << std::endl;
}