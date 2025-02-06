#include "../includes/Zombie.hpp"

int main( void )
{
	Zombie Foo("Foo");
	Foo.announce();
	Zombie *bar = newZombie("bar");
	bar->announce();
	randomChump("Mar");
	delete (bar);
	return 0;
}