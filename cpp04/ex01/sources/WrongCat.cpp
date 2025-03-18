#include "../includes/WrongCat.hpp"

WrongCat::WrongCat()
{
	_type = "Wrong Cat";
	std::cout << "Wrong Cat was created!" << std::endl;
}
WrongCat::~WrongCat()
{
	std::cout << "Wrong Cat was destroyed!" << std::endl;
}
WrongCat::WrongCat(const WrongCat &other)
{
	_type = other._type;
	std::cout << "Wrong Cat's copy constructor was called!" << std::endl;
}
WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
		_type = other._type;
	std::cout << "Wrong Cat's copy operator was called!" << std::endl;
	return *this;
}
void WrongCat::makeSound(void) const
{
	std::cout << "Wrong Meow!" << std::endl;
}