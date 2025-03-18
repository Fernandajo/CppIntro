#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
private:
	Brain* _brain;
public:
	Dog();
	~Dog();
	Dog(const Dog &other);
	Dog &operator=(const Dog&other);
	void makeSound(void) const;

	void	setIdeas(int count, std::string idea);
	std::string	getIdeas(int i) const;
};

#endif