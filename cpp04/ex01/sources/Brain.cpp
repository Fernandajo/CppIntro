#include "../includes/Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
	{
		_ideas[i] = "";
	}
	std::cout << "Brain constructor called!" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called!" << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; ++i)
		_ideas[i] = other._ideas[i];
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Brain assignment operator called" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; ++i)
			_ideas[i] = other._ideas[i];
	}
	return *this;
}

void	Brain::setIdeas(int count, std::string idea)
{
	for (int i = 0; i <= count && i < 100; i++)
	{
		_ideas[i] = idea;
	}
	
}
std::string	Brain::getIdeas(int i) const
{
	return _ideas[i];
}