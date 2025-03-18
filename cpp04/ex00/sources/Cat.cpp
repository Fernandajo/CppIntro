#include "../includes/Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
	std::cout << "Cat was created!" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat is destroyed!" << std::endl;
}

Cat::Cat(const Cat &other)
{
	_type = other._type;
	std::cout << "Cat's copy constructor was called!" << std::endl;
}
Cat &Cat::operator=(const Cat &other)
{
	if(this != &other)
		_type = other._type;
	std::cout << "Cat's copy operator was called!" << std::endl;
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "Meow!" << std::endl;
}