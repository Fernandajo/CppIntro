#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Icharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
private:
	std::string _name;
	AMateria *_inventory[4];
	static AMateria *materiasDropped[4];
	static int		dropped;
public:
	Character();
	Character(std::string &name);
	Character(const Character &other);
	Character &operator=(const Character &other);
	~Character();

	void use(int idx, ICharacter& target);
	void unequip(int idx);
	void equip(AMateria* m);
	std::string const & getName() const;
};




#endif