#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string.h>
#include <iostream>

class AMateria
{
protected:
	std::string _type;
public:
	AMateria(/* args */);
	~AMateria();
	AMateria(std::string const & type);

	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};


#endif