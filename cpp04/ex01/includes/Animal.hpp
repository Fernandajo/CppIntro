#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string.h>
class Animal
{
protected:
	std::string _type;
public:
	Animal(void); //default constructor
	Animal(std::string name); //name constructor
	Animal(const Animal &other); //copy constructor
	Animal &operator=(const Animal &other); //copy assignment constructor
	virtual ~Animal(void); //deconstructor

	std::string getType(void) const;
	virtual void makeSound(void) const;
};

#endif