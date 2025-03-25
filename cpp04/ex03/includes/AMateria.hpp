#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string.h>
#include <iostream>
#include "Icharacter.hpp"

class AMateria
{
protected:
	std::string _type;
public:
	AMateria();
	~AMateria();
	AMateria(const AMateria &other);
	AMateria &operator=(const AMateria &other);
	AMateria(std::string const & type);

	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};


#endif