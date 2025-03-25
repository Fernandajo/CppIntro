#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
private:
	std::string _name;
	AMateria *_inventory[4];
public:
	Character();
	Character(std::string const &name);
	Character(const Character &other);
	Character &operator=(const Character &other);
	~Character();

	void use(int idx, ICharacter& target);
	void unequip(int idx);
	void equip(AMateria* m);
	std::string const & getName() const;
};




#endif