#include "../includes/ClapTrap.hpp"

int main()
{
	// ========================== ClapTrap Testing ==========================
	{
		{
			std::cout << "\033[1;32m=== ClapTrap Constructor Testing ===\033[0m" << std::endl;
			
			ClapTrap defaultClap;
			ClapTrap namedClap("Clappy");
			ClapTrap copyClap(namedClap);
			ClapTrap assignedClap;
			assignedClap = namedClap;
			
			std::cout << "\033[1;34m=== ClapTrap Functionality Testing ===\033[0m" << std::endl;
			
			namedClap.attack("Bandit-01");
			namedClap.takeDamage(3);
			namedClap.beRepaired(2);
			copyClap.attack("Bandit-02");
			assignedClap.takeDamage(5);
			assignedClap.beRepaired(4);
			std::cout << "\033[1;31m=== Test Concluded ===\033[0m" << std::endl;
		}
		{
			std::cout << "\033[1;34m=== ClapTrap Testing Ground ===\033[0m" << std::endl;
			ClapTrap clappy("Clappy");
			
			for (int i = 0; i < 7; i++) {
				clappy.attack("Bandit-01");
			}
				
			clappy.takeDamage(5);
			clappy.beRepaired(2);
			clappy.takeDamage(5);
			clappy.attack("Bandit-01");
			clappy.beRepaired(5);
			clappy.takeDamage(3);
			clappy.beRepaired(3);
			clappy.takeDamage(5);
			
			clappy.attack("Bandit-01");
			clappy.takeDamage(5);
			clappy.beRepaired(5);
			std::cout << "\033[1;31m=== ClapTrap Test Concluded ===\033[0m" << std::endl;
		}
	}
	return 0;
}