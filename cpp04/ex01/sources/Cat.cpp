#include "../includes/Cat.hpp"

Cat::Cat() : _brain(new Brain())
{
	_type = "Cat";
	std::cout << "Cat was created!" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat is destroyed!" << std::endl;
	delete _brain;
}

Cat::Cat(const Cat &other)
{
	_type = other._type;
	_brain = new Brain(*(other._brain));
	std::cout << "Cat's copy constructor was called!" << std::endl;
}
Cat &Cat::operator=(const Cat &other)
{
	if(this != &other)
	{
		_type = other._type;
		delete _brain;
		_brain = new Brain(*(other._brain));
	}
	std::cout << "Cat's copy operator was called!" << std::endl;
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "Meow!" << std::endl;
}

void	Cat::setIdeas(int count, std::string idea)
{
	_brain->setIdeas(count, idea);
}
std::string	Cat::getIdeas(int i) const
{
	return _brain->getIdeas(i);
}