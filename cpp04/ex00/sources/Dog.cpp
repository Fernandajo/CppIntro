#include "../includes/Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	std::cout << "Dog was created!" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog was destroyed!" << std::endl;
}

Dog::Dog(const Dog &other)
{
	_type = other._type;
	std::cout << "Dog's copy constructor was called!" << std::endl;
}
Dog &Dog::operator=(const Dog&other)
{
	if(this != &other)
		_type = other._type;
	std::cout << "Dog's copy operator was called!" << std::endl;
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "Bark!" << std::endl;
}