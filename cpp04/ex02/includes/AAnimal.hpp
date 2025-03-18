#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string.h>
class AAnimal
{
protected:
	std::string _type;
public:
	AAnimal(void); //default constructor
	AAnimal(std::string name); //name constructor
	AAnimal(const AAnimal &other); //copy constructor
	AAnimal &operator=(const AAnimal &other); //copy assignment constructor
	virtual ~AAnimal(void); //deconstructor

	std::string getType(void) const;
	virtual void makeSound(void) const = 0;
};

#endif