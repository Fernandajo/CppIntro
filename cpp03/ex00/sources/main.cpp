#include "../includes/ClapTrap.hpp"

int main(void)
{
	ClapTrap jan("Jan");
	ClapTrap tom("Tom");
	ClapTrap clone(tom);
	ClapTrap clone2("clone 2");
	clone2 = jan;

	tom.attack("Jan");
	jan.takeDamage(5);
	jan.attack("Tom");
	tom.takeDamage(5);
	tom.beRepaired(3);
	clone2.takeDamage(5);
	jan.attack("Clone");
	clone.takeDamage(5);
	tom.takeDamage(10);
	tom.attack("Chuck");
	tom.beRepaired(10);
	return 0;
}