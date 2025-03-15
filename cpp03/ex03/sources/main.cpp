#include "../includes/FragTrap.hpp"

int main(void)
{
	FragTrap trap("Trap");
	FragTrap clone(trap);
	trap.attack("Chuck");
	trap.takeDamage(10);
	trap.beRepaired(10);
	trap.highFivesGuys();
	return 0;
}