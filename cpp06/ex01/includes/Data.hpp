#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <cstdlib>

struct Data
{
	int number;
	std::string name;
};

Data* deserialize(uintptr_t raw);

#endif