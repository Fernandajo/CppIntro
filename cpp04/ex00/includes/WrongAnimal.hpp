#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string.h>
class WrongAnimal
{
protected:
	std::string _type;
public:
	WrongAnimal(void); //default constructor
	WrongAnimal(std::string name); //name constructor
	WrongAnimal(const WrongAnimal &other); //copy constructor
	WrongAnimal &operator=(const WrongAnimal &other); //copy assignment constructor
	~WrongAnimal(void); //deconstructor

	std::string getType(void) const;
	void makeSound(void) const;
};


#endif