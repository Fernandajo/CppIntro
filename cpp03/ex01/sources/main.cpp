#include "../includes/ScavTrap.hpp"


int main(void)
{
	ScavTrap serena("Serena");
	serena.attack("Chuck");
	serena.takeDamage(10);
	serena.beRepaired(10);
	serena.guardGate();
	return 0;
}