#include "../includes/Cat.hpp"

//default constructor
Cat::Cat()
{
	_type = "Cat";
	std::cout << "Cat was created!" << std::endl;
}

//deconstructor
Cat::~Cat()
{
	std::cout << "Cat is destroyed!" << std::endl;
}

//copy constructor
Cat::Cat(const Cat &other)
{
	*this = other;
	std::cout << "Cat's copy constructor was called!" << std::endl;
}

//copy assignment constructor
Cat &Cat::operator=(const Cat &other)
{
	if(this != &other)
		_type = other._type;
	std::cout << "Cat's copy assignment operator was called!" << std::endl;
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "Meow!" << std::endl;
}