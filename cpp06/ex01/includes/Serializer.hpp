#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Data.hpp"

struct Data;

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer &other);
	Serializer &operator=(const Serializer &other);
	~Serializer();
public:
	static uintptr_t serialize(Data* ptr);
};



#endif