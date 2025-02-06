#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string _name;
	public:
		void setName( std::string name );
		void announce( void );
		Zombie();
		Zombie( std::string name );
		~Zombie( void );
};
Zombie* zombieHorde( int N, std::string name );

#endif