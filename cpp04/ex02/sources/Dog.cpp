#include "../includes/Dog.hpp"

Dog::Dog() : _brain(new Brain())
{
	_type = "Dog";
	std::cout << "Dog was created!" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog was destroyed!" << std::endl;
	delete _brain;
}

Dog::Dog(const Dog &other)
{
	_type = other._type;
	_brain = new Brain(*other._brain);
	std::cout << "Dog's copy constructor was called!" << std::endl;
}
Dog &Dog::operator=(const Dog&other)
{
	if(this != &other)
	{
		_type = other._type;
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	std::cout << "Dog's copy operator was called!" << std::endl;
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "Bark!" << std::endl;
}

void	Dog::setIdeas(int count, std::string idea)
{
	_brain->setIdeas(count, idea);
}
std::string	Dog::getIdeas(int i) const
{
	return _brain->getIdeas(i);
}